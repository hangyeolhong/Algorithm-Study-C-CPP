#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];
int main(){
    int N;
    cin >> N;

    for(int i=0;i<3;i++){
        cin >> dp[0][i];
    }

    int R,G,B;
    for(int i=1;i<N;i++){
        cin >> R>>G>>B;
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + R;
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+G;
        dp[i][2] = min(dp[i-1][0],dp[i-1][1])+B;

    }

    // sort(dp[N-1],dp[N-1]+3);
    
    cout << min(min(dp[N-1][0],dp[N-1][1]),dp[N-1][2])<<endl;
    
}