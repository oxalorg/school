#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void bresen(int x1,int y1,int x2,int y2);
int sign(float arg);

void main()
{
  int gd=DETECT,gm;
  int x1,y1,x2,y2,thick,i;
  initgraph(&gd,&gm,"\\TC\\bgi");
  cleardevice();
  printf("Bresenhams Line Drawing");
  printf("\nEnter the starting point's co-ordinate for line:");
  scanf("%d%d",&x1,&y1);
  printf("\nEnter the ending point's co-ordinate:");
  scanf("%d%d",&x2,&y2);
  bresen(x1,y1,x2,y2);
  getch();
  closegraph();
}

void bresen(int x1,int y1,int x2,int y2)
{
 int s1,s2,exchange,y,x,i;
 float dx,dy,g,temp;
 dx=abs(x2-x1);
 dy=abs(y2-y1);
 x=x1;
 y=y1;
 s1=sign(x2-x1);
 s2=sign(y2-y1);
 if(dy>dx)
 {
  temp=dx;
  dx=dy;
  dy=temp;
  exchange=1;
 }
 else
  exchange=0;
 g=2*dy-dx;
 i=1;
 while(i<=dx)
 {
  putpixel(x,y,WHITE);
  putpixel(x,y+1,WHITE);
	putpixel(x,y-1,WHITE);
	putpixel(x+1,y,WHITE);
	putpixel(x-1,y,WHITE);
	putpixel(x-1,y+1,WHITE);
	putpixel(x+1,y+1,WHITE);
	putpixel(x+1,y-1,WHITE);
  while(g>=0)
  {
   if(exchange==1)
    x=x+s1;
   else
    y=y+s2;
   g=g-2*dx;
  }
  if(exchange==1)
   y=y+s2;
  else
   x=x+s1;
  g=g+2*dy;
  i++;
 }
}

int sign(float arg)
{
 if(arg<0)
   return -1;
 else if(arg==0)
   return 0;
 else
   return 1;
}
