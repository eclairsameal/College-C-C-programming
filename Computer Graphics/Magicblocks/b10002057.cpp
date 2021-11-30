#include <GL/glut.h>
//#include <ctime>
#define FBOX 1
#define BBOX 2
#define RBOX 3
#define LBOX 4
#define UBOX 5
#define DBOX 6
void display1()
{
    int i,j;
 glClear(GL_COLOR_BUFFER_BIT);
   
 glNewList(FBOX, GL_COMPILE);
     glBegin(GL_POLYGON);
   glVertex3f(-1.0, -1.0, 1.0);
   glVertex3f(1.0, -1.0, 1.0);
   glVertex3f(1.0, 1.0, 1.0);
   glVertex3f(-1.0, 1.0, 1.0);
  glEnd();
 glEndList();
 glNewList(BBOX, GL_COMPILE);
     glBegin(GL_POLYGON);
   glVertex3f(-1.0, -1.0, -1.0);
   glVertex3f(-1.0, 1.0, -1.0);
   glVertex3f(1.0, 1.0, -1.0);
   glVertex3f(1.0, -1.0, -1.0);
  glEnd();
 glEndList();
//////////////////////////////////////////////////////////////////////////////////////////
  glNewList(RBOX, GL_COMPILE);
     glBegin(GL_POLYGON);
   glVertex3f(1.0, -1.0, 1.0);
   glVertex3f(1.0, -1.0, -1.0);
   glVertex3f(1.0, 1.0, -1.0);
   glVertex3f(1.0, 1.0, 1.0);
  glEnd();
 glEndList();
  glNewList(LBOX, GL_COMPILE);
     glBegin(GL_POLYGON);
   glVertex3f(-1.0, -1.0, 1.0);
   glVertex3f(-1.0, -1.0, -1.0);
   glVertex3f(-1.0, 1.0, -1.0);
   glVertex3f(-1.0, 1.0, 1.0);
  glEnd();
 glEndList();
  glNewList(UBOX, GL_COMPILE);
     glBegin(GL_POLYGON);
   glVertex3f(-1.0, 1.0, 1.0);
   glVertex3f(1.0, 1.0, 1.0);
   glVertex3f(1.0, 1.0, -1.0);
   glVertex3f(-1.0, 1.0, -1.0);
  glEnd();
 glEndList();
  glNewList(DBOX, GL_COMPILE);
     glBegin(GL_POLYGON);
   glVertex3f(-1.0, -1.0, 1.0);
   glVertex3f(1.0, -1.0, 1.0);
   glVertex3f(1.0, -1.0, -1.0);
   glVertex3f(-1.0, -1.0, -1.0);
  glEnd();
 glEndList();
//////////////////////////////////////////////////////////////////////////////////////////
    for (i=0;i<3;i++) { 
        for (j=0;j<3;j++) {
             glColor3f(1.0, 0.0, 1.0);
             glPushMatrix();
             glScalef(0.2,0.2,1.0);
             glTranslatef(4.0-2.1*i, 4.0-2.1*j, 0.0);
              // glRotatef(45,0.0,0.0,1.0);
              glCallList(FBOX);
              glPopMatrix();
              }
      }
    
 for (i=0;i<3;i++) { 
        for (j=0;j<3;j++) {
             glColor3f(1.0, 0.0, 0.0);
             glPushMatrix();
             glScalef(0.2,0.2,1.0);
             glTranslatef(4.0-2.1*i, 4.0-2.1*j, 0.76);
              glCallList(BBOX);
              glPopMatrix();
              }
      }
//////////////////////////////////////////////////////////////////////////////////////////
 for (i=0;i<3;i++) { 
        for (j=0;j<3;j++) {
             glColor3f(1.0, 1.0, 0.0);
             glPushMatrix();
             glScalef(1.0,0.2,0.2);
    glTranslatef(0.0, 4.0-2.1*i, 4.0-2.1*j);
              glCallList(RBOX);
              glPopMatrix();
              }
      }
 for (i=0;i<3;i++) { 
        for (j=0;j<3;j++) {
             glColor3f(0.0, 1.0, 0.0);
             glPushMatrix();
             glScalef(1.0,0.2,0.2);
    glTranslatef(0.76, 4.0-2.1*i, 4.0-2.1*j);
              glCallList(LBOX);
              glPopMatrix();
              }
      }
 for (i=0;i<3;i++) { 
        for (j=0;j<3;j++) {
             glColor3f(0.0, 1.0, 1.0);
             glPushMatrix();
             glScalef(0.2,1.0,0.2);
    glTranslatef(4.0-2.1*j, 0.0, 4.0-2.1*i);
              glCallList(UBOX);
              glPopMatrix();
              }
      }
 for (i=0;i<3;i++) { 
        for (j=0;j<3;j++) {
             glColor3f(0.0, 0.0, 1.0);
             glPushMatrix();
             glScalef(0.2,1.0,0.2);
    glTranslatef(4.0-2.1*j, 0.76, 4.0-2.1*i);
              glCallList(DBOX);
              glPopMatrix();
              }
      }
	  
//////////////////////////////////////////////////////////////////////////////////////////
    glFlush();
 
}
void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
 /*  Or we can use gluPerspective  */
 
    gluPerspective(45.0, w/h, 5.0, 10.0);
  
    glMatrixMode(GL_MODELVIEW);
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.5,4.5,-4.5,4.5,-4.5,4.5);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,1.0);
    gluLookAt(4, 2, 4, 0, 0, 0, 0, 2, 0);               // µø¨¤
 // glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
}
void mymouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        display1();
    }
 if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        exit(0);
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800);
    glutCreateWindow("Display List");
    myinit();
 glutReshapeFunc(myReshape);
    glutMouseFunc(mymouse);
  
 glutDisplayFunc(display1);
    glutMainLoop();
}