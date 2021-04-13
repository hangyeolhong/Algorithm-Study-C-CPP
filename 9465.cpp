#include<iostream>
#include<algorithm>
using namespace std;

int D[2][100000];
int P[2][100000];

enum{
    H,L
};

int main(){
    int T,n,num; 
    cin >> T;

    for(int i=0;i<T;i++){
        cin >> n;
        if(n==1){
            cin >> P[H][0] >> P[L][0];
            cout << max(P[H][0], P[L][0]) << endl;
            break;
        }
        if(n==2){
            cin >> P[H][0] >> P[H][1] >> P[L][0] >> P[L][1];
            D[H][0] = P[H][0];
            D[L][0] = P[L][0];
            D[H][1] = P[L][0] + P[H][1];
            D[L][1] = P[H][0] + P[L][1];
            cout << max(D[H][1],D[L][1]) << endl;
            break;
        }

        for(int j=0; j<n;j++)
            cin >> P[H][j];
        for(int j=0; j<n;j++)
            cin >> P[L][j];

        D[H][0] = P[H][0];
        D[L][0] = P[L][0];
        D[H][1] = P[L][0] + P[H][1];
        D[L][1] = P[H][0] + P[L][1];
        for(int k=2;k<n;k++){
            D[H][k] = max(D[L][k-2], D[L][k-1]) + P[H][k];
            D[L][k] = max(D[H][k-2], D[H][k-1]) + P[L][k];
        }
        cout << max(max(max(D[H][n-2],D[H][n-1]),D[L][n-2]),D[L][n-1])<< endl;
    }
}