def bwt(s):
    assert "\002" not in s and "\003" not in s, "Input string cannot contain STX and ETX characters"
    s = "\002" + s + "\003"
    sTable = sorted(s[i:] + s[:i] for i in range(len(s)))
    lastColumn = [row[-1:] for row in sTable]
    return "".join(lastColumn)

def ibwt(r):
    rTable = [""] * len(r)
    for i in range(len(r)):
        rTable = sorted(r[i] + rTable[i] for i in range(len(r)))
    s = [row for row in rTable if row.endswith("\003")][0]
    return s.rstrip("\003").strip("\002")


#----DRIVER PROGRAM----
print("# BURROWS WHEELER TRANSFORMATION ")
s =input("Original string: ")
print("Transformed string = {}".format(bwt(s)))
print("Inverse transformed string = {}".format(ibwt(bwt(s))))


