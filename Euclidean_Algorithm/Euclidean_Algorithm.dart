/* Basic Euclidean algorithm returns the GCD of two numbers by recursively diving the larger number by the smaller 
number until the remainder turns 0.*/ 
import 'dart:io';

//Recursive function to find GCD
int euclidean_Agorithm(var x, var y)
{
  if(x == 0)
  {
    return y;
  }
  return euclidean_Agorithm(y % x, x);
}

main()
{
  print("Enter first Number: ");
  var x = int.parse(stdin.readLineSync());
  print("Enter second Number: ");
  var y = int.parse(stdin.readLineSync());
  int result= euclidean_Agorithm(x, y);
  print("GCD = $result");
}

/*
Enter first Number: 
10
Enter second Number: 
15
GCD = 5
*/