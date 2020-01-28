#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int gd,gm,x=0,xx=0,yy=0,step=1;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    cleardevice();

    while(!kbhit())
    {
	//ellipse(x,y,ang,ang,rx,ry);
    ellipse(x+0,300,30,330,40,15);//body
    ellipse(x+50,300,0,360,17,7);//head
    circle(x+58,300,5);//eye
    floodfill(x+58,300,WHITE);
    line(x+64,298,x+70,294);//idk
    line(x+64,302,x+70,306);
    line(x+0,300,xx-10,320);//left legs//leg limits==-20 to 20
    line(x+0,300,yy+10,320);//right
    x=x+2;

    if(step==1)
	{xx=xx+6;yy=yy-2;}
    else{xx=xx-2;yy=yy+6;}

    if(abs(xx-x)>10)
	if(step==1)
		step=0;
	else
		step=1;

	delay(25);
	cleardevice();
    }
}
