export {}

function SieveOfEratosthenes (n : number){

    // Create a boolean array "prime[0..n]" and initialize
    // all entries of it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.

    let prime : boolean[] = [true];
    let p : number;
    let i : number;

    for(p = 0; p <= n; p++)
        prime.push(true);

    for(p = 2; p * p <= n; p++){
        // If prime[p] is true, then it is a prime
        if(prime[p]){
            // Update all multiples of p
            for(i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for(p = 2; p <= n; p++)
        if(prime[p])
            console.log(p);
}

let n : number = 30;
console.log("The prime numbers upto " + n);
SieveOfEratosthenes(n);

/*
INPUT
n = 30

OUTPUT
The prime numbers upto 30
2
3
5
7
11
13
17
19
23
29
*/
