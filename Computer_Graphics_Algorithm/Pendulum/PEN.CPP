#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
int xtop=300,ytop=150,cx=300,cy=400;
void pendulum()
{
	int i,m;
   	while(!kbhit())
	{
	//for(m=1;m<=5;m++)
	//{
	for(i=0;i<=20;i=i+2)
	{
		cx=cx+i;
		cy=cy-i+1;
		line(xtop,ytop,cx,cy);
		circle(cx,cy,5);
		delay(200);
		cleardevice();
	}
	for(i=0;i<=20;i=i+2)
	{
		cx=cx-i;
		cy=cy+i-1;
		line(xtop,ytop,cx,cy);
		circle(cx,cy,5);
		delay(200);
		cleardevice();
	}
	for(i=0;i<=20;i=i+2)
	{
		cx=cx-i;
		cy=cy-i+1;
		line(xtop,ytop,cx,cy);
		circle(cx,cy,5);
		delay(200);
		cleardevice();
	}
	for(i=0;i<=20;i=i+2)
	{
		cx=cx+i;
		cy=cy+i-1;
		line(xtop,ytop,cx,cy);
		circle(cx,cy,5);
		delay(200);
		cleardevice();
	}
	}
}

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	pendulum();
	getch();
	closegraph();
	}