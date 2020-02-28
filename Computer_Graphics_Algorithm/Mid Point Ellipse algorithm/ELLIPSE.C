#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void mpellipse(float, float, float, float);
void main()
{
	float x1, y1, a, b;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	printf("Mid point ellipse drawing algorithm\n");
	printf("Enter Center coordinates : ");
	scanf("%f%f",&x1,&y1);
	printf("Enter x-radius and y-radius: ");
	printf("\n\tx-radius : ");
	scanf("%f",&a);	
	printf("\ty-radius : ");
	scanf("%f",&b);
	mpellipse(x1, y1, a, b);
	getch();
	closegraph();
}
void mpellipse(float x1, float y1, float a, float b)
{
	float x,y,e;
	cleardevice();
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