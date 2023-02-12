/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

 

Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer a[i][0] denotes that there is an edge between i and a[i][0][0] and second integer a[i][0][1] denotes that the distance between edge i and a[i][0][0] is a[i][0][1].

In other words , adj[i][j] is of form  { u , wt } . So,this denotes that i th node is connected to u th node with  edge weight equal to wt.

 

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 

Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
Graph is connected and doesn't contain self loops & multiple edges.
*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        bool MST[V]={false};
        int mWeight[V];
        fill(mWeight,mWeight+V,INT_MAX);
        
        mWeight[0]=0;
        int ans=0;
        for(int i=0;i<V;i++){
            int u=-1;
            for(int j=0;j<V;j++){
                if(!MST[j] && (u==-1 || mWeight[j]<mWeight[u])){
                    u=j;
                }
            }
            MST[u]=true;
            ans+=mWeight[u];
            
            for(int k=0,len=adj[u].size();k<len;k++){
                if(!MST[adj[u][k][0]])
                    mWeight[adj[u][k][0]]=min(mWeight[adj[u][k][0]],adj[u][k][1]);
            }
        }
        return ans;
    }
};