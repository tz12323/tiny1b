#ifndef _LIBIRPROCESS_H_
#define _LIBIRPROCESS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
* @brief Yuv_8bit_pseudocolor_table
*/
#define yuv_8bit_pseudocolor_table {\
    {16,128,128}, {16,128,128}, {16,128,128}, {16,128,128},\
    {16,128,128}, {16,129,128}, {17,132,127}, {17,134,127},\
    {18,136,127}, {18,138,126}, {19,139,126}, {19,142,126},\
    {19,143,126}, {20,145,125}, {20,147,125}, {21,150,125},\
    {21,152,124}, {22,154,124}, {22,156,124}, {23,158,123},\
    {23,161,123}, {24,163,122}, {24,165,122}, {25,168,121},\
    {26,171,121}, {26,173,121}, {26,175,120}, {27,178,120},\
    {28,180,120}, {28,182,119}, {29,185,119}, {29,188,118},\
    {30,190,118}, {30,192,118}, {31,195,117}, {37,192,128},\
    {41,190,133}, {43,188,138}, {45,187,141}, {47,186,145},\
    {49,185,148}, {51,184,151}, {52,183,154}, {54,182,157},\
    {55,181,159}, {57,180,161}, {58,180,163}, {60,179,166},\
    {61,178,168}, {62,177,170}, {63,177,172}, {64,175,174},\
    {64,173,176}, {65,172,177}, {65,170,178}, {65,168,179},\
    {66,167,180}, {66,166,181}, {66,164,182}, {67,163,183},\
    {67,162,184}, {67,161,185}, {67,160,186}, {67,158,187},\
    {68,157,188}, {68,156,189}, {68,155,190}, {68,154,191},\
    {69,153,192}, {69,152,192}, {69,150,193}, {69,149,194},\
    {70,148,195}, {70,148,195}, {70,146,196}, {70,145,197},\
    {70,144,198}, {70,143,199}, {71,142,200}, {71,141,201},\
    {71,140,201}, {71,139,202}, {72,138,203}, {72,137,204},\
    {72,136,204}, {72,135,205}, {72,134,206}, {73,133,207},\
    {73,132,207}, {73,131,208}, {73,130,209}, {74,129,210},\
    {74,128,211}, {74,127,212}, {74,126,213}, {74,125,213},\
    {75,123,214}, {75,122,215}, {75,121,216}, {75,120,217},\
    {76,119,218}, {76,118,218}, {76,117,219}, {76,115,221},\
    {77,114,222}, {77,113,223}, {77,112,223}, {78,110,225},\
    {78,109,225}, {78,108,226}, {78,107,227}, {79,105,229},\
    {79,103,230}, {79,102,231}, {79,101,232}, {80,99,233},\
    {80,98,234}, {80,96,235}, {81,95,236}, {81,93,238},\
    {81,91,239}, {82,90,240}, {90,85,234}, {96,82,229},\
    {100,80,227}, {103,78,224}, {105,77,223}, {108,75,220},\
    {110,74,219}, {112,73,217}, {114,71,216}, {116,70,215},\
    {118,69,213}, {120,68,212}, {121,67,211}, {123,66,209},\
    {124,66,209}, {126,65,208}, {127,64,206}, {129,63,205},\
    {130,62,204}, {131,61,204}, {132,61,203}, {134,60,202},\
    {135,59,201}, {136,59,200}, {137,58,199}, {139,57,198},\
    {140,57,197}, {141,56,197}, {142,55,196}, {144,54,195},\
    {145,54,194}, {146,53,193}, {147,53,192}, {148,52,191},\
    {149,51,191}, {150,51,190}, {151,50,190}, {152,50,188},\
    {153,49,188}, {154,48,187}, {155,48,187}, {156,47,185},\
    {157,47,185}, {158,46,184}, {159,46,184}, {160,45,183},\
    {161,45,182}, {162,44,181}, {163,43,181}, {164,43,180},\
    {165,42,179}, {165,42,179}, {166,41,178}, {167,41,177},\
    {168,40,177}, {169,40,176}, {170,39,175}, {171,38,174},\
    {172,38,174}, {173,38,173}, {174,37,173}, {175,36,172},\
    {176,36,171}, {176,36,171}, {177,35,170}, {178,34,169},\
    {179,34,169}, {180,34,168}, {181,33,167}, {182,32,167},\
    {183,32,166}, {183,31,166}, {184,31,165}, {185,30,164},\
    {186,30,163}, {187,29,163}, {188,29,162}, {189,28,162},\
    {190,28,161}, {190,27,160}, {191,27,160}, {192,26,159},\
    {193,26,158}, {194,25,158}, {195,25,157}, {196,24,156},\
    {197,24,156}, {197,23,155}, {198,23,155}, {199,22,154},\
    {200,22,153}, {201,21,153}, {202,21,152}, {203,20,151},\
    {204,20,151}, {205,19,150}, {206,19,149}, {207,18,149},\
    {207,18,148}, {208,17,148}, {209,17,147}, {210,16,146},\
    {214,32,144}, {216,41,142}, {217,47,141}, {218,54,140},\
    {220,59,139}, {220,63,139}, {221,67,138}, {222,71,137},\
    {223,74,137}, {224,77,136}, {224,80,136}, {225,83,135},\
    {226,86,135}, {226,88,134}, {227,91,134}, {227,94,134},\
    {228,96,133}, {228,98,133}, {229,100,133}, {229,102,132},\
    {230,104,132}, {230,106,132}, {230,106,132}, {230,106,132},\
    {230,106,132}, {230,106,132}, {230,106,132}, {230,106,132},\
    {230,106,132}, {230,106,132}, {230,106,132}, {230,106,132},}


