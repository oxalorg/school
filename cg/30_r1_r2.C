#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void scanline(int xmin,int ymin,int xmax,int ymax,int col)
{   int i;
    setcolor(col);
    for(i=ymin;i<=ymax;i++)
	line(xmin,i,xmax,i);
    getch();
}

void main()
{
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    cleardevice();

    rectangle(100,100,300,250);//R1
    getch();
    rectangle(200,200,450,350);//R2
    getch();
    scanline(100,100,300,250,1);
    scanline(200,200,450,350,4);
    scanline(200,200,300,250,14);
	getch();
}

