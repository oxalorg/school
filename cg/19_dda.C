#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void dda(int x1,int y1,int x2,int y2);
void main()
{
	int gd=DETECT,gm;
	int x1,y1,x2,y2,thick,i;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	printf("Enter the starting co-ordinates for drawing line: ");
	scanf("%d%d",&x1,&y1);
	printf("Enter the ending co-ordinates for drawing line: ");
	scanf("%d%d",&x2,&y2);   /*
	printf("enter the thickness of line in pixels\n");
	scanf("%d",&thick);
	for(i=0;i<thick;i++)
	dda(x1+i,y1+i,x2+i,y2+i);*/
	dda(x1,y1,x2,y2);
	getch();
	closegraph();
}
void dda(int x1,int y1,int x2,int y2)
{
	int i,dx,dy,steps;
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
		putpixel(x1,y1,WHITE);
		putpixel(x1,y1+1,WHITE);
	putpixel(x1,y1-1,WHITE);
	putpixel(x1+1,y1,WHITE);
	putpixel(x1-1,y1,WHITE);
	putpixel(x1-1,y1+1,WHITE);
	putpixel(x1+1,y1+1,WHITE);
	putpixel(x1+1,y1-1,WHITE);
	}
}

