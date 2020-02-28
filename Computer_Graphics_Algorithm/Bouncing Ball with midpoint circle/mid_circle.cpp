#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void sample(int xc, int yc ,int r)
void  draw_circle(int xc, int yc, int x , int y)

int xc, yc, x,y,r;
void main()
{
int gd=DETECT, gm;
clrscr();
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
putpixel(xc-x,yc+x,RED);
putpixel(xc-x,yc-x,RED);
s}

void sample(int xc, int yc ,int r)
{
    int x = 0 ,y = r;
    int e = 1-r;
    while(x<=y)
    {   
        if(e<0)
        {
            e = e + (2*x+1);
            x++;
        }
        else
        {
            e = e +(2*(x-y))+ 1;
            x++;
            y--;

        }
        draw_circle(xc,yc,x,y);
    }
}