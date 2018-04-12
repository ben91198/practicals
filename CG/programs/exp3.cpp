/*
Title:Draw the polygons by using the mouse. Choose colors by clicking on the designed color pane. Use window port to draw. (Use DDA algorithm for line drawing)
Name:Pratik Gupta
Class:SE
Roll no:26
D.o.P:
D.o.S

*/
#include<iostream>
#include<string.h>
#include<GL/glut.h>
#define ROUND(x)((int)(x+0.5))
using namespace std;
struct point
{
    GLint x,y;
};
struct Color
{
    GLfloat r;
    GLfloat g;
    GLfloat b;
};

int height=650,width=650;
int startX,startY;
static point vertex[1];
static int pt=0;
Color fillcolor;

void drawLine(int X1, int Y1,int X2, int Y2)
{
    float x,y,dx,dy,steps;
    int i;
    dx=abs(X2-X1);
    dy=abs(Y2-Y1);
    if(dx>=dy)
       steps=dx;
    else
       steps=dy;
    dx=(X2-X1)/steps;
    dy=(Y2-Y1)/steps;
    x=X1;
    y=Y1;
    i=1;
    while(i<=steps)
    {
       glBegin(GL_POINTS);
       glVertex2i(ROUND(x),ROUND(y));
       glEnd();
       x=x+dx;
       y=y+dy;
       i=i+1;
    }
    glFlush();
}

Color getPixelColor(GLint x, GLint y)
{
    Color color;
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&color);
    return color;
}

void setPixelColor(GLint x, GLint y, Color color)
{
    glColor3f(color.r,color.g,color.b);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
void floodFill(GLint x, GLint y, Color oc, Color nc)
{
    Color color;
    color=getPixelColor(x,y);
    cout<<"x"<<x<<"y"<<y<<"\n";
    if(color.r==oc.r  &&  color.g==oc.g  &&  color.b==oc.b)
    {
       setPixelColor(x,y,nc);
       floodFill(x+1,y,oc,nc);
       floodFill(x,y+1,oc,nc);
       floodFill(x-1,y,oc,nc);
       floodFill(x,y-1,oc,nc);
    }
}

void display(void)
{
    char string[]="Step 1: Draw Polygon and press enter to draw final edge";
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(10,600);
    int len,i;
    len=(int)strlen(string);
    for(i=0;i<len;i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_9_BY_15,string[i]);
    }
    glColor3f(1.0,0.0,0.0);
    glRecti(10,30,60,10);
    glColor3f(0.0,1.0,0.0);
    glRecti(90,30,140,10);
    glColor3f(0.0,0.0,1.0);
    glRecti(170,30,220,10);
    glFlush();
}

void myKeyboard(unsigned char key, int mX,int My)
{
	char string[]="Step 2: Pick color by clicking on the desired color rectangle";
	switch (key)
	{
	case 13:
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(10,580);
	int len,i;
	len=(int)strlen(string);
	for(i=0;i<len;i++)
	{
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,string[i]);
	}
	drawLine(vertex[0].x,vertex[0].y,startX,startY);
	pt=2;
	break;

	case 27:
	     exit(0);
	}
}
void mouse(int button, int state, int x, int y)
{
   if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
   {
     if(pt==0)
     {
    	 vertex[pt].x=x;
    	 vertex[pt].y=height-y;
    	 startX=x;
    	 startY=height-y;
    	 pt++;
     }
     else if(pt==1)
     {
    	 glColor3f(0.0,0.0,1.0);
    	 drawLine(vertex[0].x,vertex[0].y,x,height-y);
    	 vertex[0].x=x;
    	 vertex[0].y=height-y;

     }
     else if(pt==2)
     {
    	 fillcolor=getPixelColor(x,height-y);
    	 char string[]="Step 3: click inside to fill color";
    	 	 glColor3f(1.0,1.0,1.0);
    	 glRasterPos2f(10,560);
    	 int len,i;
    	 len=(int)strlen(string);
    	 for(i=0;i<len;i++)
    	 {
    	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15,string[i]);
    	 }
    	 pt=3;
     }
     else if(pt==3)
     {
    	 Color nc={fillcolor.r,fillcolor.g,fillcolor.b};
    	 Color oc={0.0f,0.0f,0.0f};
    	 floodFill(x,height-y,oc,nc);
    	 pt=4;
         cout<<"foodfill called";
     }

     }
     glFlush();
}


void myInit(void)
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,650.0,0.0,650);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(650,650);
    glutInitWindowPosition(0,0);

    glutCreateWindow("test");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(mouse);

    myInit();

    glutMainLoop();
	return 0;
}

