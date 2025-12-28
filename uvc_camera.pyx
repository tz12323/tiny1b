from Inc.all_config cimport iruvc_error_t, iruvc_log_level_t
from Inc.libiruvc cimport DevCfg_t, CameraParam_t, CameraStreamInfo_t, libiruvc_version as version, product_type as p_type, uvc_camera_init as init, uvc_camera_list as uvc_list
from Inc.libiruvc cimport uvc_camera_release as uvc_r,uvc_camera_close as uvc_c,uvc_camera_info_get as info_get,FPS_CNT_MAX, uvc_camera_open as uvc_open, uvc_camera_open_same as uvc_open_same,uvc_frame_buf_create as buf_create,uvc_frame_buf_release as buf_release,uvc_frame_get as frame_get

from enum import Enum
from libc.stdlib cimport malloc, free
from libc.string cimport memcpy
import numpy as np
cimport numpy as np

class CameraStreamInfo:
    def __init__(self,format:bytes, width: int, height: int, format_size: int, fps: int):
        self.format = format.decode("utf-8")  # 图像格式
        self.width = width                    # 选定的分辨率宽度
        self.height = height                  # 选定的分辨率高度
        self.format_size = format_size
        self.fps:list = fps                        # 选定的帧率

class CameraParam:
    def __init__(self, dev_cfg:DevCfg, format:bytes, width: int, height: int, format_size: int, fps: int, timeout_ms_delay: int):
        self.dev_cfg:DevCfg = dev_cfg                # 设备配置
        self.format:str = format.decode("utf-8")  # 图像格式
        self.width:int = width                    # 选定的分辨率宽度
        self.height:int = height                  # 选定的分辨率高度
        self.format_size:int = format_size        # 单帧字节大小
        self.fps:int = fps                        # 选定的帧率
        self.timeout_ms_delay:int = timeout_ms_delay  # 帧获取超时时间（毫秒）

class iruvc_error(Enum):
    IRUVC_SUCCESS                      = 0
    IRUVC_ERROR_PARAM                   = -1
    IRUVC_UVC_INIT_FAIL                 = -2
    IRUVC_GET_DEVICE_LIST_FAIL          = -3
    IRUVC_FIND_DEVICE_FAIL              = -4
    IRUVC_NOT_GET_DEVICE_INFO           = -5
    IRUVC_DEVICE_OPEN_FAIL              = -6
    IRUVC_GET_DEVICE_DESCRIPTOR_FAIL    = -7
    IRUVC_DEVICE_OPENED                 = -8
    IRUVC_GET_FORMAT_FAIL               = -9
    IRUVC_USER_CALLBACK_EMPTY           = -10
    IRUVC_START_STREAMING_FAIL          = -11
    IRUVC_GET_FRAME_OVER_TIME           = -12
    IRUVC_VDCMD_NOT_REGISTER            = -13
    IRUVC_VDCMD_REGISTER_FAIL           = -14
    IRUVC_CONTROL_TRANSFER_FAIL         = -15
    IRUVC_CHECK_DONE_FAIL               = -16
    IRUVC_VDCMD_TOO_LONG                = -17
    IRUVC_RESET_DEVICE_FAIL             = -18
    IRUVC_CLEAR_HALT_FAIL               = -19

class DevCfg:
    """对应C结构体DevCfg_t的Python类"""
    def __init__(self, vid: int, pid: int, name: str):
        self.pid = pid   # 产品ID
        self.vid = vid   # 厂商ID
        self.name = name # 设备名称

    def __repr__(self):
        return f"DevCfg(vid={self.vid}, pid={self.pid}, name='{self.name}')"

