#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void main()
{
    float x1, x2, y1, y2, dx, dy, steps, xi, yi, i;
    //xi=x increment, yi=y increment
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");

    printf("Enter the starting co-ordinates of line.");
    scanf("%f%f%", &x1, &y1);
    printf("Enter the ending co-ordinates of line.");
    scanf("%f%f", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx)>abs(dy))
	steps = abs(dx);
    else
	steps = abs(dy);

    xi = dx / steps;
    yi = dy / steps;

    for(i=1; i<steps; i++)
    {
        putpixel(x1, y1, 15);
        x1 = x1 + xi ;
        y1 = y1 + yi;
    }
    getch();
    closegraph();

}

//Sample output - https://ibb.co/3mqM8MK

