#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void main()
{
    int xc=100,yc=300;
    int i ,j;
    
    int gd=DETECT,gm=DETECT;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    
    for ( i = 0; i < 40; i++)
    {
        circle(xc,yc,100);
        line(0,400,800,400)

        for(j=0;j<360;j+=20)
        {
            r1 = 100*cos( ((th*3.14)/180) + ((j*3.14)/180));
            r2 = 100*sin( ((th*3.14)/180) + ((j*3.14)/180));
            line(xc,yc,xc+r1 ,yc+r2 );
        }
        th = th +30;
        xc = xc +20;

        delay(100);
        cleardevice();

    }
    
    getch();
    closegraph();

}