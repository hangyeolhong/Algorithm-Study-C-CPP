#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 100001
using namespace std;

vector <int> parent, ranks;
int finds(int u){
    if(u==parent[u]) return u;
    return parent[u] = finds(parent[u]);
}

void unions(int u, int v){
    u  = finds(u);
    v = finds(v);

    if(u==v) return;
    if(ranks[u]>ranks[v]){
        parent[v] = u;
        ranks[u] += ranks[v];
        ranks[v] = ranks[u];
    }
    else {
        parent[u] = v;
        ranks[v] += ranks[u];
        ranks[u] = ranks[v];
    }
}

bool sameParent(int x,int y){
    x = finds(x);
    y = finds(y);
    if(x==y) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, F;
    string f1, f2;
    cin >> T;

    for(int i=0; i<T; i++){

        cin >> F;
        map<string, int> hm; // (이름, 번호)
        ranks.clear();
        parent.clear();
        for(int k=0; k<MAX; k++){
            parent.push_back(k);
            ranks.push_back(1);
        }
        int idx = 1;
        for(int j=0; j<F; j++){
            cin >> f1 >> f2;
            
            if(hm.count(f1)==0){
                hm[f1] = idx;
                idx++;
            }

            if(hm.count(f2)==0){
                hm[f2] = idx;
                idx++;
            }

            int firstidx = hm[f1], secondidx = hm[f2];

            int a = finds(firstidx);
            int b = finds(secondidx);
            
            if(sameParent(firstidx,secondidx)==false){
                unions(firstidx, secondidx);
                cout << max(ranks[a],ranks[b]) << '\n';
            }
            else {
                cout << max(ranks[a],ranks[b]) << '\n';
            }
        }
    }
}