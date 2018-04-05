#include<string.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
#define ROUND(x)((int)(x+0.5))
double xx1,xx2,xx3,yy1,yy2,yy3,xc,yc,inradius,XC,YC,cir_radius;

void draw_pixel(int x,int y)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void drawline(int x1,int y1,int x2,int y2)
{
	float x,y,dx,dy,length;
	int i;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
		length=dx;
	else
		length=dy;
		
	dx=(x2-x1)/length;
	dy=(y2-y1)/length;
	
	x=x1;
	y=y1;
	i=1;
	while(i<=length)
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

void drawcircle(float x,float y,int r)
{
	float x1,y1,x2,y2,startx,starty,epsilon;
	int i,val;
	
	x1=r*cos(0);
	y1=r*sin(0);
	startx=x1;
	starty=y1;
	i=0;
	do
	{
		val=pow(2,i);
		i++;
	}while(val<r);
	epsilon=1/pow(2,i-1);
	
	do
	{
		x2=x1+y1*epsilon;
		y2=y1-epsilon*x2;
		draw_pixel(x+x2,y+y2);
		
		x1=x2;
		y1=y2;
		
	}while((y1-starty)<epsilon || (startx-x1)>epsilon);
	glFlush();
}

void display(void)
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
	
	drawline(xx1,yy1,xx2,yy2);
	drawline(xx2,yy2,xx3,yy3);
	drawline(xx1,yy1,xx3,yy3);
	drawcircle(xc,yc,inradius);
	drawcircle(xc,yc,cir_radius);	
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-200.0,200.0,-200.0,200.0);
}

int main(int argc,char **argv)
{
	cout<<"\nEnter the vertex points of triangle\n";
	cout<<"\nx co of v1";
	cin>>xx1;
	cout<<"\ny co of v1";
	cin>>yy1;
	cout<<"\nx co of v2";
	cin>>xx2;
	cout<<"\ny co of v2";
	cin>>yy2;
	cout<<"\nx co of v3";
	cin>>xx3;
	cout<<"\ny co of v3";
	cin>>yy3;
	
	double a,b,c;
	a=sqrt(((xx2-xx3)*(xx2-xx3))+((yy2-yy3)*(yy2-yy3)));
	b=sqrt(((xx1-xx3)*(xx1-xx3))+((yy2-yy3)*(yy1-yy3)));
	c=sqrt(((xx2-xx3)*(xx2-xx1))+((yy2-yy1)*(yy2-yy1)));
	
	xc=((a*xx1)+(b*xx2)+(c*xx3))/(a+b+c);
	yc=((a*yy1)+(b*yy2)+(c*yy3))/(a+b+c);
	
	inradius=0.5*sqrt(((b+c-a)*(c+a-b)*(a+b-c))/(a+b+c));
	
	cir_radius=(a*b*c)/(4*((a+b+c)*(0.5))*inradius);
	
	float A=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
	float B=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
	float C=acos(((b*b)+(a*a)-(c*c))/(2*b*a));
	
	xc=((xx1*sin(2*A))+(xx2*sin(2*B))+(xx3*sin(2*C)))/(sin(2+A)+sin(2*B)+sin(2*C));
	yc=((yy1*sin(2*A))+(yy2*sin(2*B))+(yy3*sin(2*C)))/(sin(2+A)+sin(2*B)+sin(2*C));
	
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
		glutInitWindowSize(500,500);
		glutInitWindowPosition(100,100);
		glutCreateWindow("Karan");
		init();
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(display);
		glFlush();
		glutMainLoop();
		return(0);


}









