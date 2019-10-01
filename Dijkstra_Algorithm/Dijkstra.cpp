#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define Grafo vector<vpll>
#define inf 0x3f3f3f3f

using namespace std;

ll dist[10101010];

void dijkstra(Grafo& grafo, ll origem){
    priority_queue<pll,vpll,greater<pll>> heap;
    memset(dist,inf, sizeof(dist));
    dist[origem]=0; //set distance from itself as 0
    heap.push({0,origem});
    while(!heap.empty()){ //get all minimum cost edge until all o fthen have been checek
        pair<int,int> aux = heap.top();
        heap.pop();
        int p = aux.first;
        int v = aux.second;
        if(p>dist[v]){
            continue;
        }
        for(pll it:grafo[v]){
            if(dist[it.first]>p+it.second){
                dist[it.first] = p+it.second;
                heap.push({dist[it.first],it.first});
            }
        }
    }
}   
int main(){
    Grafo grafo;
    grafo.resize(5);
    grafo[0].push_back({1, 10});
    grafo[0].push_back({3, 5});
    grafo[1].push_back({3, 2});
    grafo[1].push_back({2, 1});
    grafo[2].push_back({4, 4});
    grafo[3].push_back({2, 9});
    grafo[3].push_back({1, 3});
    grafo[3].push_back({4, 2});
    grafo[4].push_back({2, 6});
    grafo[4].push_back({0, 7});
    dijkstra(grafo, 0);
    for(int i=0;i<5;i++)printf("%lld ",dist[i]);
    printf("\n");    
    
}
