#include <iostream>
#include <vector>
#define MAX 50
using namespace std;

int T, M , N, K;
int cabbage[MAX][MAX];
bool visited[MAX][MAX];
int direct[4][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0}
};

void dfs(int a, int b){

    visited[a][b] = true;

    for(int i=0; i<4; i++){
        int x = b + direct[i][0];
        int y = a + direct[i][1];

        if(x>=0 && x<M && y>=0 && y<N){
            if(cabbage[y][x]==1 && !visited[y][x])
                dfs(y,x);
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, j,k;
    cin >> T;

    for(int i=0; i<T; i++){
        int counts = 0;
        for(j=0; j<MAX; j++){
            for(k=0; k<MAX; k++){
                cabbage[j][k] = 0;
                visited[j][k] = false;
            }
        }
        cin >> M >> N >> K;

        for(j=0; j<K; j++){
            cin >> a >> b;
            cabbage[b][a] = 1;
        }

        for(j=0; j<N; j++){
            for(k=0; k<M; k++){
                if(!visited[j][k] && cabbage[j][k]==1) { dfs(j,k); counts++;}

            }
        }

        cout << counts << '\n';
    }
}