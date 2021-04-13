#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int M, N, K;
int graph[MAX][MAX];
int visited[MAX][MAX];
int direct[4][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0}
};
int small;

int dfs(int a, int b){
    visited[a][b] = true;
    small++;
    for(int i=0; i<4 ;i++){
        int x = b + direct[i][0];
        int y = a + direct[i][1];

        if(x>=0 && x<N && y>=0 && y<M){
            if(graph[y][x]==0 && !visited[y][x]){
                int k = dfs(y,x);
            }
        }
        
    }
    return small;
}

int main(){
    int x1, y1, x2, y2, counts=0;
    vector<int> result;
    cin >> M >> N >> K;

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            graph[i][j] = 0;
            visited[i][j] = false;
        }
    }

    for(int i=0; i<K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int width = x2-x1, height = y2-y1;
        int startRow = M-1-y1 - (height-1), startCol = x1;
        for(int j=startRow; j<startRow+height; j++){
            for(int k=startCol; k<startCol+width; k++){
                if(graph[j][k]==0) graph[j][k] = 1;
            }
        }
    }

    //     for(int i=0; i<M; i++){
    //     for(int j=0; j<N; j++){
    //         // graph[i][j] = 0;
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && graph[i][j]==0){
                dfs(i,j);
                counts++;
                result.push_back(small);
                small = 0;
            }
        }
    }

    sort(result.begin(),result.end());

    cout << counts << '\n';
    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";
    cout << '\n';

}