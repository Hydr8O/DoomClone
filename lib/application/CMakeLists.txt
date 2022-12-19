set(SRC src/application.cpp)
add_library(application ${SRC})
target_include_directories(application PRIVATE include)