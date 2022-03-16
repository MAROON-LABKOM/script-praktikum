/*
  Praktikum Grafika Komputer
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <gl/freeglut.h>
#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360

void draw()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0f, 1.0f, 1.0f);
  glRectf(-0.18f, 0.18f, 0.18f, -0.18f);

  glFlush();
}

void window(int width, int height)
{
  glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutCreateWindow("Grafkom LABKOM: Lingkaran");
  glutReshapeFunc(window);
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}