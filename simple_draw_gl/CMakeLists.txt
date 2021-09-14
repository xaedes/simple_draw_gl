cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME simple_draw_gl)
project( ${PROJECT_NAME} )

include("compiler_options.cmake")

add_library(
    ${PROJECT_NAME} 
    STATIC 
    src/shader/default_shaders.cpp
    src/shader/replace_string.cpp
    src/check_gl_error.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm)

target_link_libraries(${PROJECT_NAME} PUBLIC gl_classes)
target_link_libraries(${PROJECT_NAME} PUBLIC chunky_mem)
target_link_libraries(${PROJECT_NAME} PUBLIC transform_tree_glm)

