#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

bool visited[MAX];
vector<pair<int, int> > adj[MAX];
int maxDistance =0;
int maxIndex;

void dfs(int start, int cost){

    
    visited[start] = true;

    if(maxDistance < cost){
        // cout << "뿅 "<< start << endl;
        maxDistance = cost;
        maxIndex = start;
    }

    for(int i=0; i<adj[start].size(); i++){
        int tmp = adj[start][i].first;
        int len = adj[start][i].second;
        if(!visited[tmp]){
            dfs(tmp, cost+len);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int V,a,b,c;
    cin >> V;

    for(int i=1; i<=V; i++)
        visited[i] = false;


    for(int i=0;i<V-1; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }

    dfs(1,0); // 루트부터 dfs 시작
    // cout << maxIndex << " " << maxDistance << endl;

    for(int i=1; i<=V; i++)
        visited[i] = false;
    maxDistance = 0;
    dfs(maxIndex,0);
    cout << maxDistance << endl;
}