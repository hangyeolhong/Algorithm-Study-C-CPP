#include <iostream>
#include <list>
using namespace std;

int startPerson, endPerson;
struct node {
    int num;
    int count;
};

class Graph{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    int BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}
int Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] =false;

    list<node>queue;
    visited[s] = true;
    node start_node = {s, 0};
    queue.push_back(start_node);

    list<int>::iterator i;
    int count;

    while(!queue.empty()){
        s = queue.front().num;
        count = queue.front().count;
        queue.pop_front();

        if(s==endPerson){
            delete[] visited;
            return count;
        }

        for(i=adj[s].begin(); i!=adj[s].end();++i){
            if(!visited[*i]){
                visited[*i] = true;
                node temp = { *i, count+1};
                queue.push_back(temp);
            }
        }
    }
    delete[] visited;
    return -1;
}

int main(){
    int n, m ,p, c;
    cin >> n >> startPerson >> endPerson >> m;
    Graph g(n+1);
    for(int i=0;i<m;i++){
        cin >> p >> c;
        g.addEdge(p,c);
        g.addEdge(c,p);
    }

    cout << g.BFS(startPerson) << endl;
    return 0;
}