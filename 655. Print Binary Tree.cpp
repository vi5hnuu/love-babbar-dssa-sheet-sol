/*
Given the root of a binary tree, construct a 0-indexed m x n string matrix res that represents a formatted layout of the tree. The formatted layout matrix should be constructed using the following rules:

The height of the tree is height and the number of rows m should be equal to height + 1.
The number of columns n should be equal to 2height+1 - 1.
Place the root node in the middle of the top row (more formally, at location res[0][(n-1)/2]).
For each node that has been placed in the matrix at position res[r][c], place its left child at res[r+1][c-2height-r-1] and its right child at res[r+1][c+2height-r-1].
Continue this process until all the nodes in the tree have been placed.
Any empty cells should contain the empty string "".
Return the constructed matrix res.

 

Example 1:


Input: root = [1,2]
Output: 
[["","1",""],
 ["2","",""]]
Example 2:


Input: root = [1,2,3,null,4]
Output: 
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","4","","","",""]]
 

Constraints:

The number of nodes in the tree is in the range [1, 210].
-99 <= Node.val <= 99
The depth of the tree will be in the range [1, 10].
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

 //APPROACH FAILED
// class Solution {
// private:
//     int height(TreeNode *root){
//         if(!root){
//             return 0;
//         }
//         int h1=1+height(root->left);
//         int h2=1+height(root->right);
//         return max(h1,h2);
//     }
// public:
//     vector<vector<string>> printTree(TreeNode* root) {
//         int rows=height(root);
//         int cols=(1<<rows)-1;
//         queue<TreeNode*> nodes;
//         nodes.push(root);

//         vector<vector<string>> tree(rows,vector<string>(cols,""));

//         int row=0;
//         while(!nodes.empty()){
//             int sz=nodes.size();
//             /*
//             let cols=8,sz=4
//             */

            //FILLING FAILED
//             int i=(cols-sz)/2;
//             while(sz>0){
//                 sz--;
//                 TreeNode *node=nodes.front();


//                 if(node){
//                     tree[row][i]=to_string(node->val);
//                 }
//                 i++;
//                 nodes.pop();
//                 if(node){
//                     nodes.push(node->left);
//                     nodes.push(node->right);
//                 }else if(row!=rows){
//                     nodes.push(NULL);
//                     nodes.push(NULL);
//                 }
//             }
//             row++;
//         }   
//         return tree;
//     }
// };


/////////////////////////////////////////////////////////
class Solution {
private:
    int height(TreeNode *root){
        if(!root){
            return 0;
        }
        int h1=1+height(root->left);
        int h2=1+height(root->right);
        return max(h1,h2);
    }
    void fillTree(TreeNode *root,vector<vector<string>> &tree,int height,int i,int j){
            tree[i][j]=to_string(root->val);
            if(root->left)
                fillTree(root->left,tree,height,i+1,j-(1<<(height-i-1)));
            if(root->right)
                fillTree(root->right,tree,height,i+1,j+(1<<(height-i-1)));
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root)
            return {};
        int h=height(root)-1;
        int rows=h+1;
        int cols=(1<<(h+1))-1;
        vector<vector<string>> tree(rows,vector<string>(cols,""));
        fillTree(root,tree,h,0,(cols-1)/2);
        return tree;
    }
};