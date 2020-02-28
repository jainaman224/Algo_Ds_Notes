#include<stdio.h>
#include<graphics.h>

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
void movingcircle()
{
	int i;
	while(!kbhit())
	{
	for(i=0;i<70;i++)
	{
		setcolor(YELLOW);
		circle(300-i,180+i,10);
		delay(10);
		setcolor(BLACK);
		circle(300-i,180+i,10);
	}
	for(i=0;i<70;i++)
	{
		setcolor(YELLOW);
		circle(230+i,250+i,10);
		delay(10);
		setcolor(BLACK);
		circle(230+i,250+i,10);
	}
	for(i=0;i<70;i++)
	{
		setcolor(YELLOW);
		circle(300+i,320-i,10);
		delay(10);
		setcolor(BLACK);
		circle(300+i,320-i,10);
	}
	for(i=0;i<70;i++)
	{
		setcolor(YELLOW);
		circle(370-i,250-i,10);
		delay(10);
		setcolor(BLACK);
		circle(370-i,250-i,10);
	}
	setcolor(YELLOW);
	circle(300,180,10);
	}
}

void main()
{
	int gd = DETECT, gm;
	int i,bounce,x=100;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	mpcircle(300,250,30,4);
	movingcircle();
	getch();
	closegraph();
}