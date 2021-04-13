#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> st;
    for(int i=0; i<arrangement.length();i++){
        if(arrangement[i] == '('){
            st.push(0);
        }
        else if(arrangement[i] == ')'){
            int st_top = st.top();
            st.pop();
            if(st_top == 0){
                // 레이저라는 의미                    
                if(!st.empty()){ // 쇠막대기 있을 때
                    int temp=st.top() + 1;
                    st.pop();
                    st.push(temp);
                    // st.top()+=1; // 쪼개졌음
                }
            }
            
            else if (st_top>0){
                // top이 숫자면 레이저가 아니고 쇠막대기 끝을 의미
                int mak_end = st.top();
                st.pop();
                answer = answer+ mak_end+1;
                if(!st.empty()) {
                    int temp2 = st.top();
                    temp2 +=1;
                    st.pop();
                    st.push(temp2);
                    //st.top() += mak_end; 
                
                }// 다음 막대기한테 물려주기
            }
            
        }
    }
        return answer;
}

int main(){
    cout << solution("()(((()())(())()))(())") << endl;
}