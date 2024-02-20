add_executable(demo triangles.cpp LoadShaders.cpp LoadShaders.h)
target_link_libraries(demo PRIVATE GLUT::GLUT GLEW::GLEW OpenGL::GL igloo::igloo)
configure_file(triangles.vert "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
configure_file(triangles.frag "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)