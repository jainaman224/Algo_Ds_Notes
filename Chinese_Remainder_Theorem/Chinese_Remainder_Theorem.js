/*
The Chinese Remainder Theorem or CRT as it is commonly known is used to evaluate the smallest number 'n' such that:
n % numbers[0] = remainder[0],
n % numbers[1] = remainder[1],
..............................
n % numbers[length-1] = remainder[length-1].
CRT belongs to the class of residue number system.
CRT is given by relation n=Σ{s(i)*(remainders(i)*s1_inverse(i))mod divisors(i)}mod M, where:
1. s(i) is partial product.
2. s(i)_inverse is the inverse for partial product.
3. remianders(i) is the remiander set value.
4. divisors(i) is the divisor set value.
5. M is known as the dynamic range
*/

/* 
The inverse element is defined by (s1*s1_inverse)%moduli =1, 
where s1_inverse needs to be evaluated. The below function
is used as helper to find the inverse.
*/

const inverse = (s1, moduli) => {

    //test the edge case when s1<moduli
    if(s1<moduli)
        return s1;

    //test the edge case when moduli==1
    if (moduli == 1)
        return 0;
    
    //go from 1 upto moduli, and check the condition for inverse mentioned above
    for (let counter = 1; counter < moduli; counter++) {
        if ((s1 * counter) % moduli === 1) {
            return counter;
        }
    }
}

const CRT = (divisors, remainders) => { 
    const lengthDivisors = divisors.length;
    const lengthRemainders = remainders.length;

    if (lengthRemainders !== lengthDivisors) {
        //if they dont match return since result cannot be evaluated
        return `Result cannot be evaluated, since set length doesn't match`;
    }

    //M is the dynamic range evaluated as the product of all divisors.
    let M = 1; 

    for (let i = 0; i < lengthDivisors; i++) {
        M = M * divisors[i];
    }

    //the minimum dividend that is evalued using CRT
    let minDividend = 0; 

    for (let i = 0; i < lengthDivisors; i++) {

        //partial product is defined as M/divisors[i], and represented by s1
        let s1 = Math.floor(M / divisors[i]); 
        let s1_inverse = inverse(s1, divisors[i]);

        //use the formula mentioned above
        minDividend += ((remainders[i] * s1_inverse) % divisors[i]) * s1;
    }

    //used the formula mentioned above
    return minDividend % M;
};

// I/O O/P Examples

// the number will be 11
console.log(CRT([3, 4, 5], [2, 3, 1])); 

// the number will be 3371
console.log(CRT([3, 4, 5, 7, 11], [2, 3, 1, 4, 5])); 
