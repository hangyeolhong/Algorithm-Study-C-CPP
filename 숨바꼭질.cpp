#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#define MAX 100001
using namespace std;

int N, K;

queue <pair <int ,int> > q;
int direct[3] = {1, -1, 2};

void bfs(){
    int result = 0;
    vector <int> visited(MAX,false);

    while(!q.empty()){
        int temp = q.front().first;
        int temp2 = q.front().second;

        // cout << temp << endl;
        q.pop();

            if( temp == K){
                cout << temp2 << endl;
                return;
            }

            for(int i=0; i<2; i++){
                int nx = temp + direct[i];
                if(nx>=0 && nx < MAX){
                    if(!visited[nx]){
                        q.push(make_pair(nx,temp2+1));
                        visited[nx] = true;
                    }
                }
            }

            if(2*temp < MAX && !visited[temp*2]){
                q.push(make_pair(temp*2, temp2+1));

                visited[temp*2] = true;
            }
        
    }
}

int main(){
    cin >> N >> K;

    q.push(make_pair(N,0));
    bfs();
}