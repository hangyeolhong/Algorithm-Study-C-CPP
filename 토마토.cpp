#include <iostream>
#include <queue>
using namespace std;

int M, N;
int tomato[1001][1001];
bool visited[1001][1001] = {false, };
int direct[4][2] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};  // 상하좌우
queue<pair<int,int> > q;
pair<int,int> temp;

void bfs(){
    // visited[i][j] = true;
    // q.push(make_pair(i,j));

    while(!q.empty()){
        temp = q.front();
        q.pop();

        // 애초에 해당 토마토 상하좌우에 0이 없다? 그러면 그냥 넘어가는 것임. 큐에 추가가 안됨
        // 0이 있어야 큐에 추가된다.
        for(int k=0; k<4;k++){
            int x = temp.second + direct[k][0];
            int y = temp.first + direct[k][1];

            if((tomato[y][x]==0) && (x>=0) &&
                (x<M) && (y>=0) && (y<N)){
                tomato[y][x] = tomato[temp.first][temp.second] + 1;
                q.push(make_pair(y,x));
                // visited[y][x] = true;
            }
        }
    }
}
int main(){
    cin >> M >> N;

    // 행, 열로 저장 = (y,x) 로 저장
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tomato[i][j];

            // 1 아무거나 잡기--- 가 아니고..
            // 애초에 익은 토마토를 큐에 넣고 시작한다.
            if(tomato[i][j]==1){
                q.push(make_pair(i,j));
                // visited[i][j] = true;
            }
        }
    }


    bfs();
    int result=0;
    for(int i=0; i<N ; i++){
        for(int j=0; j<M; j++){
            if(tomato[i][j]==0){
                cout << -1 << endl;
                return 0;
            }

            // 최대값을 찾는다.
            if(result < tomato[i][j])
                result = tomato[i][j];

        }
    }

    // 1에서 시작했으니까
    cout << result - 1 << endl;


    // for(int i=0; i<N ; i++){
    //     for(int j=0; j<M; j++)
    //         cout << tomato[i][j]<<" ";
    //     cout << endl;
    // }
    
}