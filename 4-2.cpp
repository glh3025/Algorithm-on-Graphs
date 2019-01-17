#include <iostream>
#include <vector>

#define INF 10000000

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  vector<int> dist;
  dist.resize(adj.size());
  for (int i = 0; i < dist.size(); i++){
    dist[i] = INF;
  }


//  int dist[4];
//  for (int i = 0; i < 4; i++){
//    dist[i] = INF;
//  }
  dist[0] = 0;

  vector<int> prev;
  prev.resize(adj.size(), -1);

//  for (int u = 0; u < adj.size(); u++){
//    for (auto v : adj[u]){
//        std::cout<<u<<' '<<v<<' '<<cost[u][v]<<'\n';
//    }
//  }



  for (int i = 0; i < adj.size(); i++){
    for (int u = 0; u < adj.size(); u++){
      for (int v = 0; v < adj[u].size(); v++){
        if (dist[adj[u][v]] > dist[u] + cost[u][v]){
          dist[adj[u][v]] = dist[u] + cost[u][v];
          prev[v] = u;
        }
      }
    }
  }

//  for(auto i : dist) std::cout<<i<<' ';
//  std::cout<<'\n';


  vector<int> distcheck = dist;

    for (int u = 0; u < adj.size(); u++){
      for (int v = 0; v < adj[u].size(); v++){
        if (distcheck[adj[u][v]] > distcheck[u] + cost[u][v]){
          distcheck[adj[u][v]] = distcheck[u] + cost[u][v];
        }
      }
    }

  //for(auto i : distcheck) std::cout<<i<<' ';

  for (int i = 0; i < distcheck.size(); i++){
    if (distcheck[i] != dist[i]) return 1;
  }
  //if(distcheck != dist) return 1;

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
