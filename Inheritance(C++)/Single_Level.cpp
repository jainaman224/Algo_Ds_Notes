#include <iostream>
using namespace std;
class Rectangle
{
    protected:
       float length, breadth;
    public:
        Rectangle(): length(0.0), breadth(0.0)
        {
            length = 5;
	    breadth = 6;
        }

};

/* Area class is derived from base class Rectangle. */
class Area : public Rectangle   
{
    public:
       float calc()    
         {
             return length * breadth;
         }

};

int main()
{
     cout<<"Enter data for first rectangle to find area.\n";
     Area a;
     cout<<"Area = "<<a.calc()<<" square meter\n\n";
     return 0;
}

/* OUTPUT
Enter data for first rectangle to find area.
Area = 30 square meter */
