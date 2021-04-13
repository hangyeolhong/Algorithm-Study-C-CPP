#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 801
#define INF 987654321
using namespace std;
int N, E;
vector<pair<int, int> > adj[MAX];
vector<int> dijkstra(int src){
    vector<int> dist(N+1,INF);
    dist[src]=0;
    priority_queue<pair <int, int> > pq;
    pq.push(make_pair(0,src));

    while(!pq.empty()){
        // 가중치 제일 작은거 pop
        // 시작점으로부터의 거리가 작은것부터 pop
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here]<cost) continue;

        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;

            if(dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }

    return dist;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c, x,y;
    vector<int> dist;
    cin >> N >> E;

    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }

    cin >> x >> y;

    int result=0, result2=0, te;
    dist = dijkstra(1);

    if(dist[x]>=INF) {cout << -1 << endl; return 0; }
    result+=dist[x];
        
        dist.clear();
        dist = dijkstra(x);
        if(dist[y]>=INF) { cout << -1 << endl; return 0; }
        result+=dist[y];
        
        dist.clear();
        dist = dijkstra(y);
        if(dist[N]>=INF) { cout << -1 << endl; return 0; }
        result+=dist[N];


        dist.clear();
        dist = dijkstra(1);
        if(dist[y]>=INF) { cout << -1 << endl; return 0; }
        result2+=dist[y];

        dist.clear();
        dist = dijkstra(y);
        if(dist[x]>=INF) { cout << -1 << endl; return 0; }
        result2+=dist[x];

        dist.clear();
        dist = dijkstra(x);
        if(dist[N]>=INF) { cout << -1 << endl; return 0; }
        result2+=dist[N];

    cout << min(result,result2)<< endl;

}