#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;

int R,C;
int alpha[26] = {0,};
char board[MAX][MAX];
bool visited[MAX][MAX];
int direct[4][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0}
};
int result = 1;

void dfs(int a, int b,int c){
    if(result < c) result = c;  // 갈수있으니까 이렇게 커지는 것임..!

cout << result << endl;
    // alpha[board[a][b]-'A'] = 1;

    for(int i=0; i<4 ;i++){
        int x = b + direct[i][0];
        int y = a + direct[i][1];

        if(x>=0 && x<C && y>=0 && y<R){
            if(alpha[board[y][x]-'A']==0){
                alpha[board[y][x]-'A'] = 1;
                dfs(y,x,c+1);
                alpha[board[y][x]-'A'] = 0;
            }
        }    
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++)
            cin >> board[i][j];
    }

    alpha[board[0][0]-'A'] = 1;

    dfs(0,0,1);
    cout << result << endl;
}