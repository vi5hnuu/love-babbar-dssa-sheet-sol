/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 1. make undirected graph
 2. Do bfs from target node
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 1. make undirected graph
 2. Do bfs from target node
 */
// class Solution{
// private:
//     void buildAdj(TreeNode *root,unordered_map<int,vector<int>> &adj,TreeNode *par){
//         if(!root){
//             return;
//         }
//         if(par){
//             adj[par->val].push_back(root->val);
//             adj[root->val].push_back(par->val);
//         }
//         buildAdj(root->left,adj,root);
//         buildAdj(root->right,adj,root);
//     }
// public:
//     vector<int> distanceK(TreeNode* root,TreeNode* target, int k){
//         unordered_map<int,vector<int>> adj;
//         unordered_map<int,bool> visited;
//         //directed graph
//         buildAdj(root,adj,NULL);
        
//         queue<int> nodes;
//         nodes.push(target->val);
//         visited[target->val]=true;
        
//         vector<int> kNodes;
//         while(!nodes.empty() && k>0){
//             int sz=nodes.size();
//             while(sz>0){
//                 sz--;
//                 int node=nodes.front();
//                 nodes.pop();
//                 for(int neighbour:adj[node]){
//                     if(!visited[neighbour]){
//                         visited[neighbour]=true;
//                         nodes.push(neighbour);
//                     }
//                 }
//             }
//             if(k==0){
//                 break;
//             }
//             k--;
//         }
//         while(!nodes.empty()){
//             int node=nodes.front();
//             nodes.pop();
//             kNodes.push_back(node);
//         }
//         return kNodes;
//     }
// };
/////////////////////////////
class Solution{
private:
    bool initilizePath(TreeNode *root,TreeNode *target,vector<TreeNode*> &path){
        if(!root){
            return false;
        }
        if(root->val==target->val){
            path.push_back(root);
            return true;
        }
        if(initilizePath(root->left,target,path) || initilizePath(root->right,target,path)){
            path.push_back(root);
            return true;
        }
        return false;
    }
    //nodesAtDistK down the tree
    void nodesAtDistK(TreeNode *root,int k,vector<int> &atDistK){
        if(!root  || k<0){
            return;
        }
        if(k==0){
            atDistK.push_back(root->val);
            return;
        }
        nodesAtDistK(root->left,k-1,atDistK);
        nodesAtDistK(root->right,k-1,atDistK);
    }
public:
    vector<int> distanceK(TreeNode* root,TreeNode* target, int k){
        vector<TreeNode*> path2Target;
        if(!initilizePath(root,target,path2Target)){
            return {};
        }
        
        int pathSize=path2Target.size();
        vector<int> atDistKNodes;
        for(int i=0;i<path2Target.size();i++){
            if(i==0){
                nodesAtDistK(path2Target[i],k,atDistKNodes);
            }else{
                if(k==0){//parent itself at dist k
                    atDistKNodes.push_back(path2Target[i]->val);
                    k-=1;
                    continue;
                }
                if(path2Target[i]->left==path2Target[i-1]){//at dist k-1 in right subtree
                    nodesAtDistK(path2Target[i]->right,k-1,atDistKNodes);
                }else{//at dist k-1 in left subtree
                    nodesAtDistK(path2Target[i]->left,k-1,atDistKNodes);
                }
            }
            k-=1;
        }
        return atDistKNodes;
    }
};