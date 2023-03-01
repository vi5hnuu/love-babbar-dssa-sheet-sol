/*
Geek is at the geek summer carnival. To unlock discounts on exclusive courses he is given a card with a binary tree, a target node and a positive integer k on it. 
He needs to find the sum of all nodes within a max distance k from target node such that the target node is included in sum.

Example 1:

Input:
target = 9 
k = 1
Binary Tree = 
            1
           /  \
          2    9
        /     /  \
       4     5    7
      /  \       /  \
     8    19    20   11
    /   /   \
  30   40   50

Output: 22

Explanation: 
Nodes within distance 1 from 9 
9 + 5 + 7 + 1 = 22

Example 2:

Input:
target = 40 
k = 2
Binary Tree = 
            1
           /  \
          2    9
        /     /  \
       4     5    7
      /  \       /  \
     8    19    20   11
    /   /   \
  30   40   50

Output: 113

Explanation:
Nodes within distance 2 from 40,
40 + 19 + 50 + 4 = 113
Your Task:
You don't need to read input or print anything. Complete the function sum_at_distK() that takes the root of the given binary tree, target and k as input parameters and return the required sum. 

Expected time complexity: O(n)
Expected space complexity: O(n)

Constraints:
1 <= number of nodes <= 1000
1 <= data in nodes,target <= 10000
1 <= k <= 20
*/


struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

// class Solution{
// private:
//     void buildAdj(Node *root,unordered_map<int,vector<int>> &adj,Node *par){
//         if(!root){
//             return;
//         }
//         if(par){
//             adj[par->data].push_back(root->data);
//             adj[root->data].push_back(par->data);
//         }
//         buildAdj(root->left,adj,root);
//         buildAdj(root->right,adj,root);
//     }
// public:
//     int sum_at_distK(Node* root, int target, int k){
//         unordered_map<int,vector<int>> adj;
//         unordered_map<int,bool> visited;
//         //directed graph
//         buildAdj(root,adj,NULL);
        
//         queue<int> nodes;
//         nodes.push(target);
//         visited[target]=true;
        
//         int sum=0;
//         while(!nodes.empty() && k>0){
//             int sz=nodes.size();
//             while(sz>0){
//                 sz--;
//                 int node=nodes.front();
//                 nodes.pop();
//                 sum+=node;
//                 for(int neighbour:adj[node]){
//                     if(!visited[neighbour]){
//                         visited[neighbour]=true;
//                         nodes.push(neighbour);
//                     }
//                 }
//             }
//             k--;
//         }
//         while(!nodes.empty()){
//             int node=nodes.front();
//             nodes.pop();
//             sum+=node;
//         }
//         return sum;
//     }
// };

class Solution{
private:
    bool initilizePath(Node *root,int target,vector<Node*> &path){
        if(!root){
            return false;
        }
        if(root->data==target){
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
    int nodesWithinDistK(Node *root,int k){
        if(!root || k<0){
            return 0;
        }
        if(k==0){
            return root->data;
        }
        return root->data+nodesWithinDistK(root->left,k-1)+nodesWithinDistK(root->right,k-1);
    }
public:
    int sum_at_distK(Node* root,int target, int k){
        vector<Node*> path2Target;
        if(!initilizePath(root,target,path2Target)){
            return {};
        }
        
        int pathSize=path2Target.size();
        int atDistKWithinNodesSum=0;
        for(int i=0;i<path2Target.size() && k>=0;i++){
            if(i==0){
                atDistKWithinNodesSum+=nodesWithinDistK(path2Target[i],k);
            }else{
                if(path2Target[i]->left==path2Target[i-1]){//at dist k-1 in right subtree
                    atDistKWithinNodesSum+=path2Target[i]->data+nodesWithinDistK(path2Target[i]->right,k-1);
                }else{//at dist k-1 in left subtree
                    atDistKWithinNodesSum+=path2Target[i]->data+nodesWithinDistK(path2Target[i]->left,k-1);
                }
            }
            k-=1;
        }
        return atDistKWithinNodesSum;
    }
};