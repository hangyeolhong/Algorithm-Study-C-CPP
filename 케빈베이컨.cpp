#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 987654321
using namespace std;
int N, M;
int adj[MAX][MAX];


void floyd(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j || adj[i][j] >= INF) adj[i][j] = 0;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    // 간선 초기화
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            adj[i][j] = INF;
    }

    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    floyd();

    vector<int> result(N+1,0);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            result[i] += adj[i][j];
    }

    int idx= 1, mins= result[1];
    for(int i=2; i<=N; i++){
        if(mins > result[i]){
            idx=i;
            mins = result[i];
        }
    }

    cout << idx << endl;
}