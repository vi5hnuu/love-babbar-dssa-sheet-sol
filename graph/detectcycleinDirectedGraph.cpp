// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
   /*
    private:
    bool isCyclic(vector<int> adj[],bool *visited,bool *pathStack,int source) {
        //dfs
        visited[source]=pathStack[source]=true;
        for(const int &u:adj[source]){
            if(!visited[u]){
                if(isCyclic(adj,visited,pathStack,u))
                    return true;
            }else if(pathStack[u]){//we found visited vertex in the path
                return true;
            }
        }
        pathStack[source]=false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        bool visited[V]={false};
        bool pathStack[V]={false};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(isCyclic(adj,visited,pathStack,i))
                    return true;
            }
        }
        return false;
    }
        */
    public:
    //using kahn's algo (topological)
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> nodes;
        vector<int> indegree(V,0);
        //find indegree
        for(int i=0;i<V;i++){
            for(auto neighbour:adj[i]){
                indegree[neighbour]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                nodes.push(i);
        }
        if(nodes.empty())
            return true; //there is cycle
        
        int processedNode=0;
        while(!nodes.empty()){
            int node=nodes.front();
            processedNode++;
            nodes.pop();
            for(auto neighbour:adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                    nodes.push(neighbour);
            }
        }
        if(processedNode==V)
            return false;//all nodes processed means dependencies become zero for all
        else
            return true;//dependencies cannot be zero
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends