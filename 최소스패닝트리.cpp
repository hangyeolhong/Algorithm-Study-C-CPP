#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
#define INF 987654321
using namespace std;
int V, E, A, B, C;
vector<pair<int,int> > adj[MAX];
int prim(vector<pair<int, int> >&selected){
    selected.clear();
    vector<bool> added(V+1,false);
    // minWeight: 해당 인덱스(정점)와 인접한 간선 중 가장 작은 가중치를 저장
    vector<int> minWeight(V+1,INF), parent(V+1,-1);
    int ret=0;

    minWeight[1] = 0;
    parent[1] = 1;
    for(int iter=1; iter<V+1; iter++){
        int u = -1;
        for(int v=1; v<V+1; v++){
            if(!added[v]&&(u==-1 || minWeight[u]>minWeight[v]))
                u=v;
        }
        if(parent[u]!=u)
            selected.push_back(make_pair(parent[u],u));
        ret+=minWeight[u];
        // cout << " 뿅 " << minWeight[u] << '\n' ;
        added[u]=true;

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i].first, weight = adj[u][i].second;
            if(!added[v]&&minWeight[v]>weight){
                parent[v]=u;
                minWeight[v] = weight;
            }
        }
    }

    return ret;
}

int main(){

    vector<pair<int, int> > selected;
    cin >> V >> E;

    for(int i=0; i<E; i++){
        cin >> A >> B >> C;
        adj[A].push_back(make_pair(B,C));
        adj[B].push_back(make_pair(A,C));
    }

    int result = prim(selected);
    cout << result << '\n';

    for(int i=0; i<selected.size(); i++)
        cout << "S "<<selected[i].first << " E "<<selected[i].second << endl;
    return 0;
}