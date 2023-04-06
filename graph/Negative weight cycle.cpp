/*
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 

Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3.
Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.
 

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)
 

Constraints:
1 <= n <= 100
1 <= m <= n*(n-1), where m is the total number of Edges in the directed graph.
*/


class Solution {
public:
    //bellman ford algorithm
	int isNegativeWeightCycle(int n, vector<vector<int>> edges){
	    vector<vector<pair<int,int>>> adj(n);
	    for(auto &edge:edges){
	        adj[edge[0]].push_back({edge[1],edge[2]});//u->{v,w}
	    }
	    vector<int> dis(n,1e8);
	    //let source is 0
	    dis[0]=0;
	    
	    for(int i=0;i<n-1;i++){
	            for(int u=0;u<n;u++){
	                for(auto &v:adj[u]){
	                    if(dis[v.first]-v.second>dis[u]){
	                        dis[v.first]=dis[u]+v.second;
	                    }
	                }
	        }
	    }
	    
	    //relax once again
        for(int u=0;u<n;u++){
            for(auto &v:adj[u]){
                if(dis[v.first]-v.second>dis[u]){//new short dist found
                    return true;
                }
            }
        }
        return false;
	}
};
////////////////
// class Solution {
// public:
//     //bellman ford algorithm
// 	int isNegativeWeightCycle(int n, vector<vector<int>> edges){
// 	    vector<int> dis(n,1e8);
// 	    //let source is 0
// 	    dis[0]=0;
	    
// 	    for(int i=0;i<n-1;i++){
// 	            for(auto &edge:edges){
// 	                int u=edge[0];
// 	                int v=edge[1];
// 	                int wt=edge[2];
// 	                if(dis[v]-wt>dis[u]){
//                         dis[v]=dis[u]+wt;
//                 }
// 	        }
// 	    }
	    
// 	    //relax once again
//         for(auto &edge:edges){
//             int u=edge[0];
//             int v=edge[1];
//             int wt=edge[2];
//             if(dis[v]-wt>dis[u]){//new short dist found.
//                 return 1;
//             }
//         }
//         return 0;
// 	}
// };