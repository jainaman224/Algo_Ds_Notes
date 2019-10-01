#include<iostream>
#include<algorithm>
#include<vector>
#define ms 100000
using namespace std;

struct aresta{
    int peso;
    int x,y;
};

bool cmp(aresta a, aresta b){ return a.peso<b.peso; }

int pai[ms];
aresta fin[ms];

int find(int x){
    if(pai[x]==x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int a, int b){
    pai[find(a)] = find(b);
}

int kruskal(vector<aresta>& are){
    int tam=are.size();
    for(int i=0;i<tam;i++) pai[i]=i; //inicializando o union 
    sort(are.begin(),are.end(),cmp); //ordena as arestas
    int t=0, som=0;
    for(int i=0;i<tam;i++){
        if(find(are[i].x)!=find(are[i].y)){
            join(are[i].x,are[i].y);
            fin[t++]=are[i];
        }
    }
    for(int i=0;i<t;i++){
        cout << fin[i].x+1 << " " << fin[i].y+1 << " " << fin[i].peso << endl;
        som+=fin[i].peso;
    }
    return som;
}

int main(void){
    vector<aresta> are;
    aresta aux;
    int n, e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        cin >> aux.x >> aux.y >> aux.peso; 
        aux.x--; aux.y--;
        are.push_back(aux);
    }
    cout << endl;
    int peso = kruskal(are);
    cout << peso << endl;
    return 0;
}
