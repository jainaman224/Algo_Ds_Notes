'''
    Author: Vedant Wakalkar

    Python Program for Assembly Line Scheduling (Dynamic Programming).

    Consider two assembly lines 'A' and 'B'
    numbered from 'A1 to An' and 'B1 to Bn' respectively.

    'In1' and 'In2' are two possible where an objects enters
    and 'Out1' and 'Out2' are two exits after assembling parts.

    In1   --> A1 --> A2 --> .... --> An-2 --> An-1 --> An --> Out1
                \    *                   \    *   \    *
          tA1,2  \  /          tAn-2,n-1  \  /     \  / tBn-1,n
                  \/                       \/       \/
                  /\                       /\       /\
           tB1,2 /  \           tBn-2,n-1 /  \     /  \ tAn-1,n
                /    *                   /    *   /    *
    In2   --> B1 --> B2 --> .... --> Bn-2 --> Bn-1 --> Bn --> Out2
        
    *(arrow) = points toward

    Let 'e1' and 'e2' be entry time from 'In1' and 'In2'
    and 'ex1' and 'ex2' be out time for 'Out1' and 'Out2'

    Let 'tAn' be the time taken at 'An' node of assembly line A and
    'tBn' at 'Bn' node of assembly line B.

    Let transiton time from one assembly line to other be tAi,j
    and tBi,j for line 'A' and 'B' resp.

    tAi,j -> Translating from Ai to Bj
    tBi,j -> Translating from Bi to Aj
    j = i + 1 for most of cases.
'''
ASSEMBLY_LINES  = 2

def assemblyLineScheduling(line, transactionTime, inTime, outTime):
    
    # line            -> containing assembly line with its node values
    # transactionTime -> containing lists of Extra cost incurred to change the assembly line
    # inTime          -> list of values of In time for assembly lines
    # outTime         -> list of values of Out time for assembly lines

    noOfNodes = len(line[0])

    # line1 and line2 for storing the calculated cost at each node
    line1 = []
    line2 = []

    # Adding In time and cost of first node to respective list
    line1 += [inTime[0], (inTime[0] + line[0][0])]
    line2 += [inTime[1], (inTime[1] + line[1][0])]

    for n_node in range(1, noOfNodes):

        # tempS -> node selected on same line
        # tempC -> node selected on different line
        # temp  -> minimum of tempS and tempC

        # for Line_1
        tempS = line1[n_node] + line[0][n_node]
        tempC = line2[n_node] + transactionTime[1][n_node] + line[0][n_node]
        temp = min(tempS, tempC)
        line1.append(temp)

        # for Line_2
        tempS = line2[n_node] + line[1][n_node]
        tempC = line1[n_node] + transactionTime[0][n_node] + line[1][n_node]
        temp = min(tempS, tempC)
        line2.append(temp)

    # Adding Out time for respective line
    line1.append(line1[-1] + outTime[0])
    line2.append(line2[-1] + outTime[1])

    if min(line1[-1], line2[-1]) == line1[-1]:
        pathC = '1'
    else:
        pathC = '2'

    path = []

    for i in range(noOfNodes + 1, -1, -1):
        if (i == noOfNodes+1):
            path.insert(-1, 'Out' + pathC + '(' + str(outTime[int(pathC) - 1]) + ')')
        elif (i == 0):
            path.insert(0, 'In' + pathC + '(' + str(inTime[int(pathC) - 1]) + ')')
        else:
            path.insert(0, 'Node' + pathC + '(' + str(line[int(pathC) - 1][i - 1]) + ')')
            if (pathC == '1'):
                val = line1[i] - line1[i - 1]
                if (val != line[int(pathC) - 1][i - 1]):
                    pathC = '2'
            else:
                val = line2[i] - line2[i - 1]
                if (val != line[int(pathC) - 1][i - 1]):
                    pathC = '1'

    # Finding minimum cost and return
    if (min(line1[-1], line2[-1]) == line1[-1]):
        return path, line1[-1]
    else:
        return path, line2[-1]

if __name__ == "__main__":

    '''
        Example :
        30(In1)     --> 80 --> 40 --> 60 --> 30(Out1)
                         \     * \    *
                       20 \  /    \  / 30
                           \/      \/
                           /\      /\
                       10 /  \    /  \ 20
                         /    *  /    *
        10(In2)     --> 50 --> 70 --> 50 --> 30(Out2)
    '''

    # lineA, lineB time required at each node on assembly line                                                 Here, lineA = line[0], lineB = line[1] 
    # aToB, bToA time required at change assembly line from Ai to Bj or Bi to Aj where j = i+1                 Here, aToB = transactionTime[0], bToA = transactionTime[1]
    # inA, inB Time required to enter Assembly line                                                            Here, inA = inTime[0], inB = inTime[1]  
    # outA, outB Time required to exit from Assembly line                                                      Here, outA = outTime[0], outB = outTime[1]

    nodes = int(input("Enter the no. of nodes on Assembly line : "))
    
    line = []
    inTime = []
    outTime = []
    transactionTime = []

    print("\n-- In Time --")
    for lineN in range(ASSEMBLY_LINES):
        inTime.append(int(input("For Line" + str(lineN + 1) + ": ")))
    
    print("\n-- Out Time --")
    for lineN in range(ASSEMBLY_LINES):
        outTime.append(int(input("For Line" + str(lineN + 1) + ": ")))
    
    print("\n-- Time required at each node --")
    for lineN in range(ASSEMBLY_LINES):
        print("\nFor Assembly Line", lineN + 1)
        tmp = []
        for nThNode in range(nodes):
            tmp.append(int(input("Node" + str(nThNode) + ": ")))
        line.append(tmp)
    
    print("\n-- Transaction Time --")
    for lineN in range(ASSEMBLY_LINES):
        tmp = []
        for nThNode in range(nodes):
            if (nThNode == 0):
                tmp.append(0)
                print()
            else:
                if (lineN == 0):
                    tmp.append(int(input("Node" + str(lineN + 1) + "(" + str(line[lineN][nThNode - 1]) + ") to Node" + str(lineN + 2) + "(" +str(line[lineN + 1][nThNode]) + ") : ")))
                else:
                    tmp.append(int(input("Node" + str(lineN + 1) + "(" + str(line[lineN][nThNode - 1]) + ") to Node" + str(lineN) + "(" + str(line[lineN - 1][nThNode]) + ") : ")))
        transactionTime.append(tmp)

    path, val = assemblyLineScheduling(line, transactionTime, inTime, outTime)

    print("\nMinimum time = ", val)
    print("Path : ", ' --> '.join(path))

'''
    Output:
        Enter the no. of nodes on Assembly line : 3

        -- In Time --
        For Line1: 30
        For Line2: 10

        -- Out Time --
        For Line1: 30
        For Line2: 30

        -- Time required at each node --

        For Assembly Line 1
        Node0: 80
        Node1: 40
        Node2: 60

        For Assembly Line 2
        Node0: 50
        Node1: 70
        Node2: 50

        -- Transaction Time --

        Node1(80) to Node2(70) : 20
        Node1(40) to Node2(50) : 20

        Node2(50) to Node1(40) : 10
        Node2(70) to Node1(60) : 30

        Minimum time =  200
        Path :  In2(10) --> Node2(50) --> Node1(40) --> Node1(60) --> Out1(30)
'''

