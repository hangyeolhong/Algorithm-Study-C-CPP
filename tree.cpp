#include <list>
#include <queue>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x1f3f3f3f

int N,M;

typedef pair<int,int> iPair;
typedef pair<int, iPair> edgePair;

class Graph{
    int V;
    priority_queue<edgePair, vector<edgePair>, greater<edgePair> > pq;

    public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void Kruskal();
};

Graph::Graph(int V){
    this->V = V;
}

void Graph::addEdge(int u,int v,int w){
    pq.push(make_pair(w,make_pair(u,v)));
}

int simpleFind(const vector<int>& parent, int i){
    for(;parent[i]>=0;i=parent[i])
    ;
    return i;
}

bool weightedUnion(vector<int>& parent, int i, int j){
    i = simpleFind(parent,i);
    j = simpleFind(parent,j);
    if(i==j) return false;

    int temp = parent[i] + parent[j];
    if(parent[i] > parent[j]){
        parent[i] = j;
        parent[j] = temp;
    }
    else{
        parent[j] = i;
        parent[i] = temp;
    }
    return true;
}

void Graph::Kruskal(){
    vector<int> parent(V,-1);

    int totalCost=0;
    for(int i=0;i<N-1;i++){
        int cost = pq.top().first;
        iPair edge = pq.top().second;
        pq.pop();
        if(weightedUnion(parent,edge.first,edge.second)==true){
            totalCost+=cost;
        }
        else{
            i--;
        }
    }
    cout << totalCost << endl;
}

int main(){
    int a,b,c; cin>> N>> M;
    Graph g(N+1);

    for(int i=0;i<M;i++){
        cin >> a>>b>>c;
        g.addEdge(a,b,c);
    }
    g.Kruskal();
    return 0;
}