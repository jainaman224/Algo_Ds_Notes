# Karatsuba Multiplication
Karatsuba multiplication is an effective and efficient way of multiplication, which comes handy when multiplying really large numbers. It is different from the steps followed in conventional multiplication technique due to the fact that, it recursively performs the multiplication, thereby, making it possible to accomodate really large numbers.

#### Consider the following example:
#### 5678 x 1234 = 7006652

While carrying out traditional multiplication(I mean the method we're usually taught at schools), we first have to multiply 5678 by 4, then by 3...upto 1 and then add all the intermediary products. It turns out that, while implementing this logic in code, we have to make 2n operations(n being the number of digits in the larger number) - (n operations to calculate the intermediary products + n operations to add those products,a long with keeping track of the carry overs). This is a lot of computation.

#### Now let's have a look at how karatsuba multiplication, decreases the computations
#### Following are the steps for karatsuba multiplication:
- Consider the above 2 numbers, let x = 5678 and y = 1234
- Break each number into 2 halves and store them in variables
- In this case, let a = 56, b = 78, c = 12, d = 34
- Now we can express x and y as, x = 10 ^ (n/2) * a + b and y = 10 ^ (n/2) * c + d, where a,b,c,d are n/2 digit numbers.
- Therefore, x * y = 10 ^ n * a * c + 10 ^ (n/2) * (a * d + b * c) + b * d 
- Now, on the first look it may seem that there are 4 recursive calls, to compute ac, ad, bc and bd - but here is the trick:
- It's also called as Gauss's trick - which requires only 3 recursive calls.
- If we carefully observe, we have already computed ac and bd in the first 2 steps, so if we subtract this result from the result of (a+b) * (c+d), we reduce 1 recursive call.
- It may seems strange, but when the computations to be performed are of very high level(multiplying really large digit numbers in this case), reducing even a single recursive call significantly affects performance.
- Checkout the code in python, to understand the recursive work flow better as well as the base case for the recursive function.

### Pseudo code
``` 
karatsuba(x, y):

    m = ceil(n/2)  

    a = floor(x / 10**m)
    b = x % (10**m)

    c = floor(y / 10**m)
    d = y % (10**m)

    #recursive steps
    ac = karatsuba(a,c)
    bd = karatsuba(b,d)
    ad_plus_bc = karatsuba(a + b, c + d) - ac - bd

    return int(ac*(10**(m*2)) + ad_plus_bc*(10**m) + bd)
```

### Complexity

To analyze the complexity of the Karatsuba algorithm, consider the number of multiplications the algorithm performs as a function of n, M(n).

The algorithm multiplies together two nn-bit numbers. If n=2^k for some k then the algorithm recurses three times on n/2-bit number. The recurrence for this is:

M(n) = 3M(n/2)

This takes care of the multiplications required for Karatsuba--now to consider the additions and subtractions. There are O(n)O(n) additions and subtractions required for the algorithm. Therefore, the overall recurrence for the Karatsuba algorithm is:

T(n) = 3T(n/2) + O(n)

Using the master theorem on the above recurrence yields that the running time of the Karatsuba algorithm is: $\Theta$(n<sup>log<sub>2</sub>3</sup>)  