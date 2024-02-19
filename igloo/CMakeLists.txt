add_library(
  igloo
  igloo/shaders.h
  igloo/shaders/program.h
  igloo/shaders/program.cpp
  igloo/shaders/shader.cpp
  igloo/shaders/shader.cpp
)
target_include_directories(igloo PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
add_library(igloo::igloo ALIAS igloo)