def bwt(s):
    assert "\002" not in s and "\003" not in s, "Input string cannot contain STX and ETX characters"
    s = "\002" + s + "\003"
    table = sorted(s[i:] + s[:i] for i in range(len(s)))
    last_column = [row[-1:] for row in table]
    return "".join(last_column)


#----INVERSE BURROWS WHEELER TRANSFORMATION
#This is to get back the original message out of the compressed version.
def ibwt(r):
    table = [""] * len(r)
    for i in range(len(r)):
        table = sorted(r[i] + table[i] for i in range(len(r)))
    s = [row for row in table if row.endswith("\003")][0]
    return s.rstrip("\003").strip("\002")


#----DRIVER PROGRAM----
print("# BURROWS WHEELER TRANSFORMATION ")
s =input("Enter string: ")
print("Original string = {}".format(s))
print("Transformed string = {}".format(bwt(s)))
print("Inverse transformed string = {}".format(ibwt(bwt(s))))

