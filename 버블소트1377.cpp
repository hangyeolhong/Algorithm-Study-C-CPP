#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000
int N;
int heap[MAX];

void swap(int i1,int i2){
    int tmp = heap[i1];
    heap[i1] = heap[i2];
    heap[i2] = tmp;
    return;
}

void max_heap(int cur,int size){
    while(cur < N){
        int left = cur*2 + 1, right = cur*2 + 2;

        if(left<size || right < size){
            int tmp = cur;
            if(left < size) {
                if(heap[left] > heap[tmp]) tmp = left;
            }
            if(right < size){
                if(heap[right] > heap[tmp]) tmp = right;
            }
            if(tmp==cur) break;
            swap(cur, tmp);
            cur = tmp;
        }
        else break;
    }
    return;

}

void heapify(){
    for(int i=(N-1)/2; i>=0; i--){
        max_heap(i,N);
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++) cin >> heap[i];

    heapify();

    for(int i=N-1; i>=0; i--){
        swap(0,i);
        max_heap(0,i);
    }

    for(int i=0; i<N; i++) cout << heap[i] << " ";
    cout << endl;
}