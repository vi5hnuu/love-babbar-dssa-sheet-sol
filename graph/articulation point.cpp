
#include <bits/stdc++.h>
using namespace std;

void dfs(int source,int parent,int &timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &bridges,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){
    visited[source] = true;
    disc[source] =low[source] =timer++;

    for(auto &neighbour:adj[source]){
      if(neighbour==parent){
        continue;
      }else if(!visited[neighbour]){
        dfs(neighbour,source,timer,disc,low,bridges,adj,visited);
        low[source] =min(low[source],low[neighbour]);
        //check if edge is bridge
        if(low[neighbour]>disc[source]){
          bridges.push_back({source,neighbour});
        }
      }else{
        //backedge
        low[source] =min(low[source],disc[neighbour]);
      }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges,int v,int e){
  //adj list
  unordered_map<int,list<int>> adj;

  for(auto &edge:edges){
    int u=edge[0];
    int v=edge[1];
    //undirected graph
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int timer=0;
  vector<int> disc(v);
  vector<int> low(v);

  int parent=-1;
  unordered_map<int,bool> visited;

  for(int i=0;i<v;i++){
    disc[i]=low[i]=-1;
  }


  vector<vector<int>> bridges;
  //dfs
  for(int i=0;i<v;i++){
    if(!visited[i]){
      dfs(i,parent,timer,disc,low,bridges,adj,visited);
    }
  }
  return bridges;
}