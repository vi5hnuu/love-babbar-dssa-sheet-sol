// Given a Undirected Graph with V vertices and E edges, Find the level of node X. if X does not exist in the graph then print -1.
// Note: Traverse the graph starting from vertex 0.

Input:levelOfNode0.jpeg
X = 4
Output:levelOfNode1.jpeg
2
Explanation:

We can clearly see that Node 4 lies at Level 2.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<int> dist(V,INT_MAX);
	    bool visited[V]={false};
	    dist[0]=0;
	    visited[0]=true;
	    queue<int> nodes;
	    nodes.push(0);
	    while(!nodes.empty()){
	        int node=nodes.front();
	        nodes.pop();
	        
            if(node==X)
                return dist[node];
                
	        for(const int &u:adj[node]){
	            if(!visited[u]){
	                visited[u]=true;
	                dist[u]=dist[node]+1;
	                nodes.push(u);
	            }
	        }
	        
	    }
	    return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends