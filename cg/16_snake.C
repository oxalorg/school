#include<stdio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm,i,x,y,c=1;
 initgraph(&gd,&gm,"C:\\TC\\BGI");

 for(x=0;x<=480,c<=3;x=x+60)
 {
	//Snake 1
	setlinestyle(0,0,3);
	setcolor(c);
	arc(55+x,240,0,180,15);
	arc(85+x,240,180,360,15);
	arc(115+x,240,0,180,15);
	arc(145+x,240,180,360,15);
	setlinestyle(0,0,1);
	circle(160+x,240,10);
	delay(400);
	cleardevice();

	setlinestyle(0,0,3);
	arc(85+x,240,180,360,15);
	arc(115+x,240,0,180,15);
	arc(145+x,240,180,360,15);
	arc(175+x,240,0,180,15);
	setlinestyle(0,0,1);
	circle(190+x,240,10);
	delay(400);
	cleardevice();

	if(x<100)
	{
	setcolor(WHITE);
	circle(320,240,3);
	setfillstyle(1,RED);
	floodfill(320,240,WHITE);
	}
	if(x<260)
	{
	setcolor(WHITE);
	circle(480,240,3);
	setfillstyle(1,YELLOW);
	floodfill(480,240,WHITE);
	}
	if(x==480)
	{
	x=0;
	c++;
	}

 }
 getch();
 closegraph();

}