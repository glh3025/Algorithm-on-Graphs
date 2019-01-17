#include <iostream>
#include <vector>

using std::vector;
using std::pair;

class Graph{
    int n,m;
    vector<vector<int>> adj;
    vector<bool> visited;


public:
    Graph(int n, int m, vector<vector<int>> adj): n(n), m(m), adj(adj){}


void Explore(int v){
    visited[v] = true;
    for (auto w : adj[v]){
        if (!visited[w])
            Explore(w);
    }
}

int reach(int x, int y) {
    visited.resize(n,false);
    Explore(x);
    if (visited[y]) return 1;
    return 0;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << graph.reach(x - 1, y - 1);
}
