#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,counts=0;
    string str;
    cin >> N;
    stack<int> st;

    for(int i=0; i<N; i++){
        cin >> str;

        for(int j=0; j<str.length(); j++){
            if(str[j]=='A'){
                if(!st.empty()){
                    if(st.top()==0) st.pop();
                    else st.push(0);
                }
                else st.push(0);
            }

            else if(str[j]=='B'){
                if(!st.empty()){
                    if(st.top()==1) st.pop();
                    else st.push(1);
                }
                else st.push(1);
            }
        }

        if(st.empty()) counts++;
        else {
            while(!st.empty()) st.pop();
        }
    }

    cout << counts << endl;
}