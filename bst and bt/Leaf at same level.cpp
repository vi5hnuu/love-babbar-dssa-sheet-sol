/*
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.

Your Task: 
You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^3
*/


class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        queue<Node*> nodes;
        nodes.push(root);
        
        
        while(!nodes.empty()){
            int sz=nodes.size();
            bool isLastLevel=false;
            while(sz>0){
                sz--;
                Node *node=nodes.front();
                nodes.pop();
                
                if(!node->left && !node->right){
                    isLastLevel=true;
                }
                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);
                }
            }
            if(isLastLevel && !nodes.empty()){
                return false;
            }
        }
        return true;
    }
};