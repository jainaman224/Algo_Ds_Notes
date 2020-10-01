/*
    Sum of cubes of first N natural numbers can be calculated using the following equation

    Sum = (N*(N+1)/2)^2
    i.e 1^3 + 2^3 + 3^3 + 4^3 + ..... + N^3

*/

var number = window.prompt("Enter the number:", "");
var n = parseInt(number);
var res = sumOfCubes(n);
window.alert("Sum of cubes of first " + n + " natural numbers is " + res);
function sumOfCubes(n)
{
    var sum = Math.pow((n * (n + 1) / 2), 2);
    return sum;
}

/*
Input:-
N = 3

Output:-

Sum of cubes of first 3 natural numbers is 36

Verification:
1^3 + 2^3 + 3^3
= 1 + 8 + 27
= 36
*/
