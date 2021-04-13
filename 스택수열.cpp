#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n,i,j=0;
    stack<int> st;
    vector<char> v;

    cin >> n;
    int arr[n];
    for(i=0; i<n; i++) cin >> arr[i];

    for(i=1;i<=n;i++){
        st.push(i);
        v.push_back('+');

        while(!st.empty() && st.top()==arr[j]){
            st.pop();
            v.push_back('-');
            j++;
        }
    }

    if(!st.empty()) cout << "NO" << '\n';
    else{
        for(i=0;i<v.size();i++)
            cout << v[i] << '\n';
    }
}