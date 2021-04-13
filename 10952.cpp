#include <iostream>
#include <string>
using namespace std;

char map[3000][3000];
void init(){
    for(int i=0; i<3000;i++){
        for(int j=0; j<3000; j++)
            map[i][j] = ' ';
    }
}

void solve(int n, int x, int y){
    if(n==1){
        map[x][y] = '*';
        return;
    }
    int div = n/3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1){
                continue;
            }
            solve(div,x+(div*i), y+(div*j));
        }
    }
    return;
}
int main(){
    int N;
    cin >> N;

    init();
    solve(N,0,0);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << map[i][j];
        cout << endl;
    }
}