// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    /*
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //Kahn's algorithm //bfs based
	    //add to queue whose dependency is zero(indegree)
	    queue<int> q;
	    //find indegree
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto neighbour:adj[i]){
	            indegree[neighbour]++;
	        }
	    }
	    ///////Given a Directed Acyclic Graph (DAG) with V vertices and E edges(atleast one vertex has zero indegree)
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    //
	    vector<int> topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto neighbour:adj[node]){
	            indegree[neighbour]--;
	            if(indegree[neighbour]==0)
	                q.push(neighbour);
	        }
	    }
	    return topo;
	}
	*/
	private:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> *adj,bool *visited,stack<int> &stc,int source) 
	{
	   visited[source]=true;
	   for(auto neighbour:adj[source]){
	       if(!visited[neighbour]){
	           dfs(adj,visited,stc,neighbour);
	       }
	   }
	   //dependency node(reverse stack give topo)
	   stc.push(source);
	}
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   bool visited[V]={false};
	   vector<int> res;
	   stack<int> s;
	   for(int i=0;i<V;i++){
	       if(!visited[i]){
	           dfs(adj,visited,s,i);
	       }
	   }
	   while(!s.empty()){
	       res.push_back(s.top());
	       s.pop();
	   }
	   return res;
	}
	
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends