// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


 /*
 //this solution for directed graph cannot work for undirected graph
//1-2 is always cycle as per belo algo because 1 is in path of 2, 1->2 and this is not.
class Solution {
private:
    bool isCycle(int source,vector<int> *adj,vector<bool> &visited,vector<bool> &pathStack){
        visited[source]=pathStack[source]=true;
        
        for(int neighbour:adj[source]){
            if(!visited[neighbour]){
                 if(isCycle(neighbour,adj,visited,pathStack)){
                    return true;
                 }
            }else if(pathStack[neighbour]){
                return true;
            }
        }
        pathStack[source]=false;
        return false;
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> pathStack(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(isCycle(i,adj,visited,pathStack)){
                    return true;
                }
            }
        }
        return false;
    }
};
 */
class Solution {
/*
  private:
    // Function to detect cycle in an undirected graph.
    bool bfs(int V, vector<int> *adj,bool visited[],int source) {
        //bfs
        queue<pair<int,int>> nodes;
        nodes.push({source,-1});//already marked visited
        while(!nodes.empty()){
            int node=nodes.front().first;
            int par=nodes.front().second;
            nodes.pop();
            for(const int &child:adj[node]){
                if(!visited[child]){
                    visited[child]=true;
                    nodes.push({child,node});
                }
                else{
                    if(child!=par)
                        return true;
                }
            }
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[]) {
        //bfs
        bool visited[V]={false};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i]=true;
                if(bfs(V,adj,visited,i)){//if cycle
                    return true;                    
                }
            }
        }
        return false;
    }
    */
      private:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> *adj,bool visited[],int source,int par=-1) {
        //dfs
        visited[source]=true;
        for(const int &u:adj[source]){
            if(!visited[u]){
                if(dfs(adj,visited,u,source))
                    return true;
            }else if(u!=par){
                return true;
            }
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[]) {
        //bfs
        bool visited[V]={false};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,visited,i)){//if cycle
                    return true;
                }
            }
        }
        return false;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends