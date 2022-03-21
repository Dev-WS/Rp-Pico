cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_testproject C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

# Add blink example
#add_subdirectory(src)
#add_subdirectory(include)
add_subdirectory(rtos)


set(SOURCES 
src/main.c
)

set(INCLUDES 
include/main.h
)


add_subdirectory(lib/Config)
add_subdirectory(lib/Infrared)
add_subdirectory(lib/OLED)
add_subdirectory(lib/Icm20948)
add_subdirectory(lib/LCD)
add_subdirectory(lib/Fonts)
add_subdirectory(lib/GUI)
add_subdirectory(examples)



#添加头文件目录
include_directories(examples)
include_directories(./lib/Config)
include_directories(./lib/GUI)
include_directories(./lib/Icm20948)
include_directories(./lib/LCD)
include_directories(./lib/Infrared)
include_directories(./lib/OLED)


add_executable(src ${SOURCES} ${INCLUDES})

# target_include_directories(include PRIVATE
# ${PROJECT_SOURCE_DIR}/include)


#target_link_libraries(src pico_stdlib hardware_spi freertos)

target_link_libraries(src freertos examples LCD OLED Infrared Icm20948 GUI Fonts Config pico_stdlib hardware_spi)

# create map/bin/hex file etc.
pico_add_extra_outputs(src)


add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )
