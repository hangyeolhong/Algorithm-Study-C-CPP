#include <iostream>
#include <string>
#include <queue>
using namespace std;

int maze[101][101];
bool visited[101][101] = { false,};
int direct[4][2] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};  // 상하좌우
int N, M;
queue<pair<int, int> > q;

void bfs(int i, int j){
    visited[i][j] = true;
    q.push(make_pair(i,j));

    while(!q.empty()){
        // 행과 열은 x, y축과 반대
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        // 현재 위치에서 상하좌우 검사
        for(int k=0; k<4; k++){
            int newX = x + direct[k][0];
            int newY = y + direct[k][1];

            // 갈 수 있는 칸이면 큐에 추가 ( 이때 범위검사도 해야함! 필수.. (0,0) 같은 케이스를 위해 )
            if((!visited[newY][newX])&&(maze[newY][newX]==1) && 0<= newX && newX <M && 0<=newY && newY<N){
                q.push(make_pair(newY,newX));
                visited[newY][newX] = true;
                maze[newY][newX] = maze[y][x] + 1;
            }
        }
    }

}

int main(){
    cin >> N >> M;
    string info;
    for(int i=0;i<N;i++){
        cin >> info;
        for(int j=0;j<M;j++){
            // 이게 너무 어려웠다..
            // 문자로 된 숫자를 정수형으로 바꾸러면 'a'를 빼자.
            maze[i][j] = info[j] - '0'; // 이라면 char to int 가 가능하다. 
            
        }

    }

    bfs(0,0);
    cout << maze[N-1][M-1] << endl;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}