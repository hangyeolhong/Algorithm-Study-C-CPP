#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <string.h>
#define INF 98765432
using namespace std;

int M, N;
int maze[101][101];
int dist[101][101];

int direct[4][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0}
};

// (행, 열)을 받는다.
void dijkstra(int srcx, int srcy){
    int new_x, new_y;
    dist[srcx][srcy] = 0;   // 이걸 안해주면 무한대가 되어서 엉망이 된다.
    priority_queue<pair<int, int > > pq; // (행,열) 쌍
    pq.push(make_pair(srcx,srcy));
    
    while(!pq.empty()){
        // 열=y, 행=x
        int here_y = pq.top().first;
        int here_x = pq.top().second;
        pq.pop();

        for(int i=0; i<4; i++){
            new_x = here_x + direct[i][0];
            new_y = here_y + direct[i][1];
            int nextDist = dist[here_y][here_x] + 1;
            if(new_x>=0 && new_x <M && new_y >=0 && new_y < N){

                if((maze[new_y][new_x]==1) && (dist[new_y][new_x]>nextDist)) {
                    dist[new_y][new_x] = nextDist;
                    pq.push(make_pair(new_y,new_x));
                }
                else if((maze[new_y][new_x]==0)&& (dist[new_y][new_x]>(nextDist - 1))){
                    dist[new_y][new_x] = nextDist-1;
                    pq.push(make_pair(new_y,new_x));
                }
            }
        }
        
    }

    cout << dist[N-1][M-1] << '\n';

}
int main(){
    memset(dist,INF, sizeof(dist));

    string str;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<str.length(); j++){
            maze[i][j] = str[j]-'0';    // string을 int로 바꾸어 저장해야한다.
            // dist[i][j] = INF;
        }
    }

    dijkstra(0,0);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << dist[i][j];
        cout << endl;
    }

}