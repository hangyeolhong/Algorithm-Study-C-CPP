#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int indegree[MAX];
vector<int> graph[MAX];
int main(){
    int N, M;
    cin >> N >> M;
    priority_queue<int, vector<int> ,greater<int> > q; // 오름차순


    int a,b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        indegree[b]++;
        graph[a].push_back(b);
    }

    for(int i=1; i<=N; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.top();
        q.pop();

        cout << node << " ";

        for(int i=0;i<graph[node].size(); i++){
            int nextNode = graph[node][i];

            if(--indegree[nextNode]==0)
                q.push(nextNode);
        }
    }

    cout << '\n';

}