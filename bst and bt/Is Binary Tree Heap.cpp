/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/


class Solution {
  public:
    bool isHeap(struct Node *root) {
        queue<Node*> nodes;
        nodes.push(root);
        
        int childCount=1;
        while(!nodes.empty()){
            int sz=nodes.size();
            int cCount=sz;
            bool hasNxtLevel=false;
            bool missingInLevel=false;
            while(sz>0){
                sz--;
                Node *node=nodes.front();
                nodes.pop();
                if(node->left){
                    hasNxtLevel=true;
                    if(node->left->data>node->data || missingInLevel){
                        return false;
                    }
                    nodes.push(node->left);
                }else{
                   missingInLevel=true; 
                }
                if(node->right){
                    hasNxtLevel=true;
                    if(node->right->data>node->data || missingInLevel){
                        return false;
                    }
                    nodes.push(node->right);
                }else{
                    missingInLevel=true;
                }
            }
            
            
            
            //check if this level has missing childs
            if(hasNxtLevel && cCount!=childCount){
                return false;
            }
            childCount*=2;
        }
        return true;
    }
};