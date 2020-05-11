# **RSA Algorithm**
### RSA (Rivest-Shamir-Adleman) is an algorithm used by modern computers to encrypt and decrypt messages. It is an asymmetric cryptographic algorithm. Asymmetric means that there are two different keys. This is also called public key cryptoraphy, because one of the keys can be given to anyone. The other key must be kept private. The algorithm is based on the fact that finding the factors of large composite number is difficult: when the factors are prime numbers, the problem is called prime factorization. It is also a key pair (public and private key) generator.

![rsa algorithm](https://www.educative.io/api/edpresso/shot/5284561120395264/image/5318859621924864)

## **Algorithm**
---
- ### **Generating the keys**
  ### 1.Generate two large random primes, p and q, of approximately equal size such that their product n=pq is of the required bit length.
  ### 2.Compute n=pq and ϕ=(p−1)(q−1).
  ### 3.Choose an integer e, 1<e<ϕ, such that gcd(e,ϕ)=1.
  ### 4.Compute the secret exponent d, 1<d<ϕ, such that ed≡1modϕ. 
  ### 5.The public key is (n,e) and the private key (d,p,q). Keep all the values d, p, q and ϕ secret. [Sometimes the private key is written as (n,d) because you need the value of n when using d. Other times we might write the key pair as ((N,e),d).]

## **Encryption**
---
### Given a plaintext P, represented as a number, the ciphertext C is calculated as:
### C = P^{e} mod n

## **Decryption**
---
### Using the private key (n,d)(n,d), the plaintext can be found using:
### P=C^{d} mod n


![encryption](https://miro.medium.com/max/1172/1*bEjF4alLo2CsazW-xWaxug.png)

## **Pseudocode**
---
>int x = 61, int y = 53;
>
>int n = x * y;
>
>// n = 3233.
>
>
>// compute the totient, phi
>
>int phi = (x-1)*(y-1);
>
>// phi = 3120.
>
> 
>int e = findCoprime(phi);
>
>// find an 'e' which is > 1 and is a co-prime of phi.
>
>// e = 17 satisfies the current values.
>
> 
>// Using the extended euclidean algorithm, find 'd' which satisfies
> 
>// this equation:
>
>d = (1 mod (phi))/e;
>
>// d = 2753 for the example values.
>
> 
>public_key = (e=17, n=3233);
>
>private_key = (d=2753, n=3233);
>
> 
>// Given the plaintext P=123, the ciphertext C is :
>
>C = (123^17) % 3233 = 855;
>
>// To decrypt the cypher text C:
>
>P = (855^2753) % 3233 = 123;

## **Complexity**
---
### Three  major components of the RSA algorithm are exponentiation, inversion and modular operation. Time complexity of the algorithm heavily depends on the complexity of the sub modules used.  We can take the liberty to  perform modular addition in cryptography in O(logn) where n is the number of digits in any number in Z.

### Now modular multiplication using squaring and multiply technique  to get memodNcan be  shown as multiplying the digits of m log e times.  Considering the complexity of multiplication O({logn}2) i.e. repeated addition of two number of logn bits each,  the complexity of the modular exponentiation is about  O({logn}3)

### Using Euclidean extended GCD, inverse of a number can be calculated in O({logn}2)

### Thus overall time complexity of the key generation algorithm will be O(N2) encryption and decryption algorithm using squaring and multiply technique will be O(N3):For N digit number space.

## **Implementation**
---
- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/RSA_Algorithm/RSA_Algorithm.c)

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/RSA_Algorithm/RSA_Algorithm.cpp)

- [JAVA Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/RSA_Algorithm/RSA_Algorithm.java)

- [PYTHON Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/RSA_Algorithm/RSA_Algorithm.py)

