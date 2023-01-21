set(SRC src/shader.cpp)
add_library(shader ${SRC})

target_include_directories(shader PRIVATE include ${CMAKE_SOURCE_DIR}/vendor/glad/include ${CMAKE_SOURCE_DIR}/vendor/glm)