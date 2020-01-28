
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int gd,gm,step=1,i=0;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    cleardevice();

	while(!kbhit())
	{
	if(i<-200)
		step=1;
	else if(i>200)
		step=0;

	if(step==1)
		i++;
	else
		i--;
	cleardevice();
	ellipse(320+i,160,147,33,85,80);//head
	ellipse(320+i,320,120,60,130,120);//body
	circle(350+i,160,10);//right eye
	circle(290+i,160,10);//left eye
	circle(320+i,280,10);//buttons
	circle(320+i,340,10);
	circle(320+i,400,10);
	line(290+i,200,350+i,200);//mouth
	line(320+i,230,350+i,200);
	line(290+i,200,320+i,230);
	line(320+i,40,420+i,120);//hat
	line(220+i,120,420+i,120);
	line(320+i,40,220+i,120);
	delay(10);
	}
	getch();
	cleardevice();
}
