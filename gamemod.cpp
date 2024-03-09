#include <iostream>
#include <GL/glut.h>


GLfloat xb=1.5f,yb=-2.0f,zb=1.5f,ang=0;//ball co-ordinates
GLfloat bz =0.0f;
GLfloat zl,zw;
GLfloat reftime = 15,reft = 0;//z coordinate of road stripes
#define BALL_LIST 1
#define ROAD_LIST 2
#define WALLS_LIST 3
int gameon = 1;

void animball()
{
if(bz <= 5.0f)
   {bz = bz+0.01f;}

ang = ang+0.9f;
}

void animroadstripes()
{
if(zl <= 15.0f)
    zl = zl+0.1f;
else
    zl = 0;
}

void animwalls()
{
if(zw <= 7.0f)
    zw = zw+0.1f;
else
    zw = 0;
}
void ball()
{
    glNewList(BALL_LIST,GL_COMPILE);
    glPushMatrix();
    glPushMatrix();
    glColor3f(0.0f,0.0f,1.0f);
    glTranslatef(xb,yb,zb-bz);
    glRotatef(-15.0f-ang,1.0f,0.0f,0.0f);
    glutWireSphere(0.8f,20,20);
    glPopMatrix();
    glEndList();
}

void road()
{
glNewList(ROAD_LIST,GL_COMPILE);
    //road edges
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex3f(-3.5f,-3.0f,1.0f);
glVertex3f(-3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,1.0f);
glVertex3f(3.5f,-3.0f,-24.0f);
glEnd();

//road lines
glPushMatrix();
glScalef(0.1f,1.0f,0.4f);
glTranslatef(0.0f,0.0f,zl);
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,0.0f);
glVertex3f(2.9f,-3.0f,-5.0f);
glVertex3f(2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-5.0f);
glEnd();

glTranslatef(0.0f,0.0f,-15.0f);
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,1.0f);
glVertex3f(2.9f,-3.0f,-5.0f);
glVertex3f(2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-5.0f);
glEnd();

glTranslatef(0.0f,0.0f,-15.0f);
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,0.0f);
glVertex3f(2.9f,-3.0f,-5.0f);
glVertex3f(2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-5.0f);
glEnd();

glTranslatef(0.0f,0.0f,-15.0f);
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,1.0f);
glVertex3f(2.9f,-3.0f,-5.0f);
glVertex3f(2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-5.0f);
glEnd();

glTranslatef(0.0f,0.0f,-15.0f);
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,0.0f);
glVertex3f(2.9f,-3.0f,-5.0f);
glVertex3f(2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-5.0f);
glEnd();

glTranslatef(0.0f,0.0f,75.0f);
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,1.0f);
glVertex3f(2.9f,-3.0f,-5.0f);
glVertex3f(2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-5.0f);
glEnd();
glPopMatrix();
glEndList();
}

void walls()
{


glNewList(WALLS_LIST,GL_COMPILE);
glPushMatrix();
glTranslatef(0.0f,0.0f,zw);
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glVertex3f(3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-24.0f);
glEnd();

glTranslatef(0.0F,0.0F,7.0F);

glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glVertex3f(3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-24.0f);
glEnd();
glTranslatef(0.0f,0.0f,7.0f);

glBegin(GL_QUADS);
glColor3f(0.0f,1.0f,0.0f);
glVertex3f(3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-24.0f);
glEnd();

glTranslatef(0.0f,0.0f,7.0f);

glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,0.0f);
glVertex3f(3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-24.0f);
glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,0.0f,zw);
glTranslatef(-7.0f,0.0f,0.0f);
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,1.0f);
glVertex3f(3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-24.0f);
glEnd();

glTranslatef(0.0F,0.0F,7.0F);

glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);
glVertex3f(3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-24.0f);
glEnd();
glTranslatef(0.0f,0.0f,7.0f);

glBegin(GL_QUADS);
glColor3f(0.0f,1.0f,0.0f);
glVertex3f(3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-24.0f);
glEnd();

glTranslatef(0.0f,0.0f,7.0f);

glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,0.0f);
glVertex3f(3.5f,-3.0f,-24.0f);
glVertex3f(3.5f,-3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-17.0f);
glVertex3f(3.5f,3.0f,-24.0f);
glEnd();

glPopMatrix();
glEndList();

}



void animate()
{
    animball();
    animroadstripes();
    animwalls();
}



void display() {
glClearColor(0.0, 0.0, 0.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glEnable(GL_DEPTH_TEST);

glCallList(BALL_LIST);
glCallList(ROAD_LIST);
glCallList(WALLS_LIST);
animball();
animroadstripes();
animwalls();
glFlush();
glutSwapBuffers();
}

void myinit(void)
{
    glEnable(GL_DEPTH_TEST);
     ball();
   walls();
   road();
}
void timer(int value) {
   glutPostRedisplay();

   glutTimerFunc(reftime, timer, 0);

   reft = reft+reftime;
}


void myReshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0, (GLfloat) w / (GLfloat) h, 1.0, 30.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -5.5);
}



int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glutInitWindowSize(600, 600);
glutCreateWindow("my game");
myinit();
glutDisplayFunc(display);
glutReshapeFunc(myReshape);
//glutKeyboardFunc(keyboard);
//glutSpecialFunc(special);
glutTimerFunc(0, timer, 0);
glPointSize(2.0);
glutMainLoop();

return 0;
}
