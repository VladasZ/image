cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(image)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /source SOURCE)
add_library(${PROJECT_NAME} ${SOURCE})

if(${DESKTOP_BUILD})
	link_project_at_path(SOIL ${soil_path})
endif()
