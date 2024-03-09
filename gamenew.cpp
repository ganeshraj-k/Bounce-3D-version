#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <string>
#define BALL 1
#define STRIPES 2
#define PATCH 3
#define WALL1 4
#define WALL2 6
#define WALL3 7

#define BLOCK 5

using namespace std;

GLfloat zb=0.0f,xb=1.5f,angb=0.0f,yb=0.0f; //ball coordinates
GLfloat x2[2],y2=0.0f,z2[6]; //block coordinates
GLfloat blockspeed = 0.09f;
int j=0, top=0,k=0; //jump flag
GLfloat reft=0,xt;
int it;
int gameon = 1; 
GLfloat zm = 0.0f;
GLfloat zw = 0.0f;

//ball material variables
GLfloat mat_ambient_b[] ={ 0.1745f, 0.01175f, 0.01175f, 0.55f };
GLfloat mat_diffuse_b[] ={0.61424f, 0.04136f, 0.04136f, 0.55f };
GLfloat mat_specular_b[] ={0.727811f, 0.626959f, 0.626959f, 0.55f };
GLfloat shine_b[] ={76.8f} ;




    void setmaterial(){
            //here you set materials, you must declare each one of the colors global or locally like this:
            float MatAmbient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
            float MatDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            float MatSpecular[] = { 0.1f, 0.1f, 0.0f, 0.1f };
            float MatShininess = 60;
            float black[] = {0.0f,0.0f,0.0f,1.0f};
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
            glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);
            glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
    }

void ball()
{
	glNewList(BALL, GL_COMPILE);
	glPushMatrix();

  setmaterial();
  glColor3f(0.1f,0.9f,0.7f);
  
	glutWireSphere(0.6f,30,30);
    glPopMatrix();
	glEndList();
	
}

void block()
{  
	glNewList(BLOCK, GL_COMPILE);
	glPushMatrix();
    glColor3f(1.0f,0.398039f,0.0f);
    glScalef(1.2f,1.0f,0.6f);
    glutSolidCube(1.0f);  			
    glColor3f(0.30f,0.30f,0.6f);
    glScalef(1.5f,1.5f,1.0f);
    glutSolidCube(0.9f); 
    glPopMatrix();
    glEndList();
  
}

void stripe()
{glNewList(STRIPES, GL_COMPILE);
glPushMatrix();
glScalef(0.07f,1.0f,0.2f);
glTranslatef(0.0f,2.0f,15.0f);
glColor3f(1.0f,1.0f,1.0f);
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glVertex3f(2.9f,-3.0f,-5.0f);
glVertex3f(2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-15.0f);
glVertex3f(-2.9f,-3.0f,-5.0f);
glEnd();
glPopMatrix();
glEndList();
} 

void stripeshow()
{ 

glPushMatrix();
glTranslatef(0.0f,0.0f,zm);
glCallList(STRIPES);
glTranslatef(0.0f,0.0f,-3.0f);
glCallList(STRIPES);
glTranslatef(0.0f,0.0f,-3.0f);
glCallList(STRIPES);
glTranslatef(0.0f,0.0f,-3.0f);
glCallList(STRIPES);
glTranslatef(0.0f,0.0f,-3.0f);
glCallList(STRIPES);
glTranslatef(0.0f,0.0f,15.0f);
glCallList(STRIPES);

glPopMatrix();

}


void wall()
{
glNewList(WALL1,GL_COMPILE);
glPushMatrix();
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glColor3f(0.556863f,0.137255f ,0.137255f);
glVertex3f(6.0f,-3.0f,-24.0f);
glVertex3f(6.0f,-3.0f,-18.0f);
glVertex3f(6.0f,3.0f,-18.0f);
glVertex3f(6.0f,3.0f,-24.0f);
glEnd();
glPopMatrix();
glEndList();

glNewList(WALL2,GL_COMPILE);
glPushMatrix();
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f ,1.0f);
glVertex3f(6.0f,-3.0f,-24.0f);
glVertex3f(6.0f,-3.0f,-18.0f);
glVertex3f(6.0f,3.0f,-18.0f);
glVertex3f(6.0f,3.0f,-24.0f);
glEnd();
glPopMatrix();
glEndList();

glNewList(WALL3,GL_COMPILE);
glPushMatrix();
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_QUADS);
glColor3f(0.184314f,0.309804f,0.309804f);
glVertex3f(6.0f,-3.0f,-24.0f);
glVertex3f(6.0f,-3.0f,-18.0f);
glVertex3f(6.0f,3.0f,-18.0f);
glVertex3f(6.0f,3.0f,-24.0f);
glEnd();
glPopMatrix();
glEndList();
}


void wallshow()
{


glTranslatef(0.0f,0.0f,zw);
glTranslatef(0.0f,0.0f,-6.0f);
glCallList(WALL1);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL3);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL1);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL3);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL1);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL3);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL1);


glTranslatef(-12.0f,0.0f,-36.0f);
glCallList(WALL1);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL3);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL1);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL3);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL1);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL3);
glTranslatef(0.0f,0.0f,6.0f);
glCallList(WALL1);


}

void wallanim(){
  if(zw<6.0f)
  zw = zw + blockspeed;
else
  zw = 0.0f;

}

