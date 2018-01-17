#include<iostream>
#include<cstdlib>
#include<GL/glut.h>
#define ROUND(x) ((int)(x+0.5))
using namespace std;
float x1,x2,y1,y2;
void draw_pixel(int x,int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

void drawline(int x1,int y1,int x2,int y2)
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
        draw_pixel(ROUND(x),ROUND(y));
        x+=dx;
        y+=dy;
        i++;
    }
    glFlush();
}
void drawfig(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int n)
{
    int m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y;
    drawline(ax,ay,bx,by);
    drawline(bx,by,cx,cy);
    drawline(cx,cy,dx,dy);
    drawline(dx,dy,ax,ay);
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
        drawfig(m1x,m1y,m2x,m2y,m3x,m3y,m4x,m4y,n);
}
void display()
{
    float x,y,dx,dy,length;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2i(-200,0);
        glVertex2i(200,0);
        glVertex2i(0,-200);
        glVertex2i(0,200);
        glEnd();
        drawfig(x1,y1,x1,y2,x2,y2,x2,y1,3);
}
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(-200.0,200.0,-200.0,200.0);
}   
int main(int argc,char **argv)
{
    cout<<"x1 :";
    cin>>x1;
    cout<<"y1 :";
    cin>>y1;
    cout<<"x2 :";
    cin>>x2;
    cout<<"y2 :";
    cin>>y2;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("xyz");
    init();
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glFlush();
    glutMainLoop();
    return 0;
}