# implementing AhoCorasick using adjacency list
# Algorithm:
# 1. Construct the trie, and then set its failure transitions.
# 2. After trie is constructed, traverse the trie while reading input text
# 3. Output the positions that where  the keywords are found.
import collections

AdjList = []  # declaring thr adjacency list


def init_trie(wordList):
    createTrie()
    addKeyWords(wordList)
    setFailTrans()


def createTrie():  # initializing a root of the trie
    AdjList.append({'character': ' ', 'nextState': [], 'failedState': 0, 'outputList': []})


# character -> the character the root node is repesenting
# nextStates -> list of ids of child nodes of the root node
# failedState -> id of the failed state
# outputList -> list of all the valid words encountered

def addKeyWords(wordList):  # ading all the valid words in list of valid words
    for validWord in wordList:
        addWordList(validWord)


def findNextState(currState, val):
    # takes a node and value and return the id of the child of that node
    # whose character matches value or else return none if not found
    for node in AdjList[currState]["nextState"]:
        if AdjList[node]["character"] == val:
            return node
    return None


# adding a keyword to the trie and makring the output as the last node
def addWordList(keyword):
    currState = 0
    j = 0

    child = findNextState(currState, keyword[j])

    while child != None:  # finds the longest prefix of the keyword which exists in the trie so far
        currState = child
        j = j + 1
        if j < len(keyword):
            child = findNextState(currState, keyword[j])
        else:
            break

    for i in range(j, len(keyword)):  # going through rest of the keyword
        # creating a new node for a character
        node = {'character': keyword[i], 'nextState': [], 'failedState': 0, 'outputList': []}

        # appending the character to the Adjacency List
        AdjList.append(node)
        AdjList[currState]["nextState"].append(len(AdjList) - 1)
        currState = len(AdjList) - 1
    # appending te keyword to the output of the last node
    AdjList[currState]["outputList"].append(keyword)


# for fail transitions, breadth first search will be done on the trie
def setFailTrans():
    q = collections.deque()
    child = 0
    for node in AdjList[0]["nextState"]:
        q.append(node)
        AdjList[node]["failedState"] = 0

    while q:
        r = q.popleft()
        for child in AdjList[r]["nextState"]:
            q.append(child)
            state = AdjList[r]["failedState"]
            while (findNextState(state, AdjList[child]["character"]) is None) and (state != 0):
                state = AdjList[state]["failedState"]

            AdjList[child]["failedState"] = findNextState(state, AdjList[child]["character"])

            if AdjList[child]["failedState"] is None:
                AdjList[child]["failedState"] = 0

            AdjList[child]["outputList"] = AdjList[child]["outputList"] + AdjList[AdjList[child]["failedState"]][
                "outputList"]


def GetKeywords(words):
    currState = 0
    for i in range(len(words)):
        while findNextState(currState, words[i]) is None and currState != 0:
            currState = AdjList[currState]["failedState"]

        currState = findNextState(currState, words[i])

        if currState is None:
            currState = 0
        else:
            for j in AdjList[currState]["outputList"]:
                start = i - len(j) + 1
                end = len(j) + start - 1
                print("keyword", j, " appears from ", start, " to ", end)


n = int(input("enter no. of keywords to be saved: "))
keywords = []
for i in range(n):
    temp = input("Enter the keyword: ")
    keywords.append(temp)
init_trie(keywords)
text = input("Enter the text: ")
GetKeywords(text)

"""
input
4
he
she
his
hers
output
keyword his  appears from  1  to  3
keyword she  appears from  3  to  5
keyword he  appears from  4  to  5
keyword hers  appears from  4  to  7
"""
