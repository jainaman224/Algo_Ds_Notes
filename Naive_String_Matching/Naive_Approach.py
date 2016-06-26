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
            print("Pattern found at " + str(i))

text = "namanchamanbomanamansanam"
pattern = "aman"
search(text, pattern)

''' Output

Pattern found at 1
Pattern found at 7
Pattern found at 16

'''
