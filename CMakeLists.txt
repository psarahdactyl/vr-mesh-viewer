cmake_minimum_required(VERSION 3.1)
SET(CMAKE_BUILD_TYPE Release)
project(vr-mesh-viewer)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(ROOT "${CMAKE_CURRENT_LIST_DIR}")
message(${ROOT})

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# OpenGL library
if (NOT CMAKE_VERSION VERSION_LESS "3.11")
  cmake_policy(SET CMP0072 NEW)
endif()


# libigl
option(LIBIGL_USE_STATIC_LIBRARY "Use libigl as static library" OFF)

find_package(LIBIGL REQUIRED QUIET)

# Add your project files
include_directories("include/")

file(GLOB SRCFILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAINFILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(${PROJECT_NAME}_bin ${SRCFILES} ${MAINFILES})

target_include_directories(${PROJECT_NAME}_bin SYSTEM PUBLIC ${ROOT}/eigen/)
