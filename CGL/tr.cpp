#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define ROUND(x)((int)(x+0.5))

using namespace std;
int x1,x2,x3,yy1,y2,y3,nx1,nx2,nx3,ny1,ny2,ny3,tx,ty,c,r,sx,sy,shx,shy;
double t;

void myinit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	gluOrtho2D(-500,500,-500,500);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(-500,0);
	glVertex2i(500,0);
	glVertex2i(0,-500);
	glVertex2i(0,500);
	glEnd();
	
	
	//original traingle
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1,yy1);
	glVertex2i(x2,y2);
	glVertex2i(x3,y3);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(nx1,ny1);
	glVertex2i(nx2,ny2);
	glVertex2i(nx3,ny3);
	glEnd();
	glFlush();
	
}

int main(int argc,char **argv)
{
	x1=100;
	yy1=0;
	x2=200;
	y2=0;
	x3=150;
	y3=150;
	while(1)
	{
	cout<<"\n1.translation\n2.rotation\n3.scaling\n4.shear\n5.exit";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"\nEnter translation factor tx : ";
			cin>>tx;
			
			cout<<"\nEnter translation factor ty : ";
			cin>>ty;
			
			nx1=x1+tx;
			ny1=yy1+ty;
			nx2=x2+tx;
			ny2=y2+ty;
			nx3=x3+tx;
			ny3=y3+ty;
		
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
		glutInitWindowSize(500,500);
		glutCreateWindow("Karan");
		myinit();
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(display);
		
		glutMainLoop();
		break;
		
		case 2:
			cout<<"\nEnter angle : ";
			cin>>r;
			t=3.14*r/180;
			nx1=(x1*cos(t)-yy1*sin(t));
			ny1=(x1*sin(t)+yy1*cos(t));
			nx2=(x2*cos(t)-y2*sin(t));
			ny2=(x2*sin(t)+y2*cos(t));
			nx3=(x3*cos(t)-y3*sin(t));
			ny3=(x3*sin(t)+y3*cos(t));
			
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
		glutInitWindowSize(500,500);
		glutCreateWindow("Karan");
		myinit();
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(display);
		
		glutMainLoop();
		break;
		
		case 3:
			cout<<"\nEnter scaling factor sx : ";
			cin>>sx;
			
			cout<<"\nEnter scaling factor sy : ";
			cin>>sy;
			
			nx1=x1*sx;
			ny1=yy1*sy;
			nx2=x2*sx;
			ny2=y2*sy;
			nx3=x3*sx;
			ny3=y3*sy;
		
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
		glutInitWindowSize(500,500);
		glutCreateWindow("Karan");
		myinit();
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(display);
		
		glutMainLoop();
			break;
			
		case 4:
			cout<<"\nEnter shear factor shx : ";
			cin>>shx;
			
			cout<<"\nEnter shear factor shy : ";
			cin>>shy;	
			
			nx1=abs(x1+shx*yy1);
			ny1=abs(yy1+shy*x1);
			nx2=abs(x2+shx*y2);
			ny2=abs(y2+shy*x2);
			nx3=abs(x3+shx*y3);
			ny3=abs(y3+shy*x3);
			
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
		glutInitWindowSize(500,500);
		glutCreateWindow("Karan");
		myinit();
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(display);
		
		glutMainLoop();
			break;
		
		glFlush();
		return 0;
	}
	}
}














