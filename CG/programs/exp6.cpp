/*
Title:. Implement translation, sheer, rotation and scaling transformations on equilateral triangle and rhombus.
Name:Pratik Gupta
Class:SE
Roll no:26
D.o.P:
D.o.S

*/
#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;

int c;
int x1,yy1,x2,y2,x3,y3,r;
float t;
int nx1,ny1,nx2,ny2,nx3,ny3;
int xt,yt,sx,sy,shx,shy;
void display(void)
{
          glClear(GL_COLOR_BUFFER_BIT);
          glColor3f(1.0,0.0,0.0);
          glBegin(GL_LINES);
          glVertex2i(-500,0);
          glVertex2i(500,0);
          glVertex2i(0,-500);
          glVertex2i(0,500);
          glEnd();  
   
         //draw original triangle
         glColor3f(0.0,0.0,1.0);
         glBegin(GL_LINE_LOOP);
         glVertex2i(x1,yy1);
         glVertex2i(x2,y2);
         glVertex2i(x3,y3);
         glEnd();  
   
         glColor3f(1.0,1.0,0.0);
         glBegin(GL_LINE_LOOP);
         glVertex2i(nx1,ny1);
         glVertex2i(nx2,ny2);
         glVertex2i(nx3,ny3);
         glEnd();  
         glFlush();
}
void myinit(void)
{  
         glClearColor(0.0,0.0,0.0,1.0);
         gluOrtho2D(-500,500,-500,500);
}
void glutBlock()
{
          glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
          glutInitWindowSize(500,500);
          glutCreateWindow("2D transformation");
          glutDisplayFunc(display);
          myinit();
          glutMainLoop();
}
int main(int argc,char **argv)
{

           x1=100;
           yy1=0;
           x2=200;
           y2=0;
           x3=150;
           y3=150;
         
           cout<<"\n 1.Translation \n 2.Rotation \n 3.Scaling \n 4.Shearing \n 5.Exit";
           cout<<"\nEnter Your choice:";
           cin>>c;
           switch(c)
            {
           case 1:
                         cout<<"Enter translation factor xt:";
                         cin>>xt; 
                         cout<<"Enter translation factor yt:";
                         cin>>yt;             
                         nx1=x1+xt;
                         ny1=yy1+yt;
                         nx2=x2+xt;
                         ny2=y2+yt;
                         nx3=x3+xt;
                         ny3=y3+yt;
                         glutInit(&argc,argv);
                         glutBlock();
                         break;
             case 2:
                         cout<<"\n Enter Angle:";
                         cin>>r;
                         t=3.14*r/180;
                         nx1=(x1*cos(t)-yy1*sin(t));
                         ny1=(x1*sin(t)+yy1*cos(t));
                         nx2=(x2*cos(t)-y2*sin(t));
                         ny2=(x2*sin(t)+y2*cos(t));
                         nx3=(x3*cos(t)-y3*sin(t));
                         ny3=(x3*sin(t)+y3*cos(t));
                         glutInit(&argc,argv);
                         glutBlock(); 
                         break;   
              case 3:
                         cout<<"Enter scaling factor sx:";
                         cin>>sx; 
                         cout<<"Enter scaling factor sy:";
                         cin>>sy;    
                         nx1=x1*sx;
                         ny1=yy1*sy;
                         nx2=x2*sx;
                         ny2=y2*sy;
                         nx3=x3*sx;
                         ny3=y3*sy;
                         glutInit(&argc,argv);
                         glutBlock(); 
                         break;
              case 4:
                         cout<<"enter the shearing factors:";
                         cin>>shx;
                         cout<<"enter the shearing factor:";
                         cin>>shy;
                         nx1=x1+yy1*shx;
                         ny1=yy1+x1*shy;
                         nx2=x2+y2*shx;
                         ny2=y2+x2*shy;
                         nx3=x3+y3*shx;
                         ny3=y3+x3*shy;
                         glutInit(&argc,argv);
                         glutBlock(); 
                         break;  
               case 5:
                           exit(0);     
             }	 
     return 0;
}
