#ifndef __S6E8AA0X1_J5Y17_PARAM_H__
#define __S6E8AA0X1_J5Y17_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>
#include "dynamic_aid_s6e8aa5x01_j5y17.h"

#define EXTEND_BRIGHTNESS	355
#define UI_MAX_BRIGHTNESS	255
#define UI_DEFAULT_BRIGHTNESS	128
#define NORMAL_TEMPERATURE	25	/* 25 degrees Celsius */

#define GAMMA_CMD_CNT		ARRAY_SIZE(SEQ_GAMMA_CONDITION_SET)
#define HBM_GAMMA_CMD_CNT		22 /* C8 34th ~ 39th, 73th ~ 87th */

#define ACL_CMD_CNT		ARRAY_SIZE(SEQ_ACL_OFF)
#define OPR_CMD_CNT		ARRAY_SIZE(SEQ_OPR_ACL_OFF)
#define ELVSS_CMD_CNT		ARRAY_SIZE(SEQ_ELVSS_SET)
#define AID_CMD_CNT		ARRAY_SIZE(SEQ_AID_SETTING)
#define HBM_CMD_CNT		ARRAY_SIZE(SEQ_HBM_OFF)
#define TSET_CMD_CNT		ARRAY_SIZE(SEQ_TSET)

#define LDI_REG_ELVSS		0xB6
#define LDI_REG_COORDINATE	0xA1
#define LDI_REG_ID		0x04
#define LDI_REG_CHIP_ID		0xD5
#define LDI_REG_MTP		0xC8
#define LDI_REG_DATE		LDI_REG_MTP
#define LDI_REG_RDDPM		0x0A
#define LDI_REG_RDDSM		0x0E
#define LDI_REG_ESDERR		0xEE
#define LDI_REG_MANUFACTURE_INFO	0xC9

/* len is read length */
#define LDI_LEN_ELVSS		(ELVSS_CMD_CNT - 1)
#define LDI_LEN_COORDINATE	4
#define LDI_LEN_DATE		7
#define LDI_LEN_ID		3
#define LDI_LEN_CHIP_ID		5
#define LDI_LEN_MTP		33
#define LDI_LEN_RDDPM		1
#define LDI_LEN_RDDSM		1
#define LDI_LEN_ESDERR		1
#define LDI_LEN_HBM_GAMMA_1	6
#define LDI_LEN_HBM_GAMMA_2	15
#define LDI_LEN_MANUFACTURE_INFO	20

/* offset is position including addr, not only para */
#define LDI_OFFSET_AOR_1	1
#define LDI_OFFSET_AOR_2	2

#define LDI_OFFSET_ELVSS_1	1	/* B6h 1st Para: MPS_CON */
#define LDI_OFFSET_ELVSS_2	2	/* B6h 2nd Para: ELVSS_Dim_offset */
#define LDI_OFFSET_ELVSS_3	22	/* B6h 22th Para: ELVSS Temp Compensation */

#define LDI_OFFSET_HBM		1
#define LDI_OFFSET_ACL		1

#define LDI_GPARA_HBM_ELVSS 22  /* 0xB6 23th para */
#define LDI_GPARA_DATE		40	/* 0xC8 41th para */
#define LDI_GPARA_HBM_GAMMA_1	33	/* 0xC8 34th ~ 39th para */
#define LDI_GPARA_HBM_GAMMA_2	72	/* 0xC8 73th ~ 87th para */
#define LDI_GPARA_MANUFACTURE_INFO	1	/* C9h 2nd Para */

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_SLEEP_OUT[] = {
	0x11
};

static unsigned char SEQ_SLEEP_IN[] = {
	0x10
};

static unsigned char SEQ_DISPLAY_ON[] = {
	0x29
};

static unsigned char SEQ_DISPLAY_OFF[] = {
	0x28
};

