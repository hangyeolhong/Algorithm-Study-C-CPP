#include <iostream>
#include <vector>
using namespace std;

vector <vector<int> > adj;
vector <bool> visited;
int counts=-1;
void dfs(int here){
    counts++;
    // cout << "DFS visits " << here << endl;
    visited[here] = true;

    for(int i=0; i<adj[here].size();i++){
        int there = adj[here][i];
        if(!visited[there])
            dfs(there);
    }
}
int main(){
    int N, M, x, y;
    vector<int> temp;
    cin >> N >> M;

    // N이 여기서 필요한거다~ 아하~
    visited = vector<bool> (N+1,false);

    // 2차원 벡터를 초기화하는 방법.. 오호~
    adj = vector<vector<int> >(N+1, vector<int>(0));

    for(int i=0;i<M;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // for(int i=0; i<adj.size();i++){
    //     for(int j=0;j<adj[i].size();j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    dfs(1);
    cout << counts << endl;
}