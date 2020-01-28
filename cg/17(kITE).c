#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
#include<math.h>
 
void main()
{
        int gd=DETECT,gm;
        int color;
        int x=10,y=1,inc_x=10,inc_y=10;
        int poly[10];
 
        initgraph(&gd,&gm,"C:\\TC\\BGI ");
 
        while(!kbhit())
        {
                x += inc_x;
                if(x > 200)
                        inc_x = -5;
                if(x < 0 )
                        inc_x = 10;
                y += inc_y;
                if(y > 100)
                        inc_y = -10;
                if(y < 0 )
                        inc_y = 10;
                cleardevice();
                setcolor(WHITE);
                setbkcolor(BLUE);
 
                poly[0]=100+x;
                poly[1]=50+y;
                poly[2]=140+x;
                poly[3]=100+y;
                poly[4]=100+x;
                poly[5]=155+y;
                poly[6]=60+x;
                poly[7]=100+y;
                poly[8]=100+x;
                poly[9]=50+y;
                drawpoly(5,poly);
                setfillstyle(SOLID_FILL,RED);
                fillpoly(5,poly);
 
                setlinestyle(SOLID_LINE,1,3);
                line(100+x,155+y,100+x,180+y);
                line(100+x,155+y,110+x,180+y);
                line(100+x,155+y,90+x,180+y);
 
                setlinestyle(SOLID_LINE,1,0);
                line(0,480,100+x,90+y);
                line(100+x,90+y,130+x,100+y);
                line(100+x,90+y,70+x,100+y);
                line(100+x,90+y,100+x,70+y);
 
                delay(260);
        }
        setlinestyle(SOLID_LINE,0,0);
        fflush(stdin);
}