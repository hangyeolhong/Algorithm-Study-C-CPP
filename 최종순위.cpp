#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 501
using namespace std;
int n;

int adj[MAX][MAX];
vector<int> seen, order;
void dfs(int here){
    seen[here] = 1;
    for(int there=1; there<=n; there++){
        if(adj[here][there] && !seen[there]){
            dfs(there);
        }
    }
    order.push_back(here);
}

int main(){
    int testcase, a,b, change;
    cin >> testcase;

    vector<int> temp;
    for(int i=0; i<testcase; i++){
        seen = vector<int>(n+1,0);
        order.clear();
        cin >> n;

        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                adj[j][k] = 0;
            }
        }

        for(int j=0; j<n; j++){
            cin >> a;
            temp.push_back(a);
        }

        for(int j=0; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int p = temp[j], q = temp[k];
                adj[p][q] = 1;
            }
        }

        cin >> change;

        for(int j=0; j<change; j++){
            cin >> a >> b;
            adj[a][b] = 1; adj[b][a] = 0;
        }

        for(int i=1 ; i<=n; i++){
            if(!seen[i]) dfs(i);
        }
        
        reverse(order.begin(),order.end());

        for(int i=0; i<order.size(); i++)
            cout << order[i] << " ";
        cout << '\n';
        



    }
}