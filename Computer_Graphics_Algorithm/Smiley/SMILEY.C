#include<stdio.h>
#include<graphics.h>
#include<math.h>
void bezier(int, int[] , int[]);
float binomial(float , int ,int);
float fact(int x);
float nCr(int n,int i);

void mpcircle(int xc, int yc, int r,int color)
{
	int e,x,y;
	e=1-r;
	x=0;
	y=r;
	do
	{
		putpixel(xc+x, yc+y, color);
		putpixel(xc+x, yc-y, color);
		putpixel(xc-x, yc+y, color);
		putpixel(xc-x, yc-y, color);
		putpixel(xc+y, yc+x, color);
		putpixel(xc+y, yc-x, color);
		putpixel(xc-y, yc+x, color);
		putpixel(xc-y, yc-x, color);
		if(e<0)
			e=2*x+3+e;
		else
		{
			e=2*(x-y)+5+e;
			y=y-1;
		}
		x=x+1;
	}while(x<y);
}

void main()
{
	int gd = DETECT, gm;
	int i,bounce,x=100;
	int x1[3]={200,250,300};
	int y1[3]={260,320,260};
	int naakx[3]={260,235,255};
	int naaky[3]={225,240,250};
	initgraph(&gd,&gm, "C:\\TC\\BGI");
	mpcircle(250, 250, 100, YELLOW);
	mpcircle(215, 200, 20, YELLOW);
	mpcircle(285, 200, 20, YELLOW);
	/*setfillstyle(1,GREEN);
	floodfill(215,200,YELLOW);
	floodfill(285,200,YELLOW);
	setfillstyle(1,YELLOW);
	floodfill(250,250,YELLOW);*/
	//delay(1000);

	bezier(3,x1,y1);
	bezier(3,naakx,naaky);
	getch();
	closegraph();
}
void bezier(int n, int x[], int y[])
{
	float u=0,sum_x,sum_y,temp_x,temp_y;
	int i;
	while(u<=1)
	{
		sum_x = 0;
		sum_y = 0;
		for(i=0; i<n; i++)
		{
			temp_x = x[i] * binomial(u,i,n);
			sum_x += temp_x;
			temp_y = y[i] * binomial(u,i,n);
			sum_y += temp_y;
		}
		//setcolor(3);
		putpixel((int)sum_x,(int)sum_y,3);
		u+=0.0001;
	}
}

float binomial(float u, int i,int n)
{
	float coeff=0;
	coeff = nCr(n,i)*pow(u,i)*pow(1-u,n-i-1);
	return coeff;
}
float nCr(int n,int i)
{
	float calc=0;
	calc=fact(n-1)/(fact(i)*fact(n-i-1));
	return calc;
}
float fact(int x)
{
	float f=1;
	int i;
	for(i=1;i<=x;i++)
		f*=i;
	return f;
}