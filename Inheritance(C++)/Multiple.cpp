#include <iostream>

using namespace std;

class lectures
{
    protected:
        int rollno, marks1, marks2;

    public:
        void get()
        {
            rollno = 007;
            marks1 = 75;
		    marks2 = 50;
        }
};

class sports
{
    protected:
       int sportsmarks;

    public:
        void getsportsmarks()
        {
            sportsmarks = 100;
        }
};

class result : public lectures, public sports    // Result class inherited from lectures and sports
{
    private:
        int total, average;

    public:
        void display()
        {
            total = (marks1+marks2+sportsmarks);
            average = total/3.0;
            cout << "\nRoll No : " << rollno;
            cout << "\nTotal: " << total;
            cout << "\nAverage : " << average;
        }
};

int main()
{
   result obj;

   obj.get();
   obj.getsportsmarks();
   obj.display();

   return 0;
}


/* OUTPUT

Roll No: 007
Total: 225
Average: 75

*/
