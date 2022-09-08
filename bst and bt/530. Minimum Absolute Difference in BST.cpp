// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

// Example 1:


// Input: root = [4,2,6,1,3]
// Output: 1
// Example 2:


// Input: root = [1,0,48,null,null,12,49]
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [2, 104].
// 0 <= Node.val <= 105
 

// Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

class Solution {
    void inorderRnDiff(TreeNode *root,TreeNode *&prev,int &ans){
        if(!root)
            return;
        inorderRnDiff(root->left,prev,ans);
        if(prev){
            int cur=abs(root->val-prev->val);
            if(cur<ans)
                ans=cur;
        }
        prev=root;
        inorderRnDiff(root->right,prev,ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        TreeNode *prev=NULL;
        inorderRnDiff(root,prev,ans);
        return ans;
    }
};