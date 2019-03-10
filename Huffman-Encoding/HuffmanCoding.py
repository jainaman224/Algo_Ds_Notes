import os,sys

x=raw_input("Enter text\n")
print

class Huffman:
  def __init__(self,freq_of_char):
    self.freq_of_char=freq_of_char

  def sort(self,l):
    for i in range(len(l)-1):
        for j in range(i+1,len(l)):
            if l[i][1]>l[j][1]:
                t=l[i]
                l[i]=l[j]
                l[j]=t
    return l

  def encode(self,message):
    s=''            #stores the encoded text in the form of 1s and 0s
    for i in message:
        if i!='\n':
            arr=self.makeCodeMap(finalTree)
            s+=(arr[i])
    return s

  def createEncoding(self,encoded):
    b = bytearray()
    for i in range(0, len(encoded), 8):
        eightBitChunk = encoded[i:i+8]    #binary representation of the given 8 bits
        ascii=int(eightBitChunk,2)     #gives decimal value of the given binary no
        b.append(ascii)  #appends character equivalent to given ascii value
    return b

  def generateCode(self,finalTree,codeMap,binaryCode):
    if(len(finalTree)==2 and type(finalTree[1]) == type("")):
        codeMap[finalTree[1]]=binaryCode
    else:
        value=finalTree[0]
        lnode=finalTree[1][0]
        rnode=finalTree[1][1]
        self.generateCode(lnode,codeMap,binaryCode+"0")
        self.generateCode(rnode,codeMap,binaryCode+"1")

  def makeCodeMap(self,finalTree):
    codeMap=dict()
    self.generateCode(finalTree,codeMap,'')
    return codeMap

  def makeTree(self,freq_of_char) :
    while len(freq_of_char) > 1 :
        smallest = (freq_of_char[0],freq_of_char[1])       # get the 2 characters of lowest frequencies
        nodes  = freq_of_char[2:]                          # all the other nodes
        totalNodeVal = smallest[0][0] + smallest[1][0]     # value of the parent node of subtree
        freq_of_char   = nodes + [(totalNodeVal,smallest)]     # adding new parent node  to freq_of_char
        self.sort(freq_of_char)
    return freq_of_char[0]

i=0
freq_dict={}
while i<len(x):
    c=x[i]
    i+=1
    if not c:break
    if c in freq_dict.keys():
        freq_dict[c]+=1
    else:freq_dict.update({c:1})

freq_of_char=[]  #list of tuples containing character and frequency
for i in freq_dict:
    freq_of_char.append((freq_dict[i],i))

ob=Huffman(freq_of_char)

finalTree=ob.makeTree(freq_of_char)
codeMap=ob.makeCodeMap(finalTree)

for i in codeMap:
    print i, codeMap[i]
