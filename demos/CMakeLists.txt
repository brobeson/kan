find_package(GLUT REQUIRED)

add_executable(triangles)
target_sources(triangles PRIVATE triangles.cpp LoadShaders.cpp LoadShaders.h)
target_link_libraries(triangles PRIVATE GLUT::GLUT GLEW::GLEW OpenGL::GL)
configure_file(triangles.vert "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
configure_file(triangles.frag "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)