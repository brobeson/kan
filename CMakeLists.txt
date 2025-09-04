cmake_minimum_required(VERSION 3.21)
project(kan LANGUAGES CXX)

option(
  KAN_BUILD_DEMOS
  "Build Kan's demonstration applications. Default ${PROJECT_IS_TOP_LEVEL}"
  ${PROJECT_IS_TOP_LEVEL}
)
option(
  KAN_BUILD_DOCS
  "Build Kan's documentation. Default: ${PROJECT_IS_TOP_LEVEL}"
  ${PROJECT_IS_TOP_LEVEL}
)
option(
  KAN_BUILD_TESTS
  "Build Kan's tests. Default: ${PROJECT_IS_TOP_LEVEL}"
  ${PROJECT_IS_TOP_LEVEL}
)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
add_subdirectory(kan)

if(KAN_BUILD_DEMOS)
  add_subdirectory(demos)
endif()
if(KAN_BUILD_DOCS)
  add_subdirectory(docs)
endif()
if(KAN_BUILD_TESTS)
  add_subdirectory(tests)
endif()
