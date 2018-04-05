#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#define ROUND(x)((int)(x+0.5))
using namespace std;

float x1,x2,y1,y2;
void putpixel(int x,int y)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void drawLine(int x1,int y1,int x2,int y2)
{
	float x,y,dx,dy,steps;
	int i;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
		steps=dx;
	else
		steps=dy;
		
	dx=(x2-x1)/steps;
	dy=(y2-y1)/steps;
	
	x=x1;
	y=y1;
	i=1;
	while(i<=steps)
	{
	     if (i%5==0)
             {     
		draw_pixel(ROUND(x),ROUND(y));
	     }      
		x=x+dx;
		y=y+dy;
		i++;
		
	}	
	glFlush();	

}

void drawFig(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int n)
{
	int m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y;
	drawLine(ax,ay,bx,by);
	drawLine(bx,by,cx,cy);
	drawLine(cx,cy,dx,dy);
	drawLine(dx,dy,ax,ay);
	
	m1x=(ax+bx)/2;
	m1y=(ay+by)/2;
	m2x=(bx+cx)/2;
	m2y=(by+cy)/2;
	m3x=(cx+dx)/2;
	m3y=(cy+dy)/2;
	m4x=(dx+ax)/2;
	m4y=(dy+ay)/2;
	
	n--;
	if(n!=0)
	{
		drawFig(m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y,n);
	}
	
}


void display()
{
	float x,y,dx,dy,length;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(-200,0);
	glVertex2i(200,0);
	glVertex2i(0,-200);
	glVertex2i(0,200);
	glEnd();
	drawFig(x1,y1,x1,y2,x2,y2,x2,y1,3);
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-200.0,200.0,-200.0,200.0);
}

int main(int argc,char **argv)
{
	cout<<"\nEnter the value of left bottom x1\n";
	cin>>x1;
	cout<<"\nEnter the value of left bottom y1\n";
	cin>>y1;
	cout<<"\nEnter value of top x2:\n";
	cin>>x2;
	cout<<"\nEnter value of top x2:\n";
	cin>>y2;
	glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
		glutInitWindowSize(500,500);
		glutCreateWindow("Karan");
		init();
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(display);
		glFlush();
		glutMainLoop();
		return(0);
}
	



