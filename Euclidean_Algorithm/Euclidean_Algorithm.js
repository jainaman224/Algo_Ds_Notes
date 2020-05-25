// Euclidean Algorithm to find GCD of two numbers

// Function to return gcd of a and b
function gcd(a, b)
{
    // base case
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// Used synchronous readline package to take console input 
var readlineSync = require('readline-sync');

var a = readlineSync.question('Enter first Number');
a = parseInt(a);
var b = readlineSync.question('Enter second number');
b = parseInt(b);

var result = gcd(a, b);
console.log("The GCD is" + " " + result)

/*
    Sample Input : 9 6
    Sample Output : The GCD is 3
*/
