#include<iostream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

//lineMaker(float x1,float y1 ,float x2,float y2);

float x,y,dx,dy,xinc,yinc,len;

void lineMaker(int x1, int y1 , int x2, int y2)
{

    dx = int(x2-x1);
    dy = int(y2-y2);

    if(dx>=dy)
    {
	len = dx;
    }
    else
    {
	len = dy;
    }

    xinc = dx/len;
    yinc = dy/len;

    x = x1;
    y =  y1;
    int i=0;
    while(i<=len)
    {
	x = x + xinc;
	y  = y + yinc;
	putpixel(int(x), int(y), GREEN);
	i++;
	//delay(100);
    }

}

void main()
{
    float x1,y1,x2,y2,x3,y3 ,x4,y4;
    int ch;
    int gd = DETECT ,gm;
    initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
    
    while (true)
    {       
        
        cout<<"\n 1. Line  \n2. triangle \n3. rectangle  \n Enter the choice";
        cin >> ch;
        cleardevice();

        switch (ch)
        {
        case 1:     cout<<"enter the 1st points";
                    cin>> x1>>y1;

                    cout<<"enter the 2nd point";
                    cin>> x2>>y2;
                    cleardevice();
                    
                    lineMaker(x1,y1,x2,y2);
                    break;
        case 4:     
                    cout<<"enter the 1st points";
                    cin>> x1>>y1;

                    cout<<"enter the 2nd point";
                    cin>> x2>>y2;

                    cout<<"enter the 3rd point";
                    cin>> x3>>y3;
                    

                    cleardevice();
                    lineMaker(x1,y1,x2,y2);
                    lineMaker(x2,y2,x3,y3);
                    lineMaker(x3,y3,x1,y1);

                    break;
        case 3:     cout<<"enter the 1st points";
                    cin>> x1>>y1;

                    cout<<"enter the 2nd point";
                    cin>> x2>>y2;
                    
                    cout<<"enter the 2nd point";
                    cin>> x3>>y3;
                    
                    cout<<"enter the 2nd point";
                    cin>> x4>>y4;

                    cleardevice();
                    
                    lineMaker(x1,y1,x2,y2);
                    lineMaker(x2,y2,x3,y3);
                    lineMaker(x3,y3,x4,y4);
                    lineMaker(x4,y4,x1,y1);

                    break;
        
        case 4 :
                    exit(1);
        default:
            cout<<"not valid choice";
            break;
        }
        /* code */
        
        
        getch();
        cleardevice();
    }
    

    

closegraph();
}


