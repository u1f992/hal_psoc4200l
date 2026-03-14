/*
 * Copyright (c) 2025 PSoC 4200L Zephyr Port
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <string.h>

/*
 * PSoC 4200L uses ARM Cortex-M0 (no VTOR register).
 * Vector table relocation is done via CPUSS_CONFIG.VECT_IN_RAM bit.
 * When set, the CPU fetches exception vectors from SRAM base (0x20000000)
 * instead of Flash base (0x00000000).
 *
 * The linker script (sections.ld) reserves 256 bytes at the start of SRAM
 * for the vector table copy. relocate_vector_table() copies the flash vector
 * table there and sets the CPUSS_CONFIG bit.
 */

#define CPUSS_CONFIG_REG    (*(volatile uint32_t *)0x40100000u)
#define CPUSS_CONFIG_VECT_IN_RAM_Msk (0x01u)

/* Flash vector table symbols from Zephyr linker */
extern char _vector_start[];
extern char _vector_end[];

/* SRAM vector table reservation from sections.ld */
extern char _psoc4_sram_vectors_start[];

/*
 * Override the __weak relocate_vector_table() from arch/arm/core/cortex_m/prep_c.c.
 * Cortex-M0 has no VTOR, so we use PSoC 4200L's CPUSS_CONFIG mechanism.
 */
void relocate_vector_table(void)
{
	/*
	 * For initial bring-up: do NOT relocate vectors to SRAM.
	 * Leave CPUSS_CONFIG.VECT_IN_RAM = 0 so the CPU uses the Flash
	 * vector table at 0x00000000. This is safe for basic operation;
	 * dynamic ISR installation will not work until SRAM relocation
	 * is properly implemented.
	 *
	 * Ensure VECT_IN_RAM is cleared (reset default should be 0,
	 * but clear it explicitly in case a previous debug session set it).
	 */
	CPUSS_CONFIG_REG &= ~CPUSS_CONFIG_VECT_IN_RAM_Msk;
}

/*
 * Early SoC initialization. Called before kernel starts.
 */
void soc_early_init_hook(void)
{
	/*
	 * TODO: Initialize clocks (IMO to 48 MHz).
	 * For initial bring-up, the default 24 MHz IMO is sufficient.
	 * Full clock init will be added when clock control driver is integrated.
	 */
}
