#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;
// $ g++ gl.cpp -o gl -lGL -lGLU -lglut- To compile //
int xc,yc,x,y,rx,ry;
void setPixel(int x,int y)
{
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
void ellipsePlotPoints()
{
    setPixel(xc+x,yc+y);
    setPixel(xc+x,yc-y);
    setPixel(xc-x,yc-y);
    setPixel(xc-x,yc+y);
}
void bresenham()
{
    glClear (GL_COLOR_BUFFER_BIT);
    x = 0;
    y = ry;
    ellipsePlotPoints();
    int rx_square = rx*rx;
    int ry_square = ry*ry;
    // int two_rx_square_y = 2 * rx_square * y;
    // int two_ry_square_x = 2 * ry_square * x;
    int d1 = round(2*ry_square + rx_square - 2*rx_square*ry);
    int dx = 2*x*ry_square;
    int dy = 2*y*rx_square;
    while(dx < dy)
    {
        x++;
        dx += 2*ry_square;
        if(d1 < 0)
            d1 += 2*dx + 2*ry_square;
        else
        {
            y--;
            dy -= 2*rx_square;
            d1 += 2*(dx - dy) + 2*ry_square;
        }
        ellipsePlotPoints();
    }
    int d2 = 2*ry_square*(x+1)*(x+1) + rx_square*(y*y + (y-1)*(y-1)) -2*rx_square*ry_square;
    while(y>0)
    {
        y--;
        dy -= 2*rx_square;
        if(d2 > 0)
            d2 += 2*rx_square - 2*dy; 
        else
        {
            x++;
            dx += 2*ry_square;
            d2 += 2*rx_square + 2*(dx - dy);
        }
        ellipsePlotPoints();
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
    glutCreateWindow ("Bresenham method for ellipse generation");
    Init();
    glutDisplayFunc(bresenham);
    glutMainLoop();
    return 0;
}