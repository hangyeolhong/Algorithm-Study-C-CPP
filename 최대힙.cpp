#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void push_heap(vector<int>& heap, int newValue){
    heap.push_back(newValue);
    int idx = heap.size() -1;

    // 루트에 도달하거나 newValue 이하의 원소를 가진 조상을 만날 때까지(더이상 바꿀 필요가 없을 때까지)
    while(idx>0 && heap[(idx-1)/2] > heap[idx]){
        swap(heap[idx],heap[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

void pop_heap(vector<int>& heap){

    // 힙의 맨 끝에서 값을 가져와 루트에 덮어씌운다.
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;

    while(true){

        int left = 2*here + 1, right = 2*here + 2;

        // 리프에 도달한 경우
        if(left>=heap.size()) break;
        // heap[here]가 내려갈 위치를 찾는다.
        int next = here;
        if(heap[next] > heap[left])
            next = left;
        if(right < heap.size() && heap[next] > heap[right])
            next = right;
        if(next==here) break;
        swap(heap[here],heap[next]);
        here = next;
    }
}

void printSmall(vector<int>& heap){
    if(heap.size()==0) cout << 0 << '\n';
    else {
        cout << heap[0] << '\n';
        pop_heap(heap);
    }
}

int main(){
    vector<int> heap;
    int N, x;
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> x;
        if(x==0) printSmall(heap);
        else push_heap(heap, x);
    }
}