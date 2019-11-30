/*Code to show line clipping using Cyrus Beck Algorithm (Liang Barsky Algorithm) 
Copyright - Prateek Narendra, Gokul Shanth, Jashan Shetty (2014)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include <GL/glut.h>


GLdouble width, height;   /* window width and height */
int wd;                   /* GLUT window handle */
float a,b,c,d,e,f,g,h;       /* array of 2D points */
void takevalues()			/*Takes values of coordinates of rectangle and line*/
{
printf("Enter center coordinates of rectangle : ");
scanf("%f%f",&a,&b);
printf("Enter length and breadth of rectangle : ");
scanf("%f%f",&c,&d);
printf("Enter the coordinates of point 1 : ");
scanf("%f%f",&e,&f);
printf("Enter the coordinates of point 2 : ");
scanf("%f%f",&g,&h);

}
float minimum(float a1,float a2,float a3)	/*Calculates the minimum parameter for exit point*/
{
	if(a1<a2)
	{
		if(a1<a3)
		{
			return a1;
		}
		else
		{
			return a3;
		}
	}
	else
	{
		if(a2<a3)
		{
			return a2;
		}
		else
		{
			return a3;
		}
	}

}
float maximum(float a1,float a2,float a3)		/*Calculates the maximum parameter for entry point*/
{
	if(a1>a2)
	{
		if(a1>a3)
		{
			return a1;
		}
		else
		{
			return a3;
		}
	}
	else
	{
		if(a2>a3)
		{
			return a2;
		}
		else
		{
			return a3;
		}
	}

}

void init(void)
{
  width  = 1366.0;                 /* initial window width and height,*/
  height = 768.0;                  /* within which we draw. */
}

/* Callback functions for GLUT */

/* Draw the window - this is where all the GL actions are */
void
display(void)
{
  float centre[2]={a,b},lb[2]={c,d},rect1[2]={(centre[0]-(lb[0]/2)),(centre[1]-(lb[1]/2))},rect2[2]={(centre[0]-(lb[0]/2)),(centre[1]+(lb[1]/2))},rect3[2]={(centre[0]+(lb[0]/2)),(centre[1]+(lb[1]/2))},rect4[2]={(centre[0]+(lb[0]/2)),(centre[1]-(lb[1]/2))},line1[2]={e,f},line2[2]={g,h};
float p1,p2,p3,p4,t1,t2,t3,t4;//Above line - calculated the 4 coordinates of rectangle and 2 coordinates of line
float dx=line2[0]-line1[0];
float dy=line2[1]-line1[1];
int flags[2];
if(dx==0||dy==0)
{
	line1[0]=line1[0]+1;
	line1[1]=line1[1]+1;
	dx=line2[0]-line1[0];
    dy=line2[1]-line1[1];
}
if(dx<0)
{
	p1=(rect3[0]-line1[0])/(line2[0]-line1[0]);
	p2=(line1[0]-rect1[0])/(line1[0]-line2[0]);//Parameter calculation using x coordinates
	flags[0]=1;
}
else
{
	p2=(rect3[0]-line1[0])/(line2[0]-line1[0]);
	p1=(line1[0]-rect1[0])/(line1[0]-line2[0]);
	flags[0]=0;
}

if(dy<0)
{
	p3=(rect3[1]-line1[1])/(line2[1]-line1[1]);
	p4=(line1[1]-rect1[1])/(line1[1]-line2[1]);//Parameter calculation using y coordinates
	flags[1]=1;
}
else
{
	p4=(rect3[1]-line1[1])/(line2[1]-line1[1]);
	p3=(line1[1]-rect1[1])/(line1[1]-line2[1]);
	flags[1]=0;
}

float t_entry=maximum(0.0,p1,p3);//calculates the maximum t for entry point for all dx or dy < 0
float t_exit=minimum(1.0,p2,p4);//Calculates the minimum t for exit point for all dx or dy > 0
float newline10=line1[0]+(dx*t_entry);
float newline11=line1[1]+(dy*t_entry);//Calculation on new end points
float newline20=line1[0]+(dx*t_exit);
float newline21=line1[1]+(dy*t_exit);
printf("%f %f %f %f",newline10,newline11,newline20,newline21);
printf("\nExit : %f",t_exit);
printf("\nEntry : %f",t_entry);
if(t_entry>t_exit)
{

glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  /* draw a black line */
  glColor3f(0.0, 0.0, 0.0);
  glLineWidth(3.0);
  glBegin(GL_LINES);
	glVertex2f(rect1[0],rect1[1]);
	glVertex2f(rect2[0],rect2[1]);
	glVertex2f(rect2[0],rect2[1]);
	glVertex2f(rect3[0],rect3[1]);//Drawing only rectangle if t_entry>t_exit
	glVertex2f(rect3[0],rect3[1]);
	glVertex2f(rect4[0],rect4[1]);
	glVertex2f(rect4[0],rect4[1]);
	glVertex2f(rect1[0],rect1[1]);
	glEnd();
}
   //clear the screen to white
else
{
glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  /* draw a black line */
  glColor3f(0.0, 0.0, 0.0);
  glLineWidth(3.0);
  glBegin(GL_LINES);
	glVertex2f(rect1[0],rect1[1]);
	glVertex2f(rect2[0],rect2[1]);
	glVertex2f(rect2[0],rect2[1]);
	glVertex2f(rect3[0],rect3[1]);//Drawing new line alongwith clipping window rectangle if t_entry<t_exit
	glVertex2f(rect3[0],rect3[1]);
	glVertex2f(rect4[0],rect4[1]);
	glVertex2f(rect4[0],rect4[1]);
	glVertex2f(rect1[0],rect1[1]);
	glVertex2f(newline10,newline11);
	glVertex2f(newline20,newline21);
	glEnd();

}

  
glFlush();
}

/* Called when window is resized,
   also when window is first created,
   before the first call to display(). */
void reshape(int w, int h)
{
  /* save new screen dimensions */
  width = (GLdouble) w;
  height = (GLdouble) h;

  /* tell OpenGL to use the whole window for drawing */
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);

  /* do an orthographic parallel projection with the coordinate
     system set to first quadrant, limited by screen/window size */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, width, 0.0, height);
}

int main(int argc, char *argv[])
{

	takevalues();
    init();

  glutInit(&argc, argv);

  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

  
  glutInitWindowSize((int) width, (int) height);

  
  wd = glutCreateWindow("Liang Barsky Line Clipping");

  glutReshapeFunc(reshape);

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}


