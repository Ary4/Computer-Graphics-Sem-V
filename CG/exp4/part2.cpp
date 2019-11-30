#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
int transX, transY;
double scaleX, scaleY,centrex,centrey;
double angle, angleRad;
char reflectionAxis, shearingAxis;
int shearingX, shearingY;
int A,B,C;

double round(double d)
{
	return floor(d + 0.5);
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}
void drawPolygonScale(double x, double y,double xc,double yc)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round(xc+((pntX[i]-xc) * x)), round(yc+((pntY[i]-yc) * y)));
	}
	glEnd();
}

void drawPolygonRotation(double angleRad,double xc,double yc)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((xc+(pntX[i]-xc) * cos(angleRad)) - ((pntY[i]-yc) * sin(angleRad))), round(yc+((pntX[i]-xc) * sin(angleRad)) + ((pntY[i]-yc) * cos(angleRad))));
	}
	glEnd();
}

void drawPolygonMirrorReflection(int a,int b,int c)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	double tmp;

	
	for (int i = 0; i < edges; i++)
		{	tmp=(-2)*(a*pntX[i]+b*pntY[i]+c)/(a*a+b*b);
			glVertex2i(round(a*tmp+pntX[i]), round(pntY[i]+b*tmp));

		}
	glEnd();
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	if (choice == 1)
	{
		drawPolygon();
		drawPolygonScale(scaleX, scaleY,centrex,centrey);
	}
	else if (choice == 2)
	{
		drawPolygon();
		drawPolygonRotation(angleRad,centrex,centrey);
	}
	else if (choice == 3)
	{
		drawPolygon();
		drawPolygonMirrorReflection(A,B,C);
		glBegin(GL_LINES);
			glColor3f(0.0, 0.0, 0.0);
  			glVertex2f(-200, (200*A-C)/B);
    			glVertex2f(200, (-200*A-C)/B);
		glEnd();
	}
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "Enter your choice:\n\n" << endl;
	cout << "1. Scaling" << endl;
	cout << "2. Rotation" << endl;
	cout << "3. Mirror Reflection" << endl;
	cout << "5. Exit" << endl;

	cin >> choice;

	if (choice == 5) {
		return 0;
	}

	cout << "\n\nFor Polygon:\n" << endl;

	cout << "Enter no of edges: "; cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		cout << "Enter co-ordinates for vertex  " << i + 1 << " : "; cin >> pntX1 >> pntY1;
		pntX.push_back(pntX1);
		pntY.push_back(pntY1);
	}

	if (choice == 1)
	{
		cout << "Enter the scaling factor for X and Y and Centres x,y"; cin >> scaleX >> scaleY>>centrex>>centrey;
	}
	else if (choice == 2)
	{
		cout << "Enter the angle for rotation and Centre coordinates: "; cin >> angle>>centrex>>centrey;
		angleRad = angle * 3.1416 / 180;
	}
	else if (choice == 3)
	{
		cout << "Enter A B C in Ax+By+C  "; cin >>A>>B>>C;
	}

	//cout << "\n\nPoints:" << pntX[0] << ", " << pntY[0] << endl;
	//cout << angleRad;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Extended Basic Transformations");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}
