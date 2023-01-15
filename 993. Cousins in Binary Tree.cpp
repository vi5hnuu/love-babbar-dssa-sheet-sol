/*
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            int sz=nodes.size();
            bool foundX=false;
            bool foundY=false;
            while(sz>0){
                sz--;
                TreeNode *node=nodes.front();
                nodes.pop();

                if(node->left && node->right){
                    if((node->left->val==x && node->right->val==y)||
                    (node->right->val==x && node->left->val==y)){
                        return false;
                    }
                }
                if(node->left){
                    nodes.push(node->left);
                    if(node->left->val==x){
                        foundX=true;
                    }else if(node->left->val==y){
                        foundY=true;
                    }
                }
                if(node->right){
                    nodes.push(node->right);
                    if(node->right->val==x){
                        foundX=true;
                    }else if(node->right->val==y){
                        foundY=true;
                    }
                }
            }

            if(foundX && foundY){
                return true;
            }else if((foundX && !foundY)||(!foundX && foundY)){
                return false;
            }
        }
        return false;        
    }
};

