#include <GL/glut.h>
#include <iostream>
#include <cmath>
#define BLOCK 5

void block()
{  
	glNewList(BLOCK, GL_COMPILE);
	glPushMatrix();
    glColor3f(1.0f,0.0f,0.0f);
    glScalef(1.2f,1.0f,0.1f);
    glutSolidCube(1.0f);  			
    glColor3f(0.0f,1.0f,0.0f);
    glScalef(1.5f,0.5f,0.1f);
    glutSolidCube(0.9f); 
    glPopMatrix();
    glEndList();
  
}


void display()
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glEnable(GL_DEPTH_TEST);

glRotatef(15.0f,1.0f,0.0f,0.0f);
glBegin(GL_LINES);
 glColor3f(1.0f,1.0f,1.0f);
glVertex3f(-3.5f,-3.0f,5.0f);
glVertex3f(-3.5f,-3.0f,-35.0f);
glVertex3f(3.5f,-3.0f,5.0f);
glVertex3f(3.5f,-3.0f,-35.0f);
glEnd();
glTranslatef(0.0f,-3.0f,0.0f);
block();


glFlush();
glutSwapBuffers();
}

void myinit(void)
{
    glEnable(GL_DEPTH_TEST);}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glutInitWindowSize(1000, 600);
glutCreateWindow("my game");
myinit();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
