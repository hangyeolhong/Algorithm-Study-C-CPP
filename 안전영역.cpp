#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int country[MAX][MAX];
int rain[MAX][MAX];
int visited[MAX][MAX];
int N;
int direct[4][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0}
};

void dfs(int a, int b){
    visited[a][b] = true;

    for(int i=0; i<4 ;i++){
        int x = b + direct[i][0];
        int y = a + direct[i][1];

        if(x>=0 && x<N && y>=0 && y<N){
            if(rain[y][x]==1 && !visited[y][x]){
                dfs(y,x);
            }
        }
        
    }
}


int main(){
    vector<int> counts;
    cin >> N;
    int min=1, max=1;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> country[i][j];
            if(country[i][j]<min) min = country[i][j];
            if(country[i][j]>max) max = country[i][j];
        }
    }

    for(int k=0; k<= max; k++){
        // 초기화
        int result = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                rain[i][j] = 1;
                visited[i][j] = false;
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(country[i][j]<=k){
                    rain[i][j] = 0; //  잠겼음
                }
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                // 안전하고 방문 안했냐
                if(rain[i][j]==1 && !visited[i][j]){
                    dfs(i,j);
                    result++;
                }
            }
        }

        counts.push_back(result);


    }

    sort(counts.begin(), counts.end());
    cout << counts.back() << endl;
    
}