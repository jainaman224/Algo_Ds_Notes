// Extended Euclidean Algorithm to find GCD of two numbers

// Function to return gcd of a and b
function gcdExtended(a, b, x, y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        x = 0;  
        y = 1;  
        return b;  
    }  
  
    var x1, y1; // To store results of recursive call  
    var gcd = gcdExtended(b % a, a, x1, y1);  
  
    // Update x and y using results of  
    // recursive call  
    x = y1 - (b / a) * x1;  
    y = x1;  
  
    return gcd;  
}  

// Used synchronous readline package to take console input 
var readlineSync = require('readline-sync');

var a = readlineSync.question('Enter first Number');
a = parseInt(a);
var b = readlineSync.question('Enter second number');
b = parseInt(b);

var result = gcdExtended(a, b);
console.log("The GCD is" + " " + result)

/*
    Sample Input : 9 6
    Sample Output : The GCD is 3
*/
