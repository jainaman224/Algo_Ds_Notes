import hashlib


class BloomFilter():
    def __init__(self, length=100):

        self.bloomFilterLen = length

        # Create a bit vector array of 0s
        self.bloomFilterArray = [0] * self.bloomFilterLen

        # Using three hash digest functions - md5, sha3_512 and blake2s
        self.hashes = ['md5', 'sha3_512', 'blake2s']

    def encode(self, inputWord):
        encoded_word = inputWord.encode('utf-8')
        return encoded_word

    def bytes_to_int(self, hash_value):

        # Convert bytes to int
        return int.from_bytes(hash_value, byteorder='big')

    def bloom_index(self, hashint):

        # Int value should be within the bloom filter length
        return hashint % self.bloomFilterLen

    # Determine the indices to be updated to True in the BloomFilterArray
    def getIndices(self, inputWord):

        word = self.encode(inputWord)

        hashDigests = []

        # Use the hash functions to get the hash digests
        for hashName in self.hashes:
            hashFunction = hashlib.new(hashName)
            hashFunction.update(word)
            hashDigests.append(hashFunction.digest())

        # Convert the hash digest byte values to int
        hashInts = [self.bytes_to_int(h) for h in hashDigests]

        # Int value to be within the bloom filter length
        bloomFilterIndices = [self.bloom_index(hInt) for hInt in hashInts]

        return bloomFilterIndices

    def insert(self, inputWord):

        bloomFilterIndices = self.getIndices(inputWord)

        # Set to 1 (True) the appropriate indices in the Bloom Filter
        for index in bloomFilterIndices:
            self.bloomFilterArray[index] = 1

    def lookup(self, inputWord):

        bloomFilterIndices = self.getIndices(inputWord)

        for idx in bloomFilterIndices:
            if self.bloomFilterArray[idx] == 0:

                # Indicates element not present in the bloom filter
                return False

        return True


if __name__ == '__main__':

    # Create bloom filter
    bloomFilter = BloomFilter()

    # Words to be inserted into the bloom filter
    words = ['dog', 'crow', 'crocodile']

    # Insert words into the bloom filter
    for word in words:
        bloomFilter.insert(word)

    print('\n---------------- Positive Examples ---------------- \n ')

    # Checking that all words inserted are present in the bloom filter
    # Expected - True for all the words in the list
    for word in words:
        if bloomFilter.lookup(word):
            print('Added to Bloom Filter  - {}  \n'.format(word))

    more_words = ['badger', 'bee', 'hawk']

    print('\n---------------- False Positive Example ---------------- \n ')

    # Checking for a false positive value - a word that has not been inserted
    # but is considered present in the bloom filter
    # Expected - A false positive for a value not inserted to the bloom filter
    for word in more_words:
        if bloomFilter.lookup(word):
            print(
                'Not Added to Bloom Filter but marked found - {}  It is a FALSE POSITIVE \n'.format(word))
        else:
            print('Not Added to Bloom Filter the word - {}  \n '.format(word))

    '''
     Sample Input : 'sent'
     Sample Output: True for the word 'sent'
     Sample Output: False for the word 'blue'

     '''
