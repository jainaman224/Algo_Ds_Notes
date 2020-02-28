#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

float dx,dy,xinc,yinc,x,y,len,templen;

void normal(int x1,int y1,int x2,int y2)
{
 dx=x2-x1;
 dy=y2-y1;
 if(abs(dx)>abs(dy))
  len=abs(dx);
 else
  len=abs(dy);
 xinc=dx/len;
 yinc=dy/len;
 x=x1;
 y=y1;
 templen=len;
 while(len!=0)
 {
  x=x+xinc;
  y=y+yinc;
  putpixel((int)x,(int)y,YELLOW);
  len--;
  delay(10);
 }
}

void main()
{
 clrscr();
 int gd=DETECT,gm,x1,x2,y1,y2,x3,y3,a=1,ch;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 while(a==1)
 {
  cout<<"\n1. Line\t2. Triangle\t3. Rectangle\t4. Exit\nEnter shape choice: ";
  cin>>ch;
  cleardevice();
  switch(ch)
  {
   case 1: cout<<"Enter first point co ordinates: ";
	   cin>>x1>>y1;
	   cout<<"\nEnter second point co ordinates: ";
	   cin>>x2>>y2;
	   cleardevice();
	   normal(x1,y1,x2,y2);
	   break;
   case 2: cout<<"Enter first point co ordinates: ";
	   cin>>x1>>y1;
	   cout<<"\nEnter second point co ordinates: ";
	   cin>>x2>>y2;
	   cout<<"\nEnter third point co ordinates: ";
	   cin>>x3>>y3;
	   cleardevice();
	   normal(x1,y1,x2,y2);
	   normal(x2,y2,x3,y3);
	   normal(x3,y3,x1,y1);
	   break;
   case 3: cout<<"Enter first point co ordinates: ";
	   cin>>x1>>y1;
	   cout<<"\nEnter opposite co ordinates: ";
	   cin>>x2>>y2;
	   cleardevice();
	   normal(x1,y1,x1,y2);
	   normal(x1,y2,x2,y2);
	   normal(x2,y2,x2,y1);
	   normal(x1,y1,x2,y1);
	   break;
   case 4: a=0;
	   break;
  }
  getch();
  cleardevice();
 }
 closegraph();
}
