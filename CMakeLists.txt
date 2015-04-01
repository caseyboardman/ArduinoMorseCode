cmake_minimum_required(VERSION 3.1)
project(MorseCode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -I /Applications/Arduino.app//Contents/Resources/Java/hardware/arduino/avr/cores/arduino/")

set(SOURCE_FILES MorseCodePrinter.cpp)
add_executable(MorseCode ${SOURCE_FILES})