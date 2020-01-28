#include<stdio.h>
#include<graphics.h>
void diagram(int check);
void lighting();
void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 diagram(0);
 diagram(0);
 diagram(0);
 closegraph();
}

void diagram(int check)
{
  int i;
 char str[7]={'W','e','l','c','o','m','e'};
 setcolor(WHITE);
 rectangle(70,40,570,440);
 rectangle(170,140,470,340);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
 outtextxy(240,200,str);
 for(i=0;i<=400;i=i+100)
 {
 circle(70+50+i,40+50,30);
 }
 for(i=0;i<=100;i=i+100)
 {
 circle(520,190+i,30);
 }
 for(i=400;i>=0;i=i-100)
 {
 circle(70+50+i,390,30);
 }
 for(i=0;i>=-100;i=i-100)
 {
 circle(120,290+i,30);
 }
 if(check==0)
 {
 lighting();
 }
}

 void lighting()
 {
 int i;
 setfillstyle(1,RED);
 for(i=0;i<=400;i=i+100)
 {
 floodfill(70+50+i,40+50,WHITE);
 delay(200);
 cleardevice();
 diagram(1);
 }
 for(i=0;i<=100;i=i+100)
 {
 floodfill(520,190+i,WHITE);
 delay(200);
 cleardevice();
 diagram(1);
 }

 for(i=400;i>=0;i=i-100)
 {
 floodfill(70+50+i,390,WHITE);
 delay(200);
 cleardevice();
 diagram(1);
 }
 for(i=0;i>=-100;i=i-100)
 {
 floodfill(120,290+i,WHITE);
 delay(200);
 cleardevice();
 diagram(1);
 }
 cleardevice();
}