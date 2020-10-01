def search(text, pattern):
    lengthText = len(text)
    lengthPattern = len(pattern)

    for i in range(0, lengthText - lengthPattern):
        j = 0

        while j < lengthPattern:
            if text[i + j] != pattern[j]:
                break

            j += 1

        if j == lengthPattern:
            print("Pattern found at " + str(i + 1))

text = input()
pattern = input()
search(text, pattern)

'''
Input:
text = "namanchamanbomanamansanam"
pattern = "aman"

Output:
Pattern found at 2
Pattern found at 8
Pattern found at 17
'''
