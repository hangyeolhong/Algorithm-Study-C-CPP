#include<iostream>

using namespace std;
int D[1001];    // i개까지 샀을 때 가격의 최대값

int main(){
    int N, setPrice;
    cin >> N >> setPrice;

    D[1] = setPrice;

    for(int i=2;i<=N;i++){
        cin >> setPrice;
        D[i] = setPrice;

        for(int j=1;j<=i/2;j++){
            if(D[i] < D[j] + D[i-j])
                D[i] = D[j] + D[i-j];
        }
    }

    cout << D[N] << endl;
    

}