/* The sum of digits of a number is the mathematical addition
of the digits extracted from the number.
Example: number = 12345, sum = 1 + 2 + 3 + 4 + 5 = 15
number = 1005, sum = 1 + 0 + 0 + 5 = 6 */

const sumOfDigits = n => {
    let sum = 0; // initialise sum variable to 0
    while (n > 0) {
        const b = n % 10;
        sum += b;
        n = Math.floor(n / 10); // integer divison in JS
    }
    return sum;
};

// Call the functions
let n = 12345;
console.log(`The sum of digits of ${n} is ${sumOfDigits(n)}`);

n = 1000;
console.log(`The sum of digits of ${n} is ${sumOfDigits(n)}`);

/*
Input:
12345
Output:
The sum of digits of 12345 is 15
Input:
1000
Output:
The sum of digits of 1000 is 1
*/
