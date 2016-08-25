#include <iostream>

using namespace std;

class Father
{
    protected:
        int age;

    public:
        void getage()
        {
            age = 75;
        }
};

class Son : public Father // Son class inherited from Father
{
    protected:
        int S_age;

    public:
        void getage_S()
        {
            S_age = 45;
        }
};

class GrandSon : public Son  // Grandson class inherited from Son
{
    protected:
        int GS_age;

    public:
        void getage_GS()
        {
            GS_age = 15;
        }
};

int main()
{
	GrandSon obj;

	obj.getage();
	obj.getage_S();
	obj.getage_GS();

	cout << "Father's age :" << obj.age;
    cout << "\nSon's age :" << obj.S_age;
	cout << "\nGrandson's age :" << obj.GS_age;

    return 0;
}

/* Output

Father's age : 75
Son's age : 45
Grandson's age : 15

*/
