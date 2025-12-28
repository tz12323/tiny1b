#pragma once

#include <stdint.h>
#include "all_config.h"

#if defined(TINY1B_CMD)

//tpd_get_env_param  tpd_env_para_set
#define PARAM_TPD_ENV_EMS                   0x0100
#define PARAM_TPD_ENV_TAU                   0x0101
#define PARAM_TPD_ENV_TA                    0x0202
#define PARAM_TPD_ENV_TU                    0x0203

//tpd_get_dist  tpd_dist_para_set
#define PARAM_TPD_DIST_PARA_A0               0x0400
#define PARAM_TPD_DIST_PARA_B0               0x0401
#define PARAM_TPD_DIST_PARA_C0               0x0202
#define PARAM_TPD_DIST_PARA_A1               0x0403
#define PARAM_TPD_DIST_PARA_B1               0x0404
#define PARAM_TPD_DIST_PARA_C1               0x0205
#define PARAM_TPD_DIST_PARA_D                0x0206



//agc_get_protect_overheat_param   agc_protect_overheat_param_set
#define PARAM_AGC_OVERHEAT_THD              0x0200
#define PARAM_AGC_OVERHEAT_CNT              0x0401
#define PARAM_AGC_OVERHEAT_CLOSED_TIME      0x0202
#define PARAM_AGC_OVERHEAT_EN               0x0103


