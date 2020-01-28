#include<stdio.h>
#include<conio.h>
#include<graphics.h>
 
void boundary_fill(int x, int y, int fcolor, int bcolor)
{
 
    if ((getpixel(x, y) != fcolor) && (getpixel(x, y) != bcolor)) {
	putpixel(x, y, fcolor);
	boundary_fill(x + 1, y, fcolor, bcolor);
	boundary_fill(x - 1, y, fcolor, bcolor);
	boundary_fill(x, y - 1, fcolor, bcolor);
	boundary_fill(x, y + 1, fcolor, bcolor);
	boundary_fill(x + 1, y - 1, fcolor, bcolor);
	boundary_fill(x + 1, y + 1, fcolor, bcolor);
	boundary_fill(x - 1, y - 1, fcolor, bcolor);
	boundary_fill(x - 1, y + 1, fcolor, bcolor);
    }
}
 
 
void main()
{
    int x, y, fcolor, bcolor;
 
    clrscr();
    printf("Enter the seed point (x,y) : ");
    scanf("%d%d", &x, &y);
    printf("Enter boundary color : ");
    scanf("%d", &bcolor);
    printf("Enter new color : ");
    scanf("%d", &fcolor);
 
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    cleardevice();
 
    /* 
       please ceate your own shapes  
       to make a closed area. 
     */
 
    boundary_fill(x, y, fcolor, bcolor);
 
    getch();
}