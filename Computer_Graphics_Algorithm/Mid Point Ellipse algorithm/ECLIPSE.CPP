#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>



void midpoint_elipse(float,float,float,float);


void main()
{
int gd=DETECT, gm;
float a,b,xc,yc;
clrscr();
initgraph(&gd,&gm,"C:\\TC\\BGI");
//float x1,y1,x2,y2;
cout<<endl<<"----------midpoint eclipse Algorithm---------------";
cout<<endl;
//cout<<"enter a,b,xc,yc";
//cout<<endl;
//cin>>a>>b>>xc>>yc;

midpoint_elipse(50,100,200,200);
//line(150,200,150,100);
//line(250,200,250,100);
//line(150,100,250,100);

//midpoint_elipse(25,50,150,150);
//line(175,75,175,25);
//line(225,75,225,25);
//line(175,25,225,25);

getch();
closegraph();



}


void midpoint_elipse(float a,float b,float xc,float yc)
{

float x=0.0,y=b;

//region 1

float e = (b*b)-(a*a*b)+ (0.25*a*a);



do
{
putpixel(xc+x,yc+y,RED);
putpixel(xc+x,yc-y,YELLOW);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc-x,yc-y,GREEN);

	if(e < 0)
	{
	  x++;
	  e=e+(2*b*b*x)+(b*b);

	}
	else
	{
	  x++;
	  y--;
	  e =e +(2*b*b*x)-(2*a*a*y)+(b*b);

	}

}while((2*a*a*y)>(2*b*b*x));    // end of do while


// region 2

//e = (b*b)*(x+0.5)*(x+0.5)+(y-1)*(y-1)*(a*a)-(a*a*b*b);
 e= (b*b*x)+(b*b*0.25)-(2*y*a*a)+(a*a);
do
{
putpixel(xc+x,yc+y,RED);
putpixel(xc+x,yc-y,YELLOW);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc-x,yc-y,GREEN);

	 if(e>0)
	 {
	   y--;
	   e = e-(2*y*a*a)+(a*a);

	 }
	 else
	 {
	  y--;
	  x++;
	  e =e-(2*a*a*y)+(2*b*b*x)+(a*a);


	 }


   }while(y!=0.0);    // end of do-while


}// end of function
