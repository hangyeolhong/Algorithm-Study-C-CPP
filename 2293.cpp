#include<iostream>

using namespace std;

int D[10001];

int main(){
    int n, k, coin;
    cin >> n >> k >> coin;
    for(int temp=0; temp<=k; temp+=coin){
        D[temp] = 1;
    }

    for(int i=1;i<n;i++){
        cin >> coin;
        for(int W = coin; W<=k;W++){
            D[W] += D[W-coin];
        }
    }
    cout << D[k];
}

