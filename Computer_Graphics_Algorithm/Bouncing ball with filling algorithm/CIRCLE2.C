#include<stdio.h>
#include<graphics.h>
void Boundary_Fill4(int x, int y, int bc, int fc)
{
	int current;
	current = getpixel(x, y);
	if(current!=bc && current!=fc)
	{
		putpixel(x,y,fc);
		//delay(10);
		Boundary_Fill4(x+1, y, bc, fc);
		Boundary_Fill4(x, y+1, bc, fc);
		Boundary_Fill4(x-1, y, bc, fc);
		Boundary_Fill4(x, y-1, bc, fc);

	}
}

//will not be used to fill a circle
void Boundary_Fill8(int x, int y, int bc, int fc)
{
	int current;
	current = getpixel(x, y);
	if(current!=bc && current!=fc)
	{
		putpixel(x,y,fc);
		delay(10);
		Boundary_Fill8(x+1, y, bc, fc);
		Boundary_Fill8(x, y+1, bc, fc);
		Boundary_Fill8(x-1, y, bc, fc);
		Boundary_Fill8(x, y-1, bc, fc);
		Boundary_Fill8(x+1, y+1, bc, fc);
		Boundary_Fill8(x+1, y-1, bc, fc);
		Boundary_Fill8(x-1, y+1, bc, fc);
		Boundary_Fill8(x-1, y-1, bc, fc);

	}
}

void Flood_Fill4(int x,int y, int fill_col, int old_col)
{
	if(getpixel(x,y)==old_col)
	{
		//delay(3);
		putpixel(x,y,fill_col);
		Flood_Fill4(x+1,y,fill_col,old_col);
		Flood_Fill4(x-1,y,fill_col,old_col);
		Flood_Fill4(x,y+1,fill_col,old_col);
		Flood_Fill4(x,y-1,fill_col,old_col);
	}
}

//will not be used to fill a circle
void Flood_Fill8(int x,int y, int fill_col, int old_col)
{
	if(getpixel(x,y)==old_col)
	{
		delay(3);
		putpixel(x,y,fill_col);
		Flood_Fill8(x-1,y-1,fill_col,old_col);
		Flood_Fill8(x+1,y-1,fill_col,old_col);
		Flood_Fill8(x-1,y+1,fill_col,old_col);
		Flood_Fill8(x+1,y+1,fill_col,old_col);
		Flood_Fill8(x+1,y,fill_col,old_col);
		Flood_Fill8(x-1,y,fill_col,old_col);
		Flood_Fill8(x,y+1,fill_col,old_col);
		Flood_Fill8(x,y-1,fill_col,old_col);
	}
}
void main()
{
	int gd = DETECT, gm;
	int i,bounce,x=100;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	//make horizontal line over which the ball will bounce
	//syntax: line(x1,y1,x2,y2);
	//line(0,350,getmaxx(),350);

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
				Boundary_Fill4(x,100+i,3,4);
				if(x==getmaxx()+20)
					break;
			}
			else
			{
				circle(x,100+i,20);
				Boundary_Fill4(x,100+i,3,4);
			}
			delay(1);
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
				Flood_Fill4(x,100+i,4,BLACK);
				if(x==getmaxx()+20)
					break;
			}
			else
			{
				circle(x,100+i,20);
				Flood_Fill4(x,100+i,4,BLACK);
			}
			delay(1);
		}
	}
	getch();
	closegraph();
}