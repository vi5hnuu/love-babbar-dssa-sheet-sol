/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
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

//BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> lvl;
        queue<TreeNode *> res;
        res.push(root);
        while(!res.empty()){
            vector<int> temp;
            int sz=res.size();
            while(sz>0){
                sz--;
                TreeNode *cur=res.front();
                res.pop();
                temp.push_back(cur->val);
                if(cur->left)
                    res.push(cur->left);
                if(cur->right)
                    res.push(cur->right);
            }
            lvl.push_back(temp);
        }
        return lvl;
    }
};
/////////////////
//recursive
class Solution {
private:
    void levelOrderDfs(TreeNode *root,vector<vector<int>> &levels,int level=0){
        if(!root){
            return;
        }
        if(levels.size()>level){
            levels[level].push_back(root->val);
        }else{
            levels.push_back({root->val});
        }
        levelOrderDfs(root->left,levels,level+1);
        levelOrderDfs(root->right,levels,level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        levelOrderDfs(root,levels);
        return levels;
    }
};