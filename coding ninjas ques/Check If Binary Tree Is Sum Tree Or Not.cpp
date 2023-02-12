/*
Problem Statement
You are given an arbitrary binary tree consisting of N nodes where each node is associated with a certain value. You need to check whether the given tree is a sum tree or not.
A binary tree is a sum tree if the value of each node is equal to the sum of nodes present in the left and the right subtree. An empty tree is a sum tree with 0 sums. A leaf node is also considered a sum tree with a sum equal to the value of the leaf node.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Input Format :
The first line of the input contains a single integer T, representing the number of test cases. 

The first line of each test case will contain the values of the tree’s nodes in the level order form ( -1 for NULL node). Refer to the example for further clarification.
Example :
Consider the binary tree

The input of the tree depicted in the image above will be like: 

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1

Explanation :
Level 1 :
The root node of the tree is 1

Level 2 :
Left child of 1 = 2
Right child of 1 = 3

Level 3 :
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5 :
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node (of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

The input ends when all nodes at the last level are null (-1).
Output Format :
For each test case, print ‘true’ if the given binary tree is a sum tree else, print ‘false’. The output of each test case will be printed in a separate line.
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 5
1 <= N <= 3000

Time Limit: 1sec
Sample Input 1 :
2
3 1 2 -1 -1 -1 -1
3 -1 1 2 -1 -1 -1
Sample Output 1 :
true
false
Explanation For Sample Input 1 :
For the first test case, the given tree is

For each level, we can see that the value of each node is equal to the sum of the left and the right subtree.

For the second test case, the given tree is

We can see that the sum of a subtree of a node with root 1 is not equal to the value of the node. Hence, the answer is ‘false’.
*/
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int isSumTreeVal(TreeNode<int> *root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return root->val;
    }
    int lft=isSumTreeVal(root->left);
    if(lft==-1){
        return -1;
    }
    int rgt=isSumTreeVal(root->right);
    if(rgt==-1){
        return -1;
    }
    if(lft+rgt!=root->val){
        return -1;
    }
    return root->val+lft+rgt;
}
bool isSumTree(TreeNode<int> *root)
{
    if(!root){
        return true;
    }
    return isSumTreeVal(root)>=0;
}