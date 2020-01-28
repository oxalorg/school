
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>

void star(int x,int y);

void main()
{
int i,j,gd,gm,x=0,y=0,incrx=50,incry=40,count=0;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\TC\\BGI");
cleardevice();

while(!kbhit())
{
    if(count%2==0)
    {
    incrx=incrx-10;
    incry=incry-10;
    }
    else
    {incrx=incrx+10;
    incry=incry+10;
    }
	arc(325,425-count,225,45,36);
	arc(300,400-count,270,0,50);
	floodfill(345,450-count,WHITE);

	for(i=0;i<50;i++)//loop to print stars
    {
	x=x+incrx;
	for(j=0;j<50;j++)
       {y=y+incry;
	star(x,y);
       }
	y=0;
    }
    delay(25);
    count++;
    cleardevice();
    x=0;y=0;
}
}

void star(int x,int y)
{
	//arc(int x, int y, int stangle, int endangle, int radius)
	arc(x-3,y+3,0,90,3);
	arc(x+3,y+3,90,180,3);
	arc(x-3,y-3,270,360,3);
	arc(x+3,y-3,180,270,3);
	floodfill(x,y,WHITE);
}