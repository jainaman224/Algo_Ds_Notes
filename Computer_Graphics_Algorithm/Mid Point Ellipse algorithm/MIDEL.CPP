#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

float x[3][3],xn[3][3],rot[3][3],t[3][3],tn[3][3];

void midpoint_elllipse(float xc, float yc, float a,float b){
	float x,y,e;
	int gd=DETECT,gm=DETECT;
	x = 0;
	y = b;
	e = b*b-a*a*b+a*a/4;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	do{
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		x++;
		if(e<0){
			e = 2*b*b*x+b*b+e;
		}
		else{
			y--;
			e = 2*b*b*x-2*a*a*y+e+b*b;
		}
	}while(2*b*b*x<2*a*a*y);
	e = b*b*x-2*a*a*y+a*a+b*b/4;
	do{
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		y--;
		if(e>0){
			e = e-2*a*a*y+a*a;
		}
		else{
			x++;
			e = 2*b*b*x-2*a*a*y+e+a*a;
		}
	}while(y!=0);
}

void mat_mul(float a[3][3],float b[3][3]){
	int i,j,k;
	float prod[3][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				prod[i][j]+=a[i][k]*b[k][j];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			xn[i][j]=prod[i][j];
}

void main()
{
	float a,b,yc,xc;
	clrscr();
	cout<<"\nenter centre \n enter x";
	cin>>xc;
	cout<<"\nenter y";
	cin>>yc;
	cout<<"\nenter a";
	cin>>a;
	cout<<"\nenter b";
	cin>>b;

	midpoint_elllipse(xc,yc,a,b);

	x[0][0]=xc;
	x[0][1]=yc;
	x[1][0]=xc;
	x[1][1]=yc+b;
	x[2][0]=yc;
	x[2][1]=xc+a;
	x[0][2]=x[1][2]=x[2][2]=1;

	t[0][0]=1;
	t[0][1]=0;
	t[1][0]=0;
	t[1][1]=1;
	t[2][0]=-xc;
	t[2][1]=-yc;
	t[0][2]=t[1][2]=0;
	t[2][2]=1;

	tn[0][0]=1;
	tn[0][1]=0;
	tn[1][0]=0;
	tn[1][1]=1;
	tn[2][0]=xc;
	tn[2][1]=yc;
	tn[0][2]=tn[1][2]=0;
	tn[2][2]=1;

	rot[0][0]=cos(0.523);
	rot[0][1]=sin(0.523);
	rot[1][0]=-cos(0.523);
	rot[1][1]=cos(0.523);
	rot[2][0]=0;
	rot[2][1]=0;
	rot[0][2]=rot[1][2]=0 ;
	rot[2][2]=1;

	mat_mul(x,t);
	mat_mul(xn,rot);
	mat_mul(xn,tn);

	midpoint_elllipse(xn[0][0],xn[0][1],x[1][1]-yc,xn[2][1]-xc);

	getch();
}
