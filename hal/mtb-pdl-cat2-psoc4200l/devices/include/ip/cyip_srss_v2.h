/***************************************************************************//**
* \file cyip_srss_v2.h
*
* \brief
* SRSS v2 IP definitions for PSoC 4200L family
* Base address: 0x400B0000
*
********************************************************************************
* \copyright
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/

#ifndef _CYIP_SRSS_V2_H_
#define _CYIP_SRSS_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                   SRSS v2
* Register offsets verified against cydevice_trm.h (CY8C4248LTI-L475):
*   PWR_CONTROL    = 0x000   CLK_SELECT     = 0x100
*   PWR_KEY_DELAY  = 0x00C   CLK_ILO_CONFIG = 0x104
*   RES_CAUSE      = 0x300   CLK_IMO_CONFIG = 0x108
*   WDT_CTRLOW     = 0x200   CLK_DFT_SELECT = 0x110
*   WDT_MATCH      = 0x208   CLK_CAL_CNT1   = 0x180
*   WDT_CONFIG     = 0x20C   CLK_CAL_CNT2   = 0x184
*   WDT_CONTROL    = 0x210   CLK_IMO_TRIM1  = 0xFF28
*******************************************************************************/

typedef struct {
  __IOM uint32_t PWR_CONTROL;                   /*!< 0x00000000 */
  union {
    __IOM uint32_t PWR_INTR;                    /*!< 0x00000004 */
    __IOM uint32_t SRSS_INTR;                   /* alias for cy_device.h */
    __IOM uint32_t SRSS_INTR_SET;               /* alias (write-to-set not separate on SRSSv2) */
  };
  union {
    __IOM uint32_t PWR_INTR_MASK;               /*!< 0x00000008 */
    __IOM uint32_t SRSS_INTR_MASK;              /* alias for cy_device.h */
  };
  __IOM uint32_t PWR_KEY_DELAY;                 /*!< 0x0000000C */
  __IOM uint32_t PWR_PWRSYS_CONFIG;             /*!< 0x00000010 */
  __IOM uint32_t PWR_BG_CONFIG;                 /*!< 0x00000014 */
  __IOM uint32_t PWR_VMON_CONFIG;               /*!< 0x00000018 */
  __IOM uint32_t PWR_DFT_SELECT;                /*!< 0x0000001C */
  __IOM uint32_t PWR_DDFT_SELECT;               /*!< 0x00000020 */
  __IOM uint32_t PWR_DFT_KEY;                   /*!< 0x00000024 */
  __IOM uint32_t PWR_BOD_KEY;                   /*!< 0x00000028 */
  __IOM uint32_t PWR_STOP;                      /*!< 0x0000002C */
   __IM uint32_t RESERVED0[52];                 /*!< 0x030-0x0FC */
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00000100 */
  __IOM uint32_t CLK_ILO_CONFIG;                /*!< 0x00000104 */
  __IOM uint32_t CLK_IMO_CONFIG;                /*!< 0x00000108 */
  __IOM uint32_t CLK_IMO_SPREAD;                /*!< 0x0000010C */
  __IOM uint32_t CLK_DFT_SELECT;                /*!< 0x00000110 */
   __IM uint32_t RESERVED1[27];                 /*!< 0x114-0x17C */
  __IOM uint32_t CLK_CAL_CNT1;                  /*!< 0x00000180 */
   __IM uint32_t CLK_CAL_CNT2;                  /*!< 0x00000184 */
   __IM uint32_t RESERVED2[30];                 /*!< 0x188-0x1FC */
  __IOM uint32_t WDT_CTRLOW;                    /*!< 0x00000200 */
  __IOM uint32_t WDT_CTRHIGH;                   /*!< 0x00000204 */
  __IOM uint32_t WDT_MATCH;                     /*!< 0x00000208 */
  __IOM uint32_t WDT_CONFIG;                    /*!< 0x0000020C */
  __IOM uint32_t WDT_CONTROL;                   /*!< 0x00000210 */
   __IM uint32_t RESERVED3[59];                 /*!< 0x214-0x2FC */
  __IOM uint32_t RES_CAUSE;                     /*!< 0x00000300 */
   __IM uint32_t RESERVED4[48063];              /*!< 0x304-0xFEFC */
  __IOM uint32_t PWR_PWRSYS_TRIM1;              /*!< 0x0000FF00 */
  __IOM uint32_t PWR_PWRSYS_TRIM2;              /*!< 0x0000FF04 */
  __IOM uint32_t PWR_PWRSYS_TRIM3;              /*!< 0x0000FF08 */
  __IOM uint32_t PWR_PWRSYS_TRIM4;              /*!< 0x0000FF0C */
  __IOM uint32_t PWR_BG_TRIM1;                  /*!< 0x0000FF10 */
  __IOM uint32_t PWR_BG_TRIM2;                  /*!< 0x0000FF14 */
  __IOM uint32_t PWR_BG_TRIM3;                  /*!< 0x0000FF18 */
  __IOM uint32_t PWR_BG_TRIM4;                  /*!< 0x0000FF1C */
  __IOM uint32_t PWR_BG_TRIM5;                  /*!< 0x0000FF20 */
  __IOM uint32_t CLK_ILO_TRIM;                  /*!< 0x0000FF24 */
  __IOM uint32_t CLK_IMO_SELECT;                /*!< 0x0000FF28 (IMO freq select in trim area) */
  __IOM uint32_t CLK_IMO_TRIM1;                 /*!< 0x0000FF2C */
  __IOM uint32_t CLK_IMO_TRIM2;                 /*!< 0x0000FF30 */
  __IOM uint32_t CLK_IMO_TRIM3;                 /*!< 0x0000FF34 */
} SRSS_V2_Type;


