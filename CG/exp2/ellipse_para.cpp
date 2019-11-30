#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;
// $ g++ gl.cpp -o gl -lGL -lGLU -lglut- To compile //
int xc,yc,rx,ry;
void setPixel(int x,int y)
{   glColor3f(0.0,1.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void ellipsePlotPoints(double x1,double y1)
{
    setPixel(round(xc+x1),round(yc+y1));
    setPixel(round(xc+x1),round(yc-y1));
    setPixel(round(xc-x1),round(yc-y1));
    setPixel(round(xc-x1),round(yc+y1));
}
void Init()
{
    glClearColor(1.0,1.0,1.0,0); //clear color-black
    glColor3f(0.0,0.0,0.0); //fill color-white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0 , 500 , 0 , 500);
}
void parametric()
{
    glClear (GL_COLOR_BUFFER_BIT);
    double theta = 0;
    double delta = 0.01;
    while(theta < 3.14159265/2)//bcuz we are enterning 4 points simult
    {
        ellipsePlotPoints(rx*cos(theta),ry*sin(theta));
        theta += delta;
    }
    glFlush();
}
int main(int argc,char ** argv)
{
    cout<<"Enter the center of ellipse :\n";
    cin>>xc>>yc;
    cout<<"Enter the major and minor axis of ellipse :\n";
    cin>>rx>>ry;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500,500);
    glutInitWindowPosition (700, 700);
    glutCreateWindow ("Parametric method for ellipse generation");
    Init();
    glutDisplayFunc(parametric);
    glutMainLoop();
    return 0;
}
