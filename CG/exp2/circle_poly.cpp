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
float sqrt_term()
{
    return sqrt(r*r - (xc - x)*(xc - x));
}
void polynomial()
{
    glClear(GL_COLOR_BUFFER_BIT);
    x = xc - r;
    int y_u,y_l;
    while(x<=xc+r)
    {
        y_u = round(yc + sqrt_term());
        y_l = round(yc - sqrt_term());
        setPixel(x,y_u);
        setPixel(x,y_l);
        x++;
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
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Polynomial method for circle generation");
    Init();
    glutDisplayFunc(polynomial);
    glutMainLoop();
    return 0;
}
