#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

class Set{
  private:
  public:
    vector<int> parent;
    vector<int> height;

    void Init(int i){
      parent.resize(i);
      height.resize(i);
    }

    void MakeSet(int i){
      parent[i] = i;
      height[i] = 0;
    }

    int Find(int i){
      while (i != parent[i]){
        i = parent[i];
      }
      return i;
    }

    void Union(int i, int j){
      int i_id = Find(i);
      int j_id = Find(j);
      if (i_id == j_id) return;
      if (height[i_id] > height[j_id])
        parent[j_id] = i_id;
      else{
        parent[i_id] = j_id;
        if (height[i_id] == height[j_id])
          height[j_id] += 1;
      }
    }
};

struct Edge{
  int v1,v2;
  double weight;
};

bool comp(const Edge &a, const Edge &b){
  return a.weight < b.weight;
}

bool comp2(const Edge &a, const Edge &b){
  return a.weight > b.weight;
}

double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  int vNum = x.size();
  Set thisSet;
  thisSet.Init(vNum);
  for (int i = 0; i < vNum; i++){
    thisSet.MakeSet(i);
  }

  int edgeNum = vNum*(vNum-1)/2;
  vector<Edge> X;
  vector<Edge> edges;
  //edges.resize(edgeNum);

  for (int i = 0; i < vNum; i++){
    for (int j = i+1; j < vNum; j++){
      double len = sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
      Edge tempEdge;
      tempEdge.v1 = i;
      tempEdge.v2 = j;
      tempEdge.weight = len;
      edges.push_back(tempEdge);
    }
  }

  sort(edges.begin(), edges.end(), comp);

  for (int i = 0; i < edges.size(); i++){
    int temp1 = thisSet.Find(edges[i].v1);
    int temp2 = thisSet.Find(edges[i].v2);
    if (temp1 != temp2){
        X.push_back(edges[i]);
        thisSet.Union(edges[i].v1, edges[i].v2);
    }
  }

//  for (auto i : X){
//    std::cout<<i.v1<<' '<<i.v2<<' '<<i.weight<<'\n';
//  }

  sort(X.begin(), X.end(), comp2);

  return X[k-2].weight;

  //return -1.;
}

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
