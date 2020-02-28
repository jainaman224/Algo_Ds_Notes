//normal bouncing ball
#include<stdio.h>
#include<graphics.h>

void main()
{
	int gd = DETECT, gm;
	int i,bounce,x=100;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	//bouncing ball
	bounce = 0;
	while(x!=getmaxx()+20)
	{
		for(i=(10*bounce); i<250-20; i++)
		{
			cleardevice();
			setcolor(3);
			if(i%7==0)
			{
				circle(x++,100+i,20);
				if(x==getmaxx()+20)
					break;
			}
			else
			{
				circle(x,100+i,20);
			}
			delay(2);
		}
		bounce++;
		if(x==getmaxx()+20)
			break;
		for(i=250-20; i>(10*bounce); i--)
		{
			cleardevice();
			setcolor(3);
			if(i%7==0)
			{
				circle(x++,100+i,20);
				if(x==getmaxx()+20)
					break;
			}
			else
			{
				circle(x,100+i,20);
			}
			delay(3);
		}
	}
	getch();
	closegraph();
}