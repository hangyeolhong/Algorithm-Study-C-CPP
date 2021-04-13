#include <iostream>
#include <vector>
#define MAX 50
using namespace std;

int w, h;
int country[MAX][MAX];
int visited[MAX][MAX];
int direct[8][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0},
    {-1, 1},
    {1, 1},
    {-1,-1},
    {1,-1}
};

void dfs(int a, int b){
    visited[a][b] = true;

    for(int i=0; i<8 ;i++){
        int x = b + direct[i][0];
        int y = a + direct[i][1];

        if(x>=0 && x<w && y>=0 && y<h){
            if(country[y][x]==1 && !visited[y][x]){
                dfs(y,x);
            }
        }
        
    }
}

int main(){
    cin >> w >> h;

    while(w!=0 && h!=0){
        
        // 초기화
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                country[i][j] = 0 ;
                visited[i][j] = false;
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> country[i][j];
            }
        }

        int result = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!visited[i][j] && country[i][j]==1){
                    dfs(i,j);
                    result++;
                }
            }
        }

        cout << result << '\n';
        cin >> w >> h;
    }
}