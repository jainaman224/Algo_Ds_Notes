#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>

void main()
{
    clrscr();

    //radius is the radius of the circle
    //x0 and y0 is the centre of the circle
    //x and y are an arbitrary point on circle
    //p is the decision parameter
    int x, y, x0, y0, p, radius;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    cout<<"Enter the radius of circle.";
    cin>>radius;
    cout<<"Enter co-ordinates of centre of circle.";
    cin>>x0>>y0;

    x = 0;
    y = radius;
    //putpixel is used to plot the point
    putpixel(x0+x, y0-y, 10);

    p = 3 - (2 * radius);
    while(x <= y)
    {
        if(p < 0)
            {
		p = p + 4 * x + 6;
	    }
        else
            {
		p = p + 4 * (x - y) + 10;
                y--;
	    }
        x++;

        //since circle is 8 point symmetric so using this property to plot the circle
        //first and second input of putpixel are the coordiantes while the third one
	//is the color of the line
        putpixel(x0+x, y0+y, 10);
        putpixel(x0-x, y0-y, 9);
        putpixel(x0+x, y0-y, 8);
        putpixel(x0-x, y0+y, 7);
        putpixel(x0+y, y0+x, 6);
        putpixel(x0-y, y0-x, 5);
        putpixel(x0+y, y0-x, 4);
        putpixel(x0-y, y0+x, 3);
    }
    getch();
    closegraph();
}

//sample output - https://ibb.co/FzJbVqT

