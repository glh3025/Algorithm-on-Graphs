#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> dist;
  dist.resize(adj.size());
  for (int u = 0; u < dist.size(); u++) dist[u] = -1;
  //dist[0] = 0;

  vector<int> group;
  group.resize(adj.size());
  int currentGroup = 0;

  queue<int> Q;
  for (int i = 0; i< adj.size(); i++){
    if (dist[i] == -1){
      Q.push(i);
      group[i] = currentGroup;
      while (!Q.empty()){
            int u = Q.front();
            Q.pop();
            for (auto v : adj[u]){
                if (dist[v] == -1){
                    Q.push(v);
                    group[v] = currentGroup;
                    dist[v] = dist[u] +1;
                }
            }
      }
      currentGroup ++;
    }
  }
  for (int i = 0; i < adj.size(); i++){
    for (auto j : adj[i]){
        if ((dist[i]%2 == dist[j]%2) && (group[i] == group[j])) return 0;
    }
  }
  return 1;

}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
