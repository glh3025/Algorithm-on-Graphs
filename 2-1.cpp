#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited;
bool result = false;

void Explore(int v, int cnt, vector<vector<int> > &adj){
    visited[v] = true;
    //std::cout << v+1<< ' ';
    //CCnum[v] = cc;
    //if (adj.size()!=0){
    for (auto w : adj[v]){
        if (w == cnt){
            result = true;
            return;
        }

        else if (!visited[w])

            Explore(w, cnt, adj);
            //std::cout << w+1 ;
    }
//std::cout << '\n';
    return;
}


int acyclic(vector<vector<int> > &adj) {
  //write your code here

  visited.resize(adj.size(),false);
  //int cnt = 1;
  //bool result = false;

  for (int v = 0; v < adj.size(); v++){
        //if (!visited[v])
            {
                //std::cout << "explore" ;
            visited.resize(adj.size(),false);
            //result = ;
            Explore(v, v, adj);
            if (result)
                return 1;
            //std::cout << '\n';
            //cnt++;
        }
    }



  return 0;
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
  //std::cout << '\n';
  std::cout << acyclic(adj);
}
