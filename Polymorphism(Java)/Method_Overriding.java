//Super-class or Parent Class
public class MainRepo {
   private String name;
   private String address;
   private int number;

   public MainRepo(String name, String address, int number) {
      System.out.println("Constructing an Employee");
      this.name = name;
      this.address = address;
      this.number = number;
   }

   public void mailCheck() {
      System.out.println("Mailing a check to " + this.name + " " + this.address);
   }
   
   public String getName() {
      return name;
   }

}

//Sub-class or Child Class
public class ForkedRepo extends MainRepo {
   private double salary; // Annual salary
   
   public ForkedRepo(String name, String address, int number, double salary) {
      super(name, address, number);
      setSalary(salary);
   }
   
   public void mailCheck() {
      System.out.println("Within mailCheck of Salary class ");
      System.out.println("Mailing check to " + getName()
      + " with salary " + salary);
   }
   
   public double getSalary() {
      return salary;
   }
   
   public void setSalary(double newSalary) {
      if(newSalary >= 0.0) {
         salary = newSalary;
      }
   }
}
//Driver Class
public class MethodOverriding {

   public static void main(String [] args) {
      ForkedRepo s = new Forkedrepo("Devkant Gorai", "Birbhum, WB", 3, 36000.00);
      MainRepo e = new Forkedrepo("John Adams", "Boston, MA", 2, 24000.00);
      System.out.println("Call mailCheck using Salary reference --");   
      s.mailCheck();
      System.out.println("\n Call mailCheck using Employee reference--");
      e.mailCheck();
   }
}


/* 
sample output 
Constructing an Employee
Constructing an Employee

Call mailCheck using Salary reference --
Within mailCheck of Salary class
Mailing check to Devkant Gorai with salary 36000.0

Call mailCheck using Employee reference--
Within mailCheck of Salary class
Mailing check to John Adams with salary 24000.0
*/
