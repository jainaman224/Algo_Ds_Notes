#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>

void main()
{
	int gm=DETECT,gd=DETECT;
	int row;
	int column;
	int flag=0;
	int x=50,y=50;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	for(row=0;row<8;row++){
		for(column=0;column<8;column++){
			if(flag==0){
				setcolor(YELLOW);
				rectangle(x,y,x+50,y+50);
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(x+1,y+1,YELLOW);
				flag = 1;
			}
			else{
				setcolor(YELLOW);
				rectangle(x,y,x+50,y+50);
				setfillstyle(SOLID_FILL,BLACK);
				floodfill(x+1,y+1,YELLOW);
				flag = 0;
			}
			x = x+50;
		}
		if(flag==0)
			flag = 1;
		else
			flag = 0;
		delay(50);
		x=50;
		y=y+50;
	}
	getch();
	closegraph();
}