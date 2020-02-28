#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void mpellipse(float, float, float, float, int,int,int,int);
//void matmul(int[1][3] , int, int);
void main()
{
	float x1, y1, a, b;
	int gd = DETECT, gm;
	int x[1][3],y[3][3];
	int tx=0,ty=0,sx=1,sy=1;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	mpellipse(200, 200, 20, 40,tx,ty,sx,sy);
	getch();
	tx=40;
	ty=20;
	mpellipse(200,200,20,40,tx,ty,sx,sy);
	getch();
	sx=2;
	sy=2;
	mpellipse(200,200,20,40,tx,ty,sx,sy);
	getch();
	closegraph();
}
void mpellipse(float x1, float y1, float a, float b,int tx,int ty,int sx,int sy)
{
	float x,y,e;
	x1=x1+tx;
	y1=y1+ty;
	a=a*sx;
	b=b*sy;
	x=0;
	y=b;
	e=(b*b)-(a*a*b)+((a*a)/4);
	do
	{
		putpixel(x1+x,y1+y,2);
		putpixel(x1+x,y1-y,2);
		putpixel(x1-x,y1+y,2);
		putpixel(x1-x,y1-y,2);
		if(e<=0)
		{
			x++;
			e+=(2*b*b*x)+(b*b);
		}
		else
		{
			x++;
			y--;
			e+=(2*b*b*x)-(2*a*a*y)+(b*b);
		}
	}while((2*x*b*b)<(2*y*a*a));
	//e=(x*b*b)-(2*y*a*a)+(a*a)+((b*b)/4);
	e=((x+0.5)*(x+0.5)*b*b)+((y-1)*(y-1)*a*a)-(a*a*b*b);
	do
	{
		putpixel(x1+x,y1+y,2);
		putpixel(x1+x,y1-y,2);
		putpixel(x1-x,y1+y,2);
		putpixel(x1-x,y1-y,2);
		if(e<=0)
		{
			x++;
			y--;
			e=e-(2*a*a*y)+(2*b*b*x)+(a*a);
		}
		else
		{
			y--;
			e=e-(2*a*a*y)+(a*a);
		}
	}while(y>0);
}
/*
void matmul(int mat1[1][3], int tx, int ty)
{
	int mat2[3][3] = {
	{1,0,0},
	{0,1,0},
	{tx,ty,1}
	};
	int i,j,k,sum,ans[1][3];
	for(i=0;i<1;i++)
	{
		for(j=0;j<3;j++)
		{
			sum = 0;
			for(k=0;k<3;k++)
			{
				sum=sum+mat1[i][k]*mat2[k][j];
			}
			ans[i][j]=sum;
		}
	}
	putpixel(ans[0][0],ans[0][1],RED);
}*/