#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
    int testcase, N, M, temp;
    queue<pair<int,int> > q;
    priority_queue<int> pq;
    cin >> testcase;

    for(int i=0; i<testcase; i++){
        int counts=0;
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();
        cin >> N >> M;

        for(int j=0;j<N;j++) {
            cin >> temp;
            q.push(make_pair(j,temp));
            pq.push(temp);
        }

        while(!q.empty()){
            int a = q.front().first;    // 인덱스
            int b = q.front().second;   // 우선순위
            q.pop();

            if(pq.top()!=b){
                q.push(make_pair(a,b));
            }
            else {
                counts++;
                pq.pop();
                if(a==M){
                    cout << counts << endl;
                    break;
                }
            }
        }
    }
}