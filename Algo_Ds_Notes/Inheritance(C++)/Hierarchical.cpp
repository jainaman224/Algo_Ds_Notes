#include <iostream>

using namespace std;

class person
{
  	private:
		string name;
		long int phno;

  	public:
 		void read()
 		{
 			name = "Akash";
			phno = 9283749093;
 		}

 		void show()
 		{
 			cout << "\nName = " << name;
 			cout << "\nPhone = " << phno;
 		}
};

class student : public person
{
  	private:
 		int rollno;
 		string course;

  	public:
 		void read()
 		{
 			person::read();
			rollno = 007;
			course = "Computer Science";
 		}

 		void show()
 		{
 			person::show();
 			cout << "\nRoll No. = " << rollno;
 			cout << "\nCourse = " << course;
 		}
};

class teacher : public person
{
  	private:
		string dept_name;
		string qual;

  	public:
		void read()
		{
			person::read();
			dept_name = "CSE";
			qual = "PhD";
		}
		void show()
		{
			person::show();
			cout << "\nDepartement = " << dept_name;
			cout << "\nQualififcation = " << qual;
		}
};

int main()
{
	student s1;

	s1.read();
	cout << "\n************************ Displaying Student Information*************";

	s1.show();

	teacher t1;

	t1.read();
	cout << "\n*****************************Displaying Teacher Information************";

	t1.show();

	return 0;
}


/* OUTPUT

************************ Displaying Student Information*************
Name = Akash
Phone = 9283749093
Roll No. = 007
Course = Computer Science
*****************************Displaying Teacher Information************
Name = Akash
Phone = 9283749093
Department = CSE
Qualification = PhD

*/
