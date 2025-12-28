from libc.stdint cimport uint16_t,uint8_t
cdef extern from "libirparse.h" nogil:
    # -------------------------- 枚举类型映射 --------------------------
    # 日志级别枚举
    ctypedef enum irparse_log_level:
        IRPARSE_LOG_DEBUG = 0       # 打印调试+错误信息
        IRPARSE_LOG_ERROR = 1       # 仅打印错误信息
        IRPARSE_LOG_NO_PRINT = 2    # 不打印任何信息

    # 错误类型枚举
    ctypedef enum irparse_error:
        IRPARSE_SUCCESS = 0         # 执行成功
        IRPARSE_ERROR_PARAM = -1    # 参数无效

    # -------------------------- 函数指针映射 --------------------------
    # 调试日志打印函数指针（可变参数）
    cdef void (*irparse_debug_print)(const char* fmt, ...)

    # 错误日志打印函数指针（可变参数）
    cdef void (*irparse_error_print)(const char* fmt, ...)

    # -------------------------- 工具函数映射 --------------------------
    # 获取库版本
    char* irparse_version(void)

    # Y14转Y8（14位Y值转8位Y值）
    uint8_t y14_to_y8(uint16_t y14_value)

    # Y14数组转RGB数组
    irparse_error_t y14_to_rgb(uint16_t* packet_data, int pixel_num, uint8_t* rgb_data)

    # Y14数组转YUV444数组（U=128, V=128）
    irparse_error_t y14_to_yuv444(uint16_t* packet_data, int pixel_num, uint8_t* yuv_data)

    # YUV444数组转YUV422数组
    irparse_error_t yuv444_to_yuv422(uint8_t* yuv444_data, int pixel_num, uint8_t* yuv422_data)

    # YUV422数组转RGB数组
    irparse_error_t yuv422_to_rgb(uint8_t* yuv422, int pixel_num, uint8_t* rgb_data)

    # YUV444数组转RGB数组
    irparse_error_t yuv444_to_rgb(uint8_t* packet_data, int pixel_num, uint8_t* rgb_data)

    # RGB数组转BGR数组
    irparse_error_t rgb_to_bgr(uint8_t* rgb_data, int pixel_num, uint8_t* bgr_data)

    # YUV422数组Y分量叠加值
    irparse_error_t yuv422_add_y(uint8_t* src, int pixel_num, int y_value, uint8_t* dst)

    # 原始数据分割为图像帧和温度帧
    irparse_error_t raw_data_cut(uint8_t* raw_data, int image_byte_size, int temp_byte_size,
                                 uint8_t* image_data, uint8_t* temp_data)

    # 注册日志级别（绑定日志打印函数）
    void irparse_log_register(irparse_log_level_t log_level)

# -------------------------- 类型别名（简化使用） --------------------------
ctypedef irparse_log_level irparse_log_level_t
ctypedef irparse_error irparse_error_t