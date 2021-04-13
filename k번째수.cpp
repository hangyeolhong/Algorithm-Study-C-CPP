#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 5000000
using namespace std;

int N;
int heap[MAX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> heap[i];

    sort(heap,heap+N);


    cout << heap[K-1] << endl;
}