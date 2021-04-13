#include <iostream>
using namespace std;

// 전형적인 DP 문제~
int D[1000001]; // 0~i까지 부분수열 중 i항을 반드시 포함하고 길이가 최대인 수열의 sum
int P[1000001]; // i항의 값
int main(){
    int N, start;
    cin >> N >> start;
    D[0] = 0;
    P[0] = 0;
    P[1] = start;
    D[1] = D[0] + 1;

    int max = D[0];
    for(int i=2;i<=N;i++){
        cin >> P[i];
        int tempMax = 0;

        // 전에꺼를 다 훑어본다.
        for(int j=i;j>0;j--){
            if(P[j] < P[i]){
                // 증가수열이면
                if(D[j] > tempMax){
                    tempMax = D[j];
                }
            }
        }
        D[i] = tempMax + 1;
        if(D[i] > max)
            max = D[i];
    }
    if(N==1) max=1;
    cout << max<<endl;
}