/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
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
// class Solution {
//     private:
//     //inorder traversal->inc order
//     //-2^31 <= Node.val <= 2^31 - 1 ... 
//     bool isValidBST(TreeNode* root,long long &prev) {
//         if(!root)
//             return true;
//         if(!isValidBST(root->left,prev))
//             return false;
        
//         if(root->val<=prev)
//             return false;
//         prev=root->val;
//         return isValidBST(root->right,prev);
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         long long prev=(long long)INT_MIN-1;
//         return isValidBST(root,prev);
//     }
// };
////////////////////
class Solution {
    private:
    //preorder traversal
    //-2^31 <= Node.val <= 2^31 - 1 ... 
    bool isValidBST(TreeNode* root,long long left,long long right) {
        if(!root)
            return true;
        
        if(!(root->val>left && root->val<right)){
            return false;
        }
        if(!isValidBST(root->left,left,root->val)){
            return false;
        }
        return isValidBST(root->right,root->val,right);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long lft=(long long)INT_MIN-1;
        long long rgt=(long long)INT_MAX+1;
        return isValidBST(root,lft,rgt);
    }
};