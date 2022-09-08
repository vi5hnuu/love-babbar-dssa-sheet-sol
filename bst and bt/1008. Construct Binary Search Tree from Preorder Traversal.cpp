// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

// Example 1:


// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
// Example 2:

// Input: preorder = [1,3]
// Output: [1,null,3]
 

// Constraints:

// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 1000
// All the values of preorder are unique.

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
    private:
    TreeNode* bstFromPreorder(vector<int>& preorder,int &pi,int lbound=INT_MIN,int hbound=INT_MAX) {
        if(pi>=preorder.size() || !(preorder[pi]>=lbound &&  preorder[pi]<=hbound) )
            return NULL;
        TreeNode *root=new TreeNode(preorder[pi++]);
        root->left=bstFromPreorder(preorder,pi,lbound,root->val-1);
        root->right=bstFromPreorder(preorder,pi,root->val+1,hbound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preorderIndex=0;
        return bstFromPreorder(preorder,preorderIndex);
    }
};

//using single bound
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
/*
class Solution {
    private:
    TreeNode* bstFromPreorder(vector<int>& preorder,int &pi,int lbound=INT_MIN,int hbound=INT_MAX) {
        if(pi>=preorder.size() || !(preorder[pi]>=lbound &&  preorder[pi]<=hbound) )
            return NULL;
        TreeNode *root=new TreeNode(preorder[pi++]);
        root->left=bstFromPreorder(preorder,pi,lbound,root->val-1);
        root->right=bstFromPreorder(preorder,pi,root->val+1,hbound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preorderIndex=0;
        return bstFromPreorder(preorder,preorderIndex);
    }
};
*/

class Solution {
    private:
    TreeNode* bstFromPreorder(vector<int>& preorder,int &pi,int upper=INT_MAX) {
        if(pi>=preorder.size() || preorder[pi]>upper )
            return NULL;
        TreeNode *root=new TreeNode(preorder[pi++]);
        root->left=bstFromPreorder(preorder,pi,root->val);
        //cout<<upper<<" ";
        root->right=bstFromPreorder(preorder,pi,upper);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preorderIndex=0;
        return bstFromPreorder(preorder,preorderIndex);
    }
};


//treeFromPreorderExp.png
// smaple input
// [8,5,1,7,10,12]
// stdout upper values -> 5 8 8 2147483647 2147483647 2147483647  

// right of 1 -> upper should be 5
// right of 5 and right of 7 -> upper 8
// right of 8,10,12-> upper int max

