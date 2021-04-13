#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    queue<int> q;
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        q.push(i);
    }

    while(q.size()>1){
        int trash = q.front();
        q.pop();
        cout << trash << " ";
        int a = q.front();
        q.pop();
        q.push(a);
    }

    cout << q.front() << endl;


}