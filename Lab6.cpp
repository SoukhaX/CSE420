#include <GL/glut.h>

class Point2 {
public:
	float x;
	float y;
	Point2() {
		x = y = 0;
	}

	Point2(float x0, float y0) {
		x = x0;	y = y0;
	}
	
	Point2(const Point2 &p) {
		x = p.x;
		y = p.y;
	}
};

Point2 tween(const Point2 &Q, const Point2 &R, float t)
{
	Point2 P;
	P.x = Q.x + (R.x - Q.x) * t;
	P.y = Q.y + (R.y - Q.y) * t;
	return P;
}

void drawTween(const Point2 A[], const Point2 B[], int n, float t, const Point2 &c)
{
	glColor3f(0, 0, 0);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(1);

	// draw the tween at time t between polylines A and B
	Point2 P0 = tween(A[0], B[0], t);
	Point2 P1 = Point2(P0.x + c.x, P0.y + c.y);
	for (int i = 1; i < n; i++)
	{
		Point2 P, P2;
		if (i == n)
			P = tween(A[0], B[0], t);
		else
			P = tween(A[i], B[i], t);
		P2 = Point2(P.x + c.x, P.y + c.y);
		if (i < n - 1) {
			glBegin(GL_POINTS);
			glVertex2f(P2.x, P2.y);
			glEnd();
		}
		glBegin(GL_LINES);
		glVertex2f(P1.x, P1.y);
		glVertex2f(P2.x, P2.y);
		glEnd();
		P1 = P2;
	}
}

//create two figures for demo use
void makeHand(Point2 A[], Point2 B[])
{
	A[0].x = 1.2;	A[0].y = 9.8; 	A[1].x = 2;		A[1].y = 8;
	A[2].x = 3;		A[2].y = 7; 	A[3].x = 6;		A[3].y = 7;
	A[4].x = 7;		A[4].y = 5;		A[5].x = 7;		A[5].y = 4;

	B[0].x = 1;		B[0].y = 4; 	B[1].x = 2;		B[1].y = 5;
	B[2].x = 3;		B[2].y = 7; 	B[3].x = 6;		B[3].y = 7;
	B[4].x = 7.5;	B[4].y = 5.5;	B[5].x = 8;		B[5].y = 5;
}

void makeBody(Point2 A[], Point2 B[])
{
	A[0].x = 4.5;	A[0].y = 8; 	A[1].x = 4.7;	A[1].y = 5;
	A[2].x = 4.5;	A[2].y = 4;

	B[0].x = 4.5;	B[0].y = 8; 	B[1].x = 5;	B[1].y = 5;
	B[2].x = 4.5;	B[2].y = 4;
}

void makeLeg(Point2 A[], Point2 B[])
{
	A[0].x = 3.5;	A[0].y = 0.2; 	A[1].x = 3;		A[1].y = 2;
	A[2].x = 3.2;	A[2].y = 4; 	A[3].x = 5.8;	A[3].y = 4;
	A[4].x = 6;		A[4].y = 2;		A[5].x = 6.2;	A[5].y = 0.2;

	B[0].x = 3.2;	B[0].y = 0.2; 	B[1].x = 3.5;	B[1].y = 2;
	B[2].x = 3;		B[2].y = 4; 	B[3].x = 5.8;	B[3].y = 4;
	B[4].x = 4.8;	B[4].y = 2;		B[5].x = 7;		B[5].y = 1.8;
}

void makeHead(Point2 A[], Point2 B[])
{
	//Start
	A[0].x = 4.5;	A[0].y = 8; 	A[1].x = 2.5;	A[1].y = 8;
	A[2].x = 2.5;	A[2].y = 11; 	A[3].x = 6;		A[3].y = 11;
	A[4].x = 6;		A[4].y = 8;		A[5].x = 4.5;	A[5].y = 8;

	//End
	B[0].x = 4.5;	B[0].y = 8; 	B[1].x = 2.5;	B[1].y = 8;
	B[2].x = 2.5;	B[2].y = 11; 	B[3].x = 6;		B[3].y = 11;
	B[4].x = 6;		B[4].y = 8;		B[5].x = 4.5;	B[5].y = 8;
}

void makeLeftEye(Point2 A[], Point2 B[])
{
	//Start
	A[0].x = 3;	A[0].y = 10.5; 	A[1].x = 4;	A[1].y = 10.5;
	A[2].x = 4;	A[2].y = 9.5; 	A[3].x = 3;	A[3].y = 9.5;
	A[4].x = 3;	A[4].y = 10.5; 	A[5].x = 3;	A[5].y = 9.5;

	//End
	A[0].x = 3;	A[0].y = 10.5; 	A[1].x = 4;	A[1].y = 10.5;
	A[2].x = 4;	A[2].y = 9.5; 	A[3].x = 3;	A[3].y = 9.5;
	A[4].x = 3;	A[4].y = 10.5; 	A[5].x = 3;	A[5].y = 9.5;
}

