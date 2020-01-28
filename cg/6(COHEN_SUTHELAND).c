#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>

typedef struct coordinate
{int x,y;
char code[4];
}PT;
void draww();
void drawl(PT p1,PT p2,int cl);
PT setc(PT p);
int visib(PT p1,PT p2);
PT resetep(PT p1,PT p2);

void main()
{
int gd=DETECT,gm,v;
PT p1,p2,ptemp;
initgraph(&gd,&gm,"C:\\TC\\BGI");
cleardevice();
printf("enter the endpoint 1(x,y)\n");
scanf("%d",&p1.x);
scanf("%d",&p1.y);
printf("enter the endpoint 2(x,y)\n");
scanf("%d",&p2.x);
scanf("%d",&p2.y);
draww();
getch();
drawl(p1,p2,15);
getch();
cleardevice();
p1=setc(p1);
p2=setc(p2);
v=visib(p1,p2);
switch(v)
{
	case(0):
	cleardevice();
	draww();
	drawl(p1,p2,15);
	break;

	case(1):
	draww();
	break;

	case(2):
	p1=resetep(p1,p2);
	p2=resetep(p2,p1);
	draww();
	drawl(p1,p2,15);
	break;
}
getch();
closegraph();
}

void draww()
{	setcolor(WHITE);//min(150,100) max(450,350)
line(150,100,450,100);
line(450,100,450,350);
line(450,350,150,350);
line(150,350,150,100);
}

void drawl(PT p1,PT p2,int cl)
{	setcolor(cl);
line(p1.x,p1.y,p2.x,p2.y);
}

PT setc(PT p)
{	PT ptemp;
if(p.y<100 ptemp.code[1]=1;//bottom
else ptemp.code[1]=0;

if(p.y>350) ptemp.code[0]=1;//top
else ptemp.code[0]=0;

if(p.x<150) ptemp.code[3]=1;//left
else ptemp.code[3]=0;

if(p.x>450) ptemp.code[2]=1;//right
else ptemp.code[2]=0;

ptemp.x=p.x;
ptemp.y=p.y;
return(ptemp);
}

int visib(PT p1,PT p2)
{
int i,flag=0;
for(i=0;i<4;i++)
	if((p1.code[i]==1)||(p2.code[i]==1))//check for complete visibility
		flag=1;
if(flag==0)
	return 0;
for(i=0;i<4;i++)
	if((p1.code[i]==1)&&(p2.code[i]==1))//check for complete invisibility
		flag=0;
if(flag==0)
	return 1;
return 2;//partially visible
}

PT resetep(PT p1,PT p2)
{
PT temp;
int x,y,i;
float m,k;

if(p1.code[3]==1)
x=150;
if(p1.code[2]==1)
x=450;

if((p1.code[3]==1)||(p1.code[2]==1))
{
m=(float)(p2.y-p1.y)/(p2.x-p1.x);
k=(float)(p1.y+(m*(x-p1.x)));
temp.y=k;
temp.x=x;
for(i=0;i<4;i++)
temp.code[i]=p1.code[i];
if(temp.y<=350&&temp.y>=100)
return temp;
}
if(p1.code[0]==1) y=350;
if(p1.code[1]==1) y=100;
if((p1.code[0]==1)||(p1.code[1]==1))
{
m=(float)(p2.y-p1.y)/(p2.x-p1.x);
k=(float)(p1.x+(float)((y-p1.y)/m));
temp.y=y;
temp.x=k;
for(i=0;i<4;i++)
temp.code[i]=p1.code[i];
return temp;
}
else
return p1;
}
