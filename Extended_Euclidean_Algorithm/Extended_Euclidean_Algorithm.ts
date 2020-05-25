export {}

/*
Extended Euclidean Algorithm :- Find greatest common divisor of the two numbers
                                 a*x + b*y = gcd(a,b)
                                 and solves the above linear equation
*/

// find greatest common divisor
function gcdExtended(a:number , b:number) : number[]
{
    //base case
    if (a==0)
    {
        return [b,0,1];
    }
    //recursive call
    let ans: number[] = gcdExtended(b%a , a);
    return [ans[0], (ans[2] - (Math.floor(b/a) * ans[1])) , ans[1]];
}

let a : number = 12;
let b : number = 16;

let ans : number[] = gcdExtended(a,b);
console.log(ans[0] , ans[1] , ans[2]);

/*
INPUT
a = 12
b = 16

OUTPUT
4 -1 1
*/
