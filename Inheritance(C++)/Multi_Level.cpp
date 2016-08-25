#include <iostream>

using namespace std;

class Father
{
    protected:
        int age;

    public:
        void setage()
        {
            age = 75;
        }

        int getage()
        {
            return age;
        }
};

class Son : public Father // Son class inherited from Father
{
    protected:
        int S_age;

    public:
        void setage_S()
        {
            S_age = 45;
        }

        int getage_S()
        {
            return S_age;
        }
};

class GrandSon : public Son  // Grandson class inherited from Son
{
    protected:
        int GS_age;

    public:
        void setage_GS()
        {
            GS_age = 15;
        }

        int getage_GS()
        {
            return GS_age;
        }
};

int main()
{
	GrandSon obj;

	obj.setage();
	obj.setage_S();
	obj.setage_GS();

	cout << "Father's age : " << obj.getage() << endl;
    cout << "Son's age : " << obj.getage_S() << endl;
	cout << "Grandson's age : " << obj.getage_GS() << endl;

    return 0;
}

/* Output

Father's age : 75
Son's age : 45
Grandson's age : 15

*/
