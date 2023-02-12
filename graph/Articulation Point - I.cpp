/*
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

 

Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
 

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
 

Constraints:
1 ≤ V ≤ 105
*/


class Solution {
private:
    void dfs(int source,vector<int> *adj,vector<int> &low,vector<int> &disc,int &timer,int parent,vector<bool> &aps,vector<bool> &visited){
        visited[source]=true;
        low[source]=disc[source]=timer++;
        
        int children=0;
        for(auto &neighbour:adj[source]){
            if(neighbour==parent){
                continue;
            }
            if(!visited[neighbour]){
                children++;
                dfs(neighbour,adj,low,disc,timer,source,aps,visited);
                low[source]=min(low[source],low[neighbour]);
                //check if this is articulation point
                if(low[neighbour]>=disc[source] && parent!=-1){
                    aps[source]=true;
                }
                
            }else{//back edge
                low[source]=min(low[source],disc[neighbour]);
            }
        }
        if(parent==-1 && children>1){
            aps[source]=true;
        }
    }
public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> low(V,-1);
        vector<int> disc(V,-1);
        int parent=-1;
        int timer=0;
        
        vector<bool> isap(V,false);
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,low,disc,timer,parent,isap,visited);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(isap[i]){
                ans.push_back(i);
            }
        }
        if(ans.empty()){
            ans.push_back(-1);
        }
        return ans;
    }
};