cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(image_test)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /source SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

link_project(image)

if(${DESKTOP_BUILD})
	link_project_at_path(SOIL ${soil_path})
endif()
