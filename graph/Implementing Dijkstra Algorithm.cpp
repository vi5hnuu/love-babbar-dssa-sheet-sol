/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.

 

Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.
 

Example 2:

Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

 

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

 

Constraints:
1 ≤ V ≤ 1000
0 ≤ adj[i][j] ≤ 1000
1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
0 ≤ S < V
*/

//negative weight not permissible
//work with both directed and undirected with or without cycles

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    /*
        vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
       vector<int> dist(V, INT_MAX);
       vector<int> fin(V, false);
       dist[S] = 0;
       
        for(int i=0;i<V-1;i++){
            //get minimum node from non-finalized
            int u=-1;
            for(int j=0;j<V;j++){
                if(!fin[j] && (u==-1 || dist[j]<dist[u])){
                    u=j;
                }
            }
            fin[u]=true;
            
            //relax adjacent
            for(auto &ad:adj[u]){
                int v=ad[0];
                int dis=ad[1];
                if(dist[v]>dist[u]+dis){//!fin[v] &&
                    dist[v]=dist[u]+dis;
                }
            }
            
        }
        return dist;
   }
    */
   ///////////////////////
//     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
//         // Code here
//        vector<int> dist(V, INT_MAX);
//        vector<int> fin(V, false);
//        dist[S] = 0;
       
//         for(int i=0;i<V-1;i++){
//             //get minimum node from non-finalized
//             int u=-1;
//             for(int j=0;j<V;j++){
//                 if(!fin[j] && (u==-1 || dist[j]<dist[u])){
//                     u=j;
//                 }
//             }
//             fin[u]=true;
            
//             //relax adjacent
//             for(auto &ad:adj[u]){
//                 int v=ad[0];
//                 int dis=ad[1];
//                 if(!fin[v] && dist[v]>dist[u]+dis){
//                     dist[v]=dist[u]+dis;
//                 }
//             }
            
//         }
//         return dist;
        //we do not detected negative edge cycle [as there is no -ve edge cycle for sure as  the ques is of dijkstra and in dijkstra -ve edge weight is not alloweded]
//    }
    

    //bellmanford's algorithm
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> key(V,INT_MAX);
        key[S]=0;
        
        for(int i=0;i<V-1;i++){//counter for vertext at edge dist i
            //on every edge -> relax
            for(int j=0;j<V;j++){
                for(int k=0;k<adj[j].size();k++){
                    if(key[adj[j][k][0]]-adj[j][k][1]>key[j]){
                        key[adj[j][k][0]]=adj[j][k][1]+key[j];
                    }
                }
            }
        }

        //relax one more time if we get different distances there is negative weight cycle[bellman ford]
        
        return key;
    }
};