/**
* @brief Rgb_8bit_pseudocolor_table
*/
#define rgb_8bit_pseudocolor_table {\
    {0,  0, 0}, { 0,  0, 5},{ 0,  0, 11}, { 0,  0, 16},\
    {0,  0, 20},{ 0,  0, 25},{ 0,  0, 29},{ 0,  0, 33},\
    {0,  0, 38},{ 0,  0, 43},{ 0,  0, 48},{ 0,  0, 53},\
    {0,  0, 58},{ 0,  0, 63},{ 0,  0, 69},{ 0,  0, 74},\
    {0,  0, 80},{ 0,  0, 86},{ 0,  0, 92},{ 0,  0, 96},\
    {0,  0, 99},{ 0,  0, 102},{ 0,  0, 105},{ 0,  0, 107},\
    {0,  0, 110},{ 0,  0, 113},{ 0,  0, 116},{ 0,  0, 119},\
    {0,  0, 122},{ 0,  0, 125},{ 0,  0, 127},{ 0,  0, 130},\
    {0,  0, 133},{ 0,  0, 136},{ 0,  0, 139},{ 0,  0, 142},\
    {0,  0, 145},{ 0,  0, 148},{ 0,  0, 151},{ 5,  0, 154},\
    {18	,0, 154},{ 27, 0, 154},{ 34, 0, 154},{ 40, 0, 154},\
    {46	,0, 154},{ 51, 0, 154},{ 55, 0, 154},{ 59, 0, 154},\
    {63	,0, 154},{ 67, 0, 154},{ 71, 0, 154},{ 74, 0, 154},\
    {78	,0, 154},{ 81, 0, 154},{ 84, 0, 154},{ 87, 0, 154},\
    {90	,0, 154},{ 93, 0, 154},{ 96, 0, 154},{ 99, 0, 154},\
    {102, 0, 154}, { 105, 0, 154 }, { 108, 0, 154 }, { 111, 0, 154 },\
    {113, 0, 154}, { 116, 0, 154 }, { 119, 0, 154 }, { 121, 0, 154 },\
    {124, 0, 154}, { 127, 0, 154 }, { 129, 0, 152 }, { 132, 0, 149 },\
    {134, 0, 146}, { 137, 0, 143 }, { 139, 0, 140 }, { 141, 0, 138 },\
    {143, 0, 135}, { 145, 0, 133 }, { 147, 0, 130 }, { 149, 0, 128 },\
    {151, 0, 126}, { 153, 0, 123 }, { 155, 0, 121 }, { 157, 0, 119 },\
    {159, 0, 117}, { 160, 0, 115 }, { 162, 0, 113 }, { 164, 0, 111 },\
    {165, 0, 109}, { 167, 0, 107 }, { 169, 0, 105 }, { 170, 0, 103 },\
    {172, 0, 101}, { 174, 0, 99 }, { 175, 0, 97 }, { 177, 0, 95 },\
    {178, 0, 93}, { 180, 0, 91 }, { 182, 0, 89 }, { 183, 0, 87 },\
    {185, 0, 86}, { 186, 0, 84 }, { 188, 0, 82 }, { 189, 0, 80 },\
    {191, 0, 78}, { 193, 0, 76 }, { 194, 0, 74 }, { 196, 0, 72 },\
    {198, 0, 70}, { 199, 0, 68 }, { 201, 0, 66 }, { 203, 0, 64 },\
    {204, 0, 62}, { 206, 0, 60 }, { 208, 0, 58 }, { 210, 0, 56 },\
    {211, 0, 54}, { 213, 0, 51 }, { 215, 0, 49 }, { 217, 0, 47 },\
    {219, 0, 45}, { 221, 0, 42 }, { 223, 0, 40 }, { 225, 0, 38 },\
    {227, 0, 35}, { 229, 0, 33 }, { 231, 0, 30 }, { 233, 0, 28 },\
    {235, 0, 25}, { 237, 0, 23 }, { 239, 0, 20 }, { 241, 0, 17 },\
    {244, 0, 15}, { 246, 0, 12 }, { 248, 0, 9 }, { 251, 0, 6 },\
    {253, 0, 3}, { 255, 0, 1 }, { 255, 14, 0 }, { 255, 26, 0 },\
    {255, 35, 0}, { 255, 42, 0 }, { 255, 47, 0 }, { 255, 53, 0 },\
    {255, 57, 0}, { 255, 62, 0 }, { 255, 66, 0 }, { 255, 70, 0 },\
    {255, 74, 0}, { 255, 77, 0 }, { 255, 80, 0 }, { 255, 84, 0 },\
    {255, 87, 0}, { 255, 90, 0 }, { 255, 93, 0 }, { 255, 96, 0 },\
    {255, 98, 0}, { 255, 101, 0 }, { 255, 104, 0 }, { 255, 106, 0 },\
    {255, 109, 0}, { 255, 111, 0 }, { 255, 114, 0 }, { 255, 116, 0 },\
    {255, 119, 0}, { 255, 121, 0 }, { 255, 123, 0 }, { 255, 126, 0 },\
    {255, 128, 0}, { 255, 130, 0 }, { 255, 132, 0 }, { 255, 135, 0 },\
    {255, 137, 0}, { 255, 139, 0 }, { 255, 141, 0 }, { 255, 143, 0 },\
    {255, 145, 0}, { 255, 147, 0 }, { 255, 149, 0 }, { 255, 151, 0 },\
    {255, 153, 0}, { 255, 155, 0 }, { 255, 157, 0 }, { 255, 159, 0 },\
    {255, 161, 0}, { 255, 163, 0 }, { 255, 165, 0 }, { 255, 167, 0 },\
    {255, 169, 0}, { 255, 171, 0 }, { 255, 173, 0 }, { 255, 175, 0 },\
    {255, 177, 0}, { 255, 179, 0 }, { 255, 181, 0 }, { 255, 182, 0 },\
    {255, 184, 0}, { 255, 186, 0 }, { 255, 188, 0 }, { 255, 190, 0 },\
    {255, 192, 0}, { 255, 194, 0 }, { 255, 196, 0 }, { 255, 197, 0 },\
    {255, 199, 0}, { 255, 201, 0 }, { 255, 203, 0 }, { 255, 205, 0 },\
    {255, 207, 0}, { 255, 209, 0 }, { 255, 210, 0 }, { 255, 212, 0 },\
    {255, 214, 0}, { 255, 216, 0 }, { 255, 218, 0 }, { 255, 220, 0 },\
    {255, 221, 0}, { 255, 223, 0 }, { 255, 225, 0 }, { 255, 227, 0 },\
    {255, 229, 0}, { 255, 230, 0 }, { 255, 232, 0 }, { 255, 234, 0 },\
    {255, 236, 0}, { 255, 238, 0 }, { 255, 240, 0 }, { 255, 241, 0 },\
    {255, 243, 0}, { 255, 245, 0 }, { 255, 247, 0 }, { 255, 249, 0 },\
    {255, 251, 0}, { 255, 252, 0 }, { 255, 254, 0 }, { 255, 255, 2 },\
    {255, 255, 43}, { 255, 255, 63 }, { 255, 255, 78 }, { 255, 255, 91 },\
    {255, 255, 102}, { 255, 255, 112 }, { 255, 255, 121 }, { 255, 255, 129 },\
    {255, 255, 137}, { 255, 255, 145 }, { 255, 255, 152 }, { 255, 255, 159 },\
    {255, 255, 165}, { 255, 255, 171 }, { 255, 255, 177 }, { 255, 255, 182 },\
    {255, 255, 187}, { 255, 255, 192 }, { 255, 255, 197 }, { 255, 255, 202 },}


