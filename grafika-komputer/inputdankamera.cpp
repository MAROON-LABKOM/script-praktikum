#include <gl/freeglut.h>
#include <math.h>

float angle = 0.0f;
float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;
float deltaAngle = 0.0f;
float deltaMove = 0;

void changeSize(int w, int h)
{
  if (h == 0)
  {
    h = 1;
  }
  float ratio = w * 1.0 / h;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, w, h);
  gluPerspective(45.0f, ratio, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void drawSnowMan()
{
  glColor3f(1.0f, 1.0f, 1.0f);

  glTranslatef(0.0f, 0.75f, 0.0f);
  glutSolidSphere(0.75f, 20, 20);

  glTranslatef(0.0f, 1.0f, 0.0f);
  glutSolidSphere(0.25f, 20, 20);

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef(0.05f, 0.10f, 0.18f);
  glutSolidSphere(0.05f, 10, 10);
  glTranslatef(-0.1f, 0.0f, 0.0f);
  glutSolidSphere(0.05f, 10, 10);
  glPopMatrix();

  glColor3f(1.0f, 0.5f, 0.5f);
  glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
  glutSolidCone(0.08f, 0.5f, 10, 2);
}

void computePos(float deltaMove)
{
  x += deltaMove * lx * 0.1f;
  z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle)
{
  angle += deltaAngle;
  lx = sin(angle);
  lz = -cos(angle);
}

void renderScene()
{
  if (deltaMove)
  {
    computePos(deltaMove);
  }

  if (deltaAngle)
  {
    computeDir(deltaAngle);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(x, 1.0f, z,
            x + lx, 1.0f, z + lz,
            0.0f, 1.0f, 0.0f);

  glColor3f(0.9f, 0.9f, 0.9f);
  glBegin(GL_QUADS);
  glVertex3f(-100.0f, 0.0f, -100.0f);
  glVertex3f(-100.0f, 0.0f, 100.0f);
  glVertex3f(100.0f, 0.0f, 100.0f);
  glVertex3f(100.0f, 0.0f, -100.0f);
  glEnd();

  for (int i = -3; i < 3; i++)
  {
    for (int j = -3; j < 3; j++)
    {
      glPushMatrix();
      glTranslatef(i * 10.0, 0, j * 10.0);
      drawSnowMan();
      glPopMatrix();
    }
  }

  glutSwapBuffers();
}

void pressKey(int key, int xx, int yy)
{

  switch (key)
  {
  case GLUT_KEY_LEFT:
    deltaAngle = -0.01f;
    break;
  case GLUT_KEY_RIGHT:
    deltaAngle = 0.01f;
    break;
  case GLUT_KEY_UP:
    deltaMove = 0.5f;
    break;
  case GLUT_KEY_DOWN:
    deltaMove = -0.5f;
    break;
  }
}

void releaseKey(int key, int x, int y)
{

  switch (key)
  {
  case GLUT_KEY_LEFT:
  case GLUT_KEY_RIGHT:
    deltaAngle = 0.0f;
    break;
  case GLUT_KEY_UP:
  case GLUT_KEY_DOWN:
    deltaMove = 0;
    break;
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(320, 320);

  glutCreateWindow("Boneka Salju");
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  glutSpecialFunc(pressKey);
  glutIgnoreKeyRepeat(1);
  glutSpecialUpFunc(releaseKey);

  glEnable(GL_DEPTH_TEST);
  glutMainLoop();

  return 1;
}
