#include <iostream>
#include<vector>

using namespace std;

class Graph{
    int numberOfNodes;
    vector<int> *adjacencyList;
    
    public:
    Graph(int nodesCount)
    {
        numberOfNodes = nodesCount;
        adjacencyList = new vector<int>[numberOfNodes];
    }
    void addEdge(int a, int b){
       adjacencyList[a].push_back(b);
       adjacencyList[b].push_back(a);
    }
    void showConnections(){
        for(int i=0; i<numberOfNodes;i++)
        {
            cout<<i<< "--> ";
            for(int j=0;j<adjacencyList[i].size();j++)
            {
                cout<<adjacencyList[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph graph1(7);
    
graph1.addEdge(3, 1);
graph1.addEdge(3, 4);
graph1.addEdge(4, 2);
graph1.addEdge(4, 5);
graph1.addEdge(1, 2);
graph1.addEdge(1, 0);
graph1.addEdge(0, 2);
graph1.addEdge(6, 5);

graph1.showConnections();

    return 0;
}

//OUTPUT 
// 0-->1 2 
// 1-->3 2 0 
// 2-->4 1 0 
// 3-->1 4 
// 4-->3 2 5 
// 5-->4 6 
// 6-->5
