#include<stdio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm,i,x,y,c=1;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 setcolor(LIGHTGREEN);
 for(x=-180;x<=180,c<=4;x=x+30)
 {
 //top cone shape of tree
 line(320+x,100,240+x,180);
 line(320+x,100,400+x,180);

 //body
 for(y=0;y<=80;y=y+80)
 {
 line(240+x,180+y,270+x,180+y);
 line(370+x,180+y,400+x,180+y);
 line(240+x,260+y,270+x,180+y);
 line(370+x,180+y,400+x,260+y);
 }

 //base
 line(240+x,340,400+x,340);
 setfillstyle(1,GREEN);
 floodfill(320+x,240,LIGHTGREEN);
 setcolor(BROWN);
 line(270+x,440,370+x,440);
 line(300+x,340,300+x,440);
 line(340+x,340,340+x,440);
 setcolor(LIGHTGREEN);
 delay(400);
 cleardevice();
 if(x==180)
 {
 x=-180;
 c++;
 }

 }
 getch();


 closegraph();
}