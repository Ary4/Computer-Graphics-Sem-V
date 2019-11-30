#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;
// $ g++ gl.cpp -o gl -lGL -lGLU -lglut- To compile //
int xc,yc,x,y,r;
void setPixel(int x,int y)
{   glColor3f(0.0,1.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void Init()
{
    glClearColor(1.0,1.0,1.0,0); //clear color-black
    glColor3f(0.0,0.0,0.0); //fill color-white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0 , 500 , 0 , 500);
}
void circlePlotPoints()
{
    setPixel(xc+x,yc+y);
    setPixel(xc+x,yc-y);
    setPixel(xc+y,yc-x);
    setPixel(xc-y,yc-x);
    setPixel(xc-x,yc-y);
    setPixel(xc-x,yc+y);
    setPixel(xc-y,yc+x);
    setPixel(xc+y,yc+x);
}
void midpoint()
{
    glClear (GL_COLOR_BUFFER_BIT);
    x = 0;
    y = r;
    circlePlotPoints();
    int p = 5/4 - r;
    while(x<y)
    {
        x++;
        if(p < 0)
        {
            p += 2*x + 1;
        }
        else
        {
            y--;
            p += 2*(x - y) + 1;
        }
        circlePlotPoints();
    }
    glFlush();
}
int main(int argc,char ** argv)
{
    cout<<"Enter the center of circle :\n";
    cin>>xc>>yc;
    cout<<"Enter the radius of circle :\n";
    cin>>r;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500,500);
    glutInitWindowPosition (700, 700);
    glutCreateWindow ("Midpoint method for circle generation");
    Init();
    glutDisplayFunc(midpoint);
    glutMainLoop();
    return 0;
}