static unsigned char SEQ_TEST_KEY_ON_F0[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_F0[] = {
	0xF0,
	0xA5, 0xA5
};

static unsigned char SEQ_AID_SETTING[] = {
	0xB2,
	0x00, 0x0F
};

static unsigned char SEQ_GAMMA_UPDATE[] = {
	0xF7,
	0x03
};

static unsigned char SEQ_ACL_SET[] = {
	0xB5,
	0x00,
	0x00,
	0x14,
	0x00
};

static unsigned char SEQ_OPR_ACL_OFF[] = {
	0x40	/* 16 Frame Avg. at ACL Off */
};

static unsigned char SEQ_OPR_ACL_ON[] = {
	0x50	/* 32 Frame Avg. at ACL On */
};

static unsigned char SEQ_ACL_START_POINT_60[] = {
	0x99
};

static unsigned char SEQ_ACL_START_POINT_50[] = {
	0x7F
};

static unsigned char SEQ_ACL_PERCENT_8[] = {
	0x0A
};

static unsigned char SEQ_ACL_PERCENT_15[] = {
	0x14
};

static unsigned char SEQ_ACL_OFF[] = {
	0x55,
	0x00
};

static unsigned char SEQ_ACL_ON[] = {
	0x55,
	0x02	/* 0x02 : ACL 15% (Default) */
};

static const unsigned char SEQ_TSET_SETTING_1[] = {
	0xB0,
	0x1D
};

static const unsigned char SEQ_TSET_SETTING_2[] = {
	0xB5,
	0x19
};

/***********************************************/
static const unsigned char SEQ_GAMMA_CONDITION_SET[] = {
	0xCA,
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x00
};

#if defined(CONFIG_PANEL_S6E8AA5X01_J5Y17_KOR)
static const unsigned char SEQ_LTPS_SETTING[] = {
	0xCB,
	0x09, 0x15, 0x10, 0x00, 0x09, 0x02, 0x04, 0x00, 0x00, 0x00,
	0x00, 0x05, 0x05, 0x00, 0x00, 0x00, 0x0A, 0x01, 0x41, 0x7A,
	0x41, 0x7A, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x9B,
	0x00, 0x00, 0x08, 0x05, 0x22, 0x41, 0x03, 0xCC, 0x00, 0xFF,
	0xFB, 0x03, 0x00, 0x0D, 0x0F, 0x11, 0x02, 0x03, 0x0B, 0x0C,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x04, 0x05, 0x02, 0x03, 0x0B, 0x0C, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00
};
#endif

static const unsigned char SEQ_ELVSS_SET[] = {
	0xB6,
	0xBC,    /* B6h 1st Para: MPS_CON */
	0x0F,    /* B6h 2nd Para: ELVSS_Dim_offset */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00,
	0x00,    /* B6h 22nd Para: ELVSS Temp Compensation */
	0x00	/* B6h 23rd Para: OTP for B6h 22nd Para of HBM Interpolation */
};

static const unsigned char SEQ_ELVSS_GLOBAL[] = {
	0xB0,
	0x15,
};

static const unsigned char SEQ_PENTILE_SETTING[] = {
	0xC0,
	0xD8, 0xD8, 0x40, /* pentile setting */
};

static const unsigned char SEQ_DE_DIM_GP[] = {
	0xB0,
	0x06, /* Global para(7th) */
};

static const unsigned char SEQ_DE_DIM_SETTING[] = {
	0xB8,
	0xA8, /* DE_DIN On */
};

static const unsigned char SEC_PCD_SETTING[] = {
	0xCC,
	0x4C,
};

static const unsigned char SEC_ERR_FLAG_SETTING[] = {
	0xE7,
	0xED, 0xC7, 0x23, 0x67, /* MIPI Error check Setting */
};

static const unsigned char SEQ_AID_360NIT[] = {
	0xB2,
	0x00, 0x0F,
};

static const unsigned char SEQ_ELVSS_360NIT[] = {
	0xB6,
	0xBC, 0x0F,
};

static const unsigned char SEQ_TSET_GP[] = {
	0xB0,
	0x07,
};

static const unsigned char SEQ_TSET[] = {
	0xB8,
	0x19,
};

static const unsigned char SEQ_MTP_READ_DATE_GP[] = {
	0xB0,
	LDI_GPARA_DATE,
};

static const unsigned char SEQ_MTP_READ_HBM_GP_1[] = {
	0xB0,
	LDI_GPARA_HBM_GAMMA_1,
};

static const unsigned char SEQ_MTP_READ_HBM_GP_2[] = {
	0xB0,
	LDI_GPARA_HBM_GAMMA_2,
};

#if defined(CONFIG_DISPLAY_USE_INFO)
struct bit_info {
	unsigned int reg;
	unsigned int len;
	char **print;
	unsigned int expect;
	unsigned int invert;
	unsigned int mask;
	unsigned int result;
};

enum {
	LDI_BIT_ENUM_05,	LDI_BIT_ENUM_RDNUMED = LDI_BIT_ENUM_05,
	LDI_BIT_ENUM_0A,	LDI_BIT_ENUM_RDDPM = LDI_BIT_ENUM_0A,
	LDI_BIT_ENUM_0E,	LDI_BIT_ENUM_RDDSM = LDI_BIT_ENUM_0E,
	LDI_BIT_ENUM_0F,	LDI_BIT_ENUM_RDDSDR = LDI_BIT_ENUM_0F,
	LDI_BIT_ENUM_EE,	LDI_BIT_ENUM_ESDERR = LDI_BIT_ENUM_EE,
	LDI_BIT_ENUM_MAX
};

char *LDI_BIT_DESC_05[BITS_PER_BYTE] = {
	[0 ... 6] = "number of corrupted packets",
	[7] = "overflow on number of corrupted packets",
};

char *LDI_BIT_DESC_0A[BITS_PER_BYTE] = {
	[2] = "Display is Off",
	[7] = "Booster has a fault",
};

char *LDI_BIT_DESC_0E[BITS_PER_BYTE] = {
	[0] = "Error on DSI",
};

char *LDI_BIT_DESC_0F[BITS_PER_BYTE] = {
	[7] = "Register Loading Detection",
};

char *LDI_BIT_DESC_EE[BITS_PER_BYTE] = {
	[2] = "VLIN3 error",
	[3] = "ELVDD error",
	[6] = "VLIN1 error",
};

struct bit_info ldi_bit_info_list[LDI_BIT_ENUM_MAX] = {
	[LDI_BIT_ENUM_05] = {0x05, 1, LDI_BIT_DESC_05, 0x00, },
	[LDI_BIT_ENUM_0A] = {0x0A, 1, LDI_BIT_DESC_0A, 0x9C, .invert = (BIT(2) | BIT(7)), },
	[LDI_BIT_ENUM_0E] = {0x0E, 1, LDI_BIT_DESC_0E, 0x00, },
	[LDI_BIT_ENUM_0F] = {0x0F, 1, LDI_BIT_DESC_0F, 0x80, .invert = (BIT(7)), },
	[LDI_BIT_ENUM_EE] = {0xEE, 1, LDI_BIT_DESC_EE, 0x00, },
};

/* Write COMMAND before read */
static const unsigned char SEQ_ESD_MONITOR_ON[] = {
	0xED,
	0x4C,
};

#endif

/***********************************************/

enum {
	ACL_STATUS_0P,
	ACL_STATUS_8P,
	ACL_STATUS_15P,
	ACL_STATUS_MAX
};

enum {
	OPR_STATUS_ACL_OFF,
	OPR_STATUS_ACL_ON,
	OPR_STATUS_MAX
};

enum {
	TEMP_ABOVE_MINUS_00_DEGREE,	/* T > 0 */
	TEMP_ABOVE_MINUS_15_DEGREE,	/* -15 < T <= 0 */
	TEMP_BELOW_MINUS_15_DEGREE,	/* T <= -15 */
	TEMP_MAX
};

enum {
	HBM_STATUS_OFF,
	HBM_STATUS_ON,
	HBM_STATUS_MAX
};

static unsigned char *ACL_TABLE[ACL_STATUS_MAX] = {SEQ_ACL_OFF, SEQ_ACL_ON};
static unsigned char *OPR_TABLE[OPR_STATUS_MAX] = {SEQ_OPR_ACL_OFF, SEQ_OPR_ACL_ON};
/*	T > 0, -15 < T <= 0, T<= -15 */
/* {Register, MPSCON, ELVSS_Dim_offset, B6 22th} */
static unsigned char elvss_offset_data[IBRIGHTNESS_HBM_MAX][TEMP_MAX][4] = {
	[IBRIGHTNESS_005NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_006NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_007NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_008NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_009NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_010NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_011NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_012NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_013NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_014NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_015NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_016NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_017NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_019NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_020NIT] = {{0xb6, 0xAC, 0x0F, 0x0A}, {0xb6, 0xAC, 0x0F, 0x14}, {0xb6, 0xAC, 0x0F, 0x1A} },
	[IBRIGHTNESS_021NIT] = {{0xb6, 0xAC, 0x11, 0x0A}, {0xb6, 0xAC, 0x11, 0x12}, {0xb6, 0xAC, 0x11, 0x18} },
	[IBRIGHTNESS_022NIT] = {{0xb6, 0xAC, 0x13, 0x0A}, {0xb6, 0xAC, 0x13, 0x11}, {0xb6, 0xAC, 0x13, 0x16} },
	[IBRIGHTNESS_024NIT] = {{0xb6, 0xAC, 0x15, 0x0A}, {0xb6, 0xAC, 0x15, 0x10}, {0xb6, 0xAC, 0x15, 0x14} },
	[IBRIGHTNESS_025NIT] = {{0xb6, 0xAC, 0x17, 0x0A}, {0xb6, 0xAC, 0x17, 0x0F}, {0xb6, 0xAC, 0x17, 0x12} },
	[IBRIGHTNESS_027NIT] = {{0xb6, 0xAC, 0x19, 0x0A}, {0xb6, 0xAC, 0x19, 0x0E}, {0xb6, 0xAC, 0x19, 0x10} },
	[IBRIGHTNESS_029NIT] = {{0xb6, 0xAC, 0x1C, 0x0A}, {0xb6, 0xAC, 0x1C, 0x0C}, {0xb6, 0xAC, 0x1C, 0x0D} },
	[IBRIGHTNESS_030NIT] = {{0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00} },
	[IBRIGHTNESS_032NIT] = {{0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00} },
	[IBRIGHTNESS_034NIT] = {{0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00} },
	[IBRIGHTNESS_037NIT] = {{0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00} },
	[IBRIGHTNESS_039NIT] = {{0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00}, {0xb6, 0xAC, 0x1F, 0x00} },
	[IBRIGHTNESS_041NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_044NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_047NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_050NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_053NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_056NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_060NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_064NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_068NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_072NIT] = {{0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00}, {0xb6, 0xBC, 0x1F, 0x00} },
	[IBRIGHTNESS_077NIT] = {{0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00} },
	[IBRIGHTNESS_082NIT] = {{0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00} },
	[IBRIGHTNESS_087NIT] = {{0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00} },
	[IBRIGHTNESS_093NIT] = {{0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00} },
	[IBRIGHTNESS_098NIT] = {{0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00}, {0xb6, 0xBC, 0x1E, 0x00} },
	[IBRIGHTNESS_105NIT] = {{0xb6, 0xBC, 0x1D, 0x00}, {0xb6, 0xBC, 0x1D, 0x00}, {0xb6, 0xBC, 0x1D, 0x00} },
	[IBRIGHTNESS_111NIT] = {{0xb6, 0xBC, 0x1D, 0x00}, {0xb6, 0xBC, 0x1D, 0x00}, {0xb6, 0xBC, 0x1D, 0x00} },
	[IBRIGHTNESS_119NIT] = {{0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00} },
	[IBRIGHTNESS_126NIT] = {{0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00} },
	[IBRIGHTNESS_134NIT] = {{0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00} },
	[IBRIGHTNESS_143NIT] = {{0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00} },
	[IBRIGHTNESS_152NIT] = {{0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00} },
	[IBRIGHTNESS_162NIT] = {{0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00} },
	[IBRIGHTNESS_172NIT] = {{0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00} },
	[IBRIGHTNESS_183NIT] = {{0xb6, 0xBC, 0x1B, 0x00}, {0xb6, 0xBC, 0x1B, 0x00}, {0xb6, 0xBC, 0x1B, 0x00} },
	[IBRIGHTNESS_195NIT] = {{0xb6, 0xBC, 0x19, 0x00}, {0xb6, 0xBC, 0x19, 0x00}, {0xb6, 0xBC, 0x19, 0x00} },
	[IBRIGHTNESS_207NIT] = {{0xb6, 0xBC, 0x19, 0x00}, {0xb6, 0xBC, 0x19, 0x00}, {0xb6, 0xBC, 0x19, 0x00} },
	[IBRIGHTNESS_220NIT] = {{0xb6, 0xBC, 0x18, 0x00}, {0xb6, 0xBC, 0x18, 0x00}, {0xb6, 0xBC, 0x18, 0x00} },
	[IBRIGHTNESS_234NIT] = {{0xb6, 0xBC, 0x17, 0x00}, {0xb6, 0xBC, 0x17, 0x00}, {0xb6, 0xBC, 0x17, 0x00} },
	[IBRIGHTNESS_249NIT] = {{0xb6, 0xBC, 0x16, 0x00}, {0xb6, 0xBC, 0x16, 0x00}, {0xb6, 0xBC, 0x16, 0x00} },
	[IBRIGHTNESS_265NIT] = {{0xb6, 0xBC, 0x15, 0x00}, {0xb6, 0xBC, 0x15, 0x00}, {0xb6, 0xBC, 0x15, 0x00} },
	[IBRIGHTNESS_282NIT] = {{0xb6, 0xBC, 0x14, 0x00}, {0xb6, 0xBC, 0x14, 0x00}, {0xb6, 0xBC, 0x14, 0x00} },
	[IBRIGHTNESS_300NIT] = {{0xb6, 0xBC, 0x13, 0x00}, {0xb6, 0xBC, 0x13, 0x00}, {0xb6, 0xBC, 0x13, 0x00} },
	[IBRIGHTNESS_316NIT] = {{0xb6, 0xBC, 0x12, 0x00}, {0xb6, 0xBC, 0x12, 0x00}, {0xb6, 0xBC, 0x12, 0x00} },
	[IBRIGHTNESS_333NIT] = {{0xb6, 0xBC, 0x11, 0x00}, {0xb6, 0xBC, 0x11, 0x00}, {0xb6, 0xBC, 0x11, 0x00} },
	[IBRIGHTNESS_360NIT] = {{0xb6, 0xBC, 0x0F, 0x00}, {0xb6, 0xBC, 0x0F, 0x00}, {0xb6, 0xBC, 0x0F, 0x00} },
	[IBRIGHTNESS_378NIT] = {{0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00}, {0xb6, 0xBC, 0x1C, 0x00} },
	[IBRIGHTNESS_395NIT] = {{0xb6, 0xBC, 0x1A, 0x00}, {0xb6, 0xBC, 0x1A, 0x00}, {0xb6, 0xBC, 0x1A, 0x00} },
	[IBRIGHTNESS_413NIT] = {{0xb6, 0xBC, 0x18, 0x00}, {0xb6, 0xBC, 0x18, 0x00}, {0xb6, 0xBC, 0x18, 0x00} },
	[IBRIGHTNESS_430NIT] = {{0xb6, 0xBC, 0x16, 0x00}, {0xb6, 0xBC, 0x16, 0x00}, {0xb6, 0xBC, 0x16, 0x00} },
	[IBRIGHTNESS_448NIT] = {{0xb6, 0xBC, 0x14, 0x00}, {0xb6, 0xBC, 0x14, 0x00}, {0xb6, 0xBC, 0x14, 0x00} },
	[IBRIGHTNESS_465NIT] = {{0xb6, 0xBC, 0x12, 0x00}, {0xb6, 0xBC, 0x12, 0x00}, {0xb6, 0xBC, 0x12, 0x00} },
	[IBRIGHTNESS_483NIT] = {{0xb6, 0xBC, 0x10, 0x00}, {0xb6, 0xBC, 0x10, 0x00}, {0xb6, 0xBC, 0x10, 0x00} },
	[IBRIGHTNESS_500NIT] = {{0xb6, 0xBC, 0x0F, 0x00}, {0xb6, 0xBC, 0x0F, 0x00}, {0xb6, 0xBC, 0x0F, 0x00} },
};

static unsigned char AOR_TABLE[UI_MAX_BRIGHTNESS + 1 + 1][AID_CMD_CNT] = {
	/* UI_MAX_BRIGHTNESS + 1 = 255 + HBM&Interpolation, "+ 1" for array initialize */
	{0xB2, 0x04, 0xEE},
	{0xB2, 0x04, 0xEB},
	{0xB2, 0x04, 0xE8},
	{0xB2, 0x04, 0xE5},
	{0xB2, 0x04, 0xE1},
	{0xB2, 0x04, 0xDC},
	{0xB2, 0x04, 0xD8},
	{0xB2, 0x04, 0xD5},
	{0xB2, 0x04, 0xD2},
	{0xB2, 0x04, 0xD1},
	{0xB2, 0x04, 0xD0},
	{0xB2, 0x04, 0xCF},
	{0xB2, 0x04, 0xCE},
	{0xB2, 0x04, 0xCB},
	{0xB2, 0x04, 0xC7},
	{0xB2, 0x04, 0xC3},
	{0xB2, 0x04, 0xC0},
	{0xB2, 0x04, 0xBD},
	{0xB2, 0x04, 0xBA},
	{0xB2, 0x04, 0xB7},
	{0xB2, 0x04, 0xB3},
	{0xB2, 0x04, 0xB1},
	{0xB2, 0x04, 0xB0},
	{0xB2, 0x04, 0xAF},
	{0xB2, 0x04, 0xAE},
	{0xB2, 0x04, 0xAC},
	{0xB2, 0x04, 0xA9},
	{0xB2, 0x04, 0xA6},
	{0xB2, 0x04, 0xA3},
	{0xB2, 0x04, 0x9F},
	{0xB2, 0x04, 0x9B},
	{0xB2, 0x04, 0x97},
	{0xB2, 0x04, 0x93},
	{0xB2, 0x04, 0x92},
	{0xB2, 0x04, 0x91},
	{0xB2, 0x04, 0x8F},
	{0xB2, 0x04, 0x8E},
	{0xB2, 0x04, 0x8A},
	{0xB2, 0x04, 0x87},
	{0xB2, 0x04, 0x83},
	{0xB2, 0x04, 0x80},
	{0xB2, 0x04, 0x7A},
	{0xB2, 0x04, 0x75},
	{0xB2, 0x04, 0x70},
	{0xB2, 0x04, 0x6A},
	{0xB2, 0x04, 0x5E},
	{0xB2, 0x04, 0x52},
	{0xB2, 0x04, 0x4A},
	{0xB2, 0x04, 0x42},
	{0xB2, 0x04, 0x40},
	{0xB2, 0x04, 0x3E},
	{0xB2, 0x04, 0x34},
	{0xB2, 0x04, 0x2A},
	{0xB2, 0x04, 0x1D},
	{0xB2, 0x04, 0x10},
	{0xB2, 0x04, 0x08},
	{0xB2, 0x04, 0x00},
	{0xB2, 0x03, 0xF1},
	{0xB2, 0x03, 0xE2},
	{0xB2, 0x03, 0xD3},
	{0xB2, 0x03, 0xC4},
	{0xB2, 0x03, 0xBC},
	{0xB2, 0x03, 0xB4},
	{0xB2, 0x03, 0xAA},
	{0xB2, 0x03, 0x9F},
	{0xB2, 0x03, 0x91},
	{0xB2, 0x03, 0x83},
	{0xB2, 0x03, 0x72},
	{0xB2, 0x03, 0x61},
	{0xB2, 0x03, 0x52},
	{0xB2, 0x03, 0x43},
	{0xB2, 0x03, 0x39},
	{0xB2, 0x03, 0x2E},
	{0xB2, 0x03, 0x1A},
	{0xB2, 0x03, 0x06},
	{0xB2, 0x02, 0xF3},
	{0xB2, 0x02, 0xE0},
	{0xB2, 0x02, 0xCF},
	{0xB2, 0x02, 0xBE},
	{0xB2, 0x02, 0xA8},
	{0xB2, 0x02, 0x92},
	{0xB2, 0x02, 0x81},
	{0xB2, 0x02, 0x6F},
	{0xB2, 0x02, 0x55},
	{0xB2, 0x02, 0x3B},
	{0xB2, 0x02, 0x26},
	{0xB2, 0x02, 0x11},
	{0xB2, 0x02, 0x0A},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x08},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x0C},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x0B},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x09},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x0C},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x07},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x0D},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x08},
	{0xB2, 0x01, 0xF2},
	{0xB2, 0x02, 0x0B},
	{0xB2, 0x01, 0xF0},
	{0xB2, 0x01, 0xD7},
	{0xB2, 0x01, 0xBE},
	{0xB2, 0x01, 0xA9},
	{0xB2, 0x01, 0x95},
	{0xB2, 0x01, 0x80},
	{0xB2, 0x01, 0x6A},
	{0xB2, 0x01, 0x55},
	{0xB2, 0x01, 0x3F},
	{0xB2, 0x01, 0x26},
	{0xB2, 0x01, 0x0D},
	{0xB2, 0x00, 0xF4},
	{0xB2, 0x00, 0xDC},
	{0xB2, 0x00, 0xC4},
	{0xB2, 0x00, 0xAC},
	{0xB2, 0x00, 0x99},
	{0xB2, 0x00, 0x85},
	{0xB2, 0x00, 0x72},
	{0xB2, 0x00, 0x5E},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x36},
	{0xB2, 0x00, 0x22},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x57},
	{0xB2, 0x00, 0x50},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x41},
	{0xB2, 0x00, 0x3A},
	{0xB2, 0x00, 0x33},
	{0xB2, 0x00, 0x2C},
	{0xB2, 0x00, 0x25},
	{0xB2, 0x00, 0x1D},
	{0xB2, 0x00, 0x16},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x53},
	{0xB2, 0x00, 0x4C},
	{0xB2, 0x00, 0x45},
	{0xB2, 0x00, 0x3F},
	{0xB2, 0x00, 0x38},
	{0xB2, 0x00, 0x31},
	{0xB2, 0x00, 0x2A},
	{0xB2, 0x00, 0x23},
	{0xB2, 0x00, 0x1D},
	{0xB2, 0x00, 0x16},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x54},
	{0xB2, 0x00, 0x4D},
	{0xB2, 0x00, 0x46},
	{0xB2, 0x00, 0x3F},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x32},
	{0xB2, 0x00, 0x2B},
	{0xB2, 0x00, 0x24},
	{0xB2, 0x00, 0x1D},
	{0xB2, 0x00, 0x16},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x55},
	{0xB2, 0x00, 0x4E},
	{0xB2, 0x00, 0x47},
	{0xB2, 0x00, 0x40},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x32},
	{0xB2, 0x00, 0x2B},
	{0xB2, 0x00, 0x24},
	{0xB2, 0x00, 0x1D},
	{0xB2, 0x00, 0x16},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x56},
	{0xB2, 0x00, 0x4F},
	{0xB2, 0x00, 0x47},
	{0xB2, 0x00, 0x40},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x32},
	{0xB2, 0x00, 0x2B},
	{0xB2, 0x00, 0x24},
	{0xB2, 0x00, 0x1D},
	{0xB2, 0x00, 0x16},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x56},
	{0xB2, 0x00, 0x4F},
	{0xB2, 0x00, 0x48},
	{0xB2, 0x00, 0x41},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x32},
	{0xB2, 0x00, 0x2B},
	{0xB2, 0x00, 0x24},
	{0xB2, 0x00, 0x1D},
	{0xB2, 0x00, 0x16},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x56},
	{0xB2, 0x00, 0x50},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x43},
	{0xB2, 0x00, 0x3C},
	{0xB2, 0x00, 0x36},
	{0xB2, 0x00, 0x2F},
	{0xB2, 0x00, 0x29},
	{0xB2, 0x00, 0x22},
	{0xB2, 0x00, 0x1C},
	{0xB2, 0x00, 0x15},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x56},
	{0xB2, 0x00, 0x4F},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x43},
	{0xB2, 0x00, 0x3C},
	{0xB2, 0x00, 0x36},
	{0xB2, 0x00, 0x2F},
	{0xB2, 0x00, 0x29},
	{0xB2, 0x00, 0x22},
	{0xB2, 0x00, 0x1C},
	{0xB2, 0x00, 0x15},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x4A},
	{0xB2, 0x00, 0x44},
	{0xB2, 0x00, 0x3E},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x33},
	{0xB2, 0x00, 0x2D},
	{0xB2, 0x00, 0x27},
	{0xB2, 0x00, 0x21},
	{0xB2, 0x00, 0x1B},
	{0xB2, 0x00, 0x15},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x4B},
	{0xB2, 0x00, 0x46},
	{0xB2, 0x00, 0x40},
	{0xB2, 0x00, 0x3B},
	{0xB2, 0x00, 0x35},
	{0xB2, 0x00, 0x30},
	{0xB2, 0x00, 0x2A},
	{0xB2, 0x00, 0x25},
	{0xB2, 0x00, 0x1F},
	{0xB2, 0x00, 0x1A},
	{0xB2, 0x00, 0x14},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x68},
	{0xB2, 0x00, 0x61},
	{0xB2, 0x00, 0x59},
	{0xB2, 0x00, 0x52},
	{0xB2, 0x00, 0x4A},
	{0xB2, 0x00, 0x43},
	{0xB2, 0x00, 0x3C},
	{0xB2, 0x00, 0x34},
	{0xB2, 0x00, 0x2D},
	{0xB2, 0x00, 0x25},
	{0xB2, 0x00, 0x1E},
	{0xB2, 0x00, 0x16},
	{0xB2, 0x00, 0x0F},
	{0xB2, 0x00, 0x0F},
	[256] = {0xB2, 0x00, 0x0F},
};

