#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define M 1234567891
using namespace std;
long long r = 31;

long long zegop(int k){
    long long tmp = 1;
    for(int i=0; i<k; i++)
        tmp *= r;

    return tmp;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int L;
    long long sum=0;

    string str;
    cin >> L >> str;

    for(int i=0; i<L; i++){
        sum += ((long long)(str[i]-'a'+1) * zegop(i));
    }

    cout << sum % M  << endl;

}