#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
 
void main()
{
        int gd=DETECT,gm;
        int newx=0,newy=0,inc_y=5;
 
        initgraph(&gd,&gm,"C:\\TC\\BGI");
        cleardevice();
        while(!kbhit())
        {
                ellipse(520-newx,200,30,330,90,30);
                circle(450-newx,193,3);
                line(430-newx,200,450-newx,200);
                line(597-newx,185,630-newx,170);
                line(597-newx,215,630-newx,227);
                line(630-newx,170,630-newx,227);
                line(597-newx,200,630-newx,200);
                line(597-newx,192,630-newx,187);
                line(597-newx,207,630-newx,213);
                line(500-newx,190,540-newx,150+newy);
                line(530-newx,190,540-newx,150+newy);
                if(newx>=500)
                        newx=0;
                if(newy>=82)
                        inc_y=-5;
                newx=newx+5;
                if(newy<=0)
                        inc_y=5;
                newy=newy+inc_y;
                delay(50);
                cleardevice();
        }
        cleardevice();
}