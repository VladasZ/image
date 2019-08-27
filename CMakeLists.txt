cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(${BUILD_DIRECTORY}/build_info.cmake)
include(${BUILD_SCRIPT_PATH})

set(CMAKE_CXX_STANDARD 17)

project(image)

if(${DESKTOP_BUILD})
	add_definitions(-DUI_DESKTOP=1)
	add_definitions(-DIOS=0)
endif()

if(${IOS})
	add_definitions(-DUI_DESKTOP=0)
	add_definitions(-DIOS=1)
endif()

add_subdirectory(source/image)

if(${DESKTOP_BUILD})
	add_subdirectory(source/image_test)
endif()

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  foreach(var ${GIT_DEPENDENCIES})
	add_subdirectory(${var} "${var}/dep_build")
  endforeach()
endif()
