#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> parent, ranks;

int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unions(int u, int v){
    u  = find(u);
    v = find(v);

    if(u==v) return;
    if(ranks[u]>ranks[v]) swap(u,v);

    parent[u] = v;
    if(ranks[u]==ranks[v]) ++ranks[v];
}

bool finds(int u, int v){
    u = find(u);
    v = find(v);
    if(u==v) return true;
    else return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int a,b,calc;


    for(int i=0; i<=n; i++){
        parent.push_back(i);
        ranks.push_back(1);
    }
    for(int i=0; i<m; i++){
        cin >> calc >> a >> b;
        if(calc==0) unions(a,b);
        else if(calc==1) {
            if(finds(a,b)==true) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}