#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int V, E;
vector<pair<int,int> > adj[1001];
// vector<int> dijkstra(int src){
//     vector<int> dist(V+1, INF);
//     vector<bool> visited(V+1, false);
//     dist[src] = 0; visited[src] = false;
//     while(true){
//         int closest = INF, here;
//         for(int i=1; i<=V; i++){
//             if(dist[i] < closest && !visited[i]){
//                 here = i;
//                 closest = dist[i];
//             }
//         }
//         if(closest == INF) break;

//         visited[here]= true;
//         for(int i=0; i<adj[here].size(); ++i){
//             int there = adj[here][i].first;
//             if(visited[there]) continue;
//             int nextDist = dist[here] + adj[here][i].second;
//             dist[there] = min(dist[there], nextDist); //  첨에 주어진 가중치 vs 거쳐가는 길
//         }
//     }
//     return dist;
// }

vector<int> dijkstra(int src){
    vector<int> dist(V+1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int cost = -pq.top().first; // 여기서 양수로 만들어준다..
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;
        for(int i=0; i<adj[here].size();i++){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(dist[there]>nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main(){
    int start, end, u, v;
    int w;
    vector<int> result;
    cin >> V >> E ;

    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
    }

    cin >> start >> end;
    result = dijkstra(start);

    if(result[end]!=INF)   cout << result[end] << '\n';
}