cdef extern from "all_config.h" nogil:
    cdef const char* PRODUCT_TYPE

    enum iruvc_error:
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
    ctypedef iruvc_error iruvc_error_t

    enum iruvc_log_level:
        IRUVC_LOG_DEBUG     = 0
        IRUVC_LOG_ERROR     = 1
        IRUVC_LOG_NO_PRINT  = 2
    ctypedef iruvc_log_level iruvc_log_level_t

    cdef void (*iruvc_debug_print)(const char* fmt, ...)
    cdef void (*iruvc_error_print)(const char* fmt, ...)


