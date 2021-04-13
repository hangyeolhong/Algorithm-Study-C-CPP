#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool binary(int* arr, int target, int size){
    int start = 0, end = size - 1;
   
    while(end>=start){
        int mid = (start + end) / 2;
        if(arr[mid] < target){
            start = mid + 1;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else {return true; }
    }

    return false;

}

int main(){
    int N, M;
    cin >> N;
    int arr[N];

    for(int i=0; i<N; i++) cin >> arr[i];

    cin >> M;
    int arr2[M];
    for(int i=0; i<M; i++) cin >> arr2[i];

    sort(arr,arr+N);

    for(int i=0; i<M; i++){
        if(binary(arr,arr2[i],N)) cout << 1 << " ";
        else cout << 0 << " ";
        
    }
    cout << endl;
}