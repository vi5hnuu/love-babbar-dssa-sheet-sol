#include<bits/stdc++.h>
using namespace std;

class Graph{
  private:
    unordered_map<int,list<int>> adj;
  public:
    enum TYPE{
      DIRECTED,UNDIRECTED
    };
    void addEdge(int u,int v,TYPE type){
      adj[u].push_back(v);
      if(type == UNDIRECTED && u!=v){
        adj[v].push_back(u);
      }
    }
    void printAdjList(){
      cout<<"Adjacency List :"<<endl;
      for(auto itr:adj){
        cout<<itr.first<<" -> ";
        for(auto &node:itr.second){
          cout<<node<<" ";
        }
        cout<<endl;
      }
    }
};

int main(){
  int n;
  cout<<"Enter the number of nodes"<<endl;
  cin>>n;

  int m;
  cout<<"Enter the number of edges"<<endl;
  cin>>m;

  Graph graph;
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    // graph.addEdge(u,v,Graph::TYPE::UNDIRECTED);
    graph.addEdge(u,v,Graph::TYPE::DIRECTED);
  } 
  graph.printAdjList();
}