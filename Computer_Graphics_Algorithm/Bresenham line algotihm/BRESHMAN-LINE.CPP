
#include<iostream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void line1(int x1,int y1,int x2,int y2)
{

dx = x2-x1;
dy = y2 - y1;

    if(x1<x2)
        {
                xinc  = 1 ;
        }
    else
        {
                xinc =  -1; 
        }
    if(y1<y2)
        {
                yinc  = 1 ;
        }
    else
        {
                yinc =  -1; 
        }
    x = x1;
    y = y1;

    if(dx>=dy)
    {
        e = 2*(dy)- dx;
        while (x != x2)
        {
                    /* code */
                
                
                if(e<0)
                {
                    e = e+(2*dy);
                }
                else
                {
                    e = e + 2*(dy-dx);
                    y  = y + yinc;
                }
                x = x + xinc;
                
        }
    }
    else
    {
        
        e = 2*(dx)- dy;
        while (y != y2)
        {
                    /* code */
                 if(e<0)
                {
                    e = e+(2*dx);
                }
                else
                {
                    e = e + 2*(dx-dy);
                    x  = x + yinc;
                }
        }    
   
    }
    

          


}

void main()
{

    int gd = DETECT,gm;
    initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");

    line1(x1,y1,x2,y2)
    getch();
    closegraph();
}