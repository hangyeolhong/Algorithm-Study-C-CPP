#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;


vector<bool> prime(MAX,true);
vector<int> primes;

void Prime(){
	prime[0]=false, prime[1]=false;
	int counts=0;

	for(int i=2; i<=MAX; i++){
		for(int j=i*2; j<=MAX; j+=i){
			if(prime[j]==true) {prime[j] = false; }
		}
	}
}

void findPrime(int a){
    int i;
    vector<pair<int, int > > temp;
    for(i=2; i<=a; i++){
        if(prime[i]==true){
            int sum = a - i;
            if(prime[sum]==true){
                cout << a << " = " << i << " + " << sum << '\n';
                return;
            }
        }
    }

    if(i==a+1){
        cout << "Goldbach's conjecture is wrong." << '\n';
        return;
    }
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    Prime();
	
	int N;

    cin >> N;

    while(N!=0){
        findPrime(N);
        cin >> N;
    }

}