void ballanim()
{
glPushMatrix();
glColor3f(0.0f,0.0f,1.0f);
glTranslatef(xb,-2.0f+yb,1.5f+zb);
if(zb >= -3.2f)
zb = zb -blockspeed;
angb = angb + 1.2f;
glRotatef(-15.0f-angb,1.0f,0.0f,0.0f);
glCallList(BALL);
glPopMatrix();
}

void blockanim()
{
	glPushMatrix();

	glTranslatef(x2[0],-3.0f+y2,z2[0]);
    glCallList(BLOCK);
    glPopMatrix();
     
    glPushMatrix(); 

    glTranslatef(x2[1],-3.0f+y2,z2[1]);
    glCallList(BLOCK);
    glPopMatrix();
    
    glPushMatrix();

    glTranslatef(x2[2],-3.0f+y2,z2[2]);
    glCallList(BLOCK);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f,0.0f,30.0f);
    glTranslatef(x2[3],-3.0f+y2,z2[3]);
    glCallList(BLOCK);
    glPopMatrix();
}



int hit(GLfloat z,int i)
{ if(x2[i] == xb && (yb>=-0.1f && yb <= 0.6f) &&( z <= -1.75f && z >= -2.00f))
   return 1;
   else 
   	return 0;
}


void blockmove()
{ 

  int i;


for(i=0 ; i<4 ; i++)
{
	if(z2[i] <= 1.5f)
		{if(hit(z2[i],i) )
             	{gameon = 0;}
            z2[i] = z2[i] + blockspeed;
		}
	else
		z2[i] = rand()%10 - 20;
}


  
}


void jump()
{  
if( j == 1){
if(top == 0){

    if(yb<2.0f)
       yb = yb+0.10f;
    else
      top = 1;}

else if(top == 1)
   {
     if(yb>0.0f)
     yb=yb-0.10f;
     else{
        top = 0;
         j = 0;}
   }
}
}



void stripemove()
{
  if(zm < 3.0f)
    zm = zm + blockspeed;

  else
    zm = 0.0f;
}


void animate()
{   
	if(gameon){
	blockmove();
  stripemove();
  wallanim();
  

	if(j)
	{jump();}
	glutPostRedisplay();

   }

	blockspeed = blockspeed + 0.00005f;
    
}


void keyboard(unsigned char key, int x, int y)
{ 
	switch(key)
	{
		case 'w':
		j = 1;
		break;
		case 'd':
        xb = 1.5f;
        break;
        case 'a' :
        xb = -1.5f;
        break;
        };


}

void timer(int value) {
       // Post re-paint request to activate display()
   glutTimerFunc(10, timer, 0); // next timer call milliseconds later
   reft = reft+10;
}

void display()
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glEnable(GL_DEPTH_TEST);

glPushMatrix();
glRotatef(15.0f,1.0f,0.0f,0.0f);
glBegin(GL_QUADS);
 glColor3f(0.2f,0.2f,0.2f);
glVertex3f(3.5f,-3.0f,-35.0f);
glVertex3f(-3.5f,-3.0f,-35.0f);
glVertex3f(-3.5f,-3.0f,5.0f);
glVertex3f(3.5f,-3.0f,5.0f);
glEnd();
glBegin(GL_QUADS);
 glColor3f(0.0f,0.8f,0.2f);
glVertex3f(-3.5f,-3.0f,-35.0f);
glVertex3f(-6.0f,-3.0f,-35.0f);
glVertex3f(-6.0f,-3.0f,5.0f);
glVertex3f(-3.5f,-3.0f,5.0f);
glEnd();
glBegin(GL_QUADS);
 glColor3f(0.0f,0.8f,0.2f);
glVertex3f(3.5f,-3.0f,-35.0f);
glVertex3f(6.0f,-3.0f,-35.0f);
glVertex3f(6.0f,-3.0f,5.0f);
glVertex3f(3.5f,-3.0f,5.0f);
glEnd();
//sky blue
glBegin(GL_QUADS);
 glColor3f(0.196078f,0.6f,0.8f);
glVertex3f(-100.0f,-3.0f,-24.0f);
glVertex3f(100.0f,-3.0f,-24.0f);
glVertex3f(100.0f,15.0f,-24.0f);
glVertex3f(-100.0f,15.0f,-24.0f);
glEnd();


ballanim();
glColor3f(1.0f,1.0f,1.0f);
stripeshow();
blockanim();
wallshow();
glPopMatrix();



glFlush();
glutSwapBuffers();
}




void myinit(void)
{
    glEnable(GL_DEPTH_TEST);
    glRotatef(10.0f,1.0f,0.0f,0.0f);
    ball();
    wall();
   
    block();
    stripe();

  
    z2[0] = -15.0f;
z2[1] = -15.0f;
z2[2] = -15.0f;
z2[3] = -15.0f;
x2[1] = -1.5f;
x2[0] = 1.5f;
x2[3] = -1.5f;
x2[2] = 1.5f;
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
glutIdleFunc(animate);

glutKeyboardFunc(keyboard);
//glutSpecialFunc(special);
glutTimerFunc(0, timer, 0);

glutMainLoop();

return 0;
}
