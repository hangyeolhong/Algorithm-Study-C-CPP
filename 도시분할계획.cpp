#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
#define INF 987654321
using namespace std;

int N, M;
int parent[MAX];
vector<pair<double, pair<double,double> > > edge; // (가중치, (x,y))
vector<double> V;

int finds(int x){
    if(x==parent[x]) return x;
    else return parent[x] = finds(parent[x]);
}

void unions(int u,int v){
    u = finds(u);
    v = finds(v);

    if(u==v) return;
    parent[v] = u;
    // N--;
}

bool sameParent(int x,int y){
    x = finds(x);
    y = finds(y);
    if(x==y) return true;
    else return false;
}

int kruskal(){

    for(int i=1; i<=N; i++) parent[i] = i;
    int counts=0;
    // kruskal은 간선 위주 알고리즘
    for(int i=0; i<M; i++){
        int a = edge[i].second.first
            ,b = edge[i].second.second;
        if(sameParent(a,b)==false){
                unions(a,b); counts++;
                V.push_back(edge[i].first);
        }
    }

    int result=0;
    if(counts!=N-1) return -1; 
    else {
        for(int i=0; i<V.size(); i++){
            result+=V[i];
        }
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double A,B,C;
    char g;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        cin >> A >> B >> C;
        edge.push_back(make_pair(C,make_pair(A,B)));
    }

    sort(edge.begin(),edge.end()); // 가중치 오름차순으로 정렬
    int result = kruskal();
    cout << result << endl;
}