/**
* @brief Image resulution
*/
typedef struct {
    uint16_t width;    ///< resolution width
    uint16_t height;   ///< resolution height
}ImageRes_t;


/**
* @brief Yuv pseudo_color component
*/ 
typedef struct {
    uint8_t y;       ///< the y component of yuv pseudocolor
    uint8_t u;       ///< the u component of yuv pseudocolor
    uint8_t v;       ///< the v component of yuv pseudocolor
}PseudocolorYuv_t;


/**
* @brief Rgb pseudo_color component
*/
typedef struct {
    uint8_t r;      ///< the red component of rgb pseudocolor
    uint8_t g;      ///< the green component of rgb pseudocolor
    uint8_t b;      ///< the blue component of rgb pseudocolor
}PseudocolorRgb_t;


/**
* @brief Log level definition in libirprocess library
*/
typedef enum {
    IRPROC_LOG_DEBUG            = 0,    ///< print debug and error infomation
    IRPROC_LOG_ERROR            = 1,    ///< only print error infomation
    IRPROC_LOG_NO_PRINT         = 2     ///< don't print debug and error infomation
}irproc_log_level_t;


/**
* @brief Error type in libirprocess library
*/
typedef enum {
    IRPROC_SUCCESS              = 0,    ///< function excute success
    IRPROC_ERROR_PARAM          = -1,   ///< parameter is invalid
    IRPROC_FMT_NOT_SUPPORTED    = -2    ///< image format not supported
}irproc_error_t;


