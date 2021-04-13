#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX 101
#define INF 987654321
using namespace std;

int N, M;
int parent[MAX];
vector<pair<double, double> > temp; // (x,y)
vector<pair<double, pair<int,int> > > edge; // (가중치, (x,y))
vector<double> V;

int finds(int x){
    if(x==parent[x]) return x;
    else return parent[x] = finds(parent[x]);
}

void unions(int u,int v){
    u = finds(u);
    v = finds(v);

    if(u==v) return;
    parent[v] = u;
    // N--;
}

bool sameParent(int x,int y){
    x = finds(x);
    y = finds(y);
    if(x==y) return true;
    else return false;
}

double kruskal(){

    for(int i=1; i<=N; i++) parent[i] = i;
    int counts=0;
    // kruskal은 간선 위주 알고리즘
    for(int i=0; i<M; i++){
        int a = edge[i].second.first
            ,b = edge[i].second.second;
        if(sameParent(a,b)==false){
                unions(a,b); counts++;
                // cout << edge[i].first << "지롱\n";
                V.push_back(edge[i].first);
        }
    }

    double result=0.0;
    if(counts==N-1) {
        for(int i=0; i<V.size(); i++){
            result+=V[i];
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double A,B,C;

    cin >> N;

    if(N==1) M=0;
    else if(N==2) M=2;
    else if(N>2) {
        M = N*(N-1)/2;
    }
    for(int i=0; i<N; i++){
        cin >> A >> B;
        temp.push_back(make_pair(A,B));
    }

    // 간선 구하기
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            // cout << "aaa " << temp[i].second << " " << temp[j].second << '\n';
            C = sqrt(
                pow(temp[i].first-temp[j].first,2)
                + pow(temp[i].second - temp[j].second,2)
                );
            // cout << "*** "<< C << '\n';
            edge.push_back(make_pair(C,make_pair(i,j)));
        }
    }

    sort(edge.begin(),edge.end()); // 가중치 오름차순으로 정렬
    double result = kruskal();
    cout.precision(3);
    cout << result << endl;
}