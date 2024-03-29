/*
Given an undirected graph with V vertices(numbered from 1 to V) and E edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is a fully connected component.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in a component, the given graph can be a disconnected graph. Consider the adjacency list from index 1.

Example 1:

Input: 

Output: 1
Explanation: We can see that there is only one 
component in the graph and in this component 
there is a edge between any two vertces.
Example 2:

Input:

Output: 2
Explanation: We can see that there are 3 components
in the graph. For 1-2-7 there is no edge between
1 to 7, so it is not a fully connected component.
Rest 2 are individually fully connected component.
Your Task:
You don't need to read input or print anything. Your task is to complete the function
findNumberOfGoodComponent() which takes an integer V and an adjacency list adj as input parameters and returns an integer denoting the number of good components.

Expected Time Complexity: O(V+E)
Expected Auxiliary Space: O(depth of the graph)

Constraints:
1 ≤ V, E ≤ 104
*/


class Solution {
private:
    void dfs(int u,vector<vector<int>> &adj,int &adjCount,vector<bool> &visited){
        visited[u]=true;
        
        int adjSz=adj[u].size();
        if(adjCount==-1){
            adjCount=adjSz;
        }else{
            if(adjCount!=adjSz){
                adjCount=-2;   
            }
        }
        for(int v:adj[u]){
            if(!visited[v]){
                dfs(v,adj,adjCount,visited);   
            }
        }
    }
public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V+1,false);
        int goodComponent=0;
        
        //if isolated component is good then nodeCount*(nodeCount-1)/2===total indegree of nodes
        
        for(int i=1;i<=V;i++){
            if(visited[i]){
                continue;
            }
            queue<int> nodes;
            nodes.push(i);
            int edges=adj[i].size();
            visited[i]=true;
            
            int nodeCount=1;
            while(!nodes.empty()){
                int node=nodes.front();
                nodes.pop();
                for(int neigh:adj[node]){
                    if(!visited[neigh]){
                        visited[neigh]=true;
                        edges+=adj[neigh].size();
                        nodeCount++;
                        nodes.push(neigh);
                    }
                }
            }
            if(edges==(nodeCount*(nodeCount-1))){
                goodComponent++;
            }
        }
        return goodComponent;
    }
};