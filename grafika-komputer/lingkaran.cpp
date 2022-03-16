/*
  Praktikum Grafika Komputer
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <gl/freeglut.h>
#include <math.h>
#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 360
#define LINES 360 // Diambil dari derajat lingkaran yaitu 360, artinya butuh 360 titik atau garis untuk membuat lingkaran sempurna

void createCircle(float x, float y)
{
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < LINES; i++)
  {
    float angle = 2 * M_PI * i / LINES;
    glVertex2f(x + (cos(angle) / 5.0f), y + (sin(angle) / 5.0f));
  }
  glEnd();
}

void draw()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  createCircle(0.0f, 0.0f);

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