/*
Cupid wants to strike maximum houses in Geek Land on Valentine's Day. The houses in Geek Land are arranged in the form of a binary tree. Cupid is standing at target node initially. 
Find the sum of all nodes within a maximum distance k from target node. The target node should be included in the sum.


Example 1:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 9, K = 1
Output:
22
Explanation:
Nodes within distance 1 from 9 are 9, 5, 7, 1  
Example 2:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 40, K = 2
Output:
113
Explanation:
Nodes within distance 2 from 40 are 40, 19, 50, 4

Your Task:
You don't need to read input or print anything. Complete the function sum_at_distK() which takes the root of the tree, target, and K  as input parameter and returns the sum of all nodes within a max distance of k from the target


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N, Node Value ≤ 105
1 ≤ K ≤ 20
*/


/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/


//TLE 905 /1060
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
//         while(!nodes.empty() && k>=0){
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
//         return sum;
//     }
// };
//////////////////////////
class Solution{
private:
    bool getPath2Target(Node *root,int &target,vector<Node*> &path2Target){
        if(!root){
            return false;
        }
        if(root->data==target){
            path2Target.push_back(root);
            return true;
        }
        if(getPath2Target(root->left,target,path2Target) || getPath2Target(root->right,target,path2Target)){
            path2Target.push_back(root);
            return true;
        }
        return false;
    }
    int nodesWithinKDistSum(Node *root,int k){
        if(!root || k<0){
            return 0;
        }
        if(k==0){
            return root->data;
        }
        return root->data+nodesWithinKDistSum(root->left,k-1)+nodesWithinKDistSum(root->right,k-1);
    }
public:
    int sum_at_distK(Node* root, int target, int k){
       vector<Node*> path2Target;
       if(!getPath2Target(root,target,path2Target)){
           return -1;
       }
      int pathSize=path2Target.size(); 
      int nodesWithinKSum=0;
      for(int i=0;i<pathSize && k>=0;i++){
          if(i==0){
              nodesWithinKSum+=nodesWithinKDistSum(path2Target[i],k);
          }else{
              if(path2Target[i]->left==path2Target[i-1]){
                  nodesWithinKSum+=path2Target[i]->data+nodesWithinKDistSum(path2Target[i]->right,k-1);
              }else{
                  nodesWithinKSum+=path2Target[i]->data+nodesWithinKDistSum(path2Target[i]->left,k-1);
              }
          }
          k-=1;
      }
      return nodesWithinKSum;
    }
};
