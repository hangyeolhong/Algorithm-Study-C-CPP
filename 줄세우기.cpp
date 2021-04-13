#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 32001
using namespace std;
int N, M;
vector<int> adj[MAX];
vector<int> seen, order;
void dfs(int here){
    seen[here] = 1;
    for(int there=0; there<adj[here].size(); there++){
        if(!seen[adj[here][there]]){
            dfs(adj[here][there]);
        }
    }
    order.push_back(here);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;

    cin >> N >> M;
    seen = vector<int>(N+1, 0);
    order.clear();

    for(int i=0; i<M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }


    for(int i=1 ; i<=N; i++){
        if(!seen[i]) dfs(i);
    }
    
    reverse(order.begin(),order.end());

    for(int i=0; i<order.size(); i++)
        cout << order[i] << " ";
    cout << endl;
}