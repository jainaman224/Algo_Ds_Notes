#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

int xc,yc, x,y,r;

void sample(int xc, int yc ,int r);
void draw_circle(int xc, int yc, int x,int y);


void main()
{
clrscr();

int gd=DETECT, gm;

initgraph(&gd,&gm,"C:\\TC\\BGI");
cout<<endl<<"----------midpoint eclipse Algorithm---------------";
cout<<endl;

cout<<"Enter the xc and yc :";
cin>>xc>>yc;

cout<<"Enter r :";
cin>>r;

sample(xc,yc,r);
getch();
closegraph();

}

void draw_circle(int xc ,int yc, int x , int y)
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

void sample(int xc, int yc ,int r)
{
    int x = 0 ,y = r;
    int e = 1-r;
    while(x<=y)
    {
	if(e<0)
	{
	    e = e + (2*x+3);

	}
	else
	{
	    e = e + 2*(x-y) + 5;
	    y--;

	}
	x++;
	draw_circle(xc,yc,x,y);
    }
}