# hal_psoc4200l module CMakeLists.txt
# Adds PSoC 4200L-specific HAL headers to the include path

if(CONFIG_SOC_SERIES_PSOC4200L)
  zephyr_include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/../hal/mtb-pdl-cat2-psoc4200l/devices/include
    ${CMAKE_CURRENT_LIST_DIR}/../hal/mtb-pdl-cat2-psoc4200l/devices/include/ip
  )
endif()
