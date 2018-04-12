/*
Title:
2. Draw inscribed and Circumscribed circles in the triangle as shown as an example below.(Use any Circle drawing and Line drawing algorithms)

Name:Pratik Gupta
Class:SE
Roll no:26
D.o.P:
D.o.S

*/
#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>
#define ROUND(x)((int)(x+0.5))
using namespace std;
double xx1,xx2,xx3,yy1,yy2,yy3,xc,yc,inradius,XC,YC,outradius;

void putpixel(int x,int y)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void drawLine(int x1,int y1,int x2,int y2)
{
		int steps,i,x,y;
		float dx,dy;
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		if(dx>=dy)
		steps=dx;
		else
		steps=dy;
		dx=(x2-x1)/steps;
		dy=(y2-y1)/steps;
		x=x1;
		y=y1;
		i=0;
		while(i<=steps)
		{
		  putpixel(ROUND(x),ROUND(y));
		  x=x+dx;
		  y=y+dy;
		  i++;
	        }
		glFlush();
}

void draw(int xc,int yc,int x,int y)
{
    putpixel(xc+x, yc+y);
    putpixel(xc-x, yc+y);
    putpixel(xc+x, yc-y);
    putpixel(xc-x, yc-y);
    putpixel(xc+y, yc+x);
    putpixel(xc-y, yc+x);
    putpixel(xc+y, yc-x);
    putpixel(xc-y, yc-x);
}

void drawCircle(int xc, int yc, int r)
{
int x=0,y=r;
int d=3-2*r;
while(y>=x)
{
  draw(xc,yc,x,y);
  x++;
  if(d>0)
  {
    y--;
    d=d+4*(x-y)+10;
  }
  else
  d=d+4*x+6;

}


}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);

drawLine(xx1,yy1,xx2,yy2);
drawLine(xx2,yy2,xx3,yy3);
drawLine(xx1,yy1,xx3,yy3);
drawCircle(xc,yc,inradius);
drawCircle(XC,YC,outradius);

glFlush();
}
void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
gluOrtho2D(-200.0,200.0,-200.0,200.0);
}

int main(int argc, char ** argv)
{
cout<<"Enter the vertex points of triangle";
cout<<"\nxx1:";
cin>>xx1;
cout<<"\nyy1:";
cin>>yy1;
cout<<"\nxx2:";
cin>>xx2;
cout<<"\nyy2:";
cin>>yy2;
cout<<"\nxx3:";
cin>>xx3;
cout<<"\nyy3:";
cin>>yy3;

double a,b,c;
a=sqrt(((xx2-xx3)*(xx2-xx3))+((yy2-yy3)*(yy2-yy3)));
b=sqrt(((xx1-xx3)*(xx1-xx3))+((yy1-yy3)*(yy1-yy3)));
c=sqrt(((xx2-xx1)*(xx2-xx1))+((yy2-yy1)*(yy2-yy1)));

xc=((a*xx1)+(b*xx2)+(c*xx3))/(a+b+c);
yc=((a*yy1)+(b*yy2)+(c*yy3))/(a+b+c);

inradius=0.5*sqrt(((b+c-a)*(c+a-b)*(a+b-c))/(a+b+c));


outradius=(a*b*c)/(4*((a+b+c)*(0.5))*inradius);

float A=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
float B=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
float C=acos(((b*b)+(a*a)-(c*c))/(2*b*a));

XC=((xx1*sin(2*A))+(xx2*sin(2*B))+(xx3*sin(2*C)))/(sin(2*A)+sin(2*B)+sin(2*C));

YC=((yy1*sin(2*A))+(yy2*sin(2*B))+(yy3*sin(2*C)))/(sin(2*A)+sin(2*B)+sin(2*C));

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutCreateWindow("Anand");
init();
glClear(GL_COLOR_BUFFER_BIT);
glutDisplayFunc(display);
glFlush();
glutMainLoop();
return 0;
}