/**
* @brief Supported image format in libirprocess library
*/
typedef enum {
    IRPROC_SRC_FMT_Y14 = 0,     ///< Y14 format of source image
    IRPROC_SRC_FMT_YUV422,      ///< YUV422 format of source image
    IRPROC_SRC_FMT_YUV444,      ///< YUV444 format of source image
    IRPROC_SRC_FMT_RGB888,      ///< RGB888 format of source image
    IRPROC_SRC_FMT_BGR888       ///< BGR888 format of source image
}irproc_src_fmt_t;

#if defined(_WIN32)
#define DLLEXPORT __declspec(dllexport)
#elif defined(linux) || defined(unix)
#define DLLEXPORT
#endif


#if defined(_WIN32)
    #define IRPROC_DEBUG(format, ...) irproc_debug_print("libirprocess debug [%s:%d/%s] " format "\n", \
                                                        __FILE__,__LINE__, __FUNCTION__, __VA_ARGS__)
    #define IRPROC_ERROR(format, ...) irproc_error_print("libirprocess error [%s:%d/%s] " format "\n", \
                                                        __FILE__,__LINE__, __FUNCTION__, __VA_ARGS__)
#elif defined(linux) || defined(unix)
    #include <libgen.h>
    #define IRPROC_DEBUG(format, ...) irproc_debug_print("libirprocess debug [%s:%d/%s] " format "\n", \
                                                        basename(__FILE__), __LINE__, __FUNCTION__, ##__VA_ARGS__)
    #define IRPROC_ERROR(format, ...) irproc_error_print("libirprocess error [%s:%d/%s] " format "\n", \
                                                        basename(__FILE__), __LINE__, __FUNCTION__, ##__VA_ARGS__)
#endif

extern void (*irproc_debug_print)(const char* fmt, ...);
extern void (*irproc_error_print)(const char* fmt, ...);

/**
 * @brief Get current libirprocess library version
 *
 * @param NULL
 *
 * @return current libirprocess library version
 */
