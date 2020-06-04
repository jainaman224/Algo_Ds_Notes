import 'dart:io';

var pred = [];

int minimum (var a, var b)
{
    if (a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void floydwarshall (int n, var weight)
{
    var dist = [];
    for(var i = 0; i < n; i++)
    {
        var distlist = [];
        var predlist = [];
        for(var j = 0; j < n; j++)
        {
            distlist.insert(j, weight[i][j]);
            predlist.insert(j, -999);
        }
        dist.insert(i, distlist);
        pred.insert(i, predlist);
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            var distlist = [];
            var predlist = [];

            for(int j = 0; j < n; j++)
            {
                distlist.insert(j, minimum(dist[i][j], dist[i][k] + dist[k][j]));
                predlist.insert(j, k);
            }

            dist.removeAt(i);
            dist.insert(i, distlist);
            pred.removeAt(i);
            pred.insert(i, predlist);
        }
    }

    print("The matrix shows the shortest distance between each of the vertices:");

    for (var i = 0; i < n; i++)
        print(dist[i]);
}

main()
{
    print("Enter number of vertices in the graph:");
    var n = int.parse(stdin.readLineSync());
    var weight = [];
    print("Enter initial weights of the paths connecting each vertex(Enter 9999 for the pair of vertices with no path):");

    for(int i = 0; i < n; i++)
    {
        var weightlist = [];
        for(int j = 0; j < n; j++)
        {
            print("Enter distance between $i to $j: ");
            var input = int.parse(stdin.readLineSync());
            weightlist.insert(j, input);
        }
        weight.insert(i, weightlist);

    }

    print("The initial distances between vertices:");

    for (var i = 0; i < n; i++)
    {
        print(weight[i]);
    }
    floydwarshall(n, weight);
}

/*
Enter number of vertices in the graph:
4
Enter initial weights of the paths connecting each vertex(Enter 9999 for the pair of vertices with no path):
Enter distance between 0 to 0:
0
Enter distance between 0 to 1:
8
Enter distance between 0 to 2:
9999
Enter distance between 0 to 3:
1
Enter distance between 1 to 0:
9999
Enter distance between 1 to 1:
0
Enter distance between 1 to 2:
1
Enter distance between 1 to 3:
9999
Enter distance between 2 to 0:
4
Enter distance between 2 to 1:
12
Enter distance between 2 to 2:
0
Enter distance between 2 to 3:
5
Enter distance between 3 to 0:
9999
Enter distance between 3 to 1:
2
Enter distance between 3 to 2:
9
Enter distance between 3 to 3:
0
The initial distances between vertices:
[0, 8, 9999, 1]
[9999, 0, 1, 9999]
[4, 12, 0, 5]
[9999, 2, 9, 0]
The matrix shows the shortest distance between each of the vertices:
[0, 3, 4, 1]
[5, 0, 1, 6]
[4, 7, 0, 5]
[7, 2, 3, 0]*/
