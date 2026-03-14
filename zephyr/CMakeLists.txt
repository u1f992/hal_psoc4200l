# hal_psoc4200l module CMakeLists.txt
# Adds PSoC 4200L-specific HAL headers and compile definitions

if(CONFIG_SOC_SERIES_PSOC4200L)
  # Add PSoC 4200L device headers before hal_infineon headers
  # so our cy8c4248lti_l475.h and cyip_srss_v2.h are found first
  zephyr_include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/../hal/mtb-pdl-cat2-psoc4200l/devices/include
    ${CMAKE_CURRENT_LIST_DIR}/../hal/mtb-pdl-cat2-psoc4200l/devices/include/ip
  )

  # Define the part number macro that infineon_kconfig.h would normally set.
  # This is needed because zephyr's modules/hal_infineon/infineon_kconfig.h
  # does not know about PSoC 4200L series.
  if(CONFIG_SOC_CY8C4248LTI_L475)
    zephyr_compile_definitions(CY8C4248LTI_L475)
    zephyr_compile_definitions(CY8C4248LTI_L475_)
  endif()
endif()
