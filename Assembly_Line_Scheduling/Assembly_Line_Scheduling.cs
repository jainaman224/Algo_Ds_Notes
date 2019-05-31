/*
    Author: Vedant Wakalkar

    C# Program for Assembly Line Scheduling (Dynamic Programming). 

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
*/
using System;

class MainClass 
{
    public static int assemblyLineScheduling(int assemblyLines, int nodes, int [ , ]line, int [ ]inTime, int [ ]outTime, int [ , ]tTime, int [ ]path)
    {
        // assemblyLines  -> no. of assembly lines
        // nodes          -> no. of nodes on station
        // line           -> containing assembly line with its node values
        // tTime          -> containing lists of Extra cost incurred to change the assembly line
        // inTime         -> list of values of In time for assembly lines
        // outTime        -> list of values of Out time for assembly lines

        int value = 0;
        int [ ]line1 = new int[nodes + 2];
        int [ ]line2 = new int[nodes + 2];
        // line1 and line2 for storing the calculated cost at each node
        
        // # Adding in_time 
        line1[0] = inTime[0];
        line2[0] = inTime[1];

        // # Adding cost of first node
        line1[1] = line1[0] + line[0, 0];
        line2[1] = line2[0] + line[1, 0];

        for (int node = 1; node < nodes; node++)
        {
            int tempS, tempC, temp;
            // tempS -> node selected on same line
            // tempC -> node selected on different line
            // temp  -> minimum of tempS and tempC
            
            // for Line_1
            tempS = line1[node] + line[0, node];
            tempC = line2[node] + line[0, node] + tTime[1, node];
            temp = Math.Min(tempS, tempC);
            line1[node + 1] = temp;

            // for Line_2
            tempS = line2[node] + line[1, node];
            tempC = line1[node] + line[1, node] + tTime[0, node];
            temp = Math.Min(tempS, tempC);
            line2[node + 1] = temp;
        }

        // Adding Out time for respective line
        line1[nodes + 1] = line1[nodes] + outTime[0];
        line2[nodes + 1] = line2[nodes] + outTime[1];

        int minLine = Math.Min(line1[nodes + 1], line2[nodes + 1]);
        int pathC = 0;
        
        // Finding minimum cost 
        if (minLine == line1[nodes + 1])
        {
            pathC = 0;
            path[nodes + 1] = pathC;
            value = line1[nodes + 1];
        }
        else
        {
            pathC = 1;
            path[nodes + 1] = pathC;
            value = line2[nodes + 1];
        }
        
        // Path travesed 
        for (int node = nodes; node >= 0; node--)
        {
            if (node == 0)
            {
                path[node] = pathC;
            }
            else
            {
                path[node] = pathC;
                if (pathC == 1)
                {
                    int val_t = line2[node] - line2[node - 1];
                    if (val_t != line[pathC, node - 1])
                    {
                        pathC = 0;
                    }
                }
                else
                {
                    int val_t = line1[node] - line1[node - 1];
                    if (val_t != line[pathC, node - 1])
                    {
                        pathC = 1;
                    }
                }   
            }
        }
        return value;
    }
    static void Main ()
    {
        /*
            Example :
            30(In1)     --> 80 --> 40 --> 60 --> 30(Out1)
                             \     * \    *
                           20 \  /    \  / 30
                               \/      \/
                               /\      /\
                           10 /  \    /  \ 20
                             /    *  /    *
            10(In2)     --> 50 --> 70 --> 50 --> 30(Out2)
            
            line_a, line_b time required at each node on assembly line
            a_to_b, b_to_a time required at change assembly line from Ai to Bj or Bi to Aj where j = i+1
            in_a, in_b Time required to enter Assembly line
            out_a, out_b Time required to exit from Assembly line

            line[0]     = line_a        and     line[1]     = line_b
            tTime[0]    = a_to_b        and     tTime[1]    = b_to_a
            inTime[0]   = in_a          and     inTime[1]   = in_b 
            outTime[0]  = out_a         and     outTime[1]  = out_b 
        */
                
        int assemblyLines, nodes;
        assemblyLines = 2;

        Console.Write("Enter the no. of nodes on Assembly line : ");
        nodes = Convert.ToInt32(Console.ReadLine());
        
        int [ , ]line    = new int[assemblyLines,nodes];
        int [ ]inTime    = new int[assemblyLines];
        int [ ]outTime   = new int[assemblyLines];
        int [ , ]tTime   = new int[assemblyLines,nodes];
        int [ ]path      = new int[nodes + 2];

        Console.WriteLine("\n-- In Time --\n");
        for (int lineN = 0; lineN < assemblyLines; lineN++)
        {
            Console.Write("For Line" + (lineN + 1) +": ");
            inTime[lineN] = Convert.ToInt32(Console.ReadLine());
        }

        Console.WriteLine("\n-- Out Time --\n");
        for (int lineN = 0; lineN < assemblyLines; lineN++)
        {
            Console.Write("For Line" + (lineN + 1) + ": ");
            outTime[lineN] = Convert.ToInt32(Console.ReadLine());
        }

        Console.WriteLine("\n-- Time required at each node --");
        for (int lineN = 0; lineN < assemblyLines; lineN++)
        {
            Console.Write("\nFor Assembly Line" + (lineN + 1) + ": \n");
            for (int nThNode = 0; nThNode < nodes; nThNode++)
            {
                Console.Write("Node" + nThNode + ": ");
                line[lineN, nThNode] = Convert.ToInt32(Console.ReadLine());
            }
        }

        Console.WriteLine("\n-- Transaction Time --");
        for (int lineN = 0; lineN < assemblyLines; lineN++)
        {
            for (int nThNode = 0; nThNode < nodes; nThNode++)
            {
                if (nThNode == 0)
                {
                    tTime[lineN, nThNode] = 0;
                    Console.Write("\n");
                }
                else
                {
                    if (lineN == 0)
                    {
                        Console.Write("Node" + (lineN + 1) + "(" + (line[lineN, nThNode - 1]) + ") to Node" + (lineN + 2) + "(" + (line[lineN + 1, nThNode]) + ") : ");
                        tTime[lineN, nThNode] = Convert.ToInt32(Console.ReadLine());
                    }   
                    else
                    {
                        Console.Write("Node" + (lineN + 1) + "(" + (line[lineN, nThNode - 1]) + ") to Node" + (lineN) + "(" + (line[lineN - 1, nThNode]) + ") : ");
                        tTime[lineN, nThNode] = Convert.ToInt32(Console.ReadLine());
                    }
                }
            }
        }

        int val = 0;
        val = assemblyLineScheduling(assemblyLines, nodes, line, inTime, outTime, tTime, path);
        Console.WriteLine("\nMinimum Time : " + val);
        for (int node = 0; node < (nodes + 2); node++)
        {
            if (node == 0)
            {
                Console.Write("Path : In" + (path[node] + 1) + "(" + inTime[path[node]] + ") --> ");	
            }
            else if (node == nodes + 1)
            {
                Console.WriteLine("Out" + (path[node] + 1) + "(" + outTime[path[node]] + ")");
            }
            else
            {
                Console.Write("Node" + (path[node] + 1) + "(" + line[path[node], node - 1] + ") --> ");
            }
        }
    }
}
/*
    Output:
        Enter the no. of nodes on Assembly line : 3

        -- In Time --

        For Line1: 30
        For Line2: 10

        -- Out Time --

        For Line1: 30
        For Line2: 30

        -- Time required at each node --

        For Assembly Line1:
        Node0: 80
        Node1: 40
        Node2: 60

        For Assembly Line2:
        Node0: 50
        Node1: 70
        Node2: 50

        -- Transaction Time --

        Node1(80) to Node2(70) : 20
        Node1(40) to Node2(50) : 20

        Node2(50) to Node1(40) : 10
        Node2(70) to Node1(60) : 30

        Minimum Time : 200
        Path : In2(10) --> Node2(50) --> Node1(40) --> Node1(60) --> Out1(30)
*/
