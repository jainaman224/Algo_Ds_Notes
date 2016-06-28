                                                   #**EUCLIDEAN ALGORITHM**



##**INTRODUCTION**

...In mathematics, the *Euclidean algorithm*, or *Euclid's algorithm*, is an efficient method for computing the **greatest common divisor** (GCD) of two numbers, *the largest number that divides both of them without leaving a remainder*.



##**HISTORY**

It is named after the ancient Greek mathematician Euclid, who first described it in Euclid's Elements . It is an example of an algorithm, a step-by-step procedure for performing a calculation according to well-defined rules, and is one of the oldest algorithms in common use. 


The Euclidean algorithm is based on the principle that the greatest common divisor of two numbers does not change if the larger number is replaced by its difference with the smaller number. For example, 21 is the GCD of 252 and 105 (252 = 21 × 12 and 105 = 21 × 5), and the same number 21 is also the GCD of 105 and 147 = 252 − 105. Since this replacement reduces the larger of the two numbers, repeating this process gives successively smaller pairs of numbers until the two numbers become equal. When that occurs, they are the GCD of the original two numbers. By reversing the steps, the GCD can be expressed as a sum of the two original numbers each multiplied by a positive or negative integer, e.g., 21 = 5 × 105 + (−2) × 252.


                               ![image](https://upload.wikimedia.org/wikipedia/commons/thumb/3/37/Euclid%27s_algorithm_Book_VII_Proposition_2_3.png/300px-Euclid%27s_algorithm_Book_VII_Proposition_2_3.png)

Euclid's method for finding the greatest common divisor (GCD) of two starting lengths BA and DC, both defined to be multiples of a common "unit" length. The length DC being shorter, it is used to "measure" BA, but only once because remainder EA is less than DC. EA now measures (twice) the shorter length DC, with remainder FC shorter than EA. Then FC measures (three times) length EA. Because there is no remainder, the process ends with FC being the GCD. On the right Nicomachus' example with numbers 49 and 21 resulting in their GCD of 7 



##**APPLICATIONS**

The Euclidean algorithm has many theoretical and practical applications. It is used for reducing fractions to their simplest form and for performing division in modular arithmetic. Computations using this algorithm form part of the cryptographic protocols that are used to secure internet communications, and in methods for breaking these cryptosystems by factoring large composite numbers. 



##**GENERALIZATIONS**

Although the Euclidean algorithm is used to find the greatest common divisor of two natural numbers (positive integers), it may be generalized to the real numbers, and to other mathematical objects, such as polynomials, quadratic integers and Hurwitz quaternions. In the latter cases, the Euclidean algorithm is used to demonstrate the crucial property of unique factorization, i.e., that such numbers can be factored uniquely into irreducible elements, the counterparts of prime numbers. Unique factorization is essential to many proofs of number theory.



##**TIME COMPLEXITY**

The Time Complexity is O(log min(a, b)).



##**PSEUDO-CODE**

                The algorithm can be written in pseudo-code as follows

 
                   Euclid(a,b) {

                       while (b not 0) { 
  
                           interchange(a,b)
    
                           b := b mod a
    
                           }
  
                       return(a)
  
                      }




