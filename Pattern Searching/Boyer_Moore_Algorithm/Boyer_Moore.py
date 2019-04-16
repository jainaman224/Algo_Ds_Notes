badchar = []

def badCharHeuristic(ch, size):
	global badchar
	for i in range(256):
		badchar.append(-1)

	for i in range(size):
		badchar[ord(ch[i])] = i

def search(text, pattern):
	global badchar
	len_text = len(text)
	len_pattern = len(pattern)

	badCharHeuristic(pattern, len_pattern)

	s = 0
	while s < (len_text - len_pattern):
		j =  len_pattern - 1

		while (j >= 0 and pattern[j] == text[s + j]):
			j -= 1

		if j < 0:
			print("Pattern match at shift = {0}".format(s))
			if (s + len_pattern < len_text):
				s += len_pattern - badchar[ord(text[s + len_pattern])]
			else:
				s += 1
		else:
			s += max(1, j - badchar[ord(text[s + j])])

text = "ABAAABCD"
pattern = "ABC"

search(text, pattern)