cdef tuple dev_cfg_to_obj(DevCfg_t *c_cfg, int max_num):
    """
    将C的DevCfg_t结构体数组转换为Python列表（按终止条件停止，避免越界）
    返回：(Python设备列表, 实际遍历的设备数) → 用于后续释放name内存
    """
    if not c_cfg:
        raise ValueError("DevCfg_t指针为空，无法转换")
    
    cdef:
        int i = 0
        list dev_list = []
        str py_name
        int actual_cnt = 0  # 记录实际有效设备数（用于释放内存）
    
    # 遍历规则：
    # 1. 不超过max_num（避免数组越界）
    # 2. 遇到「无效设备」（pid=0且vid=0且name=NULL）停止（C侧隐含终止条件）
    while i < max_num:
        # 检查是否是终止标记（核心！避免越界）
        if c_cfg[i].pid == 0 and c_cfg[i].vid == 0 and c_cfg[i].name == NULL:
            break
        
        # 转换设备信息（处理name为空的情况）
        py_name = c_cfg[i].name.decode("utf-8", errors="ignore") if c_cfg[i].name else "未知设备"
        dev_list.append(DevCfg(
            pid=c_cfg[i].pid,
            vid=c_cfg[i].vid,
            name=py_name
        ))
        
        i += 1
        actual_cnt += 1  # 实际设备数+1
    
    return dev_list, actual_cnt  # 返回列表和实际设备数

def libiruvc_version():
    return version().decode("utf-8")

def product_type():
    return p_type().decode("utf-8")

def uvc_camera_init():
    cdef iruvc_error_t err = init()
    return iruvc_error(err).name

# ---------------------- 核心修复2：释放name内存，避免泄漏 ----------------------
def uvc_camera_list(int num = 10):
    """
    获取UVC摄像头列表（修复越界+内存泄漏）
    :param num: 最大支持设备数（默认10，足够日常使用，且避免分配过多内存）
    :return: (错误枚举, 设备列表)
    """
    cdef:
        DevCfg_t* dev = NULL
        iruvc_error_t ret
        list dev_list = []
        int actual_cnt = 0  # 实际有效设备数（用于释放name）
    
    dev = <DevCfg_t*>malloc(sizeof(DevCfg_t) * num)
    if not dev:
        raise MemoryError("无法分配设备列表内存")
    
    # 2. 调用C函数（无法修改签名，只能传入数组指针）
    ret = uvc_list(dev)
    
    # 3. 先判断C函数返回值，失败直接返回（避免无效转换）
    error_enum = iruvc_error(ret)
    if error_enum != iruvc_error.IRUVC_SUCCESS:
        return error_enum, []
    
    # 4. 转换设备列表（按终止条件遍历，返回实际设备数）
    dev_list, actual_cnt = dev_cfg_to_obj(dev, num)

    # 5. 关键修复：释放C侧分配的name内存（避免泄漏）
    if dev != NULL:
        # 只释放实际有效设备的name（遍历actual_cnt次，而非num次）
        for i in range(actual_cnt):
            if dev[i].name != NULL:
                free(dev[i].name)  # 释放每个设备的name内存
        free(dev)  # 释放设备数组内存
        dev = NULL
    
    return error_enum.name, dev_list

def uvc_camera_release():
    uvc_r()

def uvc_camera_close():
    uvc_c()

def uvc_camera_info_get(dev_cfg:DevCfg):
    """
    获取相机支持的流信息
    :param dev_cfg: 设备配置对象
    :return: (CameraStreamInfo对象, 错误枚举)
    """
    cdef CameraStreamInfo_t* cam_info = NULL

    # 准备C结构体参数
    cdef DevCfg_t c_dev_cfg
    cdef bytes name = DevCfg.name.encode("utf-8")
    cdef char* name_ptr = name
    c_dev_cfg.pid = dev_cfg.pid
    c_dev_cfg.vid = dev_cfg.vid
    c_dev_cfg.name = <char*>malloc(len(name) + 1)
    if not c_dev_cfg.name:
        raise MemoryError("无法分配DevCfg_t.name内存")
    memcpy(c_dev_cfg.name, name_ptr, len(name) + 1)

    # 调用C函数获取相机流信息
    cdef iruvc_error_t ret
    cam_info = <CameraStreamInfo_t*>malloc(sizeof(CameraStreamInfo_t))
    if not cam_info:
        raise MemoryError("无法分配CameraStreamInfo_t内存")
    ret = info_get(c_dev_cfg, cam_info)
    error_enum = iruvc_error(ret)
    if error_enum != iruvc_error.IRUVC_SUCCESS:
        free(cam_info)
        raise RuntimeError(f"获取相机流信息失败，错误码：{error_enum.name}")
    fps_list = []
    cdef int i
    for i in range(FPS_CNT_MAX):  # 假设FPS_CNT_MAX为5
        if cam_info.fps[i] != 0:
            fps_list.append(cam_info.fps[i])
    result = CameraStreamInfo(
        format=cam_info.format,
        width=cam_info.width,
        height=cam_info.height,
        format_size=cam_info.frame_size,
        fps=fps_list
    )
    free(cam_info)
    return error_enum.name,result

