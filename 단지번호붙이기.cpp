#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N,counts;
int maze[26][26];
int direct[4][2] = {
    {0,1},
    {-1,0},
    {0,-1},
    {1,0}
};
bool visited[26][26] = {false, };

void dfs(int i, int j){
    visited[i][j]= true;
    counts++;

    for(int k=0; k<4; k++){
        int newY = i + direct[k][1];    // y는 행
        int newX = j + direct[k][0];    // x는 열

        if(newY>=0 && newY < N && newX>=0 && newX<N){
            if(maze[newY][newX]==1 && !visited[newY][newX])
                dfs(newY,newX);
        }
    }
}
int main(){

    // memset(visited,false,26*26);
    vector<int> result;
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

    for(int i=0 ; i<N; i++){
        for(int j=0; j<N; j++){
            if(maze[i][j]==1 && !visited[i][j]){
                counts=0;
                dfs(i,j);
                result.push_back(counts);
            }
        }
    }

    sort(result.begin(),result.end());

    cout << result.size() << '\n';
    for(int i=0; i<result.size(); i++)
        cout << result[i] << '\n';


}