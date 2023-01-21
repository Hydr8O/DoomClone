SET(SRC src/stb_image.cpp)
add_library(stb_image STATIC ${SRC})
target_include_directories(stb_image PRIVATE include)