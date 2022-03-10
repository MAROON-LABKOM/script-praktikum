#include <gl/freeglut.h>

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
GLfloat xt = 0, yt = 0, zt = 0;

void draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  glTranslatef(0.0, 0.0, -4.0);
  glRotatef(xt, 1.0, 0.0, 0.0);
  glRotatef(yt, 0.0, 1.0, 0.0);
  glRotatef(zt, 0.0, 0.0, 1.0);
  glutSolidCube(1.0);

  glutSwapBuffers();
  glutPostRedisplay();
}

void idle()
{
  xt += 0.03;
  yt += 0.02;
  zt += -0.04;
}

void init()
{
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  gluPerspective(40.0, 1.0, 1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 5.0, /* eye = (0,0,5) */
            0.0, 0.0, 0.0, /* center = (0,0,0) */
            0.0, 1.0, 0.); /* up = Y positif */

  glTranslatef(0.0, 0.0, -1.0);
  glRotatef(60, 1.0, 0.0, 0.0);
  glRotatef(-20, 0.0, 0.0, 1.0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(640, 480);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("Pencahayaan");
  glutDisplayFunc(draw);
  glutIdleFunc(idle);
  init();
  glutMainLoop();
  return 0;
}
