# implementing AhoCorasick using adjacency list
import collections

AList = []  # declaring thr adjacency list


def init_trie(wordList):
    createTrie()
    addKeyWords(wordList)
    setFailTrans()


def createTrie():  # initializing a root of the trie

    AList.append({'character': ' ', 'nextState': [], 'failedState': 0, 'outputList': []})


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
    for node in AList[currState]["nextState"]:
        if AList[node]["character"] == val:
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
        AList.append(node)
        AList[currState]["nextState"].append(len(AList) - 1)
        currState = len(AList) - 1
    # appending te keyword to the output of the last node
    AList[currState]["outputList"].append(keyword)


# for fail transitions, breadth first search will be done on the trie

def setFailTrans():
    q = collections.deque()
    child = 0
    for node in AList[0]["nextState"]:
        q.append(node)
        AList[node]["failedState"] = 0

    while q:
        r = q.popleft()
        for child in AList[r]["nextState"]:
            q.append(child)
            state = AList[r]["failedState"]
            while (findNextState(state, AList[child]["character"]) is None) and (state != 0):
                state = AList[state]["failedState"]

            AList[child]["failedState"] = findNextState(state, AList[child]["character"])

            if AList[child]["failedState"] is None:
                AList[child]["failedState"] = 0

            AList[child]["outputList"] = AList[child]["outputList"] + AList[AList[child]["failedState"]]["outputList"]


def GetKeywords(words):
    currState = 0
    for i in range(len(words)):

        while findNextState(currState, words[i]) is None and currState != 0:
            currState = AList[currState]["failedState"]

        currState = findNextState(currState, words[i])

        if currState is None:
            currState = 0

        else:
            for j in AList[currState]["outputList"]:
                start = i - len(j) + 1
                end = len(j) + start -1
                print("keyword", j, " appears from ",start , " to " ,end)


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