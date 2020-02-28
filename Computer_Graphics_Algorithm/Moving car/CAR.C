// C program to draw a moving car. This 
// program run in gcc compiler having 
// graphics.h library installed 
#include <graphics.h> 
#include <stdio.h> 

int abs(int n)
{
return((n>0)?n:(n*(-1)));
}
// Function to draw line
void DDA(int x0,int y0,int x1,int y1)
{
 int dx,dy,length,i;
 float xinc,yinc,x,y;
 dx=x1-x0;
 dy=y1-y0;
 length=abs(dx)>=abs(dy)?abs(dx):abs(dy);
 xinc=dx/(float)length;
 yinc=dy/(float)length;
 x=x0;
 y=y0;
 for(i=0;i<length;i++)
 {
  putpixel(x,y,GREEN);
  x=x+xinc;
  y=y+yinc;
 }
}

//Function to draw Circle
 void midcircle(int x1,int y1,int r)
 {
	 int e,x=0,y;
	 y=r;
	 e=1-r;
	 do{
		 putpixel(x1+x, y1+y,GREEN);
		 putpixel(x1+x,y1-y,GREEN);
		 putpixel(x1-x,y1+y,GREEN);
		 putpixel(x1-x,y1-y,GREEN);
		 putpixel(x1+y,y1+x,GREEN);
		 putpixel(x1+y,y1-x,GREEN);
		 putpixel(x1-y,y1+x,GREEN);
		 putpixel(x1-y,y1-x,GREEN);
		 
		 if(e<0)
			 e=2*x+3+e;
		 else{
			 e=2*(x-y)+5+e;
			 y=y-1;
		 }
		 x=x+1;
		 
	 } while(x<y);
 }

// Function to draw moving car 
void draw_moving_car(void) { 

	int i, j = 0, gd = DETECT, gm; 

	// Passed three arguments to initgraph 
	// function to initialize graphics mode 
	initgraph(&gd, &gm, ""); 

	for (i = 0; i <= 420; i = i + 10) { 

		// Set color of car as red 
		setcolor(RED); 

		// Thease DDAs for bonnet and 
		// body of car 
		DDA(0 + i, 300, 210 + i, 300); 
		DDA(50 + i, 300, 75 + i, 270); 
		DDA(75 + i, 270, 150 + i, 270); 
		DDA(150 + i, 270, 165 + i, 300); 
		DDA(0 + i, 300, 0 + i, 330); 
		DDA(210 + i, 300, 210 + i, 330); 

		// For left wheel of car 
		midcircle(65 + i, 330, 15); 
		midcircle(65 + i, 330, 2); 

		// For right wheel of car 
		midcircle(145 + i, 330, 15); 
		midcircle(145 + i, 330, 2); 

		// DDA left of left wheel 
		DDA(0 + i, 330, 50 + i, 330); 

		// DDA middle of both wheel 
		DDA(80 + i, 330, 130 + i, 330); 

		// DDA right of right wheel 
		DDA(210 + i, 330, 160 + i, 330); 

		delay(100); 

		// To erase previous drawn car 
		// use cleardevice() function 
		cleardevice(); 
	} 

	getch(); 

	closegraph(); 
} 

// Driver code 
int main() 
{ 
	draw_moving_car(); 

	return 0; 
} 
