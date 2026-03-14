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
 */

#define CPUSS_CONFIG_REG    (*(volatile uint32_t *)0x40100000u)
#define CPUSS_CONFIG_VECT_IN_RAM_Msk (0x01u)

/* Symbols from linker script */
extern char _vector_start[];
extern char _vector_end[];

/*
 * Override the __weak relocate_vector_table() from arch/arm/core/cortex_m/prep_c.c.
 * Cortex-M0 has no VTOR, so we use PSoC 4200L's CPUSS_CONFIG mechanism.
 */
void relocate_vector_table(void)
{
	size_t vector_size = (size_t)_vector_end - (size_t)_vector_start;

	/* Copy vector table from Flash to SRAM base */
	(void)memcpy((void *)CONFIG_SRAM_BASE_ADDRESS, _vector_start, vector_size);

	/* Tell CPUSS hardware to fetch vectors from SRAM */
	CPUSS_CONFIG_REG |= CPUSS_CONFIG_VECT_IN_RAM_Msk;
}

/*
 * Early SoC initialization. Called before kernel starts.
 * Sets up IMO clock to 48 MHz (default after reset is 24 MHz on PSoC 4200L).
 */
void soc_early_init_hook(void)
{
	/*
	 * TODO: Initialize clocks (IMO to 48 MHz).
	 * For initial bring-up, the default 24 MHz IMO is sufficient.
	 * Full clock init will be added when clock control driver is integrated.
	 */
}
