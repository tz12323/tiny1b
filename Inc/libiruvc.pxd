from all_config cimport iruvc_error_t,iruvc_log_level_t
cdef extern from "libiruvc.h" nogil:
    # -------------------------- 宏定义映射 --------------------------
    # 图像格式常量
    cdef const char* FORMAT_YUY2    # "YUY2"
    cdef const char* FORMAT_MJPEG   # "MJPEG"
    # 最大FPS数量
    cdef const int FPS_CNT_MAX      # 32

    # -------------------------- 结构体类型映射 --------------------------
    # 设备配置结构体
    ctypedef struct DevCfg_t:
        unsigned int pid     # 产品ID
        unsigned int vid     # 厂商ID
        char* name           # 设备名称（C字符串指针）

    # 相机支持的流信息结构体
    ctypedef struct CameraStreamInfo_t:
        char* format               # 图像格式（如"YUY2"）
        unsigned int width         # 分辨率宽度
        unsigned int height        # 分辨率高度
        unsigned int frame_size    # 单帧字节大小
        unsigned int fps[FPS_CNT_MAX]  # 支持的帧率列表

    # 相机流参数结构体
    ctypedef struct CameraParam_t:
        DevCfg_t dev_cfg               # 设备配置
        char* format                   # 图像格式
        unsigned int width             # 分辨率宽度
        unsigned int height            # 分辨率高度
        unsigned int frame_size        # 单帧字节大小
        unsigned int fps               # 选定的帧率
        unsigned int timeout_ms_delay  # 帧获取超时时间（毫秒）

    # 用户回调函数结构体
    ctypedef struct UserCallback_t:
        void* usr_func   # 用户回调函数指针
        void* usr_param  # 用户回调参数指针

    # -------------------------- 函数接口映射 --------------------------
    # 获取libiruvc库版本（返回C字符串）
    char* libiruvc_version()

    # 获取当前支持的设备类型（返回C字符串）
    char* product_type()

    # 初始化libiruvc服务上下文
    iruvc_error_t uvc_camera_init()

    # 获取设备列表（输出参数为DevCfg_t数组指针）
    iruvc_error_t uvc_camera_list(DevCfg_t* devs_cfg)

    # 根据设备配置获取相机支持的流信息（输出参数为CameraStreamInfo_t数组指针）
    iruvc_error_t uvc_camera_info_get(DevCfg_t dev_cfg, CameraStreamInfo_t* camera_stream_info)

    # 打开相机设备（通过设备配置）
    iruvc_error_t uvc_camera_open(DevCfg_t dev_cfg)

    # 打开相同型号的多个设备（通过设备配置+设备索引区分）
    iruvc_error_t uvc_camera_open_same(DevCfg_t dev_cfg, int same_dev_index)

    # 启动相机流（支持回调模式或轮询模式，usr_callback=NULL为轮询）
    iruvc_error_t uvc_camera_stream_start(CameraParam_t camera_param, UserCallback_t* usr_callback)

    # 关闭相机流
    iruvc_error_t uvc_camera_stream_close()

    # 断开相机设备连接
    void uvc_camera_close()

    # 释放libiruvc服务上下文
    void uvc_camera_release()

    # 创建帧缓冲区（用于uvc_frame_get）
    void* uvc_frame_buf_create(CameraParam_t camera_param)

    # 释放帧缓冲区
    void uvc_frame_buf_release(void* frame_buf)

    # 轮询获取相机帧数据（回调模式下不可用）
    iruvc_error_t uvc_frame_get(void* raw_data)

    # 向UV相机发送控制指令
    iruvc_error_t uvc_control_cmd(unsigned char request_type, unsigned char bRequest,
                                 unsigned short wValue, unsigned short wIndex,
                                 unsigned char* data, unsigned short wLength,
                                 unsigned int timeout)

    # 注册日志打印级别
    void iruvc_log_register(iruvc_log_level_t log_level)
