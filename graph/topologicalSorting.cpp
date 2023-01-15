//this algo work when no cycle in graph  because of dependencies

// BFS based -> kahns algo
/*
class Solution
{
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
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> res;
	    bool visited[V]={false};
	    vector<int> indegrees=getIndegree(V,adj);
	    queue<int> nodes;
	    for(int i=0;i<V;i++){
	        if(indegrees[i]==0){
	            nodes.push(i);
	            visited[i]=true;
	        }
	    }
	    while(!nodes.empty()){
	        int node=nodes.front();
	        nodes.pop();
	        res.push_back(node);
	        for(const int &child:adj[node]){
	            if(!visited[child]){
	                indegrees[child]--;
    	            if(indegrees[child]==0){
    	               nodes.push(child);
    	               visited[child]=true; 
    	            }
	            }
	        }
	    }
	    return res;
	}
};
*/
/*
class Solution
{
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
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> res;
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
	        res.push_back(node);
	        for(const int &child:adj[node]){
	                indegrees[child]--;
    	            if(indegrees[child]==0){
    	               nodes.push(child);
    	            }
	        }
	    }
	    return res;
	}
};
*/


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