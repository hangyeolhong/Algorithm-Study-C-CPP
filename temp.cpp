#include <string>
#include <vector>
#include <stack>
#include<iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> st, st2;
    int temp, t;
    
    for(int i=0;i<heights.size();i++)
        st.push(heights[i]);
    
    for(int i=0;i<heights.size();i++){
        temp = st.top();
        st.pop();
        while(!st.empty()){
            t = st.top();
            if(t > temp){
                answer.push_back(st.size());
                while(!st2.empty()){
                    int temp2 = st.top();
                    st.pop();
                    st2.push(temp2);
                }
            }
            else{
                st.pop();
                st2.push(t);
            }
        }
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
}
int main(){
    vector<int> t;
    t.push_back(6);
    t.push_back(9);
    t.push_back(5);
    t.push_back(7);
    t.push_back(4);
    vector<int> result = solution(t);
    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";
    cout << endl;
}