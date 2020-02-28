#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>

float max(float ,float);
float min(float ,float);
void main()
{
	int gd=DETECT, gm;
	float dx, dy, xw1, xw2, yw1, yw2, x1, x2, y1, y2;
	float p[4], q[4];
	float t1=0,t2=1;
	int i;
	initgraph(&gd, &gm, "C://TurboC3//BGI");
	printf("Enter the diagonally opposite coordinates of the window: \n");
	scanf("%f%f%f%f", &xw1, &yw1, &xw2, &yw2);
	printf("\nEnter coordinates of the line: \n");
	scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
	cleardevice();
	//initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	setcolor(4);
	rectangle(xw1, yw1, xw2, yw2);
	setcolor(3);
	line(x1, y1, x2, y2);
	getch();
	dx= x2-x1;
	dy=y2-y1;
	p[0]= (-1)*dx;
	p[1]=dx;
	p[2]= (-1)*dy;
	p[3]= dy;
	q[0]= x1- min(xw1,xw2);
	q[1]= max(xw1,xw2) - x1;
	q[2]= y1- min(yw1, yw2);
	q[3]= max(yw1, yw2)- y1;
	for(i=0; i<=3; i++)
	{
		if(p[i]==0 && q[i]<0)
		{
			printf("\nLine is outside the window");
			getch();
			exit(1);
		}
		if(p[i]<0)
			t1= max(t1, q[i]/p[i]);
		if(p[i]>0)
			t2= min(t2, q[i]/p[i]);
	}
	if(t1>t2)
	{
		printf("\nLine is outside");
		getch();
		exit(1);
	}
	else
	{
		x2= x1+ (t2*dx);
		y2= y1+ (t2*dy);
		x1= x1+ (t1*dx);
		y1= y1+ (t1*dy);
		setcolor(15);
		line(x1,y1,x2,y2);
	}
	getch();
	closegraph();
}

float max(float a, float b)
{

	if(a<b)
		return b;
	else return a;
}
float min(float a, float b)
{
	if(a<b)
		return a;
	else return b;
}