
// for MS Windows
#include <GL/glut.h>
#include <iostream>
#include <cmath>

GLfloat whiteSpecularLight[] = {1.0, 1.0, 1.0};
GLfloat mat_specular[] = {0.0, 0.0, 1.0, 1.0};
GLfloat mat_ambient[] ={0.0, 0.0, 1.0, 1.0};
GLfloat mat_diffuse[] ={0.0, 0.0, 1.0, 1.0};
GLfloat mat_shininess[] ={128.0 * 0.4};

GLfloat mat_specular2[] ={0.508273, 0.508273, 0.508373};
GLfloat mat_ambient2[] ={0.19225, 0.19225, 0.19225};
GLfloat mat_diffuse2[] ={0.50754, 0.50754, 0.50754};
GLfloat mat_shininess2[] ={128.0 * 0.6};

GLfloat mat_specular3[] = {1.0, 1.0, 0.0};
GLfloat mat_ambient3[] ={1.0, 1.0, 0.0};
GLfloat mat_diffuse3[] ={1.0, 1.0, 0.0};
GLfloat mat_shininess3[] ={0.0 * 0.0};

GLfloat reftime=15.0f,xt=0,yt=0,zt=0,zm=0,ang=0,zb=0,reft=0,jint=0,zw=0;
int top=0;

void jump()
{

if(top == 0)
   {
if(yt<2.5f)
    yt = yt+0.15f;
else
    top = 1;
   }
else if(top == 1)
   {
     if(yt>0.0f)
     yt=yt-0.15f;
     else
        top = 0;

   }



}

void trans1()
{
  if(zt <= 5.0f)
   {

   zt = zt+0.01f;

   }




ang = ang+0.9f;

}

void trans3()
{
  if(zb <= 20.0f)
    zb = zb+0.1f;
else
    zb = 0;

}

void trans2()
{
if(zm <= 15.0f)
    zm = zm+0.1f;
else
    zm = 0;
}
void transw()
{
if(zw <= 7.0f)
    zw = zw+0.1f;
else
    zw = 0;
}

void SetMaterial(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[])
{

  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_SHININESS, shin);
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
}

void display()
{

glClearColor(0.0, 0.0, 0.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glEnable(GL_DEPTH_TEST);

//glRotatef(-20.0f,-4.0f,0.0f,0.0f);
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
glTranslatef(0.0f,0.0f,zm);
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
trans2();

//side walls
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
transw();

//sphere
glPushMatrix();
glColor3f(0.0f,0.0f,1.0f);
glTranslatef(1.5f+xt,-2.0f+yt,1.5f-zt);
glRotatef(-15.0f-ang,1.0f,0.0f,0.0f);
glutWireSphere(0.8f,20,20);
glPopMatrix();
trans1();

//blocks
glPushMatrix();
glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
glColor3f(1.0f,1.0f,1.0f);
glScalef(0.6f,0.5f,0.5f);
glTranslatef(1.5f,0.0f,-15.0f+zb);
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glBegin(GL_QUADS);
//bottom face
glVertex3f(1.0f,-3.0f,0.6f);
glVertex3f(1.0f,-3.0f,-2.0f);
glVertex3f(-1.0f,-3.0f,-2.0f);
glVertex3f(-1.0f,-3.0f,0.6f);

//top face
glVertex3f(1.0f,-1.0f,0.6f);
glVertex3f(1.0f,-1.0f,-2.0f);
glVertex3f(-1.0f,-1.0f,-2.0f);
glVertex3f(-1.0f,-1.0f,0.6f);

//right face
glVertex3f(1.0f,-3.0f,-2.0f);
glVertex3f(1.0f,-3.0f,0.6f);
glVertex3f(1.0f,-1.0f,0.6f);
glVertex3f(1.0f,-1.0f,-2.0f);

//left face
glVertex3f(-1.0f,-3.0f,-2.0f);
glVertex3f(-1.0f,-3.0f,0.6f);
glVertex3f(-1.0f,-1.0f,0.6f);
glVertex3f(-1.0f,-1.0f,-2.0f);

glColor3f(0.0f,1.0f,1.0f);
glVertex3f(-1.0f,-3.0f,0.6f);
glVertex3f(1.0f,-3.0f,0.6f);
glVertex3f(1.0f,-1.0f,0.6f);
glVertex3f(-1.0f,-1.0f,0.6f);


glEnd();
glPopMatrix();
trans3();


glFlush();
glutSwapBuffers();

}


void special(int key, int x, int y)
{

  int i = 0;

  switch (key) {
    /* start of view position functions */
  case GLUT_KEY_RIGHT:{
     xt = 0.25f;
    }
    break;
  case GLUT_KEY_LEFT:{
     xt = -2.75f;
    }
    break;
  case GLUT_KEY_UP:{
    jump();
    }
    break;


  }

    glutPostRedisplay();
}




void myinit(void)
{
    glEnable(GL_DEPTH_TEST);

}
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(reftime, timer, 0); // next timer call milliseconds later
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
glutInitWindowSize(1000, 600);
glutCreateWindow("my game");
myinit();
glutDisplayFunc(display);
glutReshapeFunc(myReshape);
//glutKeyboardFunc(keyboard);
glutSpecialFunc(special);
glutTimerFunc(0, timer, 0);
glPointSize(2.0);
glutMainLoop();

return 0;
}
