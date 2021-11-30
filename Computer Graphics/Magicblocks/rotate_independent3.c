/* Rotating cube with color interpolation */

/* Demonstration of use of homogeneous coordinate 
transformations and simple data structure for representing
cube from Chapter 4 */

/*Both normals and colors are assigned to the vertices */
/*Cube is centered at origin so (unnormalized) normals
are the same as the vertex values */

#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
	{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0}, 
	{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};

GLfloat normals[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
	{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0}, 
	{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};

GLfloat colors[][3] = {{0.3,0.3,0.3},{1.0,0.0,0.0},
	{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, 
	{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};

void polygon(int a, int b, int c , int d)
{
/* draw a polygon via list of vertices */

 	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normals[a]);
		glVertex3fv(vertices[a]);
		glColor3fv(colors[b]);
		glNormal3fv(normals[b]);
		glVertex3fv(vertices[b]);
		glColor3fv(colors[c]);
		glNormal3fv(normals[c]);
		glVertex3fv(vertices[c]);
		glColor3fv(colors[d]);
		glNormal3fv(normals[d]);
		glVertex3fv(vertices[d]);
	glEnd();																						
}

void colorcube(void)
{
/* map vertices to faces */

	polygon(0,1,2,3);
	polygon(3,2,6,7);
	polygon(7,4,0,3);
	polygon(1,5,6,2);
	polygon(4,5,1,0);
	polygon(6,5,4,7);
}
static GLint glkey[6][9];
static GLint step,glmask[3][3][3][200];
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;
static GLdouble viewer[]={10.0, 10.0, 10.0};


void top(void){  
     int i;
                               /* Top */
     glPushMatrix();
     glTranslatef(-2.05,2.05,-2.05);
//     for (i=0;i<step;i++)
     for (i=step-1;i>=0;i--){
          if (glmask[0][0][0][i]==1) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[0][0][0][i]==3) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[0][0][0][i]==6) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-2.05,2.05,0.0);
//     for (i=0;i<step;i++){
     for (i=step-1;i>=0;i--){
          if (glmask[0][0][1][i]==1) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[0][0][1][i]==3) glRotatef(90, -1.0, 0.0, 0.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-2.05,2.05,2.05);
//     for (i=0;i<step;i++){
     for (i=step-1;i>=0;i--){
          if (glmask[0][0][2][i]==1) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[0][0][2][i]==3) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[0][0][2][i]==5) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.0,2.05,-2.05);
//     for (i=0;i<step;i++){
     for (i=step-1;i>=0;i--){
          if (glmask[1][0][0][i]==1) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[1][0][0][i]==6) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.0,2.05,0.0);
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.0,2.05,2.05);
//     for (i=0;i<step;i++){
     for (i=step-1;i>=0;i--){         
          if (glmask[1][0][2][i]==1) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[1][0][2][i]==5) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(2.05,2.05,-2.05);
//     for (i=0;i<step;i++){
     for (i=step-1;i>=0;i--){
          if (glmask[2][0][0][i]==1) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[2][0][0][i]==4) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[2][0][0][i]==6) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(2.05,2.05,0.0);
//     for (i=0;i<step;i++){
     for (i=step-1;i>=0;i--){
          if (glmask[2][0][1][i]==1) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[2][0][1][i]==4) glRotatef(90, -1.0, 0.0, 0.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(2.05,2.05,2.05);
//     for (i=0;i<step;i++){
     for (i=step-1;i>=0;i--){
          if (glmask[2][0][2][i]==1) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[2][0][2][i]==4) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[2][0][2][i]==5) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();
             
                               /* Down */
     glPushMatrix();
     glTranslatef(-2.05,-2.05,-2.05);
     for (i=0;i<step;i++){
          if (glmask[0][2][0][i]==2) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[0][2][0][i]==3) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[0][2][0][i]==6) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-2.05,-2.05,0.0);
     for (i=0;i<step;i++){
          if (glmask[0][2][1][i]==2) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[0][2][1][i]==3) glRotatef(90, -1.0, 0.0, 0.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-2.05,-2.05,2.05);
     for (i=0;i<step;i++){
          if (glmask[0][2][2][i]==2) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[0][2][2][i]==3) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[0][2][2][i]==5) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.0,-2.05,-2.05);
     for (i=0;i<step;i++){
          if (glmask[1][2][0][i]==2) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[1][2][0][i]==6) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.0,-2.05,0.0);
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.0,-2.05,2.05);
     for (i=0;i<step;i++){
          if (glmask[1][2][2][i]==2) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[1][2][2][i]==5) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(2.05,-2.05,-2.05);
     for (i=0;i<step;i++){
          if (glmask[2][2][0][i]==2) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[2][2][0][i]==4) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[2][2][0][i]==6) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(2.05,-2.05,0.0);
     for (i=0;i<step;i++){
          if (glmask[2][2][1][i]==2) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[2][2][1][i]==4) glRotatef(90, -1.0, 0.0, 0.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(2.05,-2.05,2.05);
     for (i=0;i<step;i++){
          if (glmask[2][2][2][i]==2) glRotatef(90, 0.0, -1.0, 0.0);
          if (glmask[2][2][2][i]==4) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[2][2][2][i]==5) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();          
     
                             /* Left */
     glPushMatrix();
     glTranslatef(-2.05,0.0,-2.05);
     for (i=0;i<step;i++){
          if (glmask[0][1][0][i]==3) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[0][1][0][i]==6) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-2.05,0.0,0.0);
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-2.05,0.0,2.05);
     for (i=0;i<step;i++){
          if (glmask[0][1][2][i]==3) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[0][1][2][i]==5) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

                   /* Right */
     glPushMatrix();
     glTranslatef(2.05,0.0,-2.05);
     for (i=0;i<step;i++){
          if (glmask[2][1][0][i]==4) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[2][1][0][i]==6) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(2.05,0.0,0.0);
     colorcube();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(2.05,0.0,2.05);
     for (i=0;i<step;i++){
          if (glmask[2][1][2][i]==4) glRotatef(90, -1.0, 0.0, 0.0);
          if (glmask[2][1][2][i]==5) glRotatef(90, 0.0, 0.0, -1.0);
          }
     colorcube();
     glPopMatrix();               
     
                                  /* Front */
    
     glPushMatrix();
     glTranslatef(0.0,0.0,2.05);
     colorcube();
     glPopMatrix();

    
                                /* Back */
    
     glPushMatrix();
     glTranslatef(0.0,0.0,-2.05);
     colorcube();
     glPopMatrix();

}


