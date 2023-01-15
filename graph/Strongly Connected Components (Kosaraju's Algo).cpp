/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*106
*/

void dfs(int source,int V,const vector<int> adj[],bool visited[]){
    visited[source]=true;
    for(int i=0;i<adj[source].size();i++){
        if(!visited[adj[source][i]]){
            dfs(adj[source][i],V,adj,visited);
        }
    }
}
void fillOrder(int source,int V,const vector<int> adj[],bool visited[],stack<int> &stck){
    visited[source]=true;
    
    for(int i=0;i<adj[source].size();i++){
        if(!visited[adj[source][i]]){
            fillOrder(adj[source][i],V,adj,visited,stck);
        }
    }
    stck.push(source);
}

vector<int> * transpose(int V,vector<int> adj[]){
    vector<int> *nadj=new vector<int>[V];
    
    for(int i=0;i<V;i++){
        for(int j=0,len=adj[i].size();j<len;j++){
            nadj[adj[i][j]].push_back(i);
        }
    }
    return nadj;
}

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        bool visited[V]={false};
        stack<int> stck;//sink order
        
        //topo sort varient [we used visited array to counter cycles(strongly connected componet)]
        for(int i=0;i<V;i++){
            if(!visited[i]){
                fillOrder(i,V,adj,visited,stck);//dfs
            }
        }
        
        vector<int> *nadj = transpose(V,adj);
        
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        
        int connectedComp=0;
        while(!stck.empty()){
            int tp=stck.top();
            stck.pop();
            if(!visited[tp]){
                connectedComp++;
                dfs(tp,V,nadj,visited);
            }
        }
        return connectedComp;
    }
};