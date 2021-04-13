#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int K, temp;
    stack<int> st;
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> temp;
        if(temp!=0){
            st.push(temp);
        }
        else {
            st.pop();
        }
    }

    int result=0;
    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}