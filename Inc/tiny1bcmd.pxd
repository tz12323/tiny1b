from all_config cimport iruvc_error_t
from libc.stdint cimport uint16_t,uint8_t,int16_t,uint32_t
cdef extern from "tiny1bcmd.h" nogil:
    # 环境参数相关宏（tpd_get_env_param / tpd_env_para_set）
    cdef const uint16_t PARAM_TPD_ENV_EMS                # 0x0100
    cdef const uint16_t PARAM_TPD_ENV_TAU                # 0x0101
    cdef const uint16_t PARAM_TPD_ENV_TA                 # 0x0202
    cdef const uint16_t PARAM_TPD_ENV_TU                 # 0x0203

    # 距离参数相关宏（tpd_get_dist / tpd_dist_para_set）
    cdef const uint16_t PARAM_TPD_DIST_PARA_A0           # 0x0400
    cdef const uint16_t PARAM_TPD_DIST_PARA_B0           # 0x0401
    cdef const uint16_t PARAM_TPD_DIST_PARA_C0           # 0x0202
    cdef const uint16_t PARAM_TPD_DIST_PARA_A1           # 0x0403
    cdef const uint16_t PARAM_TPD_DIST_PARA_B1           # 0x0404
    cdef const uint16_t PARAM_TPD_DIST_PARA_C1           # 0x0205
    cdef const uint16_t PARAM_TPD_DIST_PARA_D            # 0x0206

    # 过热保护参数相关宏（agc_get_protect_overheat_param / agc_protect_overheat_param_set）
    cdef const uint16_t PARAM_AGC_OVERHEAT_THD           # 0x0200
    cdef const uint16_t PARAM_AGC_OVERHEAT_CNT           # 0x0401
    cdef const uint16_t PARAM_AGC_OVERHEAT_CLOSED_TIME   # 0x0202
    cdef const uint16_t PARAM_AGC_OVERHEAT_EN            # 0x0103

    # -------------------------- 函数接口映射 --------------------------
    # 初始化并注册vdcmd句柄
    iruvc_error_t vdcmd_init()

    # 获取快门自动状态标志
    iruvc_error_t shutter_get_auto_flag(uint8_t* value)

    # 获取快门最小间隔时间
    iruvc_error_t shutter_get_min_interval(uint8_t* min_interval)

    # 获取快门最大间隔时间
    iruvc_error_t shutter_get_max_interval(uint8_t* max_interval)

    # 从设备获取环境参数
    iruvc_error_t tpd_get_env_param(uint16_t param, uint8_t* value)

    # 从设备获取过热保护参数
    iruvc_error_t agc_get_protect_overheat_param(uint16_t param, uint8_t value_len, uint8_t* value)

    # 从设备获取IR传感器增益标志
    iruvc_error_t get_ir_sensor_flag(uint8_t* flag)

    # 从设备获取IR传感器Vtemp值
    iruvc_error_t get_ir_sensor_vtemp(uint16_t* pwVtemp)

    # 从设备获取NUC_T参数（P0/P1/P2）
    iruvc_error_t tpd_nuc_t_param_get(uint8_t paramtype, uint8_t byLen, uint8_t* pbyData)

    # 从设备获取K_T数组
    iruvc_error_t tpd_kt_get(uint16_t wAddr, uint16_t wLen, uint8_t* pbyData)

    # 从设备获取NUC_T数组
    iruvc_error_t tpd_nuct_get(uint16_t wAddr, uint16_t wLen, uint8_t* pbyData)

    # 设置快门自动状态标志（去重：头文件重复声明，仅保留一次）
    iruvc_error_t shutter_set_auto_flag(uint8_t auto_flag)

    # 设置快门策略参数：Vtemp阈值
    iruvc_error_t shutter_set_vtemp_thd(uint8_t vtemp_thd)

    # 设置快门策略参数：最小间隔时间
    iruvc_error_t shutter_set_min_interval(uint8_t min_interval)

    # 设置快门策略参数：最大间隔时间
    iruvc_error_t shutter_set_max_interval(uint8_t max_interval)

    # 手动触发快门
    iruvc_error_t shutter_manual(void)

    # 重置快门参数
    iruvc_error_t shutter_reset(void)

    # 重置坏点表
    iruvc_error_t dpc_dpt_reset(void)

    # 手动添加坏点位置（x/y从1开始）
    iruvc_error_t dpc_manual_dp_location(uint16_t x, uint16_t y)

    # 手动添加坏点（固件移除）
    iruvc_error_t dpc_manual_dp_add(void)

    # 保存手动坏点列表
    iruvc_error_t dpc_manual_dp_list_save(void)

    # 校准盖片并移除盖片影响
    iruvc_error_t rmvc_cal(void)

    # 重置盖片参数
    iruvc_error_t rmvc_reset(void)

    # 设置温度检测算法环境参数
    iruvc_error_t tpd_env_para_set(uint16_t param, uint16_t value)

    # 设置温度数据手动参数TK
    iruvc_error_t tpd_manual_param_tk_set(uint16_t value)

    # 设置温度数据手动参数TB
    iruvc_error_t tpd_manual_param_tb_set(int16_t value)

    # 设置TK/TB启用标志（1=开启/0=关闭）
    iruvc_error_t tpd_manual_kb_cali_en_set(uint8_t enable_flag)

    # 重置温度检测参数（KT/BT/NUCT/P0/P1/P2）
    iruvc_error_t tpd_temp_param_reset(void)

    # 重置温度检测环境参数（EMS/TAU/TA/TU）
    iruvc_error_t tpd_env_param_reset(void)

    # 记录高温黑体的NUC值和温度
    iruvc_error_t tpd_cal_high_temp_set(uint16_t temp)

    # 记录低温黑体的NUC值和温度
    iruvc_error_t tpd_cal_low_temp_set(uint16_t temp)

    # 重新计算温度检测算法参数
    iruvc_error_t tpd_new_recal(void)

    # 记录当前温度黑体的NUC值和温度（开尔文）
    iruvc_error_t tpd_single_point_temp_set(uint16_t temp)

    # 单点校准：重新计算温度检测算法参数
    iruvc_error_t tpd_single_point_cal(void)

    # 设置KTBT算法启用标志（1=开启/0=关闭）
    iruvc_error_t tpd_ktbt_cali_enable(uint8_t enable_flag)

    # 设置环境因子校准算法启用标志（1=开启/0=关闭）
    iruvc_error_t tpd_env_cali_enable(uint8_t enable_flag)

    # 设置NUC-T映射算法启用标志（1=开启/0=关闭）
    iruvc_error_t tpd_nuc_t_enable(uint16_t enable_flag)

    # 设置AGC算法启用标志（1=开启/0=关闭）
    iruvc_error_t agc_enable_set(uint8_t enable_flag)

    # 设置AGC算法增益范围
    iruvc_error_t agc_gain_range_set(uint16_t range)

    # 设置过热保护算法参数
    iruvc_error_t agc_protect_overheat_param_set(uint16_t param, uint32_t value)

    # 切换到高增益模式
    iruvc_error_t sw_high_flag(void)

    # 切换到低增益模式
    iruvc_error_t sw_low_flag(void)

    # 重置设备所有配置
    iruvc_error_t reset_all(void)

    # 256*192模式下切换图像数据/温度数据显示（0=图像/1=温度）
    iruvc_error_t temp_data_display_switch(uint8_t enable_flag)

