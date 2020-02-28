#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<iostream.h>
#include<stdio.h>
#include<dos.h>
void bezier(int, int[] , int[]);
float binomial(float , int ,int);
float fact(int x);
float nCr(int n,int i);
void flower();
void main()
{
	int gd = DETECT, gm;
	int i, n, x[50], y[50], ch;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	printf("\nBEZIER CURVE GENERATION\n");
	printf("\n\t--------------------------");
	printf("\n\t|1.Curve of your choice   |");
	printf("\n\t|2.Flower having 4 petals |");
	printf("\n\t--------------------------");
	printf("\n\nEnter your choice: ");
	scanf("%d",&ch);
	cleardevice();
	switch(ch)
	{
		case 1:
			printf("Enter the number of control points: ");
			scanf("%d", &n);
			printf("\nEnter the coordinates of control points: ");
			for (i=0; i<n; i++)
			{
				printf("\n\tControl point %d: ",i+1);
				scanf("%d%d", &x[i], &y[i]);
			}
			cleardevice();
			//plotting the points
			setcolor(RED);
			for(i=0;i<n;i++)
			{
				circle(x[i],y[i],2);
				delay(10);
			}
			//drawing lines between the points
			setcolor(WHITE);
			for(i=0;i<n-1;i++)
			{
				setlinestyle(DASHED_LINE,1,1);
				delay(10);
				line(x[i],y[i],x[i+1],y[i+1]);
			}
			//actual curve generation
			bezier(n, x, y);
			break;
		case 2:
			//calling the flower function for making flower
			flower();
			break;
		default:
			printf("\nWrong choice");
	}
	getch();
	closegraph();
}

void bezier(int n, int x[], int y[])
{
	float u=0,sum_x,sum_y,temp_x,temp_y;
	int i;
	while(u<=1)
	{
		sum_x = 0;
		sum_y = 0;
		for(i=0; i<n; i++)
		{
			temp_x = x[i] * binomial(u,i,n);
			sum_x += temp_x;
			temp_y = y[i] * binomial(u,i,n);
			sum_y += temp_y;
		}
		//setcolor(3);
		putpixel((int)sum_x,(int)sum_y,3);
		u+=0.0001;
	}
}

float binomial(float u, int i,int n)
{
	float coeff=0;
	coeff = nCr(n,i)*pow(u,i)*pow(1-u,n-i-1);
	return coeff;
}
float nCr(int n,int i)
{
	float calc=0;
	calc=fact(n-1)/(fact(i)*fact(n-i-1));
	return calc;
}
float fact(int x)
{
	float f=1;
	int i;
	for(i=1;i<=x;i++)
		f*=i;
	return f;
}
void flower()
{
	//circle
	int xc1[4]={420,420,430,430};
	int yc1[4]={190,200,200,190};
	int xc2[4]={420,420,430,430};
	int yc2[4]={190,180,180,190};
	//petal1
	int x1[4]={420,390,460,430};
	int y1[4]={200,400,400,200};
	//petal2
	int x2[4]={430,630,630,430};
	int y2[4]={185,155,225,195};
	//petal3
	int x3[4]={420,220,220,420};
	int y3[4]={185,155,225,195};
	//petal4
	int x4[4]={420,390,460,430};
	int y4[4]={180,0,0,180};
	//calling bezier function to make the circle and petals
	bezier(4,xc1,yc1);
	bezier(4,xc2,yc2);
	bezier(4,x1,y1);
	bezier(4,x2,y2);
	bezier(4,x3,y3);
	bezier(4,x4,y4);
}