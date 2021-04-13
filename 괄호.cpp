#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool vps(string str){
    stack<char> st;
    int len = str.length();
    for(int i=0;i<len;i++){
        if(str[i]=='('){
            // 여는 괄호면
            st.push(str[i]);
        }
        else if(str[i]==')'){
            // 닫는 괄호면
            if (st.empty()){ // (가 안들어가있는거
                return false;
            }
            else if(st.top()==')') { // 짝이 안맞음
                return false;
            }
            else if(st.top()=='(') {
                st.pop();
            }
        }
    }

    return st.empty();
}
int main(){
    int T;
    string testcase;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> testcase;
        if(!vps(testcase))   cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}