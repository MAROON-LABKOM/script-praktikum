/*
  Praktikum Grafika Komputer
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <gl/freeglut.h>
#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360

void createLine(float from_x, float from_y, float to_x, float to_y, float line_size)
{
  glLineWidth(line_size);
  glBegin(GL_LINES);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(from_x, from_y);
  glVertex2f(to_x, to_y);
  glEnd();
}

void draw()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  createLine(-0.5f, -0.5f, 0.5f, 0.5f, 10.0f);

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
  glutCreateWindow("Grafkom LABKOM: Garis");
  glutReshapeFunc(window);
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}