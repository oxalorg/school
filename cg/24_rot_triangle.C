#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int gd,gm,i,j,a,b,c,d;
    float theta;
    int x[8]={320,200,280,320};
    int y[4]={240,20,20,240};
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    cleardevice();

    theta=(float)(3.14*5)/180;

    while(!kbhit())
    {
	cleardevice();
	line(x[0],y[0],x[1],y[1]);
	line(x[0],y[0],x[2],y[2]);
	line(x[1],y[1],x[2],y[2]);
	for(i=0;i<4;i++)
	{
	x[i]=x[i]-320;
	y[i]=y[i]-240;
	}
	for(i=0;i<4;i++)
	{
	a=ceil(x[i]*sin(theta));
	b=ceil(y[i]*cos(theta));
	c=ceil(x[i]*cos(theta));
	d=ceil(y[i]*sin(theta));
	x[i]=c-d;
	y[i]=a+b;
	}
	for(i=0;i<4;i++)
	{
	x[i]=x[i]+320;
	y[i]=y[i]+240;
	}
	delay(10);

    }

}
