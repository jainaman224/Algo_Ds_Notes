#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

// Driver Function 
int main()
{
	/* Variables Defined -> for coordinates xa, ya, xb, yb of line */ 
	int xa, ya, xb, yb, dx, dy, x, y, xend, p;
	int gd=DETECT, gm=0;

	initgraph(&gd, &gm, "C:\\Turboc3\\bGI");

	printf("Enter the values for xa, ya"); 
    scanf("%d %d", &xa, &ya); //Taking coordinates from User

    printf("Enter the values for xb, yb"); 
    scanf("%d %d" , &xb, &yb); //Taking coordinates from User

    dx = abs(xa - xb);
    dy = abs(ya - yb);

    p = 2 * dy - dx;

    if(xa > xb)
    	{ x=xb;
    	  y=yb;
    	  xend = xa;   
    	}
    else { x = xa;
    	   y = ya;
    	   xend = xb;
          }	 

    putpixel(x, y, 7); //To Plots Points 

    while(x < xend) {
    	x = x + 1;
    	if(p < 0){
    		p = p + 2 * dy;
    	}
    	else{ 
    		y = y + 1; 
            p = p + 2 * (dy - dx);
            putpixel(x, y, 7); //To Plots Points to draw line 
    	    }
    } 
    getch();
    return 0;
}