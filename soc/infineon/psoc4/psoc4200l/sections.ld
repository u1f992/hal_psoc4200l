/*
 * PSoC 4200L: Reserve space at SRAM start for vector table relocation.
 * Cortex-M0 has no VTOR; PSoC 4 uses CPUSS_CONFIG.VECT_IN_RAM to redirect
 * vector fetches to SRAM base (0x20000000).
 *
 * 48 entries (16 system + 32 IRQ) x 4 bytes = 192 bytes, rounded up to 256
 * for alignment.
 */

SECTION_PROLOGUE(.psoc4_sram_vectors, (NOLOAD),)
{
	_psoc4_sram_vectors_start = .;
	. += 0x100;  /* 256 bytes reserved */
	_psoc4_sram_vectors_end = .;
} GROUP_DATA_LINK_IN(RAMABLE_REGION, RAMABLE_REGION)
