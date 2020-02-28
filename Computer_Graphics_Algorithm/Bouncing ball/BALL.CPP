// program run in gcc compiler having
// graphics.h library installed
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>


void bouncyball() {

	int i, j = 0, gd = DETECT, gm=DETECT, a,b;

	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

	for (i = 0; i <= 150; i = i + 10) {

		// Set color of car as red
		setcolor(RED);
		circle(200+i,200-i,50);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(200+i,200-i,RED);
		delay(100);
		cleardevice();
		a = 200+i;
		b = 200-i;
	}
	for (i = 0; i <= 150; i = i + 10) {

		// Set color of car as red
		setcolor(RED);
		circle(a+i,b+i,50);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(a+i,b+i,RED);
		delay(100);
		cleardevice(); 
	}
	/*
	for (i = 0; i <= 150; i = i + 10) {

		// Set color of car as red
		setcolor(RED);
		circle(200,200-i,50);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(200,200-i,RED);
		delay(100);
		cleardevice();
	}
	for (i = 0; i <= 150; i = i + 10) {

		// Set color of car as red
		setcolor(RED);
		circle(200,a+i,50);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(200,a+i,RED);
		delay(100);
		cleardevice();
	}*/

	getch();

	closegraph();
}

// Driver code
int main()
{
	bouncyball();

	return 0;
}