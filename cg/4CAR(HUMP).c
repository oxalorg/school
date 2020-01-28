#include<conio.h>
#include<dos.h>
#include<graphics.h>
 
void car(int x, int c, int i_f_y, int i_r_y)
{
    setcolor(c);
    line(x + 150, 100+i_r_y, x + 242, 100+i_f_y);
    ellipse(x + 242, 105+i_f_y, 0, 90, 10, 5);
    line(x + 150, 100+i_r_y, x + 120, 150+i_r_y);
    line(x + 252, 105+i_f_y, x + 280, 150+i_f_y);
    line(x + 100, 150+i_r_y, x + 320, 150+i_f_y);
    line(x + 100, 150+i_r_y, x + 100, 200+i_r_y);
    line(x + 320, 150+i_f_y, x + 320, 200+i_f_y);
    line(x + 100, 200+i_r_y, x + 110, 200+i_r_y);
    line(x + 320, 200+i_f_y, x + 310, 200+i_f_y);
    arc(x + 130, 200+i_r_y, 0, 180, 20);
    arc(x + 290, 200+i_f_y, 0, 180, 20);
    line(x + 270, 200+i_f_y, x + 150, 200+i_r_y);
    circle(x + 130, 200+i_r_y, 17);
    circle(x + 290, 200+i_f_y, 17);
 
}
 
 
void main()
{
    int gd = DETECT, gm = DETECT, i = -200;
    int iy=0, prv_iy=0, prv_iry=0;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
 
    ellipse(318, 220, 0, 180, 15, 8);
    line(0,220,640,220);
    setfillstyle(SOLID_FILL, RED);
    floodfill(318,215,15);
    car(i, 15,0,0);
 
    while (!kbhit()) {
		car(i++, 0,prv_iy,prv_iry);
		if(i>0 && i<50) {
			car(i,15,iy,0);
			prv_iy = iy;
			if(i>25){
				if(i%2==0) iy++;
			} else {
				if(i%2==0) iy--;
			}
		} else if(i>160 && i<210) {
			car(i,15,0,iy);
			prv_iry = iy;
			if(i>185){
				if(i%2==0) iy++;
			} else {
				if(i%2==0) iy--;
			}
		} else if(i>500) {
			break;
		} else {
			prv_iy = 0;
			prv_iry = 0;
			iy = 0;
			car(i, 15,0,0);
		}
		delay(20);
    }
}