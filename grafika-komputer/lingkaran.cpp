#include <math.h>
void draw()
{
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  const int smoothness = 100;
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < smoothness; i++)
  {
    float angle = 2 * M_PI * i / smoothness;
    glVertex2f(cos(angle), sin(angle));
  }
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutCreateWindow("Lingkaran");
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
