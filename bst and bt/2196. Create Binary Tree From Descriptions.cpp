/*
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

 

Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:


Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
 

Constraints:

1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodes;
        unordered_map<int,bool> isChild;
        

        for(auto &des:descriptions){
            int rootVal=des[0];
            int childVal=des[1];
            bool isLeft=des[2]==1;

            //create if node not in nodes
            if(!nodes[rootVal]){
                TreeNode *rt=new TreeNode(rootVal);
                nodes[rootVal]=rt;
            }
            if(!nodes[childVal]){
                TreeNode *ch=new TreeNode(childVal);
                nodes[childVal]=ch;
            }
            if(isLeft){
                isChild[childVal]=true;
                nodes[rootVal]->left=nodes[childVal];        
            }else{
                
                isChild[childVal]=true;
                nodes[rootVal]->right=nodes[childVal];
            }
        }

        unordered_map<int,TreeNode*>::iterator itr=nodes.begin();
        while(itr!=nodes.end()){
            if(!isChild[itr->first]){
                return itr->second;
            }
            itr++;
        }
        return NULL;
    }
};