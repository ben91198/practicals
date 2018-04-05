#include<stdio.h>
#define ROUND(x)((int)(x+0.5))
int main()
	{
		int i;
		float xin,yin,x,y,x1,y1,x2,y2,steps,dx,dy;
		printf("\nEnter First Point : ");
		scanf("%f %f",&x1,&y1);
		
		printf("\nEnter Second Point : ");
		scanf("%f %f",&x2,&y2);
		
		dx=x2-x1;
		dy=y2-y1;
		
		if(dx>dy)
			steps=dx;
		else
			steps=dy;
			
		xin = dx/steps;
		yin = dy/steps;
		
		x=x1;
		y=y1;
		
		for(i=0;i<=steps;i++)
			{
				printf("%d \t %d\n",ROUND(x),ROUND(y));
				x=x+xin;
				y=y+yin;
			}		
		
	}
