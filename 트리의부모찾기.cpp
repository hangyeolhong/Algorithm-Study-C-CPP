#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

bool visited[MAX];
vector<int> adj[MAX];
int parent[MAX] = {0,};

void dfs(int start){
    visited[start] = true;

    for(int i=0; i<adj[start].size(); i++){
        int tmp  = adj[start][i];
        if(!visited[tmp]){
            parent[tmp] = start;
            dfs(tmp);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N,a,b;
    cin >> N;

    for(int i=1; i<=N; i++)
        visited[i] = false;

    for(int i=0;i<N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1); // 루트부터 dfs 시작

    for(int i=2;i<=N; i++){
        cout << parent[i] << '\n';
    }
}