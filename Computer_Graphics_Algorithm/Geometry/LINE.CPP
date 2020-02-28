#include<conio.h>
#include<graphics.h>
#include<iostream.h>
#include<math.h>
#include<dos.h>
 
void main()
{
 
 int gd = DETECT ,gm;
 initgraph(&gd,&gm,"c:\\TC\\BGI");

/* Romen */
// line(100,100, 300,100);
// line(100,50,300,50)  ;
// line(150,100,150,50) ;
 //line(200,100,200,50) ;

/* HASH

line(100,100,500,100);
line(100,400,500,400);
line(250,100,250,400);
line(350,100,350,400);

*/

/* K
line(50,50,50,250);
line(200,200,50,150);
line(50,150,200,50);
*/
line(200,200,300,300);

 getch();
 closegraph();

}

void line(float x1,float y1, float x2,float y2)
{
float x,y,dx,dy,len,xinc,yinc;
int i;
 cout<<"enter the 1st point";
 cin>>x1>>y1  ;
 cout<<"enter the 2nd point";
 cin>>x2>>y2;
 
 dx = int(x2-x1);
 dy = int(y2-y1);
 
	if(dx>=dy)
	{
	len = dx;
 
	}
	else
	{
	len= dy;
	}
 
	//xinc and yinc
	xinc = dx/len;
	yinc = dy/len;
 
	x = x1;
	y = y1;
	i =1;
 
	while(i<=len)
	{
 
	x = x+xinc;
	y = y+yinc;
	putpixel((int)x, (int)y, WHITE);
	i = i+1;
	delay(100);
	}
}
