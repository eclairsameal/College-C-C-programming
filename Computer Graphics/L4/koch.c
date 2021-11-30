/* Koch.c  */

/*
	Purpose: generate Koch curve and snowflake
*/

#include <GL/glut.h>	/* includes gl.h */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



/* Global Variables */
static GLfloat mOldX = 0.0;
static GLfloat mOldY = 0.0;



/*
	Functions
*/

void printHelp( char *progname )
{
	fprintf(stdout,
			"\n%s - Koch curves\n\n"
			"Any key to go to the next iteration\n"
			"Escape key    - exit the program\n\n",
			progname);
}


GLvoid init( GLvoid )
{
        glClearColor( 1.0, 1.0, 1.0, 1.0);
		glColor3f(0.3, 0.25, 0.8);
		glLineWidth(3.0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho( -0.05, 1.05, -0.05, 0.35, -1.0, 1.0 );
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
}

GLvoid keyboard( GLubyte key, GLint x, GLint y)
{
    switch (key)
	{
    case 27:   /* exit when escape key is pressed */
         exit(0);
	break;
	default:
		glutPostRedisplay();
    }
}


GLvoid specialkeys( GLint key, GLint x, GLint y)
{
    switch (key) {
    case GLUT_KEY_F1:   /* print Help information */
         printHelp( "Koch curves" );
         break;
    }
}


GLvoid drawKoch( GLdouble dir, GLdouble len, GLint n)
{
	GLdouble dirRad = 0.0174533 * dir;  /* convert to radians  */
	GLfloat newX = mOldX + len * cos(dirRad);
	GLfloat newY = mOldY + len * sin(dirRad);

	if (n == 0)
	{
		/* Now draw the line */
		glVertex2f(mOldX, mOldY);
		glVertex2f(newX, newY);
		mOldX = newX;
		mOldY = newY;
	}
	else
	{
		n--;          /* reduce the order  */
		len /= 3.0;   /* reduce the length */
		drawKoch(dir, len, n);

		dir += 60.0;
		drawKoch(dir, len, n);

		dir -= 120.0;
		drawKoch(dir, len, n);

		dir += 60.0;
		drawKoch(dir, len, n);
	}
}


GLvoid display( GLvoid )
{
	static int maxLevel = 2;
	maxLevel++;

	glClear( GL_COLOR_BUFFER_BIT );
	/* Do all your OpenGL rendering here */
	glBegin(GL_LINES);

	/* Construct the Koch snowflake - generate Koch curves on
		each side of an equilateral triangle. */
	/*
	mOldX = 0.0; mOldY = 0.0;
	drawKoch(60.0, 1.0, maxLevel);
	mOldX = 0.5; mOldY = sqrt(3)/2.0;
	drawKoch(-60.0, 1.0, maxLevel);
	mOldX = 1.0; mOldY = 0.0;
	drawKoch(-180.0, 1.0, maxLevel);
	*/

	/* single Koch curve :  */
	mOldX = 0.0;
	mOldY = 0.0;
	drawKoch( 0.0, 1.0, maxLevel );

	glEnd();
	glFlush();
}


int main( int argc, char *argv[] )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGB );
	glutCreateWindow( argv[0] );

	init();

    glutKeyboardFunc( keyboard );
    glutSpecialFunc( specialkeys );

	glutDisplayFunc( display );

	printHelp( argv[0] );

	glutMainLoop();

	return 0;
}
