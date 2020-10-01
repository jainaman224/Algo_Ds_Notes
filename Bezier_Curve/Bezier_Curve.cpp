#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <iostream.h>

//function that takes coordinates of control points as input and then draws the curve
void bezier (int x[4], int y[4])
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, "");

    for (double t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = pow (1-t, 3) * x[0] + 3 * t * pow (1-t, 2) * x[1] + 3 * pow (t, 2) * (1-t) * x[2] + pow (t, 3) * x[3];
        double yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] + 3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];
        putpixel (xt, yt, WHITE);
    }
    for (int i = 0; i < 4; i++)
        putpixel (x[i], y[i], YELLOW);
    return;
}

void main()
{
    // two arrays to hold the coordinates of 4 control points
    int x[4] = {23, 49, 95, 130};
    int y[4] = {76, 92, 112, 73};
    bezier (x, y);
    closegraph();
}

//Sample output - https://ibb.co/qJttpQm
