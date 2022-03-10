/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <gl/freeglut.h>

void draw()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glPointSize(5.0f);
  glBegin(GL_POINTS);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(0.0f, 0.0f);
  glEnd();

  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(480, 480);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutCreateWindow("Grafkom LABKOM: Titik");
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
