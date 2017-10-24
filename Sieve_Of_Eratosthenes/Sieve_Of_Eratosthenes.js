var SieveOfEratosthenes = function(n){
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    prime = [true];
    for(i=0; i<n; i++)
      prime.push(true);

    for(p = 2; p*p <= n; p++){
        // If prime[p] is not changed, then it is a prime
        if(prime[p] == true){
            // Update all multiples of p
            for(i = p*2; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for(p = 2; p <= n; p++)
       if(prime[p])
          console.log(p);
}


n = 30;
console.log("Following are the prime numbers smaller than or equal to " + n);
SieveOfEratosthenes(n);

/*

Following are the prime numbers smaller than or equal to 30
2 3 5 7 11 13 17 19 23 29

*/
