/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

 

Example 1:


Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
Example 2:


Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
 

Constraints:

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
*/


class Solution {
private:
    void longestCycleLength(int src,vector<vector<int>> &adj,vector<bool> &visitedA,vector<bool> &visitedB,int &mx,int rnCount){
        visitedA[src]=true;
        visitedB[src]=true;
        rnCount++;
        for(int neigh:adj[src]){
            if(!visitedA[neigh]){
                longestCycleLength(neigh,adj,visitedA,visitedB,mx,rnCount);
            }else{
                mx=max(mx,rnCount);
            }
        }
        visitedA[src]=false;
    }
public:
    int longestCycle(vector<int>& edges) {
        int sz=edges.size();
        vector<vector<int>> adj(sz);
        vector<int> indegree(sz,0);
        for(int i=0;i<sz;i++){
            if(edges[i]==-1){
                continue;
            }
            indegree[edges[i]]++;
            adj[i].push_back(edges[i]);
        }
        queue<int> nodes;
        for(int i=0;i<sz;i++){
            if(indegree[i]==0){
                nodes.push(i);
            }
        }
        vector<bool> visitedA(sz,false);
        while(!nodes.empty()){//remove uncycle nodes
            int node=nodes.front();
            nodes.pop();
            visitedA[node]=true;
            for(int neigh:adj[node]){
                indegree[neigh]--;;
                if(indegree[neigh]==0){
                    nodes.push(neigh);
                }
            }
        }
        int mx=-1;//only cycles left
        /*
        visitedA for counting cycles length
        visitedB is for actually making nodes permanent visited so that if cycles are 
        disconnected we can count there length as well.
        */
        vector<bool> visitedB=visitedA;
        for(int i=0;i<sz;i++){
            if(!visitedB[i]){
                longestCycleLength(i,adj,visitedA,visitedB,mx,0);
            }
        }
        return mx;
    }
};