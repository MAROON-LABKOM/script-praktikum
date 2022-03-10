#include <gl/freeglut.h>
GLfloat xt = 0, yt = 0, zt = 0;
void draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -4.0);
  glRotatef(xt, 1.0, 0.0, 0.0);
  glRotatef(yt, 0.0, 1.0, 0.0);
  glRotatef(zt, 0.0, 0.0, 1.0);
  glScalef(2.0, 1.0, 1.0);
  glutWireCube(1.0);
  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

void idle()
{
  xt += 0.03;
  yt += 0.01;
  zt += -0.04;
}

void init()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, 1.0, 0.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, 640, 480);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutCreateWindow("Callback");
  glutDisplayFunc(draw);
  glutIdleFunc(idle);
  init();
  glutMainLoop();
  return 0;
}
