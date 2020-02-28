#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>

char *buff1,*buff2;

void main()
{
    int gd=DETECT,gm;
    char *buff;
    int area1,area2,x,y;

    initgraph(&gd,&gm,"c:\\tc\\bgi");


     ellipse(240,80,115,65,10,40);

     circle(240,40,10);
     ellipse(215,40,15,100,20,40);
     ellipse(265,40,85,165,20,40);

     ellipse(160,90,270,0,80,25);
     ellipse(160,60,0,90,80,25);
     ellipse(160,75,270,90,15,40);
     ellipse(320,75,90,270,15,40);

     ellipse(320,90,180,270,80,25);
     ellipse(320,60,90,180,80,25);

     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(240,40,WHITE);
     setfillstyle(SOLID_FILL,BLUE);
     floodfill(200,80,WHITE);
     floodfill(290,60,WHITE);
     setfillstyle(SOLID_FILL,BROWN);
     floodfill(240,80,WHITE);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(240,110,WHITE);


     area1=imagesize(160,0,320,120);
     buff1=malloc(area1);

     getimage(160,0,320,120,buff1);
     clearviewport();

     ellipse(240,80,120,60,10,40);

     circle(240,40,10);
     ellipse(215,40,15,100,20,30);
     ellipse(265,40,85,165,20,30);

     ellipse(320,90,180,260,80,40);
     ellipse(320,60,100,180,80,40);
     ellipse(310,75,105,255,15,60);

     ellipse(160,90,280,0,80,40);
     ellipse(160,60,0,80,80,40);
     ellipse(170,75,285,75,15,60);
     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(240,40,WHITE);
     setfillstyle(SOLID_FILL,BLUE);
     floodfill(200,80,WHITE);
     floodfill(290,60,WHITE);
     setfillstyle(SOLID_FILL,BROWN);
     floodfill(240,80,WHITE);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(240,110,WHITE);


     area2=imagesize(160,0,320,140);
     buff2=malloc(area2);
     getimage(160,0,320,140,buff2);
     clearviewport();

     x=220;y=475;
     while(!kbhit())
     {
       if(y==25)
	  y=475;
       putimage(x,y,buff1,COPY_PUT);
       delay(30);
       clearviewport();
       putimage(x,y,buff2,COPY_PUT);
       delay(30);
       clearviewport();
       y=y-15;
      }
      getch();
      closegraph();
}