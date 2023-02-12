/*
Problem Statement
Given a binary tree, return the zigzag level order traversal of the nodes' values of the given tree. Zigzag traversal means starting from left to right, then right to left for the next level and then again left to right and so on in an alternate manner.
For Example:
For the binary tree in the image below

The zigzag traversal will be {{2}, {5, 7}, {2, 6, 9}, {4, 11, 5}}.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
2
1 2 3 4 -1 -1 -1 -1 -1
1 -1 2 -1 -1
Sample Output 1:
1 3 2 4
1 2
Explanation Of Sample Input 1:
For the first test case, the zigzag level order traversal of the given binary tree will be {{1}, {3, 2}, {4}}.

For the second test case, the zigzag level order traversal of the given binary tree will be {{1}, {2}}.
Sample Input 2:
2
1 -1 -1
0 1 2 4 5 3 6 -1 -1 7 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
1
0 2 1 4 5 3 6 7 
Explanation Of Sample Input 2:
For the first test case, the zigzag level order traversal of the given binary tree will be {{1}}.

For the second test case, the zigzag level order traversal of the given binary tree will be {{0}, {2, 1}, {4, 5, 3, 6}, {7}}.

*/
#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root){
    queue<TreeNode<int> *> nodes;
    nodes.push(root);

    vector<int> zigzag;
    int right=true;
    while(!nodes.empty()){
        int sz=nodes.size();
        vector<int> level;
        while(sz>0){
            sz--;
            TreeNode<int> *node=nodes.front();
            nodes.pop();
            level.push_back(node->data);
            if(node->left){
                nodes.push(node->left);
            }
            if(node->right){
                nodes.push(node->right);
            }
        }
        if(right){
            for(int n:level){
                zigzag.push_back(n);
            }
        }else{
            for(int i=level.size()-1;i>=0;i--){
                zigzag.push_back(level[i]);
            }
        }
        right=!right;
    }
    return zigzag;
}