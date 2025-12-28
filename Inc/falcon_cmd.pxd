from all_config cimport iruvc_error_t
from libc.stdint cimport uint8_t ,uint16_t,int16_t,uint32_t
cdef extern from "your_falcon_cmd_header.h" nogil:
    # 恢复默认配置类型
    ctypedef enum prop_default_cfg:
        DEF_CFG_ALL = 0
        DEF_CFG_TECLESS_K
        DEF_CFG_TPD
        DEF_CFG_PROP_PAGE

    # 属性页默认参数类型
    ctypedef enum prop_default_params:
        PROP_SEL_SHUTTER = 0
        PROP_SEL_IMAGE
        PROP_SEL_OVEREXPOSURE
        PROP_SEL_TPD

    # 属性页自动快门参数类型
    ctypedef enum prop_auto_shutter_params:
        SHUTTER_PROP_SWITCH = 0
        SHUTTER_PROP_MIN_INTERVAL
        SHUTTER_PROP_MAX_INTERVAL
        SHUTTER_PROP_TEMP_THRESHOLD_OOC
        SHUTTER_PROP_TEMP_THRESHOLD_B

    # 属性页图像参数类型
    ctypedef enum prop_image_params:
        IMAGE_PROP_LEVEL_TNR = 0
        IMAGE_PROP_LEVEL_SNR
        IMAGE_PROP_LEVEL_DDE
        IMAGE_PROP_LEVEL_BRIGHTNESS
        IMAGE_PROP_LEVEL_CONTRAST
        IMAGE_PROP_MODE_AGC
        IMAGE_PROP_LEVEL_MAX_GAIN
        IMAGE_PROP_LEVEL_BOS
        IMAGE_PROP_ONOFF_AGC
        IMAGE_PROP_SEL_MIRROR_FLIP

    # 属性页过曝参数类型
    ctypedef enum prop_overexposure_params:
        OVEXP_PROP_SWITCH = 0
        OVEXP_PROP_PIX_THRESHOLD
        OVEXP_PROP_CNT_THRESHOLD
        OVEXP_PROP_CNT_DELAY_CLOSE

    # 属性页TPD参数类型
    ctypedef enum prop_tpd_params:
        TPD_PROP_DISTANCE = 0
        TPD_PROP_TU
        TPD_PROP_TA
        TPD_PROP_EMS
        TPD_PROP_TAU
        TPD_PROP_GAIN_SEL

    # 预览路径
    ctypedef enum preview_path:
        PREVIEW_PATH0 = 0
        PREVIEW_PATH1

    # 设备ID类型
    ctypedef enum device_id_types:
        CHIP_FW_INFO = 0
        FW_COMPILE_DATA
        DEV_QUALIFICATION
        IR_INFO

    # OOC/B更新类型
    ctypedef enum ooc_b_update_types:
        B_UPDATE = 0
        OOC_UPDATE
        OOC_B_UPDATE

    # 快门控制使能状态
    ctypedef enum shutter_sta_types:
        SHUTTER_CTL_DIS = 0
        SHUTTER_CTL_EN

    # 快门手动开关类型
    ctypedef enum shutter_manual_types:
        SHUTTER_OPEN = 0
        SHUTTER_CLOSE

    # 无TEC温度区域类型
    ctypedef enum tecless_temp_area_types:
        HIGH_TEMP = 0
        NORMAL_TEMP
        LOW_TEMP

    # 镜像/翻转类型
    ctypedef enum mirror_flip_types:
        NO_MIRROR_FLIP = 0
        ONLY_MIRROR
        ONLY_FLIP
        MIRROR_FLIP

    # 伪彩色模式类型
    ctypedef enum pseudo_color_types:
        PSEUDO_COLOR_BYPASS = 0
        PSEUDO_COLOR_MODE_1
        PSEUDO_COLOR_MODE_2
        PSEUDO_COLOR_MODE_3
        PSEUDO_COLOR_MODE_4
        PSEUDO_COLOR_MODE_5
        PSEUDO_COLOR_MODE_6
        PSEUDO_COLOR_MODE_7
        PSEUDO_COLOR_MODE_8
        PSEUDO_COLOR_MODE_9
        PSEUDO_COLOR_MODE_10
        PSEUDO_COLOR_MODE_11
        PSEUDO_COLOR_MODE_GUARD

    # 缩放步长
    ctypedef enum zoom_scale_step:
        ZOOM_STEP1 = 1
        ZOOM_STEP2
        ZOOM_STEP3
        ZOOM_STEP4

    # -------------------------- 结构体类型映射 --------------------------
    # 点坐标结构体（#pragma pack(1) 由C头文件处理，Cython自动兼容）
    ctypedef struct Point_t:
        uint16_t x
        uint16_t y

    # 矩形区域结构体
    ctypedef struct Rect_t:
        uint16_t start_x
        uint16_t start_y
        uint16_t end_x
        uint16_t end_y

    # 帧温度索引结构体
    ctypedef struct FrameTempIdx_t:
        uint8_t max_point_idx
        uint8_t min_point_idx
        uint8_t center_point_idx

    # ISP Gamma参数结构体
    ctypedef struct isp_gamma_param_t:
        uint8_t gamma_en
        uint8_t pix_inv_en
        uint8_t gamma_rate
        int16_t brightness

    # -------------------------- 函数接口映射 --------------------------
    # 初始化并注册vdcmd句柄
    iruvc_error_t vdcmd_init(void)

    # 恢复默认配置
    iruvc_error_t restore_default_cfg(prop_default_cfg default_cfg_type)

    # 加载属性页默认参数
    iruvc_error_t load_prop_default_params(prop_default_params default_param)

    # 设置属性页自动快门参数
    iruvc_error_t set_prop_auto_shutter_params(prop_auto_shutter_params shutter_param, uint16_t value)

    # 获取属性页自动快门参数
    iruvc_error_t get_prop_auto_shutter_params(prop_auto_shutter_params shutter_param, uint16_t* value)

    # 设置属性页图像参数
    iruvc_error_t set_prop_image_params(prop_image_params image_param, uint16_t value)

    # 获取属性页图像参数
    iruvc_error_t get_prop_image_params(prop_image_params image_param, uint16_t* value)

    # 设置属性页过曝参数
    iruvc_error_t set_prop_overexposure_params(prop_overexposure_params ovexp_param, uint16_t value)

    # 获取属性页过曝参数
    iruvc_error_t get_prop_overexposure_params(prop_overexposure_params ovexp_param, uint16_t* value)

    # 设置属性页TPD参数
    iruvc_error_t set_prop_tpd_params(prop_tpd_params tpd_param, uint16_t value)

    # 获取属性页TPD参数
    iruvc_error_t get_prop_tpd_params(prop_tpd_params tpd_param, uint16_t* value)

    # 获取设备信息
    iruvc_error_t get_device_info(device_id_types id_type, uint8_t* id_content)

    # 获取PN编号
    iruvc_error_t get_pn(uint8_t* pn_content)

    # 设置PN编号
    iruvc_error_t set_pn(uint8_t* pn_content)

    # 获取SN编号
    iruvc_error_t get_sn(uint8_t* sn_content)

    # 设置SN编号
    iruvc_error_t set_sn(uint8_t* sn_content)

    # 更新OOC/B值
    iruvc_error_t ooc_b_update(ooc_b_update_types update_type)

    # 设置快门控制状态
    iruvc_error_t shutter_sta_set(shutter_sta_types sta_type)

    # 手动开关快门
    iruvc_error_t shutter_manual_switch(shutter_manual_types manual_type)

    # 获取无TEC温度区域
    iruvc_error_t tecless_temp_area_get(uint8_t* temp_area)

    # 获取Gamma参数
    iruvc_error_t gamma_param_get(isp_gamma_param_t* gamma_param)

    # 设置Gamma参数
    iruvc_error_t gamma_param_set(isp_gamma_param_t* gamma_param)

    # 获取镜像/翻转状态
    iruvc_error_t mirror_flip_get(uint8_t* mirror_flip_status)

    # 设置镜像/翻转状态
    iruvc_error_t mirror_flip_set(mirror_flip_types mirror_flip_status)

    # 获取预览路径的伪彩色模式
    iruvc_error_t pseudo_color_get(preview_path path, uint8_t* color_type)

    # 设置预览路径的伪彩色模式
    iruvc_error_t pseudo_color_set(preview_path path, pseudo_color_types color_type)

    # 获取TPD距离值
    iruvc_error_t tpd_distance_get(uint16_t* tpd_distance)

    # 设置TPD距离值（注意：C头文件中参数是指针，保持一致）
    iruvc_error_t tpd_distance_set(uint16_t* tpd_distance)

    # 获取TPD的EMS值
    iruvc_error_t tpd_ems_get(uint8_t* tpd_ems)

    # 设置TPD的EMS值（C头文件中参数是指针，保持一致）
    iruvc_error_t tpd_ems_set(uint8_t* tpd_ems)

    # 显示点测温
    iruvc_error_t tpd_show_point_temp(preview_path path, uint8_t point_idx, Point_t point)

    # 隐藏点测温
    iruvc_error_t tpd_hide_point_temp(preview_path path, uint8_t point_idx)

    # 显示矩形测温
    iruvc_error_t tpd_show_rect_temp(preview_path path, uint8_t rect_idx, Rect_t rect)

    # 隐藏矩形测温
    iruvc_error_t tpd_hide_rect_temp(preview_path path, uint8_t rect_idx)

    # 显示整帧测温
    iruvc_error_t tpd_show_frame_temp(preview_path path, FrameTempIdx_t frame_idx)

    # 隐藏整帧测温
    iruvc_error_t tpd_hide_frame_temp(preview_path path)

    # 中心放大
    iruvc_error_t zoom_center_up(preview_path path, zoom_scale_step scale_step)

    # 中心缩小
    iruvc_error_t zoom_center_down(preview_path path, zoom_scale_step scale_step)

    # 定点放大
    iruvc_error_t zoom_position_up(preview_path path, zoom_scale_step scale_step, Point_t position)

    # 定点缩小
    iruvc_error_t zoom_position_down(preview_path path, zoom_scale_step scale_step, Point_t position)

    # XDATA读取
    iruvc_error_t xdata_read(uint16_t addr, uint8_t bylen, uint8_t* pbyData)

    # XDATA写入
    iruvc_error_t xdata_write(uint16_t addr, uint8_t bylen, uint8_t* pbyData)

    # SPI读取
    iruvc_error_t spi_read(uint32_t addr, uint16_t wlen, uint8_t* pbyData)

    # SPI写入
    iruvc_error_t spi_write(uint32_t addr, uint16_t wlen, uint8_t* pbyData)

    # SPI扇区擦除
    iruvc_error_t spi_erase_sector(uint32_t addr, uint16_t sector_cnt)

    # SPI固件擦除
    iruvc_error_t spi_erase_fw(void)

    # SPI状态写入
    iruvc_error_t spi_write_status(uint8_t status_reg_type, uint8_t status_val)

    # SPI状态读取
    iruvc_error_t spi_read_status(uint8_t status_reg_type, uint8_t* pstatus_val)

    # SPI写入标签
    iruvc_error_t spi_write_tag(void)

    # SPI读取ID
    iruvc_error_t spi_read_id(uint8_t* pbyID)

    # 获取系统设备信息
    iruvc_error_t sys_get_device_info(uint8_t sys_device_info_mode_key, uint16_t wlen, uint8_t* pbyData)

    # 复位更新固件
    iruvc_error_t sys_reset_to_update_fw(void)

    # 复位到ROM
    iruvc_error_t sys_reset_to_rom(void)

    # I2C从机读取
    iruvc_error_t i2c_slave_read(uint16_t addr, uint8_t bylen, uint8_t* pbyData)