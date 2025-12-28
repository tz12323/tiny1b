#pragma once


#include <stdint.h>
#include "all_config.h"

/**
 * @file
 *
 * @brief Header file for command of Falcon chips 
 *
 */

#if defined(FALCON_CMD)
#pragma pack (1)

 /**
  * @brief Restore defaut config types
  */
enum prop_default_cfg
{
    /// all config
    DEF_CFG_ALL = 0,
    /// tecless k config
    DEF_CFG_TECLESS_K,
    /// tpd config
    DEF_CFG_TPD,
    /// prop page config
    DEF_CFG_PROP_PAGE
};

 /**
  * @brief Property page's defaut parameters types
  */
enum prop_default_params
{
    /// shutter parameters
    PROP_SEL_SHUTTER = 0,
    /// image parameters
    PROP_SEL_IMAGE,
    /// overexposure parameters
    PROP_SEL_OVEREXPOSURE,
    /// tpd parameters
    PROP_SEL_TPD
};


/**
 * @brief Property page's auto shutter parameters types
 */
enum prop_auto_shutter_params
{
    /// shutter switch
    SHUTTER_PROP_SWITCH = 0,
    /// shutter minimun interval
    SHUTTER_PROP_MIN_INTERVAL,
    /// shutter maximun interval
    SHUTTER_PROP_MAX_INTERVAL,
    /// vtemp's threshold to trigger OOC update
    SHUTTER_PROP_TEMP_THRESHOLD_OOC,
    /// vtemp's threshold to trigger B update
    SHUTTER_PROP_TEMP_THRESHOLD_B
};


/**
 * @brief Property page's image parameters types
 */
enum prop_image_params
{
    /// tnr level
    IMAGE_PROP_LEVEL_TNR = 0,
    /// snr level
    IMAGE_PROP_LEVEL_SNR,
    /// dde level
    IMAGE_PROP_LEVEL_DDE,
    /// brightness level
    IMAGE_PROP_LEVEL_BRIGHTNESS,
    /// contrast level
    IMAGE_PROP_LEVEL_CONTRAST,
    /// agc level
    IMAGE_PROP_MODE_AGC,
    /// agc max gain
    IMAGE_PROP_LEVEL_MAX_GAIN,
    /// pseudo color mode in path1
    IMAGE_PROP_LEVEL_BOS,
    /// pseudo color mode in path2
    IMAGE_PROP_ONOFF_AGC,
    /// mirror flip status
    IMAGE_PROP_SEL_MIRROR_FLIP
};


/**
 * @brief Property page's overexposure parameters types
 */
enum prop_overexposure_params
{
    /// overexposure switch
    OVEXP_PROP_SWITCH = 0,
    /// overexposure pixel threshold
    OVEXP_PROP_PIX_THRESHOLD,
    /// overexposure count threshold
    OVEXP_PROP_CNT_THRESHOLD,
    /// overexposure close delay count
    OVEXP_PROP_CNT_DELAY_CLOSE
};


/**
 * @brief Property page's TPD parameters types
 */
enum prop_tpd_params
{
    /// distance property
    TPD_PROP_DISTANCE = 0,
    /// Tu property
    TPD_PROP_TU,
    /// Ta property
    TPD_PROP_TA,
    /// EMS property
    TPD_PROP_EMS,
    /// Tau property
    TPD_PROP_TAU,
    /// gain select
    TPD_PROP_GAIN_SEL
};


/**
 * @brief Preview path
 */
enum preview_path
{
    /// preview path 0
    PREVIEW_PATH0 = 0,
    /// preview path 1
    PREVIEW_PATH1
};


/**
 * @brief Device id types
 */
enum device_id_types
{
    /// chip infomation
    CHIP_FW_INFO = 0,
    /// firmware compile data
    FW_COMPILE_DATA,
    /// develop qualification
    DEV_QUALIFICATION,
    /// IR infomation
    IR_INFO
};


/**
 * @brief Update B/OOC types
 */
enum ooc_b_update_types
{
    /// update B value
    B_UPDATE = 0,
    /// update OOC value
    OOC_UPDATE,
    /// update both B and OOC value
    OOC_B_UPDATE
};


/**
 * @brief Shutter control enable
 */
enum shutter_sta_types
{
    /// shutter control disable
    SHUTTER_CTL_DIS = 0,
    /// shutter control enable
    SHUTTER_CTL_EN
};


/**
 * @brief Shutter control open/close
 */
enum shutter_manual_types
{
    /// shutter open
    SHUTTER_OPEN = 0,
    /// shutter close
    SHUTTER_CLOSE
};


/**
 * @brief Tecless temperature area
 */