/**
 * @brief Initialize and register vdcmd's handle
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t vdcmd_init();


/**
 * @brief Get shutter auto state flag
 *
 * @param[out] value the value array get from device
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_get_auto_flag(uint8_t* value);


/**
 * @brief Get shutter minimum interval time
 *
 * @param[out] min_interval the minimum interval time of shutter
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_get_min_interval(uint8_t* min_interval);


/**
 * @brief Get shutter maximum interval time
 *
 * @param[out] max_interval the maximum interval time of shutter
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_get_max_interval(uint8_t* max_interval);


/**
 * @brief Get environment parameter from device
 *
 * @param[in] param represents which parameter need to get
 * @param[out] value the value array get from device
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_get_env_param(uint16_t param, uint8_t* value);



/**
 * @brief Get overheat protection parameter from device
 *
 * @param[in] param represents which parameter need to get
 * @param[in] value_len the length of value array
 * @param[out] value the value array get from device
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t agc_get_protect_overheat_param(uint16_t param, uint8_t value_len, uint8_t* value);


/**
 * @brief Get ir sensor gain flag from device
 *
 * @param[out] flag the value array get from device
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_ir_sensor_flag(uint8_t* flag);


/**
 * @brief Get ir sensor vtemp from device
 *
 * @param[out] pwVtemp the value array get from device
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_ir_sensor_vtemp(uint16_t* pwVtemp);


/**
 * @brief Get NUC_T parameter(P0,P1,P2) from device
 *
 * @param[in] paramtype represents which parameter need to get
 * @param[in] byLen the length of value array
 * @param[out] pbyData the value array get from device
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_nuc_t_param_get(uint8_t paramtype, uint8_t byLen, uint8_t* pbyData);


/**
 * @brief Get K_T array from device
 *
 * @param[in] wAddr the start address of K_T array
 * @param[in] wLen the length of value array
 * @param[out] pbyData the value array get from device
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_kt_get(uint16_t wAddr, uint16_t wLen, uint8_t* pbyData);


/**
 * @brief Get NUC_T array from device
 *
 * @param[in] wAddr the start address of NUC_T array
 * @param[in] wLen the length of value array
 * @param[out] pbyData the value array get from device
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_nuct_get(uint16_t wAddr, uint16_t wLen, uint8_t* pbyData);


/**
 * @brief Set shutter auto state flag
 *
 * @param[in] auto_flag  the flag of shutter auto state
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_set_auto_flag(uint8_t auto_flag);


/**
 * @brief Set shutter policy parameter: vtemp threshold
 *
 * @param[in] vtemp_thd  vtemp threshold
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_set_vtemp_thd(uint8_t vtemp_thd);


/**
 * @brief Set shutter policy parameter: minimum interval time
 *
 * @param[in] min_interval  minimum interval time
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_set_min_interval(uint8_t min_interval);


/**
 * @brief Set shutter policy parameter: maximum interval time
 *
 * @param[in] max_interval  maximum interval time
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_set_max_interval(uint8_t max_interval);


/**
 * @brief Manual shutter
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_manual(void);


/**
 * @brief Reset shutter parameter
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_reset(void);


/**
 * @brief Reset dead  pix table
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t dpc_dpt_reset(void);


/**
 * @brief Manual add dead  pix location
 *
 * @param[in] x the row of image(from 1 to count)
 * @param[in] y the column of image(from 1 to count)
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t dpc_manual_dp_location(uint16_t x, uint16_t y);


/**
 * @brief Manual add dead pix for firmware remove dead pix
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t dpc_manual_dp_add(void);


/**
 * @brief Save manual dead pix list
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t dpc_manual_dp_list_save(void);


/**
 * @brief Calibrate cover and remove cover
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t rmvc_cal(void);


/**
 * @brief Reset cover
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t rmvc_reset(void);



/**
 * @brief Set shutter auto state flag
 *
 * @param auto_flag auto flag of shutter
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_set_auto_flag(uint8_t auto_flag);


/**
 * @brief Set environment parameter for temperature detection algorithm
 *
 * @param[in] param  represent which parameter will be set
 * @param[in] value  the value of the parameter
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_env_para_set(uint16_t param, uint16_t value);



/**
 * @brief Set manual parameter TK for temperature data
 *
 * @param[in]  value  the value of the TK
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_manual_param_tk_set(uint16_t value);


/**
 * @brief Set manual parameter TB for temperature data
 *
 * @param[in]  value  the value of the TB
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_manual_param_tb_set(int16_t value);


/**
 * @brief Set enable flag of TK and TB for temperature data
 *
 * @param[in]  enable_flag  enable flag(1:open /0:close)
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_manual_kb_cali_en_set(uint8_t enable_flag);


/**
 * @brief Reset temperature parameter(KT,BT,NUCT,P0,P1,P2) for temperature detection
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_temp_param_reset(void);


/**
 * @brief Reset environment parameter(EMS,TAU,TA,TU) for temperature detection
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_env_param_reset(void);


/**
 * @brief Record NUC value and blackbody temperature facing high temperature blackbody 
 *
 * @param[in] temp temperature of high temperature blackbody 
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_cal_high_temp_set(uint16_t temp);


/**
 * @brief Record NUC value and blackbody temperature facing low temperature blackbody
 *
 * @param[in] temp temperature of low temperature blackbody
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_cal_low_temp_set(uint16_t temp);


/**
 * @brief Recalculate parameter for temperature detection algorithm
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_new_recal(void);


/**
 * @brief Record NUC value and blackbody temperature facing current temperature blackbody
 *
 * @param[in] temp temperature of current temperature blackbody(Kelvin temperature)
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_single_point_temp_set(uint16_t temp);


/**
 * @brief Recalculate parameter for temperature detection algorithm
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_single_point_cal(void);


/**
 * @brief Set enable flag of KTBT algorithm
 *
 * @param[in]  enable_flag  enable flag(1:open /0:close)
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_ktbt_cali_enable(uint8_t enable_flag);


/**
 * @brief Set enable flag of environment factor calibration algorithm
 *
 * @param[in]  enable_flag  enable flag(1:open /0:close)
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_env_cali_enable(uint8_t enable_flag);


/**
 * @brief Set enable flag of NUC-T mapping algorithm
 *
 * @param[in]  enable_flag  enable flag(1:open /0:close)
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_nuc_t_enable(uint16_t enable_flag);


/**
 * @brief Set enable flag of AGC algorithm
 *
 * @param[in]  enable_flag  enable flag(1:open /0:close)
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t agc_enable_set(uint8_t enable_flag);


/**
 * @brief Set gain range of  AGC algorithm
 *
 * @param[in]  range  gain range of  AGC algorithm
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t agc_gain_range_set(uint16_t range);


/**
 * @brief Set parameter of overheat protection algorithm
 *
 * @param[in]  param  represents which parameter of overheat protection algorithm
 * @param[out]  value  the value of parameter
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t agc_protect_overheat_param_set(uint16_t param, uint32_t value);


/**
 * @brief Switch to high gain mode
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t sw_high_flag(void);


/**
 * @brief Switch to low gain mode
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t sw_low_flag(void);


/**
 * @brief Reset all configuration of device
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t reset_all(void);


/**
 * @brief  Switch display mode between image data and temperature data at 256*192 display mode
 *
 * @param  enable_flag(0:image data/1:temperature data)
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t temp_data_display_switch(uint8_t enable_flag);

#endif