/*
  Praktikum Grafika Komputer
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <gl/freeglut.h>
#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360

void createPoint(float x, float y, float point_size)
{
  glPointSize(point_size);
  glBegin(GL_POINTS);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(x, y);
  glEnd();
}

void draw()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  createPoint(0.0f, 0.0f, 10.0f);

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
  glutCreateWindow("Grafkom LABKOM: Titik");
  glutReshapeFunc(window);
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}