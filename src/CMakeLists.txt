cmake_minimum_required(VERSION 3.12)

project(hotwire-lite-v1.0)

set(CMAKE_C_STANDARD 99)

SET(CMAKE_C_COMPILER /usr/bin/gcc)
#SET(CMAKE_C_COMPILER /usr/bin/avr-gcc)
##SET(CMAKE_CXX_COMPILER /usr/bin/avr-g++)

# Define some constants
#set(AVR_MCU "atmega328p")
#set(AVR_SPEED "20000000")
#set(AVR_OPT "s")
#
## Define compiler flags
#add_definitions("-mmcu=${AVR_MCU}")
#add_definitions("-DF_CPU=${AVR_SPEED}")
#add_definitions("-O${AVR_OPT}")
#add_definitions("-pedantic")

add_definitions("-Wall")
add_definitions("-Werror")

# Summarize the flags
message("")
message("AVR-GCC OPTIONS ENABLED:")
message("    Target MCU: ${AVR_MCU}")
message("    MCU Speed: ${AVR_SPEED}Hz")
message("    Optimization: -O${AVR_OPT}")
message("")

include_directories(.)

add_executable(main main.c filter/SkippingAverage.c filter/SkippingAverage.h)

