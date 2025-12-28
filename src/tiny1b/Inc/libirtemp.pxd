from libc.stdint cimport uint16_t,uint8_t,int16_t
cdef extern from "libirtemp.h" nogil:
    # -------------------------- 宏定义映射（仅声明常量，无初始化） --------------------------
    cdef const double EPSILON          # 精度常量（0.001）
    cdef const int TEMP_NUM            # 温度点数（14）
    cdef const int DIST_NUM            # 距离点数（64）
    cdef const int HIGH_GAIN           # 高增益标记（1）
    cdef const int LOW_GAIN            # 低增益标记（0）
    cdef const int EMS_MAX             # 发射率最大值（128）
    cdef const int EMS_MIN             # 发射率最小值（0）
    cdef const int TAU_MAX             # 大气透过率最大值（128）
    cdef const int TAU_MIN             # 大气透过率最小值（0）
    cdef const int HIGH_GAIN_TA_MAX    # 高增益TA最大值（430）
    cdef const int HIGH_GAIN_TU_MAX    # 高增益TU最大值（430）
    cdef const int HIGH_GAIN_TA_MIN    # 高增益TA最小值（230）
    cdef const int HIGH_GAIN_TU_MIN    # 高增益TU最小值（230）
    cdef const int LOW_GAIN_TA_MAX     # 低增益TA最大值（873）
    cdef const int LOW_GAIN_TU_MAX     # 低增益TU最大值（873）
    cdef const int LOW_GAIN_TA_MIN     # 低增益TA最小值（230）
    cdef const int LOW_GAIN_TU_MIN     # 低增益TU最小值（230）
    cdef const int TAU_TEMP_MIN        # TAU温度最小值（-5）
    cdef const int TAU_TEMP_MAX        # TAU温度最大值（55）
    cdef const int TAU_DIST_MAX        # TAU距离最大值（50）
    cdef const int TAU_DIST_MIN        # TAU距离最小值（0.25）

    # -------------------------- 结构体类型映射 --------------------------
    # 温度数据分辨率结构体
    ctypedef struct TempDataRes_t:
        uint16_t width   # 宽度
        uint16_t height  # 高度

    # KT曲线搜索信息结构体
    ctypedef struct SearchInfo_t:
        uint16_t start_point  # 搜索起始点
        uint16_t end_point    # 搜索结束点

    # KT曲线转折点地址结构体
    ctypedef struct KtInfo_t:
        uint16_t start_addr  # 起始转折地址
        uint16_t end_addr    # 结束转折地址

    # Vtemp转换为真实温度的常量结构体
    ctypedef struct VtempInfo_t:
        int16_t Ktemp         # Ktemp值
        int16_t Btemp         # Btemp值
        uint16_t Address_CA   # CA地址

    # 初始校准环境温度点结构体
    ctypedef struct CaliPoint_t:
        int TH  # 高环境温度点
        int TL  # 低环境温度点

    # KT曲线归一化系数结构体
    ctypedef struct CaliFactor_t:
        int Kn  # KT曲线归一化K值
        int Bn  # KT曲线归一化B值

    # 双点校准环境温度结构体
    ctypedef struct EnvTemp_t:
        double T_high  # 高环境温度（℃）
        double T_low   # 低环境温度（℃）

    # 双点校准传感器Vtemp结构体
    ctypedef struct VTempSet_t:
        int VTemp_High  # 高环境温度下的Vtemp
        int VTemp_Low   # 低环境温度下的Vtemp

    # 重新校准后的修正系数结构体
    ctypedef struct ReCaliFactor_t:
        int K  # 环境估计K值
        int B  # 环境估计B值

    # 环境因子修正参数结构体
    ctypedef struct EnvParam_t:
        int EMS  # 目标发射率
        int TAU  # 大气透过率
        int Ta   # 大气温度
        int Tu   # 反射温度

    # 环境因子修正系数结构体
    ctypedef struct EnvFactor_t:
        int K_E  # 环境因子修正K值
        int B_E  # 环境因子修正B值

    # 温度阈值结构体
    ctypedef struct TempThreshold_t:
        int upper_limit  # 温度上限
        int lower_limit  # 温度下限

    # NUC映射因子结构体
    ctypedef struct NucFactor_t:
        int P0  # T-NUC映射常数项系数
        int P1  # T-NUC映射一次项系数
        int P2  # T-NUC映射二次项系数

    # 点坐标结构体
    ctypedef struct Dot_t:
        int x  # 水平坐标
        int y  # 垂直坐标

    # 线段结构体
    ctypedef struct Line_t:
        int start_x  # 起始水平坐标
        int start_y  # 起始垂直坐标
        int end_x    # 结束水平坐标
        int end_y    # 结束垂直坐标

    # 矩形区域结构体
    ctypedef struct Area_t:
        int start_x  # 起始水平坐标
        int start_y  # 起始垂直坐标
        int width    # 宽度
        int height   # 高度

    # 温度信息结构体
    ctypedef struct TempInfo_t:
        uint16_t max_temp   # 最大温度（开尔文×16）
        uint16_t min_temp   # 最小温度（开尔文×16）
        uint16_t avr_temp   # 平均温度（开尔文×16）
        Dot_t    max_cord   # 最高温度点坐标
        Dot_t    min_cord   # 最低温度点坐标

    # -------------------------- 枚举类型映射 --------------------------
    # 重新校准类型枚举
    ctypedef enum ReCaliType:
        SINGLE_POINT = 0  # 单点校准
        DOUBLE_POINT      # 双点校准

    # 报警类型枚举
    ctypedef enum AlarmType:
        TEMP_NORMAL = 0  # 温度正常
        OVER_HEAT = 1    # 过热
        OVER_COLD = 2    # 过冷

    # 日志级别枚举
    ctypedef enum irtemp_log_level:
        IRTEMP_LOG_DEBUG = 0        # 打印调试+错误信息
        IRTEMP_LOG_ERROR = 1        # 仅打印错误信息
        IRTEMP_LOG_NO_PRINT = 2     # 不打印任何信息

    # 错误类型枚举
    ctypedef enum irtemp_error:
        IRTEMP_SUCCESS = 0          # 执行成功
        IRTEMP_ERROR_PARAM = -1     # 参数无效
        MEMORY_ALLOC_FAIL = -2      # 内存分配失败
        FILE_OPERATION_FAIL = -3    # 文件操作失败

    # -------------------------- 函数指针映射 --------------------------
    # 调试日志打印函数指针（可变参数）
    cdef void (*irtemp_debug_print)(const char* fmt, ...)

    # 错误日志打印函数指针（可变参数）
    cdef void (*irtemp_error_print)(const char* fmt, ...)

    # -------------------------- 函数接口映射 --------------------------
    # 获取库版本
    char* irtemp_version(void)

    # 获取单点温度（坐标从0开始）
    irtemp_error_t get_point_temp(uint16_t* src, TempDataRes_t temp_res, Dot_t point, uint16_t* dst)

    # 获取线段温度（包含边界，坐标从0开始）
    irtemp_error_t get_line_temp(uint16_t* src, TempDataRes_t temp_res, Line_t line, TempInfo_t* temp_info)

    # 获取矩形区域温度（包含边界，坐标从0开始）
    irtemp_error_t get_rect_temp(uint16_t* src, TempDataRes_t temp_res, Area_t rect, TempInfo_t* temp_info)

    # 注册日志级别
    void irtemp_log_register(irtemp_log_level_t log_level)

    # 单点温度阈值报警
    AlarmType_t point_over_threshold_alarm(TempThreshold_t temp_threshold, uint16_t cur_temp)

    # 线段/矩形区域温度阈值报警
    AlarmType_t line_rect_over_threshold_alarm(TempThreshold_t temp_threshold, TempInfo_t* temp_info)

    # 查找KT曲线起始和结束转折地址
    irtemp_error_t find_start_and_end_addr(const uint16_t* kt_array, const SearchInfo_t* search_info,
                                           uint16_t len, KtInfo_t* kt_info)

    # 计算KT曲线归一化系数Kn和Bn
    irtemp_error_t calculate_Kn_and_Bn(const VtempInfo_t* vtemp_info, const KtInfo_t* kt_info,
                                       const CaliPoint_t* cali_point, CaliFactor_t* cali_factor)

    # 单点校准K和B值
    irtemp_error_t single_point_recalibrate_KB(const CaliFactor_t* cali_factor, int cur_vtemp,
                                               double t_env, ReCaliFactor_t* recali_factor)

    # 双点校准K和B值
    irtemp_error_t double_point_recalibrate_KB(const CaliFactor_t* cali_factor, const VTempSet_t* vtemp_set,
                                               const EnvTemp_t* env_temp, ReCaliFactor_t* recali_factor)

    # 估计当前环境温度（℃）
    irtemp_error_t env_temp_calculate(const CaliFactor_t* cali_factor, const ReCaliFactor_t* recali_factor,
                                       uint16_t cur_vtemp, double* t_env)

    # 计算固件运行的KE和BE
    irtemp_error_t calculate_KE_and_BE(const EnvParam_t* env_param, const NucFactor_t* nuc_factor,
                                       uint8_t gain_flag, EnvFactor_t* env_factor)

    # 带环境校正的NUC反向计算
    irtemp_error_t reverse_calc_NUC_with_env_correct(const NucFactor_t* nuc_factor, double kelvin_temp, uint16_t* nuc_cal)

    # 无环境校正的NUC反向计算
    irtemp_error_t reverse_calc_NUC_without_env_correct(const EnvFactor_t* env_factor, uint16_t nuc_cal, uint16_t* nuc_org)

    # 高精度计算新的KE和BE
    irtemp_error_t calculate_new_KE_and_BE(const EnvParam_t* env_param, const NucFactor_t* nuc_factor,
                                           uint8_t gain_flag, EnvFactor_t* env_factor)

    # 带环境校正的NUC重新计算
    irtemp_error_t recalc_NUC_with_env_correct(const EnvFactor_t* env_factor, uint16_t nuc_org, uint16_t* nuc_cal)

    # 用NUC表重映射温度（kelvin_temp*16）
    irtemp_error_t remap_temp(const uint16_t* nuc_table, uint16_t nuc_cal, uint16_t* temp_data)

    # 从NUC帧获取特定点的NUC值
    irtemp_error_t get_NUC_value(uint16_t* src, TempDataRes_t temp_res, Dot_t point, uint16_t* nuc_value)

    # 计算TAU值（基于不同距离的NUC值）
    uint16_t calculate_tau(uint16_t nuc_dist_high, uint16_t nuc_dist_low, uint16_t nuc_25_high, uint16_t nuc_25_low)

    # 从文件读取TAU值（双线性插值）
    irtemp_error_t read_tau(const char* file_name, float hum, float t_env, float dist, uint16_t* tau)

    # 向文件写入TAU值
    irtemp_error_t write_tau(const char* file_name, float hum, float t_env, float dist, uint16_t tau)

# -------------------------- 类型别名（简化使用） --------------------------
ctypedef ReCaliType ReCaliType_t
ctypedef AlarmType AlarmType_t
ctypedef irtemp_log_level irtemp_log_level_t
ctypedef irtemp_error irtemp_error_t