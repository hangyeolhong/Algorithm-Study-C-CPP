#include <iostream>
#include <algorithm>
using namespace std;

int dp[500][500];
int main(){
    int N,t;
    cin >> N;
    cin >> dp[0][0];

    for(int i=1;i<N;i++){ // 층개수
        for(int j=0;j<=i;j++){ // 층마다 개수 
            cin >> t;
            if(j==0){
                dp[i][j]=dp[i-1][j] + t;
            }
            else if(j==i){
                dp[i][j] = dp[i-1][j-1]+t;
            }
            else {
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+t;
            }
        }
    }
    sort(dp[N-1],dp[N-1]+N);
    cout << dp[N-1][N-1]<<endl;
}