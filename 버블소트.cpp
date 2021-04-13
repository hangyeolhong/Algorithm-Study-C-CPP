#include <iostream>
#define MAX 500000
using namespace std;
long long arr[MAX] = {0, };
int N;
long long counts= 0, ans=0;
long long arr2[MAX];
void merge(long long left, long long right){
    // cout << left << right << endl;
    long long mid = (left + right) / 2;

    long long i = left, j = mid + 1, k = left;

    while(i<=mid && j <=right){
        if(arr[i]<=arr[j]){
            arr2[k++] = arr[i++];
            // ans += counts;
        }
        else {
            arr2[k++]  = arr[j++]; 
            ans += (mid+1 - i);
        }
    }

    long long tmp = i>mid ? j : i;

    // 나머지 합치기
    while(k<=right) arr2[k++] = arr[tmp++];
    for(long long i=left; i<=right; i++){
        arr[i] = arr2[i];
    }
}
void partition(long long left, long long right){
    long long mid;
    if(left < right){
        mid = (left+ right)/2;
        partition(left,mid);
        partition(mid+1, right);
        merge(left, right);
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    partition(0,N-1);
    
    cout << ans << endl;

}