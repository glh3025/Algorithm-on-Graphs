#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits.h>

#define INF 100000000

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

struct Node{
    int node;
    int dist;
    Node(int n, int d): node(n), dist(d){};
    Node(){};

};

struct op //ÖØÐ´·Âº¯Êý
{
    bool operator() (Node a, Node b)
    {
        return a.dist < b.dist; //xiao¶¥¶Ñ
    }
};


int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
//  vector<int> dist;
//  dist.resize(adj.size(), INF);
//  dist[s] = 0;

  vector<Node> nodeset;
  nodeset.resize(adj.size());
  for(int i = 0; i < nodeset.size(); i++){
    nodeset[i].node = i;
    nodeset[i].dist = INF;
  }
  nodeset[s].dist = 0;

  vector<int> prev;
  prev.resize(adj.size(), -1);

//  priority_queue<int, vector<int>, std::greater<int>> H;
//  for (auto i : dist){
//    H.push(i);
//  }

  priority_queue<Node, vector<Node>, op> H;
  for (auto i : nodeset){
    H.push(i);
  }

  while (!H.empty()){
    Node u = H.top();
    H.pop();
    for (int i = 0; i < adj[u.node].size(); i++){
        if (nodeset[adj[u.node][i]].dist > nodeset[u.node].dist + cost[u.node][i]){
            //dist[adj[u][i]] = dist[u] + cost[u][i];
            nodeset[adj[u.node][i]].dist = nodeset[u.node].dist + cost[u.node][i];
            prev[adj[u.node][i]] = u.node;
            //H.push(dist[adj[u][i]]);
            H.push(nodeset[adj[u.node][i]]);
        }
    }
  }
  if (nodeset[t].dist != INF) return nodeset[t].dist;
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
