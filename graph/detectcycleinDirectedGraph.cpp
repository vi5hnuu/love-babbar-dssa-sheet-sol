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

/*
class Solution {
    bool dfs(int source,vector<int> adj[],bool visited[],bool stcktrc[]){
        visited[source]=true;
        stcktrc[source]=true;
        for(const int &x:adj[source]){
            if(!visited[x]){
              if(dfs(x,adj,visited,stcktrc)){
                    return true;
                }  
            }else if(stcktrc[x]){//visited in same tree
                return true;
            }
        }
        stcktrc[source]=false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        bool visited[V]={false};
        bool stcktrc[V]={false};//is the vertext in same stack trace [detect back edge]
        for(int i=0;i<V;i++){//its directed graph so  0->1<-2 is 2 graph as 1 has no adj vertex
            if(!visited[i]){
                if(dfs(i,adj,visited,stcktrc)){
                    return true;
                }
            }
        }
        return false;
    }
};
*/

/*
class Solution {
    private:
    vector<int> getIndegree(int v,vector<int> adj[]){
        vector<int> indegrees(v,0);
        for(int i=0;i<v;i++){
            for(int j=0,cols=adj[i].size();j<cols;j++){
                indegrees[adj[i][j]]++;
            }
        }
        return indegrees;
    }
    int topoSort(int V, vector<int> adj[]) {
	    int res=0;
	    vector<int> indegrees=getIndegree(V,adj);
	    queue<int> nodes;
	    for(int i=0;i<V;i++){
	        if(indegrees[i]==0){
	            nodes.push(i);
	        }
	    }
	    while(!nodes.empty()){
	        int node=nodes.front();
	        nodes.pop();
	        res++;
	        for(const int &child:adj[node]){
	                indegrees[child]--;
    	            if(indegrees[child]==0){
    	               nodes.push(child);
    	            }
	        }
	    }
	    return res;
	}
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        return V!=topoSort(V,adj);
    }
};
*/

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