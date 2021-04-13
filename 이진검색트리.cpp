#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> inorder;
vector <int> postorder;
vector<int> slice(const vector<int>& v, int a, int b){
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPreOrder(int inleft, int inright, int postleft, int postright){
    const int N = inright - inleft +1 ;
    if(N==0) return;
    const int root = postorder[postleft+N-1]; // 후위에서 루트를 찾는다.

    // 중위에서 루트로 L, R을 구한다. - 개수 느낌
    const int L = find(inorder.begin(),inorder.end(), root)
                - inorder.begin() - inleft;
    // const int R = N - 1 - L;

    cout << root << ' ';
    printPreOrder(inleft, inleft+L-1, postleft, postleft+L-1);
    printPreOrder(inleft+L+1, inleft+N-1, postleft+L, postleft+N-2);
}

int main(){
    int temp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        inorder.push_back(temp);
    }

    for(int i=0; i<n; i++){
        cin >> temp;
        postorder.push_back(temp);
    }

    printPreOrder(0, n-1, 0, n-1);

}