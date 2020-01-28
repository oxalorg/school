#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    cleardevice();

    ellipse(320,240,147,33,85,80);//head
    line(320,120,420,200);//hat
	line(220,200,420,200);
	line(320,120,220,200);
	circle(350,230,10);//right eye
	circle(290,230,10);//left eye
	circle(320,260,15);//nose
	arc(320,240,225,315,55);//smile
	getch();
	cleardevice();
}