DLLEXPORT char* irproc_version(void);

/**
 * @brief Rotate the frame left 90 degree
 *
 * @param[in] src source image frame 
 * @param[in] image_res imput image resulution, detail see ImageRes_t
 * @param[in] input_fmt imput image format, detail see irproc_src_fmt_t
 * @param[out] dst destination frame after rotate
 *
 * @return see irproc_error_t
 */
DLLEXPORT irproc_error_t rotate_left_90(uint8_t* src, ImageRes_t image_res, irproc_src_fmt_t input_fmt, uint8_t* dst);

/**
 * @brief Rotate the frame right 90 degree
 *
 * @param[in] src source image frame
 * @param[in] image_res imput image resulution, detail see ImageRes_t
 * @param[in] input_fmt imput image format, detail see irproc_src_fmt_t
 * @param[out] dst destination frame after rotate
 *
 * @return see irproc_error_t
 */
DLLEXPORT irproc_error_t rotate_right_90(uint8_t* src, ImageRes_t image_res, irproc_src_fmt_t input_fmt, uint8_t* dst);

/**
 * @brief Rotate the frame 180 degree
 *
 * @param[in] src source image frame
 * @param[in] image_res imput image resulution, detail see ImageRes_t
 * @param[in] input_fmt imput image format, detail see irproc_src_fmt_t
 * @param[out] dst destination frame after rotate
 *
 * @return see irproc_error_t
 */
DLLEXPORT irproc_error_t rotate_180(uint8_t* src, ImageRes_t image_res, irproc_src_fmt_t input_fmt, uint8_t* dst);

/**
 * @brief Mirror the frame (left and right side)
 *
 * @param[in] src source image frame
 * @param[in] image_res imput image resulution, detail see ImageRes_t
 * @param[in] input_fmt imput image format, detail see irproc_src_fmt_t
 * @param[out] dst destination frame after mirror
 *
 * @return see irproc_error_t
 */
DLLEXPORT irproc_error_t mirror(uint8_t* src, ImageRes_t image_res, irproc_src_fmt_t input_fmt, uint8_t* dst);

/**
 * @brief Flip the frame (up and down side)
 *
 * @param[in] src source image frame
 * @param[in] image_res imput image resulution, detail see ImageRes_t
 * @param[in] input_fmt imput image format, detail see irproc_src_fmt_t
 * @param[out] dst destination frame after mirror
 *
 * @return see irproc_error_t
 */
DLLEXPORT irproc_error_t flip(uint8_t* src, ImageRes_t image_res, irproc_src_fmt_t input_fmt, uint8_t* dst);

/**
 * @brief Y14 array map to YUV422 pseudocolor array
 *
 * @param[in] image_y14 source image frame with Y14 format
 * @param[in] pix_num pixel number of whole frame
 * @param[in] psdcolor_mapping_table pseudo color yuv mapping table, detail see PseudocolorYuv_t
 * @param[out] out_yuv destination frame after pseudo color mapping
 *
 * @return see irproc_error_t
 */
DLLEXPORT irproc_error_t y14_pseudocolor_mapping_yuv422(uint16_t* image_y14, uint32_t pix_num,\
                                                        PseudocolorYuv_t* psdcolor_mapping_table, uint8_t* out_yuv);

/**
 * @brief Y14 array map to RGB pseudocolor array
 *
 * @param[in] image_y14 source image frame with Y14 format
 * @param[in] pix_num pixel number of whole frame
 * @param[in] psdcolor_mapping_table pseudo color rgb mapping table, detail see PseudocolorRgb_t
 * @param[out] out_rgb destination frame after pseudo color mapping
 *
 * @return see irproc_error_t
 */
DLLEXPORT irproc_error_t y14_pseudocolor_mapping_rgb(uint16_t* image_y14, uint32_t pix_num, \
                                                     PseudocolorRgb_t* psdcolor_mapping_table, uint8_t* out_rgb);

/**
 * @brief Register log function depend on log level
 *
 * @param[in] log_level detail see irproc_log_level_t
 *
 */
DLLEXPORT void irproc_log_register(irproc_log_level_t log_level);
    
#ifdef __cplusplus
}
#endif

#endif 
