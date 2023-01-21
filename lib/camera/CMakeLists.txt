SET(SRC src/camera.cpp)
add_library(camera STATIC ${SRC})
target_include_directories(camera PRIVATE 
    include
    ${CMAKE_SOURCE_DIR}/vendor/glm
)