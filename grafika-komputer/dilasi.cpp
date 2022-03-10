#include <gl/freeglut.h>
void draw()
{
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glScalef(2.0f, 2.0f, 2.0f);
  glRectf(-0.18, 0.18, 0.18, -0.18);
  glFlush();
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutCreateWindow("Transformasi Dilasi");
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
