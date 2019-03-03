#include<iostream>
using namespace std;

class Grandfather
{
protected:
	int a=10;

public:
	int b=20;
};
//single inheritence is implemented
class Father:public Grandfather{//Father class inherits Grandfather
	public:
		void Fdisplay()
		{
			cout<<endl<<a<<" "<<b;
		}
};

class Mother{
	public:
		int z=12;
};
//multiple inheritence is implemented
class Child:public Father,public Mother{//Child class inherits Father and Mother
	public:
		void Cdisplay()
		{
			cout<<a<<" "<<b<<" "<<z;
		}
};

int main(){
	Child obj1;
	Father obj2;
	obj1.Cdisplay();
	obj2.Fdisplay();
	
}