// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

// Example 1:


// Input: root = [1,2,3,4,5,6]
// Output: true
// Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
// Example 2:


// Input: root = [1,2,3,4,5,null,7]
// Output: false
// Explanation: The node with value 7 isn't as far left as possible.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 100].
// 1 <= Node.val <= 1000



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
public:
    bool isCompleteTree(TreeNode* root) {
        //level order traversal
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        TreeNode *prev=nullptr;
        while(!nodes.empty()){
            int sz=nodes.size();
            
            for(int i=0;i<sz;i++){
                TreeNode *cur=nodes.front();
                nodes.pop();
                if(!cur->left && cur->right)
                    return false;
                    //we cannot have child of cur if prev node do not have 2 nodes
                else if(prev && (cur->left || cur->right) && !(prev->left && prev->right)){
                    return false;
                }
                
                prev=cur;
                if(cur->left)
                    nodes.push(cur->left);
                if(cur->right)
                    nodes.push(cur->right);
            }
        }
        return true;
    }
};
*/


@lee215 solution [efficient with explaination]
/*
when the tree is complete then total nodes in the tree + nulls(which we will add to fill the level if required)==nodes.size() [we store tree in nodes vector]
*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        //level order traversal
        vector<TreeNode*> nodes;//store complete tree as -> The number of nodes in the tree is in the range [1, 100]. <- not so high
        nodes.push_back(root);
        int i=0;
        while(i<nodes.size() && nodes[i]){
            nodes.push_back(nodes[i]->left);//just push doesnt matter if null or not
            nodes.push_back(nodes[i]->right);////just push doesnt matter if null or not
            i++;
        }
        while(i<nodes.size() && !nodes[i]){ //(!nodes[i] <- count nulls)  if tree is complete nodes+nulls count==nodes.size() else ❌
            i++;//count nulls
        }
        return i==nodes.size();
    }
};