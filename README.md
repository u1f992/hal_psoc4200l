# hal_psoc4200l - Zephyr RTOS port for PSoC 4200L

PSoC 4200L (CY8C4248LTI-L475) Zephyr RTOS port, packaged as an independent west module.

## Features

- ARM Cortex-M0 support (no VTOR, vector table via CPUSS_CONFIG.VECT_IN_RAM)
- SRSSv2 system resources (different from SRSSLT used in newer PSoC 4)
- GPIO (14 ports), SCB (4 blocks: UART/SPI/I2C), TCPWM (8 channels), SAR ADC
- Clock control via PERI peripheral clock dividers

## Prerequisites

This module requires a patched version of `hal_infineon` with PSoC 4200L device
header support. Use the companion fork:

- `hal_infineon` fork: `https://github.com/<user>/hal_infineon` (branch: `psoc4200l`)

## Usage

Add to your west manifest (`west.yml`):

```yaml
manifest:
  remotes:
    - name: zephyrproject-rtos
      url-base: https://github.com/zephyrproject-rtos
    - name: psoc4200l
      url-base: https://github.com/<user>

  projects:
    - name: zephyr
      remote: zephyrproject-rtos
      revision: main
      import: true

    - name: hal_psoc4200l
      remote: psoc4200l
      path: modules/hal/psoc4200l

    - name: hal_infineon
      remote: psoc4200l
      revision: psoc4200l
      path: modules/hal/infineon
```

## Build

```bash
west build -b cy8c4248lti_l475_custom samples/hello_world
```

## Repository Structure

```
hal_psoc4200l/
├── zephyr/module.yml     # West module declaration
├── soc/                  # PSoC 4200L SoC definition
├── boards/               # Board definitions
├── dts/                  # DeviceTree (CM0, peripherals, clocks, pins)
└── hal/                  # Device headers, SRSS v2 IP header
```

## Architecture Notes

### PSoC 4200L vs PSoC 4100SMax

| Feature | PSoC 4200L | PSoC 4100SMax |
|---------|-----------|---------------|
| CPU | Cortex-M0 | Cortex-M0+ |
| Flash | 256 KB | 384 KB |
| SRSS | SRSSv2 (0x400B0000) | SRSSLT (0x40030000) |
| SCB | 4 blocks | 5 blocks |
| IRQ map | Completely different | - |
| USB | Full-Speed | None |
| CAN | 2.0b × 2 | CAN-FD × 1 |
| UDB | 8 blocks | None |

## License

Apache-2.0