enum tecless_temp_area_types
{
    /// high temp area
    HIGH_TEMP = 0,
    /// normal temp area
    NORMAL_TEMP,
    /// low temp area
    LOW_TEMP
};


/**
 * @brief Mirror/flip types
 */
enum mirror_flip_types
{
    /// no mirror/flip
    NO_MIRROR_FLIP = 0,
    /// only mirror the frame
    ONLY_MIRROR,
    /// only flip the frame
    ONLY_FLIP,
    /// mirror and flip the frame
    MIRROR_FLIP
};


/**
 * @brief Pseudo color mode types
 */
enum pseudo_color_types
{
    /// bypass pseudo color
    PSEUDO_COLOR_BYPASS = 0,
    /// pseudo color mode 1
    PSEUDO_COLOR_MODE_1,
    /// pseudo color mode 2
    PSEUDO_COLOR_MODE_2,
    /// pseudo color mode 3
    PSEUDO_COLOR_MODE_3,
    /// pseudo color mode 4
    PSEUDO_COLOR_MODE_4,
    /// pseudo color mode 5
    PSEUDO_COLOR_MODE_5,
    /// pseudo color mode 6
    PSEUDO_COLOR_MODE_6,
    /// pseudo color mode 7
    PSEUDO_COLOR_MODE_7,
    /// pseudo color mode 8
    PSEUDO_COLOR_MODE_8,
    /// pseudo color mode 9
    PSEUDO_COLOR_MODE_9,
    /// pseudo color mode 10
    PSEUDO_COLOR_MODE_10,
    /// pseudo color mode 11
    PSEUDO_COLOR_MODE_11,
    /// pseudo color guard mode
    PSEUDO_COLOR_MODE_GUARD
};


/**
 * @brief Zoom scale step value
 */
enum zoom_scale_step
{
    /// zoom step = 1
    ZOOM_STEP1 = 1,
    /// zoom step = 2
    ZOOM_STEP2,
    /// zoom step = 3
    ZOOM_STEP3,
    /// zoom step = 4
    ZOOM_STEP4
};


/**
 * @brief Point struct
 */
typedef struct {
    /// x position
    uint16_t x;
    /// y position
    uint16_t y;
} Point_t;


/**
 * @brief Rectangle struct
 */
typedef struct {
    /// start point's x position
    uint16_t start_x;
    /// start point's y position
    uint16_t start_y;
    /// end point's x position
    uint16_t end_x;
    /// end point's y position
    uint16_t end_y;
} Rect_t;


/**
 * @brief Gamma parameter's struct
 */
typedef struct
{
    /// maximum temp point index
    uint8_t max_point_idx;
    /// minimum temp point index
    uint8_t min_point_idx;
    /// center temp point index
    uint8_t center_point_idx;
}FrameTempIdx_t;

/**
 * @brief Gamma parameter's struct
 */
typedef struct
{
    /// enable of gamma module
    uint8_t gamma_en;
    /// pixel inversion enable
    uint8_t pix_inv_en;
    /// rate value of gamma module
    uint8_t gamma_rate;
    /// brightness value of gamma module
    int16_t brightness;
}isp_gamma_param_t;

#pragma pack()


