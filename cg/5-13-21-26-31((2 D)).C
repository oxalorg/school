#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

void mat(float a[100][3]);
void rot(float ang);
void trans(float tx,float ty);
void scal(float sx,float sy);
void shear(float Shx,float Shy);
void display(float x[100][3]);
void mult(float a[100][3],float b[100][3],int r1,int c2,int r2);

float n,a[100][3],translation[100][3],scaling[100][3],rotation[100][3],reflection[100][3],shearing[100][3],multiply[100][3];

void main()
{
    float i,j,tx,ty,sx,sy,Shx,Shy,flag=1;
    float ang,M,C;
    int v;

    while(flag==1)
    {
    int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	printf("enter the number of vertices\n");
	scanf("%f",&n);
	for(i=0;i<n;i++)
	{
	    printf("enter X,Y of vertex %f\n",i+1);
	    scanf("%f%f",&a[i][0],&a[i][1]);
	    a[i][2]=1;
	}
	mat(a);
getch();
    for(i=0;i<3;i++)
	for(j=0;j<3;j++)
    {
	if(i==j)
	    translation[i][j]=rotation[i][j]=reflection[i][j]=shearing[i][j]=scaling[i][j]=1;
	else
	     translation[i][j]=rotation[i][j]=reflection[i][j]=shearing[i][j]=scaling[i][j]=0;
    }

    printf("1.TRANSLATION\n2.ROTATION\n3.ROTATION ABOUT A POINT\n4.SCALING\n5.SCALING ABOUT A FIXED POINT\n6.REFLECTION\n7.SHEAR\n");
    printf("choose a 2D transformation\n");
    scanf("%d",&v);
    cleardevice();
    switch(v)
    {
    case(1):
	printf("enter Tx and Ty\n");
	scanf("%f%f",&tx,&ty);
	trans(tx,ty);
	mult(a,translation,n,3,3);
	break;
    case(2):
	printf("enter angle\n");
	scanf("%f",&ang);
		rot(ang);
		mult(a,rotation,n,3,3);
	break;
    case(3):
	printf("enter x,y of the fixed point\n");
	scanf("%f%f",&tx,&ty);
	printf("enter angle\n");
	scanf("%f",&ang);
	trans(-tx,-ty);
	rot(ang);
	mult(translation,rotation,3,3,3);
	trans(tx,ty);
	mult(multiply,translation,3,3,3);
	mult(a,multiply,n,3,3);
	break;
    case(4):
	printf("enter Sx and Sy\n");
	scanf("%f%f",&sx,&sy);
	scal(sx,sy);
	mult(a,scaling,n,3,3);
	break;
    case(5):
	printf("enter Sx and Sy\n");
	scanf("%f%f",&sx,&sy);
	printf("enter x,y of the fixed point\n");
	scanf("%f%f",&tx,&ty);
	trans(-tx,-ty);
	scal(sx,sy);
	mult(translation,scaling,3,3,3);
	trans(tx,ty);
	mult(multiply,translation,3,3,3);
		printf("hehehe\n");mat(a);mat(multiply);printf("hohoho\n");
	mult(a,multiply,n,3,3);
	printf("bola tha na\n");
		mat(multiply);
	break;
    case(6):
	printf("enter M and C from the equation y=Mx+C\n");
	scanf("%f%f",&M,&C);
	line(800+320,240-(M*800)-C,-800+320,240+(M*800)-C);
	trans(0,-C);
	rot((atan(-M)*180)/3.14);
		mult(translation,rotation,3,3,3);
	scal(1,-1);
		mult(multiply,scaling,3,3,3);
	rot((atan(M)*180)/3.14);
		mult(multiply,rotation,3,3,3);
	trans(0,C);
		mult(multiply,translation,3,3,3);
		mult(a,multiply,n,3,3);
	break;
    case(7):
	printf("enter Shx and Shy\n");
	scanf("%f %f",&Shx,&Shy);
	shear(Shx,Shy);
	mult(a,shearing,n,3,3);
	break;
    }
    line(0,240,640,240);
    line(320,0,320,480);
    display(a);
	getch();
    display(multiply);
    getch();
    printf("continue(yes->1/no->0)?\n");
    scanf("%f",&flag);
    }
    closegraph();
}

void rot(float ang)
{
    float a,b;
    float theta=(float)(3.14*ang)/180;
	a=sin(theta);
	b=cos(theta);
    rotation[0][0]=b;
    rotation[0][1]=a;
    rotation[1][0]=-a;
    rotation[1][1]=b;
}

void trans(float tx,float ty)
{
    translation[2][0]=tx;
    translation[2][1]=ty;
}

void scal(float sx,float sy)
{
    scaling[0][0]=sx;
    scaling[1][1]=sy;

}
void shear(float Shx,float Shy)
{
    shearing[1][0]=Shx;
    shearing[0][1]=Shy;
}

void display(float x[100][3])
{
    int i;
	x[n][0]=x[0][0];
	x[n][1]=x[0][1];
	for(i=0;i<n;i++)
	   {
	   line((int)(x[i][0]+320),(int)(240-x[i][1]),(int)(x[i+1][0]+320),(int)(240-x[i+1][1]));getch();
	   }
}

void mult(float a[100][3],float b[100][3],int r1,int c2,int r2)
{
int i,j,k;
float sum=0;
mat(a);mat(b);
for (i = 0; i < r1; i++) {
      for (j = 0; j < c2; j++) {
	for (k = 0; k < r2; k++) {
	  sum = sum + a[i][k]*b[k][j];
	  printf("%d\t",sum);
	}
	printf("\n");
	multiply[i][j] = sum;
	sum = 0;
      }
    }
    getch();
}



void mat(float a[100][3])
{
    int i,j;
    for(i=0;i<n;i++)
       {
	   for(j=0;j<3;j++)
	    printf("%f\t",a[i][j]);
	    printf("\n");
       }
    printf("-------------\n");
}
