#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<pair <int, int > > st, temp;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    stack<int> result;
    vector<int> v;
    int N, a;
    cin >> N;

    // 스택에 집어넣기
    for(int i=0; i<N; i++){
        cin >> a;
        v.push_back(a);  // (인덱스, 숫자)
    }

    for(int i=0; i<N; i++){
        // 이 수보다 작은거는 다 재낌
        while(!st.empty() && st.top().second < v[i]){
            st.pop();
        }
        // 재꼈는데 비었다? 그러면 도달하는것이 없는것임
        if(st.empty())
            cout << 0 << " ";
            
        // 뭐가 있으면 그게 처음 만나는 큰 탑이니까 인덱스를 출력
        else {
            cout << st.top().first << " ";
        }
        st.push(make_pair(i+1,v[i]));
    }
}