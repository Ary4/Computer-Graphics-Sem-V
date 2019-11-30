#include<iostream>
#include<stdlib.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;
int xa,xb,ya,yb;
void display (void)
{
int dx=xb-xa;
int dy=yb-ya;
int p0 = 2*dy - dx;
float x=xa,y=ya;

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POINTS);
glVertex2i(x,y);
int p =p0;
int k;
for(k=0;k<dx;k++)
{
	if(p<0)
	{
	x = x+1;
	glVertex2i(x,y);
	p+=2*(dy-dx);
	}

	else
	{
	x = x+1; y = y+1;
	p+=2*(dy);
	glVertex2i(x,y);
	}
	//p+=p0;
}
// Point class to keep it a little cleaner.
class Point {
public:
    float x, y;
    void setxy(float x2, float y2) { x = x2; y = y2; }
    const Point & operator=(const Point &rPoint) {
         x = rPoint.x;
         y = rPoint.y;        
         return *this;
      }

};

Point abc[2];

void myInit() {
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(8.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,64.0,0.0,48.0);
}

void drawDot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void drawLine(Point p1, Point p2) {
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}

// Calculate the next Hermite point.
Point drawHermite(Point A, Point B,double t1,double t2, double u) {
    Point P;
    P.x = (2*u*u*u-(3*u*u)+1)*A.x+(-1*2*u*u*u+(3*u*u))*B.x+((u*u*u)-(2*u*u)+u)*t1+((u*u*u)-(u*u))*t2;
    P.y = (2*u*u*u-(3*u*u)+1)*A.y+(-1*2*u*u*u+(3*u*u))*B.y+((u*u*u)-(2*u*u)+u)*t1+((u*u*u)-(u*u))*t2;
    return P;
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); 
    cout<<"ENTER starting , ending and tangents at end points \n";
    int ax,ay,bx,by,t1,t2;	
    cin>>ax>>ay>>bx>>by>>t1>>t2;  
    Point POld=abc[0];
    abc[0].x=ax,abc[0].y=ay;
    abc[1].x=bx,abc[1].y=by;
    
    glColor3f(1.0,0.0,0.0);
    for(int i=0;i<2;i++)
        drawDot(abc[i].x, abc[i].y);       
    glColor3f(1.0,1.0,1.0);
    
    for(double t = 0.0;t <= 1.0; t += 0.01) {
        Point P = drawHermite(abc[0], abc[1],t1,t2,t);
        drawLine(POld, P);
        POld = P;       
    }
    glFlush();
}

int main(int argc, char *argv[]) {
    xa=0;
    ya=0;
    xb=100;
    yb=100;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Hermite Curve");   
    glutDisplayFunc(myDisplay);
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}
