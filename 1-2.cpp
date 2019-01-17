#include <iostream>
#include <vector>

using std::vector;
using std::pair;

class Graph{
    int n,m;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> CCnum;
    int cc;


public:
    Graph(int n, int m, vector<vector<int>> adj): n(n), m(m), adj(adj){}


void Explore(int v){
    visited[v] = true;
    CCnum[v] = cc;
    for (auto w : adj[v]){
        if (!visited[w])
            Explore(w);
    }
}

int number_of_components(void) {
    cc = 0;
    visited.resize(n,false);
    CCnum.resize(n,0);
    for (int v = 0; v < adj.size(); v++){
        if (!visited[v]){
            Explore(v);
            cc++;
        }
    }
    return cc;
}

};

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  Graph graph(n,m,adj);
  std::cout << graph.number_of_components();
}
