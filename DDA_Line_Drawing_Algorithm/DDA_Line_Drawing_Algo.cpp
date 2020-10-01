#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<graphics.h>

void main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");

    //x1 and y1 are initial coordinates of line
    //x2 and y2 are final coordinates of line
    float x1, x2, y1, y2;

    cout<<"Enter the starting coordinates of line = ";
    cin>>x1>>y1;
    cout<<"Enter the ending co-ordinates of line = ";
    cin>>x2>>y2;

    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps;
    if(abs(dx)>abs(dy))
	steps = abs(dx);
    else
	steps = abs(dy);

    float xi, yi;
    //xi=x increment, yi=y increment
    xi = dx / steps;
    yi = dy / steps;

    for(int i=1; i<steps; i++)
    {
        putpixel(x1, y1, 15);
        x1 = x1 + xi ;
        y1 = y1 + yi;
    }
    getch();
    closegraph();

}

//Sample output - https://ibb.co/3mqM8MK

