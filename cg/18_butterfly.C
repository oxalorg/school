#include<stdio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm,i;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 for(i=1;i<=30;i++)
 {
 setcolor(WHITE);
 setfillstyle(2,BLUE);
 ellipse(320,240,0,360,20,120);
 floodfill(320,240,WHITE);
 circle(320,110,10);
 line(320,110,340,90);
 line(320,110,300,90);
 if(i%2==0)
 {
 circle(380,240,10);
 circle(260,240,10);
 setfillstyle(1,YELLOW);
 floodfill(380,240,WHITE);
 floodfill(260,240,WHITE);
 }
 else
 {
 ellipse(380,240,0,360,15,8);
 ellipse(260,240,0,360,15,8);
 setfillstyle(1,YELLOW);
 floodfill(380,240,WHITE);
 floodfill(260,240,WHITE);
 }
 if(i%2==0)
 {
 //left expanded
 line(300,180,180,120);
 line(180,120,180,360);
 line(180,360,300,300);

 //right expanded
 line(340,180,460,120);
 line(460,120,460,360);
 line(460,360,340,300);
 }
 else
 {
 //left shrinked
 line(300,180,210,100);
 line(210,100,210,380);
 line(210,380,300,300);

 //right shrinked
 line(340,180,430,100);
 line(430,100,430,380);
 line(430,380,340,300);
 }
 delay(300);
 cleardevice();
 }
 getch();
 closegraph();
}