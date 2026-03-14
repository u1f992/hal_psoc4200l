# Copyright (c) 2025 PSoC 4200L Zephyr Port
# SPDX-License-Identifier: Apache-2.0

zephyr_sources(soc.c)
zephyr_include_directories(.)

# Reserve SRAM space for vector table (Cortex-M0 has no VTOR)
zephyr_linker_sources(RAM_SECTIONS sections.ld)

# default Zephyr linker script
set(SOC_LINKER_SCRIPT ${ZEPHYR_BASE}/include/zephyr/arch/arm/cortex_m/scripts/linker.ld CACHE INTERNAL "")
