cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	include(build/build_tools_generated.cmake)
endif()

setup_project(image)

add_subdirectory(source/image)

if(${DESKTOP_BUILD})
	add_subdirectory(source/image_test)
endif()
