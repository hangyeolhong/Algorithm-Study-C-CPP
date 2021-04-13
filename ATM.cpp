#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int times[N];

    for(int i=0; i<N; i++)
        cin >> times[i];

    sort(times,times+N);

    int result=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            result+= times[j];
        }
    }

    cout << result << '\n';
}