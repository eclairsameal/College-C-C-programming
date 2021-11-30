/*
 *  simple.c
 *  This program draws a white rectangle on a black background.
 */

/* E. Angel, Interactive Computer Graphics */
/* A Top-Down Approach with OpenGL, Third Edition */
/* Addison-Wesley Longman, 2003 */


#include <GL/glut.h>         /* glut.h includes gl.h and glu.h*/

GLfloat v[4][2]={{-0.75,-0.75},{-0.75,0.75},{0.75,0.75},{0.75,-0.75}};
GLfloat c[4][2]={{-0.75,-0.75},{-0.75,0.75},{-0.15,-0.15},{0.75,-0.75}};


void display(void)

{
/* clear window */

	 glClear(GL_COLOR_BUFFER_BIT); 

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  

/* draw unit square polygon */
/*
	glBegin(GL_POLYGON);
	 	glVertex2f(-0.5, -0.5);
	 	glVertex2f(-0.5, 0.5);
	 	glVertex2f(0.5, 0.5);
	 	glVertex2f(0.5, -0.5);
	glEnd();
*/
/*
	glBegin(GL_POLYGON);
	 	glVertex2fv(c[1]);
	 	glVertex2fv(c[0]);
	 	glVertex2fv(c[2]);
	 	glVertex2fv(c[3]);
	glEnd();
*/
glBegin (GL_POLYGON); 
	glEdgeFlag(GL_TRUE);
	glVertex2i (0, 0);
	glEdgeFlag(GL_FALSE);
	glVertex2i (2, 0);
	glVertex2i (1, 2); 
	glEdgeFlag(GL_TRUE);
	glVertex2i (3, 2);
	glEdgeFlag(GL_FALSE);
	glVertex2i (2, 4);
glEnd ();

/* flush GL buffers */

	glFlush(); 

}


void init()
{

/* set clear color to black */

/* 	glClearColor (0.0, 0.0, 0.0, 0.0); */
/* set fill  color to white */

/* 	glColor3f(1.0, 1.0, 1.0); */

/* set up standard orthogonal view with clipping */
/* box as cube of side 2 centered at origin */
/* This is default view and these statement could be removed */

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();   
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);  
/*	glOrtho(200,400,30,90,-1.0,1.0); */
}

int main(int argc, char** argv)
{

/* Initialize mode and open a window in upper left corner of screen */
/* Window title is name of program (arg[0]) */

/* 	glutInit(&argc,argv); */
  /*  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0); */
	glutCreateWindow("simple"); 
	glutDisplayFunc(display);
	init();
	glutMainLoop();

}
