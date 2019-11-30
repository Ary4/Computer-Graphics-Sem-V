#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
float x1,x2,y1,y2;
float gap;
void display(void)
{
 int DelX,DelY,Max;
 int n=0,Total=1,j=0;
 double Sigma=1,XIncr,YIncr,x,y,slope;
 double gapX,gapY;
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (0.0, 1.0, 0.0);
 if(x2<x1 && y2<y1)
 {
 var=x1; x1=x2; x2=var;
 var=y1; y1=y2; y2=var;
 }
 DelX = x2 - x1;
 DelY = y2 - y1; 
 Max = ((DelX > DelY) ? DelX:DelY); 

 for( n=0 ; Total<=Max ; n++)
 {
 Total=Total*2;
 }
 for( int i=n ; i>0 ; i--)
 {
 Sigma = Sigma/2;
 }
 XIncr = Sigma*DelX;
 YIncr = Sigma*DelY; 
 x=double(x1); y=double(y1);

 glBegin(GL_POINTS);
 glVertex2i(x1,y1);
 slope = DelY/DelX; 
 gapX = gap/sqrt(1+slope*slope);
 // gapX = gap/.5;
 while(x!=x2 || y!=y2)
 {
 x = x+XIncr;
 y = y+YIncr;
 j = x/gapX;

 if((j%2)==0)
 {
 glVertex2s(x,y);
 printf("%lf %lf\n ",x,y);
 }
 } 
 glColor3f (1.0, 1.0, 1.0);
 for(int i=-100 ; i<=100 ; i++)
 {
 glVertex2s(i,0);
 glVertex2s(0,i);
 } 
 for(int i=-2; i<=2 ; i++)
 {
 glVertex2s(95+i,4+i);
 glVertex2s(95-i,4+i);
 } 
 for(int i=0; i<=2 ; i++)
 {
 glVertex2s(4+i,95+i);
 glVertex2s(4-i,95+i);
 glVertex2s(4,95-i);
 } 
 glEnd();
 glFlush();
}
 void init(void) 
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }
int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);
printf("Enter gap:");
scanf("%f",&gap);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algo");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}
