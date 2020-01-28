#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int gd,gm,i,Shy,Shx,a[100][2],n,multiply[100][2],j,k,sum=0;
    int b[100][2];
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    cleardevice();

printf("enter the number of vertices\n");
scanf("%d",&n);

printf("enter the x and y co ordinates \n");

for(i=0;i<n;i++)
{
printf("enter point %d :\n",(i+1));
scanf("%d",&a[i][0]);
scanf("%d",&a[i][1]);
}

a[i][0]=a[0][0];
a[i][1]=a[0][1];

printf("enter Shx and Shy\n");
scanf("%d",&Shx);
scanf("%d",&Shy);

b[0][0]=b[1][1]=1;
b[1][0]=Shx;
b[0][1]=Shy;
cleardevice();
drawpoly(n+1,a);

for (i = 0; i < (n+1); i++) {
      for (j = 0; j < 2; j++) {
	for (k = 0; k < 2; k++) {
	  sum = sum + a[i][k]*b[k][j];
	}

	multiply[i][j] = sum;
	sum = 0;
      }
    }

getch();
drawpoly(n+1,multiply);
getch();

}
 


