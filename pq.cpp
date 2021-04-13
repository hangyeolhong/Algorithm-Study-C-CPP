#include <iostream>
#include <algorithm>
int trees[1000001];
int N, M;
using namespace std;

long long int treeLength(int cutHeight){
    long long int sum=0;
    for(int i=0;i<N;i++){
        if(trees[i]>cutHeight)
            sum +=(trees[i]-cutHeight); 
    }
    return sum;
}
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> trees[i];
    }

    int low=0, high = *max_element(trees,trees+N);
    int mid;

    while(low<high){
        mid = (low+high)/2;
        long long int temp = treeLength(mid);
        if(temp>M){
            //이러면 너무 많이 자른것. 즉 높이가 너무 낮은것. 따라서 높이를 높일 필요가 있음
            if(low==mid) break;
            low = mid;
        }
        else if(temp<M){
            //너무 높이가 높아.
            high = mid;
        }
        else break;
    }

    cout << mid << endl;
}