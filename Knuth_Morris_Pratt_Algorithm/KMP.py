def calculateLps(pattern, lps):
    length = 0
    lps[0] = 0

    i = 1
    while i < len(pattern):
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1

def KMPSearch(pattern, text):
    sizePattern = len(pattern)
    sizeText = len(text)

    lps = [0] * sizePattern
    j = 0

    calculateLps(pattern, lps)

    i = 0
    while i < sizeText:
        if pattern[j] == text[i]:
            i+=1
            j+=1

        if j == sizePattern:
            print("Pattern found at " + str(i - j))
            j = lps[j - 1]
        elif i < sizeText and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1

text = "namanchamanbomanamansanam"
pattern = "aman"
KMPSearch(pattern, text)


''' Output

Pattern found at 1
Pattern found at 7
Pattern found at 16

'''
