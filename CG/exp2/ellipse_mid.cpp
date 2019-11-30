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
void midpoint()
{
    glClear (GL_COLOR_BUFFER_BIT);
    x = 0;
    y = ry;
    ellipsePlotPoints();
    int rx_square = rx*rx;
    int ry_square = ry*ry;
    // int two_rx_square_y = 2 * rx_square * y;
    // int two_ry_square_x = 2 * ry_square * x;
    int p1 = round(ry_square + rx_square/4.0 - rx_square*ry);
    int px = 2*x*ry_square;
    int py = 2*y*rx_square;
    while(px < py)
    {
        x++;
        px += 2*ry_square;
        if(p1 < 0)
            p1 += px + ry_square;
        else
        {
            y--;
            py -= 2*rx_square;
            p1 += px - py + ry_square;
        }
        ellipsePlotPoints();
    }
    int p2 = round(ry_square*(x + 0.5)*(x + 0.5) + rx_square*(y-1)*(y-1) - rx_square * ry_square);
    while(y>0)
    {
        y--;
        py -= 2*rx_square;
        if(p2 > 0)
            p2 += rx_square - py;
        else
        {
            x++;
            px += 2*ry_square;
            p2 += rx_square + px - py;
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
    glutCreateWindow ("Midpoint method for ellipse generation");
    Init();
    glutDisplayFunc(midpoint);
    glutMainLoop();
    return 0;
}