#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool vps(string str){
    stack<char> st; // 괄호만 들어가는 스택
    int len = str.length();

    for(int i=0;i<len;i++){
        if(str[i]=='(' || str[i]=='['){
            // 여는 괄호면
            st.push(str[i]);
        }
        else if(str[i]==')'){
            // 닫는 괄호면
            if (st.empty()){ // (가 안들어가있는거
                return false;
            }
            else if(st.top()==')' || st.top()==']' || st.top()=='[') { // 짝이 안맞음
                return false;
            }
            else if(st.top()=='(') {
                st.pop();
            }
        }
        else if(str[i]==']'){
            if(st.empty()) return false;
            else if(st.top()==']' || st.top()==')' || st.top()=='(') return false;
            else if(st.top()=='[') st.pop();
        }
    }

    return st.empty();
}
int main(){
    string testcase, bracket;
    int n;
    
    getline(cin, testcase);
    while(testcase!="."){
        if(!vps(testcase))   cout << "no" << endl;
        else cout << "yes" << endl;
        getline(cin, testcase);
    }
}