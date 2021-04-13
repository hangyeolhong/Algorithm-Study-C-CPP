#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    int N,j;
    string input;
    stack<char> st;

    cin>>N;

    for(int i=0;i<N;i++){

        // 입력 문자열 초기화
        input = "";

        cin >> input;

        for(j=0;j<input.length();j++){
            if(input[j]=='(') {
                st.push(input[j]);
            }
            else if(input[j]==')'){
                if(!st.empty()) st.pop();
                else {cout << "NO"<<endl; break;}
            }

        }
        if (j==input.length()){
            if(st.empty()) cout<<"YES"<<endl;
            else {
                cout <<"NO"<<endl;
                while(!st.empty()) st.pop();
            }
        }
    }
}