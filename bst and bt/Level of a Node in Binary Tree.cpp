/*
Given a Binary Tree and a target key you need to find the level of target key in the given Binary Tree.

Note: The level of the root node is 1.

           3
         /   \
        2     5
      /   \
     1     4
Key: 4
Level: 3  
Note: if no such key exists then return 0.

Example 1:

Input:
        1
      /   \
     2     3
target = 4
Output: 0

Example 2:

Input:
         3
       /   \
      2     5
    /   \
   1     4
target = 4
Output: 3
Your Task:
 You don't have to take input. Just complete the function getLevel() that takes a node and a target as parameters and returns the level of the target value. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <= Number of nodes<= 105
1 <= Data of a node<= 105
1 <= Target <= 105
*/


/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
class Solution{
  public:
    // function should return level of the target node
    int getLevel(struct Node *root, int target){
        if(!root){
            return 0;
        }
        queue<Node*> nodes;
        nodes.push(root);
        
        int lvl=1;
        while(!nodes.empty()){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                Node *node=nodes.front();
                nodes.pop();
                if(node->data==target){
                    return lvl;
                }
                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);
                }
            }
            lvl++;
        }
        return 0;
    }
};