void spinCube()
{
/* Idle callback, spin cube 2 degrees about selected axis */

	theta[axis] += 0.2;
	if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
	glutPostRedisplay();
}

void kwhole(){

//     glPushMatrix();
     top();
//     glPopMatrix();

     glFlush();

}

void display(void)
{
/* display callback, clear frame buffer and z buffer,
   rotate cube and draw, swap buffers */

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
//	glRotatef(theta[0], 1.0, 0.0, 0.0);

	glRotatef(theta[1], 0.0, 1.0, 0.0);

//	glRotatef(theta[2], 0.0, 0.0, 1.0);

    spinCube();
    kwhole();
	glFlush();
	glutSwapBuffers();
}


void mouse(int btn, int state, int x, int y)
{

/* mouse callback, selects an axis about which to rotate */

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;

	theta[axis]+=2.0;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	display();
}


void keys(unsigned char key, int x, int y)
{
    int i,j;
	if (key=='t'){
       for (i=0;i<3;i++)
           for (j=0;j<3;j++){
               glmask[i][0][j][step]=1;           
               glkey[0][3*i+j]+=1;
               if (glkey[0][3*i+j]==4) glkey[0][3*i+j]=0;
           }
       step+=1;
       }
    if (key=='d'){
       for (i=0;i<3;i++)
           for (j=0;j<3;j++){
               glmask[i][2][j][step]=2;
               glkey[1][3*i+j]+=1;
               if (glkey[1][3*i+j]==4) glkey[1][3*i+j]=0;
           }
       step+=1;
       }
 
    if (key=='l'){
       for (i=0;i<3;i++)
           for (j=0;j<3;j++){
               glmask[0][i][j][step]=3;
               glkey[2][3*i+j]+=1;
               if (glkey[2][3*i+j]==4) glkey[2][3*i+j]=0;
           }
       step+=1;
       }    
    if (key=='r'){
       for (i=0;i<3;i++)
           for (j=0;j<3;j++){
               glmask[2][i][j][step]=4;           
               glkey[3][3*i+j]+=1;
               if (glkey[3][3*i+j]==4) glkey[3][3*i+j]=0;
           }
       step+=1;
       }
    if (key=='f'){
       for (i=0;i<3;i++)
           for (j=0;j<3;j++){
               glmask[i][j][2][step]=5;
               glkey[4][3*i+j]+=1;
               if (glkey[4][3*i+j]==4) glkey[4][3*i+j]=0;
           }
       step+=1;
       }
    if (key=='b'){
       for (i=0;i<3;i++)
           for (j=0;j<3;j++){
               glmask[i][j][0][step]=6;
               glkey[5][3*i+j]+=1;
               if (glkey[5][3*i+j]==4) glkey[5][3*i+j]=0;
           }
       step+=1;
       }

	display();
	
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat) h / (GLfloat) w,
            10.0 * (GLfloat) h / (GLfloat) w, -25.0, 25.0);
    else
        glOrtho(-10.0 * (GLfloat) w / (GLfloat) h,
            10.0 * (GLfloat) w / (GLfloat) h, -10.0, 10.0, -25.0, 25.0);

	/* Or we can use gluPerspective  */
    
//	gluPerspective(90.0, w/h, 1.0, 10.0);  

    glMatrixMode(GL_MODELVIEW);  
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* need both double buffering and z buffer */

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");
    glutReshapeFunc(myReshape);
	glShadeModel(GL_FLAT);
    glutDisplayFunc(display);
    glutIdleFunc(kwhole);
//	glutIdleFunc(spinCube); 
//	glutMouseFunc(mouse);
    glutKeyboardFunc(keys);

	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

    glutMainLoop();
}
