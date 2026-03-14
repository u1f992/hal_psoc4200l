/***************************************************************************//**
* \file gpio_psoc4200l_68_qfn.h
*
* \brief
* PSoC 4200L device GPIO header for 68-QFN package
* Minimal pin definitions for initial Zephyr port bring-up.
*
********************************************************************************
* \copyright
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/

#ifndef _GPIO_PSOC4200L_68_QFN_H_
#define _GPIO_PSOC4200L_68_QFN_H_

/* AMUX split control */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u
} cy_en_amux_split_t;

/* Package type */
#define CY_GPIO_PACKAGE_QFN
#define CY_GPIO_PIN_COUNT        68u

/* Port availability - PSoC 4200L has ports 0-13 */
#define IOSS_GPIO_GPIO_PORT_NR       14u

/* Number of pins per port */
#define CY_GPIO_PRT0_PIN_COUNT       8u
#define CY_GPIO_PRT1_PIN_COUNT       8u
#define CY_GPIO_PRT2_PIN_COUNT       8u
#define CY_GPIO_PRT3_PIN_COUNT       8u
#define CY_GPIO_PRT4_PIN_COUNT       8u
#define CY_GPIO_PRT5_PIN_COUNT       8u
#define CY_GPIO_PRT6_PIN_COUNT       8u
#define CY_GPIO_PRT7_PIN_COUNT       8u
#define CY_GPIO_PRT8_PIN_COUNT       8u
#define CY_GPIO_PRT9_PIN_COUNT       8u
#define CY_GPIO_PRT10_PIN_COUNT      8u
#define CY_GPIO_PRT11_PIN_COUNT      8u
#define CY_GPIO_PRT12_PIN_COUNT      8u
#define CY_GPIO_PRT13_PIN_COUNT      2u  /* Only 2 pins on port 13 (USB wakeup) */

/*
 * HSIOM selection enum.
 *
 * Each pin in PSoC 4200L can be configured to one of 16 HSIOM functions (0-15).
 * The full per-pin enum is device/package specific. For initial bring-up,
 * we define the common HSIOM values used by all pins, plus specific pin
 * assignments needed for the board definition.
 *
 * HSIOM function groups for PSoC 4200L:
 *   0: GPIO (software controlled)
 *   1: GPIO with DSI output enable
 *   2: DSI controlled digital
 *   3: DSI controlled analog
 *   4: CSD sense
 *   5: CSD shield
 *   6: AMUXBUS A
 *   7: AMUXBUS B
 *   8-11: Active functions (SCB, TCPWM, etc. - varies per pin)
 *   12-15: Deep Sleep functions (LCD, SCB I2C, etc. - varies per pin)
 */
typedef enum
{
    /* Common HSIOM selections (same for all pins) */
    HSIOM_SEL_GPIO                  =  0,       /* SW controlled GPIO */
    HSIOM_SEL_GPIO_DSI              =  1,       /* SW controlled 'out', DSI controlled 'oe_n' */
    HSIOM_SEL_DSI_DSI               =  2,       /* DSI controlled 'out' and 'oe_n' */
    HSIOM_SEL_DSI_GPIO              =  3,       /* DSI controlled analog */
    HSIOM_SEL_CSD_SENSE             =  4,       /* CSD sense connection */
    HSIOM_SEL_CSD_SHIELD            =  5,       /* CSD shield connection */
    HSIOM_SEL_AMUXA                 =  6,       /* AMUXBUS A connection */
    HSIOM_SEL_AMUXB                 =  7,       /* AMUXBUS B connection */

    /* Active function aliases (group 8-11) */
    HSIOM_SEL_ACT_0                 =  8,       /* Active function 0 */
    HSIOM_SEL_ACT_1                 =  9,       /* Active function 1 */
    HSIOM_SEL_ACT_2                 = 10,       /* Active function 2 */
    HSIOM_SEL_ACT_3                 = 11,       /* Active function 3 */

    /* Deep Sleep function aliases (group 12-15) */
    HSIOM_SEL_DS_0                  = 12,       /* Deep Sleep function 0 */
    HSIOM_SEL_DS_1                  = 13,       /* Deep Sleep function 1 */
    HSIOM_SEL_DS_2                  = 14,       /* Deep Sleep function 2 (I2C SCL/SDA) */
    HSIOM_SEL_DS_3                  = 15,       /* Deep Sleep function 3 */

    /* P0.4 - SCB0 UART RX (HSIOM function 8 = ACT_0 for SCB0) */
    P0_4_GPIO                       =  0,
    P0_4_AMUXA                      =  6,
    P0_4_AMUXB                      =  7,
    P0_4_SCB0_UART_RX               =  8,       /* Active - scb[0].uart_rx */

    /* P0.5 - SCB0 UART TX (HSIOM function 8 = ACT_0 for SCB0) */
    P0_5_GPIO                       =  0,
    P0_5_AMUXA                      =  6,
    P0_5_AMUXB                      =  7,
    P0_5_SCB0_UART_TX               =  8,       /* Active - scb[0].uart_tx */

    /* P1.0 - SCB0 I2C SCL */
    P1_0_GPIO                       =  0,
    P1_0_SCB0_I2C_SCL               = 14,       /* Deep Sleep - scb[0].i2c_scl */

    /* P1.1 - SCB0 I2C SDA */
    P1_1_GPIO                       =  0,
    P1_1_SCB0_I2C_SDA               = 14,       /* Deep Sleep - scb[0].i2c_sda */

    /* TODO: Add remaining pin HSIOM assignments from PSoC 4200L datasheet */
} en_hsiom_sel_t;


#endif /* _GPIO_PSOC4200L_68_QFN_H_ */