def uvc_camera_open(dev_cfg:DevCfg):
    cdef:
        DevCfg_t c_dev_cfg
        bytes name = dev_cfg.name.encode("utf-8")
        char* name_ptr = name
        iruvc_error_t ret
    c_dev_cfg.pid = dev_cfg.pid
    c_dev_cfg.vid = dev_cfg.vid
    c_dev_cfg.name = <char*>malloc(len(name) + 1)
    if not c_dev_cfg.name:
        raise MemoryError("无法分配DevCfg_t.name内存")
    memcpy(c_dev_cfg.name, name_ptr, len(name) + 1)
    ret = uvc_camera_open(c_dev_cfg)
    free(c_dev_cfg.name)
    return iruvc_error(ret).name

def uvc_camera_open_same(dev_cfg:DevCfg, int same_dev_index):
    cdef:
        DevCfg_t c_dev_cfg
        bytes name = dev_cfg.name.encode("utf-8")
        char* name_ptr = name
        iruvc_error_t ret
    c_dev_cfg.pid = dev_cfg.pid
    c_dev_cfg.vid = dev_cfg.vid
    c_dev_cfg.name = <char*>malloc(len(name) + 1)
    if not c_dev_cfg.name:
        raise MemoryError("无法分配DevCfg_t.name内存")
    memcpy(c_dev_cfg.name, name_ptr, len(name) + 1)
    ret = uvc_camera_open_same(c_dev_cfg, same_dev_index)
    free(c_dev_cfg.name)
    return iruvc_error(ret).name

cdef void*frame_buf = NULL

def uvc_frame_buf_create(camera_param:CameraParam):
    cdef CameraParam_t c_camera_param
    cdef bytes format = camera_param.format.encode("utf-8")
    cdef char* format_ptr = format
    c_camera_param.dev_cfg.pid = camera_param.dev_cfg.pid
    c_camera_param.dev_cfg.vid = camera_param.dev_cfg.vid
    c_camera_param.dev_cfg.name = <char*>malloc(len(camera_param.dev_cfg.name) + 1)
    if not c_camera_param.dev_cfg.name:
        raise MemoryError("无法分配DevCfg_t.name内存")

    cdef:
        bytes name = camera_param.dev_cfg.name.encode("utf-8")
        char* name_ptr = name
    memcpy(c_camera_param.dev_cfg.name, name_ptr, len(name) + 1)
    c_camera_param.format = <char*>malloc(len(format) + 1)
    if not c_camera_param.format:
        free(c_camera_param.dev_cfg.name)
        raise MemoryError("无法分配CameraParam_t.format内存")
    memcpy(c_camera_param.format, format_ptr, len(format) + 1)
    c_camera_param.width = camera_param.width
    c_camera_param.height = camera_param.height
    c_camera_param.frame_size = camera_param.format_size
    c_camera_param.fps = camera_param.fps
    c_camera_param.timeout_ms_delay = camera_param.timeout_ms_delay

    global frame_buf
    if frame_buf != NULL:
        free(frame_buf)
        frame_buf = NULL
    frame_buf = buf_create(c_camera_param)
    free(c_camera_param.dev_cfg.name)
    free(c_camera_param.format)
    if frame_buf == NULL:
        raise RuntimeError("创建帧缓冲区失败")

def uvc_frame_buf_release():
    global frame_buf
    if frame_buf != NULL:
        buf_release(frame_buf)

def uvc_frame_get():
    frame_get(frame_buf)
    cdef:
        unsigned char* data_ptr
        int size
    data_ptr = <unsigned char*>frame_buf
    size = <int>data_ptr[0] | (<int>data_ptr[1] << 8) | (<int>data_ptr[2] << 16) | (<int>data_ptr[3] << 24)
    cdef np.ndarray[np.uint8_t, ndim=1] np_array = np.zeros(size, dtype=np.uint8)
    memcpy(<void*>np_array.data, <void*>(data_ptr + 4), size)
    return np_array
