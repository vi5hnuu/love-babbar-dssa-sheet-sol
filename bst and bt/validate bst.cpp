// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.



class Solution {
    private:
    bool isValidBST(TreeNode* root,long long &prev) {
        if(!root)
            return true;
        if(!isValidBST(root->left,prev))
            return false;
        
        if(root->val<=prev)
            return false;
        prev=root->val;
        return isValidBST(root->right,prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long prev=(long long)INT_MIN-1;
        return isValidBST(root,prev);
    }
};