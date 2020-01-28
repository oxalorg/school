#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
 
int scan, ascii;
 
void getkey()
{
    union REGS ii, oo;
    ii.h.ah = 0;
    int86(22, &ii, &oo);
    scan = oo.h.ah;
    ascii = oo.h.al;
}
 
void car(int x, int c)
{
    setcolor(c);
    line(x + 150, 100, x + 242, 100);
    ellipse(x + 242, 105, 0, 90, 10, 5);
    line(x + 150, 100, x + 120, 150);
    line(x + 252, 105, x + 280, 150);
    line(x + 100, 150, x + 320, 150);
    line(x + 100, 150, x + 100, 200);
    line(x + 320, 150, x + 320, 200);
    line(x + 100, 200, x + 110, 200);
    line(x + 320, 200, x + 310, 200);
    arc(x + 130, 200, 0, 180, 20);
    arc(x + 290, 200, 0, 180, 20);
    line(x + 270, 200, x + 150, 200);
    circle(x + 130, 200, 17);
    circle(x + 290, 200, 17);
 
}
 
void main()
{
    int gd = DETECT, gm = DETECT, i = 0, c = 1, prev = 80;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
 
    cleardevice();
 
    car(0, 15);
 
    while (!kbhit());
 
    while (1) {
	getkey();
	if (scan == 72) {
	    c++;
	    scan = prev;
	}
 
	if (scan == 80) {
	    if (c != 1)
		c--;
	    scan = prev;
	}
 
	if (ascii == 13)
	    break;
	if (scan == 77) {
	    prev = 77;
	    while (!kbhit()) {
		car(i, 0);
		i += c;
		car(i, 15);
		delay(20);
	    }
	}
	if (scan == 75) {
	    prev = 75;
	    while (!kbhit()) {
		car(i, 0);
		i -= c;
		car(i, 15);
		delay(20);
	    }
 
 
	}
	if (ascii == 32) {
	    prev = 80;
	    car(i, 15);
	    while (!kbhit());
	}
    }
 
    getch();
}