/* platform brightness <-> gamma level */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	[0 ... 0] =	IBRIGHTNESS_005NIT,
	[1 ... 4] =	IBRIGHTNESS_006NIT,
	[5 ... 8] =	IBRIGHTNESS_007NIT,
	[9 ... 12] =	IBRIGHTNESS_008NIT,
	[13 ... 16] =	IBRIGHTNESS_009NIT,
	[17 ... 20] =	IBRIGHTNESS_010NIT,
	[21 ... 24] =	IBRIGHTNESS_011NIT,
	[25 ... 28] =	IBRIGHTNESS_012NIT,
	[29 ... 32] =	IBRIGHTNESS_013NIT,
	[33 ... 36] =	IBRIGHTNESS_014NIT,
	[37 ... 40] =	IBRIGHTNESS_015NIT,
	[41 ... 42] =	IBRIGHTNESS_016NIT,
	[43 ... 44] =	IBRIGHTNESS_017NIT,
	[45 ... 46] =	IBRIGHTNESS_019NIT,
	[47 ... 48] =	IBRIGHTNESS_020NIT,
	[49 ... 50] =	IBRIGHTNESS_021NIT,
	[51 ... 52] =	IBRIGHTNESS_022NIT,
	[53 ... 54] =	IBRIGHTNESS_024NIT,
	[55 ... 56] =	IBRIGHTNESS_025NIT,
	[57 ... 58] =	IBRIGHTNESS_027NIT,
	[59 ... 60] =	IBRIGHTNESS_029NIT,
	[61 ... 62] =	IBRIGHTNESS_030NIT,
	[63 ... 64] =	IBRIGHTNESS_032NIT,
	[65 ... 66] =	IBRIGHTNESS_034NIT,
	[67 ... 68] =	IBRIGHTNESS_037NIT,
	[69 ... 70] =	IBRIGHTNESS_039NIT,
	[71 ... 72] =	IBRIGHTNESS_041NIT,
	[73 ... 74] =	IBRIGHTNESS_044NIT,
	[75 ... 76] =	IBRIGHTNESS_047NIT,
	[77 ... 78] =	IBRIGHTNESS_050NIT,
	[79 ... 80] =	IBRIGHTNESS_053NIT,
	[81 ... 82] =	IBRIGHTNESS_056NIT,
	[83 ... 84] =	IBRIGHTNESS_060NIT,
	[85 ... 86] =	IBRIGHTNESS_064NIT,
	[87 ... 88] =	IBRIGHTNESS_068NIT,
	[89 ... 90] =	IBRIGHTNESS_072NIT,
	[91 ... 92] =	IBRIGHTNESS_077NIT,
	[93 ... 94] =	IBRIGHTNESS_082NIT,
	[95 ... 96] =	IBRIGHTNESS_087NIT,
	[97 ... 98] =	IBRIGHTNESS_093NIT,
	[99 ... 100] =	IBRIGHTNESS_098NIT,
	[101 ... 102] =	IBRIGHTNESS_105NIT,
	[103 ... 104] =	IBRIGHTNESS_111NIT,
	[105 ... 106] =	IBRIGHTNESS_119NIT,
	[107 ... 108] =	IBRIGHTNESS_126NIT,
	[109 ... 111] =	IBRIGHTNESS_134NIT,
	[112 ... 114] =	IBRIGHTNESS_143NIT,
	[115 ... 117] =	IBRIGHTNESS_152NIT,
	[118 ... 120] =	IBRIGHTNESS_162NIT,
	[121 ... 124] =	IBRIGHTNESS_172NIT,
	[125 ... 128] =	IBRIGHTNESS_183NIT,
	[129 ... 139] =	IBRIGHTNESS_195NIT,
	[140 ... 150] =	IBRIGHTNESS_207NIT,
	[151 ... 161] =	IBRIGHTNESS_220NIT,
	[162 ... 172] =	IBRIGHTNESS_234NIT,
	[173 ... 183] =	IBRIGHTNESS_249NIT,
	[184 ... 194] =	IBRIGHTNESS_265NIT,
	[195 ... 206] =	IBRIGHTNESS_282NIT,
	[207 ... 218] =	IBRIGHTNESS_300NIT,
	[219 ... 229] =	IBRIGHTNESS_316NIT,
	[230 ... 241] =	IBRIGHTNESS_333NIT,
	[242 ... 267] =	IBRIGHTNESS_360NIT,
	[268 ... 279] =	IBRIGHTNESS_378NIT,
	[280 ... 292] =	IBRIGHTNESS_395NIT,
	[293 ... 304] =	IBRIGHTNESS_413NIT,
	[305 ... 317] =	IBRIGHTNESS_430NIT,
	[318 ... 329] =	IBRIGHTNESS_448NIT,
	[330 ... 341] =	IBRIGHTNESS_465NIT,
	[342 ... 354] =	IBRIGHTNESS_483NIT,
	[355 ... EXTEND_BRIGHTNESS] =	 IBRIGHTNESS_500NIT,
};
#endif /* __S6E8AA0X1_J5Y17_PARAM_H__ */
