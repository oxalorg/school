#include<conio.h>
#include<dos.h>
#include<graphics.h>
 
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
    int gd = DETECT, gm = DETECT, i = -200;
    int ch = 'g';
    initgraph(&gd, &gm, "C:\\TC\\BGI");
 
    line(0, 70, 300, 70);
    line(450, 70, 630, 70);
    line(300, 70, 300, 0);
    line(450, 70, 450, 0);
    line(0, 230, 300, 230);
    line(450, 230, 630, 230);
    line(300, 230, 300, 500);
    line(450, 230, 450, 500);
    circle(280, 50, 10);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(280, 50, 15);
    car(i, 15);
    while (1) {
	while (!kbhit()) {
	    if (ch == 'r') {
		setfillstyle(SOLID_FILL, RED);
		floodfill(280, 50, 15);
		do {
		    while (!kbhit()) {
			if (i < -20 || i > -10) {
			    car(i++, 0);
			    car(i, 15);
			    delay(50);
			}
		    }
		    ch = getch();
		    if (ch == 'y') {
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(280, 50, 15);
		    }
		    if (ch == 'g') {
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(280, 50, 15);
		    }
		} while (ch != 'g' && ch != 13);
	    } else {
		car(i++, 0);
		car(i, 15);
		delay(50);
	    }
	}
	ch = getch();
	if (ch == 13)
	    break;
    }
 
 
    getch();
}