/*
JS Implementation of GCD Program using Euclidean Algorithm
*/

function gcd(m, n)
{
    if(m < n)
    {
        var temp = m;
        m = n;
        n = temp;
    }
    if(m % n === 0)
    {
        return n;
    }
    else
    {
        return gcd(n, m % n);
    }
}

var n1 = prompt("Enter number 1:");
var n2 = prompt("Enter number 2:");
console.log("GCD of " + n1 + " and " + n2 + " is " + gcd(n1, n2));

/*
Input:
Enter number 1: 14
Enter number 2: 63
Output:
GCD of 14 and 63 is 7
*/
