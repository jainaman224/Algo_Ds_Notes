/*
The Coin Change problem states that given an amount N, how
many possible ways are there to make the desired change using
unlimited supply of coins of given denominations.
*/

const coinChange = (denominations, amount) => {
    
    //make an array of length amount+1 and initialize with 0
    let dp_Definition = Array.from({ length: amount + 1 }, () => 0);

    //setting the base case for the definition
    dp_Definition[0] = 1;

    for (let i = 0; i < denominations.length; i++) {
        for (let j = denominations[i]; j < amount + 1; j++) {
            dp_Definition[j] += dp_Definition[j - denominations[i]]
        }
    }
    return dp_Definition[amount];
}

// I/O , O/P Examples

console.log(coinChange([1, 5, 10, 25], 1)); //1
console.log(coinChange([1, 5, 10, 25], 2)); //1
console.log(coinChange([1, 5, 10, 25], 5)); //2
console.log(coinChange([1, 5, 10, 25], 25)); //13

