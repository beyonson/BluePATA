cmake_minimum_required(VERSION 3.26)
set(CMAKE_TOOLCHAIN_FILE /home/garrett/git/bluepata/CMakeToolchains.txt)
project(BluePATA)

## add sub directories
include_directories(include)

## create executable
set (SOURCES src/main.c 
    include/stm32f10x.h 
    include/core_cm3.h 
    include/system_stm32f10x.h 
    include/core_cmFunc.h 
    include/core_cmInstr.h 
    include/cmsis_gcc.h)

add_executable(${PROJECT_NAME} ${SOURCES})
