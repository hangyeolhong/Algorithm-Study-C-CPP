#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000
using namespace std;
int N, K;
vector<long long> v;
int binary(int target){
    long long start = 1, end = v.back();
    long long sum = 0;
    while(end>= start){
        sum = 0;
        long long maxLen = (start+end)/2;
        for(int i=0; i<K; i++){
            sum += v[i]/maxLen;
        }
        if(sum < target){
            end = maxLen - 1;
        }
        else if( sum >= target){
            start = maxLen + 1;
        }

        // cout << start << " " << end << '\n';
    }
    return end;
}
int main(){
    long long a, sum = 0;
    cin >> K >> N;


    for(int i=0; i<K; i++) {
        cin >> a;
        v.push_back(a);
        sum+=a;
    }

    sort(v.begin(),v.end());
    cout << binary(N) << endl;
}