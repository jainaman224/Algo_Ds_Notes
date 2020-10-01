# Bloom Filter

A **Bloom filter** is a space-efficient probabilistic data structure. It is used to quickly tell you whether an element is a member of a set or not. Deletion is not allowed in a standard Bloom Filter.

In a Bloom Filter false positive matches are possible, but false negatives are not. A query returns either "possibly in set" or "definitely not in set". Elements can be added to the set, but not removed; the more elements that are added to the set, the larger the probability of false positives. 

An example of a Bloom Filter:

![Bloom Filter](https://upload.wikimedia.org/wikipedia/commons/a/ac/Bloom_filter.svg)

[Courtesy: Wikipedia.org](https://en.wikipedia.org/wiki/Bloom_filter)

## Features of Bloom Filter

### 1. Space Efficient
A Bloom Filter unlike a hash table it does not store member data. This is what makes a Bloom Filter more space efficient and fast for inserts and lookups.

### 2. Probabilistic

It is probabilistic since we may get a positive response to the question, if the element is in the set (even if the element was not added to the set - hence false positives are possible) but it will **never** respond with no, if the value is actually present (false negatives can’t happen). In other words, it can be considered an approximate member query data structure. 

## Implementation

A Bloom filter is implemented with a bit vector array of M bits, where M is the Bloom Filter size. Initially when the Bloom Filter is created all M bits are set to 0. 

Additionally, there are k number of hashing functions defined. Each hash function h(0), h(1),. . . , h(k-1) hashes an input value to one of the positions in the range [0, M − 1].  Then the bits in the bit vector at the index of value of those hashes is set 1 (True). Any given bit may be set to 1 (True) multiple times.

Only insert (or add) and lookup operations are permitted. Delete or remove operation is not allowed in standard Bloom filters.

So, insertion causes setting of k bits within the bit vector. Lookups repeat the k hash functions and check the corresponding bits. If any checked bit is not set, the entry is definitely not in the filter. When all checked bits are set, the entry might be in the filter. It could be because either the element is in the set or the bits were coincidentally set to 1 by hashes of other elements, resulting in a false positive.

### Step 1 - Empty Bit Vector Array

![Empty](https://contribute.geeksforgeeks.org/wp-content/uploads/enpty_bit_array.png)

### Step 2 - Add an element to the Bloom Filter

Calculate hashes using h(0), h(1),. . . , h(k-1) and the positional indices. Set all the indices to 1 in the bit array.

> _Indicative indices when adding 'geeks' to the bloom filter_

![Insertion-1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/geeks1.png)

### Step 3 - Add another element to the Bloom Filter

Calculate hashes using h(0), h(1),. . . , h(k-1) and the positional indices. Set all the indices to 1 in the bit array.

> _Indicative indices when adding 'nerd' to the bloom filter_

![Insertion-2](https://contribute.geeksforgeeks.org/wp-content/uploads/nerd.png)

### Step 4 - Lookup an element in the Bloom Filter 

##### 4a.  To lookup 'nerd' in the bloom filter 

The calculated indices from using the hashes h0, h1 .. hk-1 would return 3, 4, 5 (indicative here) a lookup of those indices in the bit array would return a True.

##### 4b. Indicative indices for looking up 'cat' in the bloom filter 
Calculate hashes using h(0), h(1),. . . , h(k-1) and the positional indices. Lookup the value of those indices in the bit array.

As the bit at the calculated indices are already set to 1 (by some other elements), the Bloom Filter will return a false positive with the claim that “cat” is present.

### False positive example
![Insertion-2](https://contribute.geeksforgeeks.org/wp-content/uploads/cat.png)


[Courtesy: geeksforgeeks.org](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)

## Some use cases of Bloom Filter

- Bloom filter can be used to implement spell checker using a predefined dictionary with large number of words

- Used for preventing weak password choices using a dictionary of easily guessable passwords

- One-hit-wonders: Akamai & Facebook use bloom filters to avoid caching the items that are very rarely searched or searched only once. Only when they are searched more than once, they will get cached. 

- Google Chrome uses the Bloom Filter to identify malicious URLs - it keeps a local Bloom Filter as the first check for Spam URL

- Bitcoin uses Bloom filters to speed up wallet synchronization and also to improve Bitcoin wallet security

- Genomics community uses Bloom Filter for classification of DNA sequences and efficient counting of k-mers in DNA sequences

- Google BigTable and Apache Cassandra use Bloom filters to reduce disk lookups for non-existent rows or columns

- Network Routers use Bloom Filters to check - Blocked IP Addresses,  Keep Track of Cached contents

## See also
- [Wikipedia : Bloom Filter](https://en.wikipedia.org/wiki/Bloom_filter)
- [GeeksForGeeks : Bloom Filter](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)
- [Interactive Bloom Filter Demo](https://www.jasondavies.com/bloomfilter/)