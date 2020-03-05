public class Employee
{
//Constructor 1
 Employee()
 {
    System.out.println("Employee Details:"); 
 }
 //Constructor 2
 Employee(String name)
 {
   System.out.println("Employee name: " +name);  
 }
 //Constructor 3
 Employee(String nCompany, int id)
 {
   System.out.println("Company name: " +nCompany);
   System.out.println("Employee id: " +id);  
 }
}
public class Constructor_Overloading
 {
public static void main(String[] args)
  {
  //"emp" is an object for the Employee class
  
     Employee emp = new Employee();//calls constructor 1
     
     Employee emp2 = new Employee("Deep");//calls constructor 2
     
     Employee emp3 = new Employee("HCL", 12234);//calls constructor 3
 }
}

/* Output:
          Employee Details:
          Employee name: Deep
          Company name: HCL
          Employee id: 12234
          */
