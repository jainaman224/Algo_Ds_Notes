#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>


void draw_circle(int xc,int yc,int x,int y);
void Breshman_circle(int xc,int yc,int r);


void main()
{
int gd=DETECT, gm;
int xc,yc,r;
clrscr();
initgraph(&gd,&gm,"C:\\TC\\BGI");
//float x1,y1,x2,y2;
cout<<"-------------Breshman circle Algorithm---------------";

cout<<"enter xc ,yc and r";
cout<<endl;
cin>>xc>>yc>>r;

setcolor(RED);
setfillstyle(SOLID_FILL , BLUE);
Breshman_circle(xc,yc,r);
floodfill(xc,yc, RED);
getch();
closegraph();



}

void Breshman_circle(int xc,int yc,int r)
{
int x = 0, y=r,e = 3-(2*r);
draw_circle(xc,yc,x,y);

while(x<=y)
{
	if(e<=0)
	{
	e = e + (4*x) +6;
	}

	else
	{
	e= e + 4*(x-y)+10;
	y--;
	}

	x++;

	draw_circle(xc,yc,x,y);

} // end of while

}// end of void

void draw_circle(int xc,int yc,int x,int y)
{

putpixel(x+xc,y+yc,RED);
delay(100);
putpixel(x+xc,-y+yc,YELLOW);
delay(100);
putpixel(-x+xc,-y+yc,WHITE);
delay(100);
putpixel(-x+xc,y+yc,BLUE);
delay(100);
putpixel(y+xc,x+yc,YELLOW);
delay(100);
putpixel(y+xc,-x+yc,WHITE);
delay(100);
putpixel(-y+xc,-x+yc,GREEN);
delay(100);
putpixel(-y+xc,x+yc,RED);



}
