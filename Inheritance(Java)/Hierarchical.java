class Person
{
    private String name;
    private long phno;

    public void read()
    {
        name = "Akash";
        phno = 928374993;
    }

    public void show()
    {
        System.out.println("Name = " + name);
        System.out.println("Phone = " + phno);
    }
}

class Student extends Person
{
    private int rollno;
    private String course;

    public void read()
    {
        super.read();
        rollno = 007;
        course = "Computer Science";
    }

    public void show()
    {
        super.show();
        System.out.println("Roll No. = " + rollno);
        System.out.println("Course = " + course);
    }
}

class Teacher extends Person
{

    private String dept_name;
    private String qual;

    public void read()
    {
        super.read();
        dept_name = "CSE";
        qual = "PhD";
    }

    public void show()
    {
        super.show();
        System.out.println("Departement = " + dept_name);
        System.out.println("Qualififcation = " + qual);
    }
}

class Hierarchical
{

    public static void main(String args[])
    {
        Student s1 = new Student();

        s1.read();
        System.out.println("******************** Displaying Student Information ********************");

        s1.show();

        Teacher t1 = new Teacher();

        t1.read();
        System.out.println("******************** Displaying Teacher Information ********************");

        t1.show();
    }
}


/* OUTPUT

******************** Displaying Student Information ********************
Name = Akash
Phone = 928374993
Roll No. = 7
Course = Computer Science
******************** Displaying Teacher Information ********************
Name = Akash
Phone = 928374993
Departement = CSE
Qualififcation = PhD


*/
