/*
TOTAL SET BITS FROM 1 to N

Total set bits in a number n is defined as number of 1s in 
binary representation of the number. The task is to calculate
total number of set bits in all numbers till N.
*/
function count(n) {
    let bit = 0;
    while(n > 0) {
        bit += n & 1;
        n >>= 1;
    }
    return bit;
}
function setBits(n) {
    let bit = 0;
    for (let i = 0; i < n; i++) {
        bit = bit + count(i);
    }
    return bit;
}
const n = 12;
const ans = setBits(n);
console.log(ans);


/*
INPUT :
n = 12
OUTPUT :
The total set bits are 20
*/
