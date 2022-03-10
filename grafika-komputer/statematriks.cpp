#include <gl/freeglut.h>

void draw()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();

  glPushMatrix();
  glRotatef(50.0f, 0.0f, 0.0f, 1.0f);
  glColor3f(0.0f, 0.0f, 1.0f);
  glRectf(-0.3, 0.18, 0.18, -0.3);
  glPopMatrix();

  glPushMatrix();
  glScalef(2.0f, 2.0f, 2.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glRectf(-0.18, 0.18, 0.04, -0.04);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-0.50, 0.50, 0);
  glColor3f(1.0f, 0.0f, 0.0f);
  glRectf(-0.18, 0.18, 0.2, -0.18);
  glPopMatrix();

  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutCreateWindow("Segitiga");
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}
