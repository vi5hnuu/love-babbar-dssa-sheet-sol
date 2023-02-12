/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<vector<int>> res;
        int oddLevel=true;
        while(!nodes.empty()){
            int sz=nodes.size();
            vector<int> temp;
            oddLevel=!oddLevel;
            while(sz>0){
                sz--;
                TreeNode *cur=nodes.front();
                temp.push_back(cur->val);
                nodes.pop();
                if(cur->left)
                    nodes.push(cur->left);
                
                if(cur->right)
                    nodes.push(cur->right);
            }
            if(oddLevel){
                for(int i=0;i<temp.size()/2;i++){
                    int t=temp[i];
                    temp[i]=temp[temp.size()-1-i];
                    temp[temp.size()-1-i]=t;
                }
            }
                
            res.push_back(temp);
        }
        return res;
    }
};