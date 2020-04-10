# RSA Algorithm

RSA (Rivest–Shamir–Adleman) is an algorithm used by modern computers to encrypt and decrypt messages. It is an asymmetric cryptographic algorithm. Asymmetric means that there are two different keys. This is also called public key cryptography, because one of the keys can be given to anyone. The other key must be kept private. The algorithm is based on the fact that finding the factors of a large composite number is difficult: when the factors are prime numbers, the problem is called prime factorization. It is also a key pair (public and private key) generator.

It implements a trapdoor function such as Diffie’s one.

RSA is rather slow so it’s hardly used to encrypt data , more frequently it is used to encrypt and pass around symmetric keys which can actually deal with encryption at a faster speed.

## Idea 

The public key consists of two numbers where one number is multiplication of two large prime numbers. And private key is also derived from the same two prime numbers. So if somebody can factorize the large number, the private key is compromised. Therefore encryption strength totally lies on the key size and if we double or triple the key size, the strength of encryption increases exponentially. RSA keys can be typically 1024 or 2048 bits long, but experts believe that 1024 bit keys could be broken in the near future. But till now it seems to be an infeasible task.

## Mechanism

For this example we will be using small prime numbers, just for easy understanding, but in actual implementation the numbers are required to be very large for better encryption.

### Generating Public Key :
    Select two prime no's. Suppose P = 53 and Q = 59.
    Now First part of the Public key  : n = P*Q = 3127.

        We also need a small exponent say e : 

        But e Must be 
                    1.  An integer.
            2.  Not be a factor of n.
            3.  1 < e < Φ(n) [Φ(n) is discussed below], 

    Let us now consider it to be equal to 3.

    --- Our Public Key is made of n and e---

### Generating Private Key :

  1. We need to calculate Φ(n) :
     Such that Φ(n) = (P-1)(Q-1)     
     so,  Φ(n) = 3016


  2. Now calculate Private Key, d : 
     d = (k*Φ(n) + 1) / e for some integer k
     For k = 2, value of d is 2011.      

------Here we now have our PUBLIC KEY (n = 3127 & e = 3) and PRIVATE KEY (d = 2011)---------------

### Encryption

    Step 1. Convert letters to numbers 
            as A = 1, B = 2 etc.

        Let us take an example of message "HI".

        H = 8 , I = 9

    Step 2. Thus **Encrypted Data c = 89e mod n**. 
            Thus our Encrypted Data comes out to be 1394

### Decryption 

    Now we will decrypt 1394 : 

        **Decrypted Data = cd mod n**. 
        Thus our Encrypted Data comes out to be 89.

        8 = H and I = 9 i.e. "HI".


## Implementation

- [C code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/RSA_Algorithm/RSA_Algorithm.c)

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/RSA_Algorithm/RSA_Algorithm.cpp) 

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/RSA_Algorithm/RSA_Algorithm.py)

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/RSA_Algorithm/RSA_Algorithm.java)

## References 
- Wikipedia.