/* SRSS_V2.CLK_SELECT */
#define SRSS_V2_CLK_SELECT_HFCLK_SEL_Pos        0UL
#define SRSS_V2_CLK_SELECT_HFCLK_SEL_Msk        0x7UL
#define SRSS_V2_CLK_SELECT_HFCLK_DIV_Pos        4UL
#define SRSS_V2_CLK_SELECT_HFCLK_DIV_Msk        0x30UL
#define SRSS_V2_CLK_SELECT_PUMP_SEL_Pos          8UL
#define SRSS_V2_CLK_SELECT_PUMP_SEL_Msk          0xF00UL
#define SRSS_V2_CLK_SELECT_SYSCLK_DIV_Pos        16UL
#define SRSS_V2_CLK_SELECT_SYSCLK_DIV_Msk        0x70000UL

/* SRSS_V2.CLK_ILO_CONFIG */
#define SRSS_V2_CLK_ILO_CONFIG_ENABLE_Pos        31UL
#define SRSS_V2_CLK_ILO_CONFIG_ENABLE_Msk        0x80000000UL

/* SRSS_V2.CLK_IMO_CONFIG */
#define SRSS_V2_CLK_IMO_CONFIG_ENABLE_Pos        31UL
#define SRSS_V2_CLK_IMO_CONFIG_ENABLE_Msk        0x80000000UL

/* SRSS_V2.CLK_DFT_SELECT */
#define SRSS_V2_CLK_DFT_SELECT_DFT_SEL0_Pos     0UL
#define SRSS_V2_CLK_DFT_SELECT_DFT_SEL0_Msk     0xFUL
#define SRSS_V2_CLK_DFT_SELECT_DFT_SEL1_Pos     8UL
#define SRSS_V2_CLK_DFT_SELECT_DFT_SEL1_Msk     0xF00UL

/* SRSS_V2.CLK_IMO_SELECT (in trim area) */
#define SRSS_V2_CLK_IMO_SELECT_FREQ_Pos          0UL
#define SRSS_V2_CLK_IMO_SELECT_FREQ_Msk          0x3FUL

/* SRSS_V2.CLK_IMO_TRIM1 */
#define SRSS_V2_CLK_IMO_TRIM1_OFFSET_Pos         0UL
#define SRSS_V2_CLK_IMO_TRIM1_OFFSET_Msk         0xFFUL

/* SRSS_V2.CLK_IMO_TRIM2 */
#define SRSS_V2_CLK_IMO_TRIM2_FSOFFSET_Pos       0UL
#define SRSS_V2_CLK_IMO_TRIM2_FSOFFSET_Msk       0x7UL

/* SRSS_V2.RES_CAUSE */
#define SRSS_V2_RES_CAUSE_RESET_WDT_Pos          0UL
#define SRSS_V2_RES_CAUSE_RESET_WDT_Msk          0x1UL
#define SRSS_V2_RES_CAUSE_RESET_PROT_FAULT_Pos   3UL
#define SRSS_V2_RES_CAUSE_RESET_PROT_FAULT_Msk   0x8UL
#define SRSS_V2_RES_CAUSE_RESET_SOFT_Pos          4UL
#define SRSS_V2_RES_CAUSE_RESET_SOFT_Msk          0x10UL

/* SRSS_V2.PWR_CONTROL */
#define SRSS_V2_PWR_CONTROL_POWER_MODE_Pos       0UL
#define SRSS_V2_PWR_CONTROL_POWER_MODE_Msk       0xFUL
#define SRSS_V2_PWR_CONTROL_DEBUG_SESSION_Pos    4UL
#define SRSS_V2_PWR_CONTROL_DEBUG_SESSION_Msk    0x10UL
#define SRSS_V2_PWR_CONTROL_LPM_READY_Pos        5UL
#define SRSS_V2_PWR_CONTROL_LPM_READY_Msk        0x20UL
#define SRSS_V2_PWR_CONTROL_EXT_VCCD_Pos         23UL
#define SRSS_V2_PWR_CONTROL_EXT_VCCD_Msk         0x800000UL

/* SRSS_V2.PWR_KEY_DELAY */
#define SRSS_V2_PWR_KEY_DELAY_WAKEUP_HOLDOFF_Pos  0UL
#define SRSS_V2_PWR_KEY_DELAY_WAKEUP_HOLDOFF_Msk  0x3FFUL

/* SRSS_V2.SRSS_INTR (mapped to PWR_INTR for compatibility) */
#define SRSS_V2_SRSS_INTR_WDT_MATCH_Pos          0UL
#define SRSS_V2_SRSS_INTR_WDT_MATCH_Msk          0x1UL

/* SRSS_V2.SRSS_INTR_MASK (mapped to PWR_INTR_MASK) */
#define SRSS_V2_SRSS_INTR_MASK_WDT_MATCH_Pos     0UL
#define SRSS_V2_SRSS_INTR_MASK_WDT_MATCH_Msk     0x1UL

/* Aliases for cy_device.h SRSS_SRSS_INTR etc. macros */
#define SRSS_V2_SRSS_INTR_SET_TEMP_HIGH_Pos       1UL
#define SRSS_V2_SRSS_INTR_SET_TEMP_HIGH_Msk       0x2UL
#define SRSS_V2_SRSS_INTR_MASK_TEMP_HIGH_Pos      1UL
#define SRSS_V2_SRSS_INTR_MASK_TEMP_HIGH_Msk      0x2UL
#define SRSS_V2_SRSS_INTR_TEMP_HIGH_Pos            1UL
#define SRSS_V2_SRSS_INTR_TEMP_HIGH_Msk            0x2UL

#endif /* _CYIP_SRSS_V2_H_ */
