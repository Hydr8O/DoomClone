set(SRC src/application.cpp)
add_library(application ${SRC})
find_package(OpenGL REQUIRED)
target_include_directories(application PRIVATE 
    ${CMAKE_SOURCE_DIR}/lib/application/include 
    ${CMAKE_SOURCE_DIR}/vendor/glad/include
    ${CMAKE_SOURCE_DIR}/lib/shader/include
    ${CMAKE_SOURCE_DIR}/vendor/stb_image/include
    ${CMAKE_SOURCE_DIR}/lib/texture/include
    ${CMAKE_SOURCE_DIR}/lib/camera/include
)
target_link_libraries(application glfw glm glad shader stb_image texture camera)