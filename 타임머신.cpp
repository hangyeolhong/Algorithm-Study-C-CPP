#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 501
#define INF 987654321
using namespace std;

int N, M;
vector<pair<int, int> > adj[MAX];
bool reachable[MAX][MAX];
vector<long long> upper;
void bellman2(int src){

    upper[src] = 0;
    for(int iter=0; iter < N -1; ++iter){
        for(int here = 1; here <= N; ++here){
            if(upper[here] == INF) continue; 
            for(int i=0; i<adj[here].size(); i++){
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                upper[there] = min(upper[there], upper[here] + cost);
 
            }
        }
    }

        // 음의 사이클이 존재하면 -1을 리턴
        for(int here = 1; here <= N; ++here){
            
            for(int i=0; i<adj[here].size(); i++){
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if(upper[here]+cost < upper[there]){
                    cout << -1 << endl;
                    return;
                }
            }
        }

    for(int i=2; i<=N; i++){
        if(upper[i]==INF) cout << -1 << endl;
        else cout << upper[i] << endl;
    }


}
int main(){
    cin >> N >> M;
    int A, B, C;

    for(int i=0; i<=N; i++){
        upper.push_back(INF);
    }

    for(int i=0; i<M; i++){
        cin >> A >> B >> C;
        adj[A].push_back(make_pair(B,C));
        // adj[B].push_back(make_pair(A,C));
    }


    bellman2(1);

}