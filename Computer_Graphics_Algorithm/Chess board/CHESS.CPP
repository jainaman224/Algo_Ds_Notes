#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

int j ,i, k=0;

int x1=50,y1=50,x2=50,y2=50;


void main()
{

clrscr();

int gd=DETECT, gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
cout<<endl;
//line(600, 0, 600, 800);
for(j=0;j<=600;j+=50)
{
    for(i=0;i<600;i+=100)
    {
	// left top right bottom
	bar(i,k,50+i,50+j);

    }

    k +=50;
    i = k-i-j;
}
for(i=0;i<=600;i+=50)
{
     for(int j=0;j<=600;j+=50)
     {
	line(x1,y1,x1+j,y1);
     }

}

getch();
closegraph();

}