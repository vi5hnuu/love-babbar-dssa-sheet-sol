/*
Problem Statement
You are given an array/list 'ARR' storing values of 'N' nodes of a binary tree.
Your task is to construct a complete binary tree from the given array in level order fashion, i.e. elements from left in the array will be filled in the tree level-wise starting from level 0.
A Binary Tree is a Complete Binary Tree if all the levels are completely filled except possibly the last level and the last level has all nodes as left as possible.
For example, the following binary tree is a complete binary tree:

Note:
You need to return the root of the binary tree, the tree will be printed in level order format.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
1
7
5 6 10 2 3 5 9
Sample Output 1:
5 6 10 2 3 5 9 -1 -1 -1 -1 -1 -1 -1 -1
Explanation Of Sample Input 1:
For the first test case, the binary tree is printed in the level order format.

Sample Input 2:
2
2
1 2
5
1 2 3 4 5
Sample Output 2:
1 2 -1 -1 -1
1 2 3 4 5 -1 -1 -1 -1 -1 -1
*/


#include <bits/stdc++.h> 
/*********************************************

    Following is the Tree Node structure 
 
    template <typename T>
    class TreeNode {
    public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};

**********************************************/

TreeNode <int>* constructCBT(vector <int> arr)
{   
    int len=arr.size();
    if(len==0){
        return NULL;
    }
    TreeNode <int> *root=new TreeNode<int>(arr[0]);
    queue<TreeNode<int>*> nodes;
    nodes.push(root);

    int i=1;
    while(true){
        int sz=nodes.size();
        while(sz>0){
            sz--;
            auto node=nodes.front();
            nodes.pop();
            TreeNode <int> *left=i<len ? new TreeNode<int>(arr[i]) : NULL;
            TreeNode <int> *right=i+1<len ? new TreeNode<int>(arr[i+1]) : NULL;   

            node->left=left;
            node->right=right;
            if(!left || !right){
                return root;
            }
            nodes.push(left);
            nodes.push(right);
            i+=2;
        }
    }
    return NULL;
}