/**
 * @brief Initialize and register vdcmd's handle
 *
 * @param NULL
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t vdcmd_init();


/**
 * @brief Load property page's defaut parameters
 *
 * @param[in] default_param default parameter type
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t restore_default_cfg(enum prop_default_cfg default_cfg_type);


/**
 * @brief Load property page's defaut parameters
 *
 * @param[in] default_param default parameter type
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t load_prop_default_params(enum prop_default_params default_param);


/**
 * @brief Set property page's auto shutter parameters
 *
 * @param[in] shutter_param auto shutter's parameter type
 * @param[in] value auto shutter's parameter value
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t set_prop_auto_shutter_params(enum prop_auto_shutter_params shutter_param, uint16_t value);


/**
 * @brief Get property page's auto shutter parameters
 *
 * @param[in] shutter_param auto shutter's parameter type
 * @param[out] value auto shutter's parameter value
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_prop_auto_shutter_params(enum prop_auto_shutter_params shutter_param, uint16_t* value);


/**
 * @brief Set property page's image parameters
 *
 * @param[in] image_param image's parameter type
 * @param[in] value image's parameter value
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t set_prop_image_params(enum prop_image_params image_param, uint16_t value);


/**
 * @brief Get property page's image parameters
 *
 * @param[in] image_param image's parameter type
 * @param[out] value image's parameter value
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_prop_image_params(enum prop_image_params image_param, uint16_t* value);


/**
 * @brief Set property page's overexposure parameters
 *
 * @param[in] ovexp_param overexposure's parameter type
 * @param[in] value overexposure's parameter value
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t set_prop_overexposure_params(enum prop_overexposure_params ovexp_param, uint16_t value);


/**
 * @brief Get property page's overexposure parameters
 *
 * @param[in] ovexp_param overexposure's parameter type
 * @param[out] value overexposure's parameter value
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_prop_overexposure_params(enum prop_overexposure_params ovexp_param, uint16_t* value);


/**
 * @brief Set property page's tpd parameters
 *
 * @param[in] tpd_param tpd's parameter type
 * @param[in] value tpd's parameter value
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t set_prop_tpd_params(enum prop_tpd_params tpd_param, uint16_t value);


/**
 * @brief Get property page's tpd parameters
 *
 * @param[in] tpd_param tpd's parameter type
 * @param[out] value tpd's parameter value
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_prop_tpd_params(enum prop_tpd_params tpd_param, uint16_t* value);


/**
 * @brief Get device infomation via id_type
 *
 * @param[in] id_type the device's id type
 * @param[out] id_content the device's infomation data
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_device_info(enum device_id_types id_type, uint8_t* id_content);


/**
 * @brief Get a PN string
 *
 * @param[out] pn_content the string data
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_pn(uint8_t* pn_content);


/**
 * @brief Set a PN string
 *
 * @param[in] pn_content the string data
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t set_pn(uint8_t* pn_content);


/**
 * @brief Get a SN string
 *
 * @param[out] sn_content the string data
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t get_sn(uint8_t* sn_content);


/**
 * @brief Set a SN string
 *
 * @param[in] sn_content the string data
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t set_sn(uint8_t* sn_content);


/**
 * @brief Update OOC or B value by select update_type
 *
 * @param[in] update_type update types
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t ooc_b_update(enum ooc_b_update_types update_type);


/**
 * @brief Set shutter's control status
 *
 * @param[in] sta_type shutter status type
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_sta_set(enum shutter_sta_types sta_type);


/**
 * @brief Switch shutter's open/close manually
 *
 * @param[in] manual_type shutter's open/close type
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t shutter_manual_switch(enum shutter_manual_types manual_type);


/**
 * @brief Get current tecless temp area
 *
 * @param[out] temp_area current tecless temp area
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tecless_temp_area_get(uint8_t* temp_area);


/**
 * @brief Get parameters of gamma module
 *
 * @param[out] gamma_param parameters of gamma modlue
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t gamma_param_get(isp_gamma_param_t* gamma_param);


/**
 * @brief Set parameters of gamma module
 *
 * @param[in] gamma_param parameters of gamma modlue
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t gamma_param_set(isp_gamma_param_t* gamma_param);


/**
 * @brief Get the status of mirror&flip
 *
 * @param[out] mirror_flip_status the status of mirror&flip
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t mirror_flip_get(uint8_t* mirror_flip_status);


/**
 * @brief Set the status of mirror&flip
 *
 * @param[in] mirror_flip_status the status of mirror&flip
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t mirror_flip_set(enum mirror_flip_types mirror_flip_status);


/**
 * @brief Get the pseudo color type via preview path
 *
 * @param[in] path preview path
 * @param[out] color_type pseudo color type
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t pseudo_color_get(enum preview_path path, uint8_t* color_type);


/**
 * @brief Set the pseudo color type of preview path
 *
 * @param[in] path preview path
 * @param[in] color_type pseudo color type
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t pseudo_color_set(enum preview_path path, enum pseudo_color_types color_type);


/**
 * @brief Get the distance value of tpd module
 *
 * @param[out] tpd_distance the distance value of tpd module
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_distance_get(uint16_t* tpd_distance);


/**
 * @brief Set the distance value of tpd module
 *
 * @param[in] tpd_distance the distance value of tpd module
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_distance_set(uint16_t* tpd_distance);


/**
 * @brief Get the EMS of tpd module
 *
 * @param[out] tpd_ems the EMS of tpd module
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_ems_get(uint8_t* tpd_ems);


/**
 * @brief Set the EMS of tpd module
 *
 * @param[in] tpd_ems the EMS of tpd module
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_ems_set(uint8_t* tpd_ems);


/**
 * @brief Display the point's temperature measurement
 *
 * @param[in] path preview path
 * @param[in] point_idx point's index
 * @param[in] point the position infomation of point
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_show_point_temp(enum preview_path path, uint8_t point_idx, Point_t point);


/**
 * @brief Hide the point's temperature measurement
 *
 * @param[in] path preview path
 * @param[in] point the position infomation of point
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_hide_point_temp(enum preview_path path, uint8_t point_idx);


/**
 * @brief Display the rectangle's temperature measurement
 *
 * @param[in] path preview path
 * @param[in] rect_idx rectangle's index
 * @param[in] rect the position infomation of rectangle
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_show_rect_temp(enum preview_path path, uint8_t rect_idx, Rect_t rect);


/**
 * @brief Hide the rectangle's temperature measurement
 *
 * @param[in] path preview path
 * @param[in] rect_idx the position infomation of rectangle
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_hide_rect_temp(enum preview_path path, uint8_t rect_idx);


/**
 * @brief Display the whole frame temperature measurement
 *
 * @param[in] enable control the display on/off
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_show_frame_temp(enum preview_path path, FrameTempIdx_t frame_idx);


/**
 * @brief Hide the whole frame temperature measurement
 *
 * @param[in] enable control the display on/off
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t tpd_hide_frame_temp(enum preview_path path);


/**
 * @brief Zoom up from the center
 *
 * @param[in] path preview path
 * @param[in] scale_step the step of zoom scale
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t zoom_center_up(enum preview_path path, enum zoom_scale_step scale_step);


/**
 * @brief Zoom down from the center
 *
 * @param[in] path preview path
 * @param[in] scale_step the step of zoom scale
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t zoom_center_down(enum preview_path path, enum zoom_scale_step scale_step);


/**
 * @brief Zoom up from the point
 *
 * @param[in] path preview path
 * @param[in] scale_step the step of zoom scale
 * @param[in] position position of the point
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t zoom_position_up(enum preview_path path, enum zoom_scale_step scale_step, Point_t position);


/**
 * @brief Zoom down from the point
 *
 * @param[in] path preview path
 * @param[in] scale_step the step of zoom scale
 * @param[in] position position of the point
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t zoom_position_down(enum preview_path path, enum zoom_scale_step scale_step, Point_t position);

/**
 * @brief Read xdata from ISP chip
 *
 * @param[in] memory address
 * @param[in] data length
 * @param[out] the data read from memory
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t xdata_read(uint16_t addr, uint8_t bylen, uint8_t* pbyData);

/**
 * @brief Write xdata to ISP chip
 *
 * @param[in] memory address
 * @param[in] data length
 * @param[in] the data write to memory
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t xdata_write(uint16_t addr, uint8_t bylen, uint8_t* pbyData);

/**
 * @brief Read xdata from ISP chip with SPI communication
 *
 * @param[in] memory address
 * @param[in] data length
 * @param[out] the data read from memory
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t spi_read(uint32_t addr, uint16_t wlen, uint8_t* pbyData);

/**
 * @brief Write xdata to ISP chip with SPI communication
 *
 * @param[in] memory address
 * @param[in] data length
 * @param[in] the data write to memory
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t spi_write(uint32_t addr, uint16_t wlen, uint8_t* pbyData);

/**
 * @brief Erase sector of ISP chip with SPI communication
 *
 * @param[in] memory address
 * @param[in] sector count that need to erase
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t spi_erase_sector(uint32_t addr, uint16_t sector_cnt);

/**
 * @brief Erase FW of ISP chip with SPI communication
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t spi_erase_fw(void);

/**
 * @brief Write status value to ISP chip with SPI communication
 *
 * @param[in] status register type
 * @param[in] status value will write to ISP chip
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t spi_write_status(uint8_t status_reg_type, uint8_t status_val);

/**
 * @brief Read status value from ISP chip with SPI communication
 *
 * @param[in] status register type
 * @param[out] status value will read from ISP chip
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t spi_read_status(uint8_t status_reg_type, uint8_t* pstatus_val);

/**
 * @brief Write tag to ISP chip with SPI communication
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t spi_write_tag(void);

/**
 * @brief Read ID from ISP chip with SPI communication
 *
 * @param[out] the ID will read from ISP chip
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t spi_read_id(uint8_t* pbyID);

/**
 * @brief Read device info from ISP chip with SPI communication
 *
 * @param[in] status register type
 * @param[out] device info will read from ISP chip
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t sys_get_device_info(uint8_t sys_device_info_mode_key, uint16_t wlen, uint8_t* pbyData);

/**
 * @brief Reset to update firmware
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t sys_reset_to_update_fw(void);

/**
 * @brief Reset to rom
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t sys_reset_to_rom(void);

/**
 * @brief I2C slave read
 *
 * @param[in] memory address
 * @param[in] data length
 * @param[out] the data read from memory
 *
 * @return see iruvc_error_t
 */
DLLEXPORT iruvc_error_t i2c_slave_read(uint16_t addr, uint8_t bylen, uint8_t* pbyData);
#endif