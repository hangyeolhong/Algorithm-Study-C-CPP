#include<iostream>
#include<algorithm>
using namespace std;

int N, c=0;
int col[15];
void queens(int);
bool promising(int);

void queens(int i){
    int j;
    if(promising(i)){
        if(i==N){
            c++;
        }
        else {
            for(j=1;j<=N;j++){
                col[i+1] = j;
                queens(i+1);
            }
        }
    }
}

bool promising(int i){
    int k=1; bool sw=true;

    while(k<i && sw){
        if((col[i]==col[k]) || (abs(col[i]-col[k])==i-k))
            sw = false;
        k++;
    }
    return sw;
}
int main(){

    cin >> N;
    queens(0);
    cout << c <<endl;
    return 0;
}