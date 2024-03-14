cmake_minimum_required (VERSION 3.20)
project (c_piscine_tester)

# #################################################################################################
# 
# Compiler options
add_compile_options ("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options ("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# #################################################################################################
# 
# Project-wide variables
set (CMAKE_C_STANDARD 11)
set (INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set (MODULES_DIR ${CMAKE_SOURCE_DIR}/modules)

# #################################################################################################
# 
# Windows and non-Windows specific compilation options
if (WIN32)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /std:c11")
    set (CMAKE_GENERATOR_TOOLSET "host=x64" CACHE STRING "host=x64" FORCE)
else ()
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Os -flto -march=native -finline-functions -funroll-loops -ffast-math -fomit-frame-pointer -s")
endif ()

set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type: Release" FORCE)

# #################################################################################################
# 
# File search
file(GLOB_RECURSE SRC
    ${MODULES_DIR}/*.c
    ${INCLUDE_DIR}/*.c
)

# #################################################################################################
# 
# Executable configuration
add_executable(${PROJECT_NAME}
    ${SRC}
    ${CMAKE_SOURCE_DIR}/main.c
)

# #################################################################################################
# 
# Target include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${INCLUDE_DIR}
)

# #################################################################################################
# 
# Windows and non-Windows specific library configurations
if (WIN32)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
        # Add Windows-specific libraries if needed

    )
else()
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
        # Add non-Windows libraries if needed
        
    )
endif()

# #################################################################################################
# 
# Installation related variables

# #################################################################################################
# 
# Installation configuration
if (WIN32)
    set(INSTALL_DESTINATION "C:/Program Files/${PROJECT_NAME}")
else()
    set(INSTALL_DESTINATION "/usr/local/bin")
endif()

install(TARGETS ${PROJECT_NAME}
    DESTINATION ${INSTALL_DESTINATION}
)