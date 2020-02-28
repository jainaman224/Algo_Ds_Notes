#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void draw_circle(int xc, int yc, int x, int y);
void midcirle(int xc ,int yc , int r);

void main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int i;
    float x,y;

    for ( i = 0; i < 360; i+=10)
    {
	/* code */
	//int xc=200 , yc = 200 ;

	x = 100*(cos((i+200)*3.14/180));
	y = 100*(sin((i+200)*3.14/180));
	midcirle(300,300, 100);
	setcolor(RED);
	setfillstyle(SOLID_FILL,GREEN);
	midcirle(x+300,y+300, 20);
	floodfill(x+300,y+300,RED);

	delay(100);
	cleardevice();
    }
    


    getch();
	closegraph();
}

void midcirle(int xc ,int yc , int r)
{
    int x = 0, y =r;
    int e = 1-r;

    while (x<=y)
    {
    
        if(e<=0)
        {
            e+= (2*x+3);
        }
        else
        {
            e+= 2*(x-y)+5;
            y--;
        }
        x++;
        draw_circle(xc,yc,x,y);
        
        
    }
}
void draw_circle(int xc, int yc, int x, int y)
{
        putpixel(xc+x,yc+y,RED);
        putpixel(xc+x,yc-y,RED);
        putpixel(xc-x,yc+y,RED);
        putpixel(xc-x,yc-y,RED);
        putpixel(xc+y,yc+x,RED);
        putpixel(xc+y,yc-x,RED);
        putpixel(xc-y,yc+x,RED);
        putpixel(xc-y,yc-x,RED);
}   