# Hashing

Hashing is a technique that is used to uniquely identify a specific object from a group of similar objects. 
In hashing, large keys are converted into small keys by using hash functions. The values are then stored in a data structure called hash table. The idea of hashing is to distribute entries (key/value pairs) uniformly across an array. Each element is assigned a key (converted key).

## EXAMPLE

Suppose the keys are - {“abcdef”, “bcdefa”, “cdefab”, “defabc”}
These are to be hashed into the Hashing Table using the Hash Function: The index for a specific string will be equal to sum of ASCII values of characters multiplied by their respective order in the string after which it is modulo with 2069 (prime number).

Thus, the hash table will look as follows:
![Hashing](https://he-s3.s3.amazonaws.com/media/uploads/e880c21.jpg)

[Courtesy: HackerEarth](https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/)

## ALGORITHM

1. Compute hash address after passing the key through the has function
2. If the index into the hash table pointed to by the hash address is not occupied then hash the key in that position.
3. If it is occupied, then find next appropriate position using either Double Hashing or Linear Probing or Quadratic Probing

## PSEUDOCODE

```
Input - hash function hf, hash table ht, key k

Hashing(hf, ht) 
{
    flag=0
    hashaddress = hf(k)

    if(ht[hf] != null) 
    {
        ht[hf] = k
        flag=1
    } 
    else 
    {
        probe = hashaddress + 1
        while flag != 1 
        {
            if(ht[hf] != null) 
            {
                ht[hf] = k
                flag=1
            }
            else
            {
                probe = probe + 1
            }
        }
    }
}

```

## COMPLEXITY

**Time complexity**  - O(n)

## See Also 

- [Hashing] (https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)
- [Hashing Visualization] (https://www.cs.usfca.edu/~galles/visualization/OpenHash.html)


## Implementation

- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Prims_Algorithm/Prims_Algorithm.c)
> :rocket: [Compile Online](https://repl.it/repls/SeriousLightsalmonCharacters) :rocket:

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Prims_Algorithm/Prims_Algorithm.java)
> :rocket: [Compile Online](https://repl.it/repls/SufficientWingedLeads) :rocket:

