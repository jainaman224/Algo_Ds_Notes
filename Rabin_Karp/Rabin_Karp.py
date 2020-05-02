# Rabin Karp Algorithm

# AN : range or No of alphabets
# val : AN ^ patlen-1
# patlen : pattern length
# PN: any prime no given input from main
# Time-Complexity:-
# The average case running time of the Rabin-Karp algorithm = O(n + m).
# The best case running time of the Rabin-Karp algorithm = O(n + m).
# The worst-case running time of the Rabin-Karp algorithm = O(n * m).

AN = 256 

def search (pattern, text, PN ) :

    patlen = len(pattern)    # pattern length
    txtlen = len(text)    # text length
    val = 1
    hpat = 0    # pattern hash value
    htxt = 0    # text hash value
    i = 0
    j = 0

    for i in range (patlen - 1) :
        val = (val * AN) % PN       # PN is a prime number

    for i in range (patlen) :
        hpat = (AN * hpat + ord(pattern[i])) % PN
        htxt = (AN * htxt + ord(text[i])) % PN

    for i in range (txtlen - patlen + 1) :
        if hpat == htxt :       
            for j in range (patlen) :
                if text[i + j] != pattern[j]:
                    break
            j += 1
            if j == patlen :
                print( "Found at index starting from " + str(i))

        # calculate the new position including i + m   
        if i < txtlen - patlen :
            htxt = (AN * (htxt -  ord(text[i]) * val) + ord(text[i + patlen])) % PN
            
            if htxt < 0 :
                htxt = htxt + PN           

# Driver program
text = input()
pattern = input()
PN = 101 # Prime number
search (pattern, text, PN)

# Input:-XWINGO XOR WINGO
#        WINGO
#        101
# OUTPUT:-Found at index starting from 1
#         Found at index starting from 11
