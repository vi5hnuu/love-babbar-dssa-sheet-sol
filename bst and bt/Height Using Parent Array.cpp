/*
Given a parent array arr[] of a binary tree of N nodes. Element at index i in the array arr[] represents the parent of ith node, i.e, arr[i] = parent(i). Find the height of this binary tree.
Note: There will be a node in the array arr[], where arr[i] = -1, which means this node is the root of binary tree.

Example 1:

Input: N = 7
arr = {-1, 0, 0, 1, 1, 3, 5}
Output: 5
Explanation: Tree formed is:
                    0
                   / \
                  1   2
                 / \
                3   4
               /
              5
             /
            6      Height of the tree= 5
Your Task:
You do not need to read input or print anything. Your task is to complete the function findHeight() which takes N and arr[] as input parameters and returns the height of the given binary tree.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
0 ≤ arr[i] ≤ 105 
*/


class Solution{
private:
    int dfsHeight(int src,vector<vector<int>> &adj){
        if(adj[src].empty()){
            return 1;
        }
        int h=0;
        for(int neighbour:adj[src]){
            h=max(h,dfsHeight(neighbour,adj));
        }
        return h+1;
    }
public:
    int findHeight(int N, int arr[]){
        //directed graph
        vector<vector<int>> adj(N);
        
        int src=-1;
        for(int node=0;node<N;node++){
            if(arr[node]==-1){
                src=node;
                continue;
            }
            adj[arr[node]].push_back(node);
        }
        return dfsHeight(src,adj);
    }
};
