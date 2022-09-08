#include<iostream>
using namespace std;


vector<int> shortestPath(vector<vector<int>> &graph){
    vector<int> dist(graph.size(),INT_MAX);
    queue<int> nodes;
    bool visited[graph.size()]={false};
    nodes.push(0);
    visited[0]=true;
    dist[0]=0;

    while(!nodes.empty()){
        int node=nodes.front();
        nodes.pop();
        for(const int &u:graph[node]){
            if(!visited[u]){
                dist[u]=dist[node]+1;
                visited[u]=true;
                nodes.push(u);
            }
        }
    }
    return dist;
}