#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void dda(int x1,int y1,int x2,int y2);
void main()
{
	int gd=DETECT,gm;
	int x1,y1,x2,y2;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	printf("Enter the starting co-ordinates for drawing line: ");
	scanf("%d%d",&x1,&y1);
	printf("Enter the ending co-ordinates for drawing line: ");
	scanf("%d%d",&x2,&y2);
	dda(x1,y1,x2,y2);
	getch();
	closegraph();
}
void dda(int x1,int y1,int x2,int y2)
{
	int i,j=0,dx,dy,steps,step=1;
	float x,y;
	float xinc,yinc;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
		steps=dx;
	else
		steps=dy;
	xinc=(float)dx/steps;
	yinc=(float)dy/steps;
	x=x1;
	y=y1;
	putpixel(x,y,WHITE);
	for(i=1;i<steps;i++)
	{
		x=x+xinc;
		y=y+yinc;
		x1=x+0.5;
		y1=y+0.5;
		if(step==1)
            putpixel(x1,y1,WHITE);
        if(j>7)
        {j=0;
        if(step==1)
            step=0;
        else step=1;
        }
        j++;
    }
}

