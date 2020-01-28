#include<stdio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm,i,x,y,c=0;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 setcolor(WHITE);
 //flower pot
 line(270,440,370,440);
 line(270,440,320,350);
 line(370,440,320,350);
 setfillstyle(2,GREEN);
 floodfill(320,420,WHITE);
 setcolor(YELLOW);
 //level 1 & 3 upside cracker
 for(y=0;y<=80;y=y+80)
 {
 line(280,310-y,295,330-y);
 line(295,310-y,310,330-y);
 line(320,310-y,320,330-y);
 line(330,330-y,345,310-y);
 line(345,330-y,360,310-y);
 //level 3 especially
 if(c==1)
 {
  line(265,310-y,280,330-y);
  line(250,310-y,265,330-y);
  line(360,330-y,375,310-y);
  line(375,330-y,390,310-y);
 }
 delay(250);
 //level 2 & 4 upside cracker
 line(280,270-y,295,290-y);
 line(295,270-y,310,290-y);
 line(320,270-y,320,290-y);
 line(330,290-y,345,270-y);
 line(345,290-y,360,270-y);

 line(265,270-y,280,290-y);
 line(360,290-y,375,270-y);
 //level 4 especially
 if(c==1)
 {
  line(250,270-y,265,290-y);
  line(235,270-y,250,290-y);
  line(375,290-y,390,270-y);
  line(390,290-y,405,270-y);
 }

 delay(400);
 c=1;
 }


 setcolor(RED);
 for(y=0;y<=80;y=y+80)
 {
 //downside level 3 & 1
 line(295,190+y,280,210+y);
 line(280,190+y,265,210+y);
 line(265,190+y,250,210+y);
 if(c==1)
 {
 line(250,190+y,235,210+y);
 line(235,190+y,220,210+y);
 }
 line(345,190+y,360,210+y);
 line(360,190+y,375,210+y);
 line(375,190+y,390,210+y);
 if(c==1)
 {
 line(390,190+y,405,210+y);
 line(405,190+y,420,210+y);
 }
 delay(250);
 //downside level 4 & 2
 line(295,230+y,280,250+y);
 line(280,230+y,265,250+y);

 if(c==1)
 {
 line(265,230+y,250,250+y);
 line(250,230+y,235,250+y);

 }
 line(345,230+y,360,250+y);
 line(360,230+y,375,250+y);

 if(c==1)
 {
 line(375,230+y,390,250+y);
 line(390,230+y,405,250+y);

 }
 delay(400);
 c--;
 }
 cleardevice();
 //final image
 setcolor(WHITE);
 line(270,440,370,440);
 line(270,440,320,350);
 line(370,440,320,350);
 setfillstyle(2,GREEN);
 floodfill(320,420,WHITE);
 delay(300);
 cleardevice();
 getch();
 closegraph();
}