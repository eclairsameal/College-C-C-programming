/* eatth.c  */

/* E. Angel, Interactive Computer Graphics */
/* A Top-Down Approach with OpenGL, Third Edition */
/* Addison-Wesley Longman, 2003 */


/* Rotating sphere with color interpolation */

/* Demonstration of use of quad strips and */
/* triangle fans for modeling a sphere by */
/* longitude and latitiude */

/* uses polygons in line mode */
 
/* simple mouse click interface to rotate */

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>


void earth()
{

double x, y, z, thet, phi;
int nlat, nlong;
double c;
x=y=0;
z=1;
glBegin(GL_TRIANGLE_FAN);
glVertex3d(x,y,z);
c=3.14159/180.0;
z=sin(c*80.0);
for(thet=-180.0; thet<=180.0;thet+=20.0)
{
	x=sin(c*thet)*cos(c*80.0);
	y=cos(c*thet)*cos(c*80.0);
	glVertex3d(x,y,z);
}
glEnd();
x=y=0;
z=-1;
glBegin(GL_TRIANGLE_FAN);
glVertex3d(x,y,z);
z=-sin(c*80.0);
for(thet=-180.0; thet<=180.0;thet+=20.0)
{
	x=sin(c*thet)*cos(c*80.0);
	y=cos(c*thet)*cos(c*80.0);
	glVertex3d(x,y,z);
}
glEnd();
for(phi=-80.0; phi<=80.0; phi+=20.0)
{
	glBegin(GL_QUAD_STRIP);
	for(thet=-180.0; thet<=180.0;thet+=20.0)
	{
		x=sin(c*thet)*cos(c*phi);
		y=cos(c*thet)*cos(c*phi);
		z=sin(c*phi);
		glVertex3d(x,y,z);
		x=sin(c*thet)*cos(c*(phi+20.0));
		y=cos(c*thet)*cos(c*(phi+20.0));
		z=sin(c*(phi+20.0));
		glVertex3d(x,y,z);
	}
	glEnd();
}
}

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;

void display(void)
{
/* display callback, clear frame buffer and z buffer,
   rotate cube and draw, swap buffers */

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

 earth();

 glFlush();
 glutSwapBuffers();
}

void spinEarth()
{

/* Idle callback, spin cube 2 degrees about selected axis */

	theta[axis] += 2.0;
	if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
	/* display(); */
	glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{

/* mouse callback, selects an axis about which to rotate */

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) theta[0]+=2;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) theta[1]+=2;
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) theta[2]+=2;
	glutPostRedisplay();
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
    glMatrixMode(GL_MODELVIEW);
}

void
main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* need both double buffering and z buffer */

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("sphere");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	glutIdleFunc(NULL);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glutMainLoop();
}
