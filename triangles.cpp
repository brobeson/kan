// clang-format off
#include <GL/glew.h>
#include <GL/freeglut.h>
// clang-format on

namespace kan {
void display() {
  static const float black[] = {0.0f, 0.0f, 0.0f, 0.0f};
  glClearBufferfv(GL_COLOR, 0, black);
}
} // namespace kan

int main(int argc, char *argv[]) {
  glewInit();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(150, 250);
  glutInitWindowSize(800, 800);
  [[maybe_unused]] auto nWindow{glutCreateWindow("Kan")};
  glutSetIconTitle("Kan Icon Title");
  glutDisplayFunc(kan::display);
  glutMainLoop();
  return 0;
}