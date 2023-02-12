/*
You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

 

Example 1:


Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
Example 2:


Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
 

Constraints:

1 <= n <= 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated edges.
*/


class Solution {
private:
    int dfs(int source,vector<vector<int>> &adj,vector<bool> &visited){
        visited[source]=true;
        int count=1;
        for(int neighbour:adj[source]){
            if(!visited[neighbour]){
                count+=dfs(neighbour,adj,visited);
            }
        }
        return count;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        if(edges.empty()){
            return (long long)n*(n-1)/2;
        }
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            if(u!=v){//self loop
                adj[v].push_back(u);
            }
        }
        vector<bool> visited(n,false);
        vector<int> cmpSizes;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int visCount=dfs(i,adj,visited);
                // cout<<visCount<<endl;
               cmpSizes.push_back(visCount);
            }
        }
        int cmps=cmpSizes.size();
        if(cmps==1){
            return 0;
        }
        long long ttl=0;
        for(int i=0;i<cmps;i++){
            long long cmpUnvis=cmpSizes[i];
            for(int j=i+1;j<cmps;j++){
                ttl+=cmpUnvis*cmpSizes[j];
            }
        }
        return ttl;
    }
};