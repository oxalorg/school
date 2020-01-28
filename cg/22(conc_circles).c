 #include <stdio.h>
  #include <conio.h>
  #include <graphics.h>
  #include <dos.h>

  int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        int i, j, midx, midy, radius, temp;

        /* initialize graphic mode */
        initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
        err = graphresult();

        if (err != grOk) {
                /* error occurred */
                printf("Graphics Error: %s\n",
                                grapherrormsg(err));
                return 0;
        }

        /* mid position of x and y axis */
        midx = getmaxx() / 2;
        midy = getmaxy() / 2;

        radius = 10;

        for (i = 1; i <= 15; i++) {
                radius = radius + 15;
                temp = radius;

                /* draws concentric circles from in to out */
                for (j = i; j >= 1; j--) {
                        setcolor(j);
                        setfillstyle(SOLID_FILL, j);
                        circle(midx, midy, temp);
                        floodfill(midx, midy, j);
                        temp = temp - 15;
                }
                sleep(1);
        }

        /* clears graphic screen */
        cleardevice();

        /* draws concentric circles out to in */
        for (i = 15; i >= 1; i--) {
                setcolor(i);
                setfillstyle(SOLID_FILL, i);
                circle(midx, midy, radius);
                floodfill(midx, midy, i);
                radius = radius - 15;
                delay(250);
        }

        getch();

        /* deallocate memory allocated for graphic screen */
        closegraph();
        return 0;
  }