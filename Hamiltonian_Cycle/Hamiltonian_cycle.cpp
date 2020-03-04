/* C++ program to determine if a given graph contains hamiltonian cycle or not. If it does print the path.
     
     Example :
     Consider the following graph 
                           
                          (0) --- (1) --- (2)
                           |       /    \      |
                           |     /        \    |
                           |   /            \  |
                          (3) ----------- (4)
      The result should be : Hamiltonian cycle exist ,path={0,1,2,4,3,0} 
*/
#include<bits/stdc++.h>
using namespace std;

// A utility funtion to check if the vertex v can be added at index 'pos' in the hamiltonian cycle constructed
// so far 
bool isSafe(int v, bool graph[V][V], int path[], int pos){

      //check if this vertex is an adjacent vertex of previously added vertex
      if(graph[path[pos-1]][v] == 0){
             return false;
      }
      
      //check if vertex has already been included. 
      for(int i=0; i<pos ; i++){
             if(path[i] == v){
                     return false;
              }
      }
      return true;
}

// A recursive funtion tp solve hamiltonian cycle problem 
bool hamilCycle(bool graph[v][v], int path[], int pos){

      // the base case : If all vertices are included in hamiltonian cycle
      if(pos == v){
             if(graph[path[pos-1]][path[0]] == 1){
                     return true;
             }
             return false;
      }
      
      // Try different vertices as a next candidate in hamiltonian cycle. 
      for(int j=1; j<v; j++){
             if(isSafe(j,graph,path,pos)){
                     path[pos] = v;
                     if(hamilCycle(graph, path, pos+1) == true){
                             return true;
                     }
                     path[pos] = -1; // backtrack if adding vertex v doesn't lead to a solution
             }
      } 
      return false; // if no vertex can be added then return false
}

// A utility funtion to print the solution
void printSolution(int path[]){
      cout<<"Hamiltonian Cycle :"<<endl;
      for(int i=0; i<v; i++){
             cout<<path[i]<<" ";
      }
      cout<<path[0]<<endl;
}

int main(){
      int v;
      cin>>v;
      bool graph[v][v];
      for(int i=0;i<v;i++){
             for(int j=0;j<v;j++){
                    cin>>graph[i][j];
             }      
      }
      
      int* path=new int[v];
      for(int i=0;i<v;i++){
              path[i] = -1;
      }

      path[0] = 0;
      if(hamilCycle(graph,path,1) == false){
              cout<<"Solution does not exist";
      };
      else{
              cout<<"Hamiltonian Cycle exist :"
              printSolution(path); 
      }
      return 0;
}

Output:
      Hamiltonian Cycle exist : {0,1,2,4,3,0}