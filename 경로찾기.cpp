#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
int N;
int adj[MAX][MAX] = {0,};
int ans[MAX][MAX] = {0,};

void floyd(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(adj[i][k]&&adj[k][j])
                    adj[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> adj[i][j];
        }
    }

    floyd();
}