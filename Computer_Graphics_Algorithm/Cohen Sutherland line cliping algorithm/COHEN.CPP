#include<stdio.h>
	#include<conio.h>
	#include<graphics.h>
	#include<iostream.h>
	#include<stdlib.h>
	#include<dos.h>
	int main(void)
	{
	int gd=DETECT, gm;
	int i,k,xmax,ymax,xmin,ymin,x1,y1,x2,y2,xx1,xx2,yy1,yy2;
	float t1,t2,p[4],q[4],temp;
	int j,dx,dy,wx1,wx2,wy1,wy2,bit[2][4],count;
	float x[4],y[4],*a,m;
	initgraph(&gd,&gm,"c:\\TurboC3\\BGI");
	clrscr();
	while(1)
	{
		printf("Enter your choise\n");
		printf("1:cohen sutherland 2:exit\n");
		scanf("%d",&k);
		switch(k)
		{
		case 1:
	    printf("\n ENTER THE FIRST POINT:");
	    scanf("%f %f",&x[0],&y[0]);
	    printf("\n ENTER THE SECOND POINT:");
	    scanf("%f %f",&x[1],&y[1]);
	    printf("\n ENTER THE FIRST WINDOW POINT:");
	    scanf("%d %d",&wx1,&wy1);
	    printf("\n ENTER THE SECOND WINDOW POINT:");
	    scanf("%d %d",&wx2,&wy2);
	    line(x[0],y[0],x[1],y[1]);
	    rectangle(wx1,wy1,wx2,wy2);
	    getch();
	    clrscr();
	    dx=x[1]-x[0];
	    dy=y[1]-y[0];
	    m=dy/dx;
	    rectangle(wx1,wy1,wx2,wy2);
	    for(i=0;i<4;i++)
	    {
			bit[0][i]=0;
			bit[1][i]=0;
		}
	    for(i=0;i<2;i++)
	    {
			if(x[i]<wx1)
			    bit[i][3]=1;
			if(x[i]>wx2)
			    bit[i][2]=1;
			if(y[i]>wy2)
			    bit[i][1]=1;
			if(y[i]<wy1)
			    bit[i][0]=1;
	    }
	    for(i=0;i<2;i++)
	    {
			count=0;
			for(j=0;j<4;j++)
			{
			    if(bit[i][j]==0)
				count++;
			    else
				break;
			}
			if(count!=4)
		    break;
	    }
	    if(count==4)
	    {
			line(x[0],y[0],x[1],y[1]);
			exit(0);
		}
	    for(i=0;i<4;i++)
		{
			if(bit[0][i]==1&&bit[1][i]==1)
			{
			    exit(0);
			}
	    }
	    for(i=0;i<2;i++)
	    {
			count=0;
			for(j=0;j<4;j++)
			{
			    if(bit[i][j]!=0)
				break;
			    else
				count++;
			}
			if(count==4)
			    break;
	    }
	    if(count<4)
	    {
		for(i=0;i<2;i++)
		{
		    if(bit[i][3]==1)
		    {
			y[i]=m*(wx1-x[i])+y[i];
			x[i]=wx1;
		    }
		    if(bit[i][2]==1)
		    {
			y[i]=m*(wx2-x[i])+y[i];
			x[i]=wx2;	    }
		    if(bit[i][1]==1)
		    {		x[i]=x[i]+(1/m)*(wy2-y[i]);
			y[i]=wy2;	    }
		    if(bit[i][0]==1)
		    {
			x[i]=x[i]+(1/m)*(wy1-y[i]);
			y[i]=wy1;
		    }	
		}
		line(x[0],y[0],x[1],y[1]);   

		}
	    getch();
	    closegraph();
		break;
		case 2:
		exit(1);
		default:printf("Please enter correct choise");
		break;
		}}
	getch();
	//closegraph();
	}