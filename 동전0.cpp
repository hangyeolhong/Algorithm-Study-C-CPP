#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K, counts=0;
    cin >> N >> K;
    int coins[N];

    for(int i=0; i<N; i++){
        cin >> coins[i];
    }

    for(int i= N-1; i>=0 ; i--){
        while(K/coins[i]){
            counts += (K/coins[i]);
            K%= coins[i];
        }
    }

    cout << counts << '\n';
}