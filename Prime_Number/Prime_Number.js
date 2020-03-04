//Description: Function to find if a given number is prime or not
//Expected Output: returns true or false

const isPrime = (num) => {
    //Numbers less than 2 are not prime numbers (including negatives)
    if (num < 2) {
        return false;
    }
    //start finding factors for num , if only 2 factors then it's prime, else not
    let i = 1, factors = 0;
    while (i <= num) {
        let rem = num % i; //check the remiander is zero or not
        if (rem === 0) {
            factors += 1;
        }
        i++;
    }
    if (factors === 2) { //exactly two factors makes it prime
        return true;
    }
    else {  //else it not a prime number
        return false;
    }
}

//I/P and O/P Examples
console.log(isPrime(-02)); //false
console.log(isPrime(0)); //false
console.log(isPrime(01)); //false
console.log(isPrime(03)); //true
console.log(isPrime(08)); //false
console.log(isPrime(12)); //false
console.log(isPrime(23)); //true
