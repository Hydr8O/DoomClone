SET(SRC src/texture.cpp)
add_library(texture STATIC ${SRC})
target_include_directories(texture PRIVATE 
    include 
    ${CMAKE_SOURCE_DIR}/vendor/stb_image/include
    ${CMAKE_SOURCE_DIR}/vendor/glad/include
)