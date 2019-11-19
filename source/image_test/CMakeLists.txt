cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(image_test)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /source SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

link_project(image)

if(${NEEDS_CONAN})
conan_target_link_libraries(${PROJECT_NAME})
endif()
