#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

vector<int> result;
vector<bool> visited;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
}

void Explore(int v, vector<vector<int> > &adj){
    visited[v] = true;
    //std::cout << v+1<< ' ';
    //if (adj[v].size() == 0)

    for (auto w : adj[v]){
        if (!visited[w])
            Explore(w, adj);
    }
    result.push_back(v);
}

//vector<int> toposort(vector<vector<int> > adj) {
//  vector<int> used(adj.size(), 0);
//  vector<int> order;
//  //write your code here
//
//
//
//  return order;
//}

void toposort(vector<vector<int> > adj) {
    visited.resize(adj.size(),false);
    result.resize(adj.size(), 0);
    for (int v = 0; v < adj.size(); v++){
        if (!visited[v]){
            Explore(v, adj);
        }
    }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  //vector<int> order = toposort(adj);
  toposort(adj);
  reverse(result.begin(), result.end());
  for (size_t i = 0; i < adj.size(); i++) {
    std::cout << result[i] + 1 << " ";
  }
  //std::cout << '\n' << result.size();
}