void makeRightEye(Point2 A[], Point2 B[])
{
	//Start
	A[0].x = 4.5;	A[0].y = 10.5; 	A[1].x = 5.5;	A[1].y = 10.5;
	A[2].x = 5.5;	A[2].y = 9.5; 	A[3].x = 4.5;	A[3].y = 9.5;
	A[4].x = 4.5;	A[4].y = 10.5; 	A[5].x = 4.5;	A[5].y = 9.5;

	//End
	B[0].x = 4.5;	B[0].y = 10.5; 	B[1].x = 5.5;	B[1].y = 10.5;
	B[2].x = 5.5;	B[2].y = 9.5; 	B[3].x = 4.5;	B[3].y = 9.5;
	B[4].x = 4.5;	B[4].y = 10.5; 	B[5].x = 4.5;	B[5].y = 9.5;
}

void makeMouth(Point2 A[], Point2 B[])
{
	//Start
	A[0].x = 3;		A[0].y = 8.4; 	A[1].x = 5.5;	A[1].y = 8.4;
	A[2].x = 5.5;	A[2].y = 9; 	A[3].x = 3;		A[3].y = 9;
	A[4].x = 3;		A[4].y = 8.4; 	A[5].x = 3;		A[5].y = 8.4;

	//End
	B[0].x = 3;		B[0].y = 8.4; 	B[1].x = 5.5;	B[1].y = 8.4;
	B[2].x = 5.5;	B[2].y = 9; 	B[3].x = 3;		B[3].y = 9;
	B[4].x = 3;		B[4].y = 8.4; 	B[5].x = 3;		B[5].y = 8.4;
}

Point2 A[10], B[10];
Point2 A1[10], B1[10];
Point2 A2[10], B2[10];

Point2 A3[10], B3[10];    //Head
Point2 A4[10], B4[10];    //LeftEye
Point2 A5[10], B5[10];    //Mouth
Point2 A6[10], B6[10];    //RightEye
Point2 center(0, 5);
float t = 0, deltat = 0.1;
float deltax = 2, deltay = 0;

void init(void)
{
	gluOrtho2D(0.0, 30.0, 0.0, 30.0);
	makeHand(A, B);		//create figure A and B
	makeBody(A1, B1);	//create figure A1 and B1
	makeLeg(A2, B2);	//create figure A2 and B2
	makeHead(A3, B3);
	makeLeftEye(A4, B4);
	makeMouth(A5, B5);
	makeRightEye(A6, B6);

	glLineWidth(2);
	glClearColor(1.0, 1.0, 1.0, 0.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawTween(A, B, 6, t, center);
	drawTween(A1, B1, 3, t, center);
	drawTween(A2, B2, 6, t, center);
	drawTween(A3, B3, 6, t, center);    //Head
	drawTween(A4, B4, 6, t, center);    //Eye
	drawTween(A5, B5, 6, t, center);    //Mouth
	drawTween(A6, B6, 6, t, center);    //Eye

	glFlush();
	glutSwapBuffers();
}

void animate()
{
	t += deltat;
	center.x += deltax;	center.y += deltay;  	//move center for clarity of display
	if (t > 1) {
		t = 1.0;
		deltat = -deltat;			//reverse direction
		deltax = -deltax;
		deltay = -deltay;
	}
	else if (t < 0) {
		t = 0;
		deltat = -deltat;			//reverse direction
		deltax = -deltax;
		deltay = -deltay;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	case 'a':
		animate();
		break;
	case 'r':
		deltat = -deltat;       //reverse direction
		deltax = -deltax;
		deltay = -deltay;
		animate();
		break;
	}
}

int main(int argc, char *argv[])
{
	// Set things (glut) up 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Create the window and handlers 
	glutCreateWindow("Tweening Demo");
	glutReshapeWindow(500, 500);
	glutInitWindowPosition(100, 100);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	//perpetual loop
	glutMainLoop();
	return(0);
}



/*
static unsigned int prev_ticks = 0;
unsigned int ticks;
float time;

if(!prev_ticks)
prev_ticks = get_ticks();

ticks = get_ticks();
time = (float)(ticks - prev_ticks);
prev_ticks = ticks;
*/