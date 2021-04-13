#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
using namespace std;
int N;
char colors[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int > > q;
int direct[4][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0}
};

void bfs(int a, int b){

    // 이렇게 큐에 집어넣는 위치도 중요한개벼..
    q.push(make_pair(a,b));
    visited[a][b] = true;
    int row, col;
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int x = col + direct[i][0];
            int y = row + direct[i][1];
            
            if(x>=0 && x<N && y>=0 && y<N){
                if(colors[y][x]==colors[a][b] && !visited[y][x]){
                    visited[y][x] = true;
                    // cout << x << " " << y << endl;
                    q.push(make_pair(y,x));
                }
            }
        }

    }
}
int main(){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j] = false;
        }
    }

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> colors[i][j];
        }
    }

    int result1 = 0, result2 = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                bfs(i,j);
                result1++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(colors[i][j] == 'G') colors[i][j] = 'R';
            visited[i][j] = false;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                bfs(i,j);
                result2++;
            }
        }
    }


    cout <<result1 << " " << result2 << endl;
}