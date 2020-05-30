// Euclidean Algorithm to find GCD of two numbers

export {}

// Recursive Function to return gcd of a and b
function gcd(a:number , b:number) : number
{
    return (b === 0) ? a : gcd(b, a % b);
}

let x : number = 24;
let y : number = 60;
let ans : number = gcd(x,y);
console.log("The GCD of " + x + " and " + y + " is " + ans);

/*
INPUT
x = 24
y = 60

OUTPUT
The GCD of 24 and 60 is 12
*/