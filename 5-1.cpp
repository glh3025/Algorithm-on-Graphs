#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

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

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
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

//  for (auto i : edges){
//    std::cout<<i.v1<<' '<<i.v2<<' '<<i.weight<<'\n';
//  }

  sort(edges.begin(), edges.end(), comp);

//  std::cout<<"---"<<'\n';
//  for (auto i : edges){
//    std::cout<<i.v1<<' '<<i.v2<<' '<<i.weight<<'\n';
//  }
//  std::cout<<"---"<<'\n';

  for (int i = 0; i < edges.size(); i++){
    int temp1 = thisSet.Find(edges[i].v1);
    int temp2 = thisSet.Find(edges[i].v2);
    if (temp1 != temp2){
        X.push_back(edges[i]);
        thisSet.Union(edges[i].v1, edges[i].v2);
//        for (auto p : thisSet.parent) std::cout<<p<<' ';
//        std::cout<<'\n';
//        for (auto h : thisSet.height) std::cout<<h<<' ';
//        std::cout<<'\n'<<"-"<<'\n';
    }
  }

  for (int i = 0; i < X.size(); i++){
    result += X[i].weight;
  }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
