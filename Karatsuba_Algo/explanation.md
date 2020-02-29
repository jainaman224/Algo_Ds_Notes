# Karatsuba Multiplication
<p>Karatsuba multiplication is an effective and efficient way of multiplication, which comes handy when multiplying really large numbers. It is different from the steps followed in conventional multiplication technique due to the fact that, it recursively performs the multiplication, thereby, making it possible to accomodate really large numbers.</p>

#### Consider the following example:
#### 5678 x 1234 = 7006652

<p>While carrying out traditional multiplication(I mean the method we're usually taught at schools), we first have to multiply 5678 by 4, then by 3...upto 1 and then add all the intermediary products. It turns out that, while implementing this logic in code, we have to make 2n operations(n being the number of digits in the larger number) - (n operations to calculate the intermediary products + n operations to add those products,a long with keeping track of the carry overs). This is a lot of computation.</p>

#### Now let's have a look at how karatsuba multiplication, decreases the computations
#### Following are the steps for karatsuba multiplication:
- Consider the above 2 numbers, let x = 5678 and y = 1234
- Break each number into 2 halves and store them in variables
- In this case, <strong>let a = 56, b = 78, c = 12, d = 34</strong>
- Now we can express x and y as, <strong>x = 10<sup>(n/2)</sup> * a + b</strong> and <strong>y = 10<sup>(n/2)</sup> * c + d</strong>, where a,b,c,d are n/2 digit numbers.
- Therefore, <strong>x * y = 10<sup>n</sup>*a*c + 10<sup>(n/2)</sup> * (a*d + b*c) + b*d</strong>
- Now, on the first look it may seem that there are 4 recursive calls, to compute ac, ad, bc and bd - but here is the trick:
- It's also called as Gauss's trick - which requires only 3 recursive calls.
- If we carefully observe, we have already computed ac and bd in the first 2 steps, so if we subtract this result from the result of <strong>(a+b) * (c+d)</strong>, we reduce 1 recursive call.
- It may seems strange, but when the computations to be performed are of very high level(multiplying really large digit numbers in this case), reducing even a single recursive call significantly affects performance.
- Checkout the code in python, to understand the recursive work flow better.
