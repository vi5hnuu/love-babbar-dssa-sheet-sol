/*
Problem Statement
Given a binary tree, convert this binary tree into its mirror tree.
A binary tree is a tree in which each parent node has at most two children.
Mirror of a Tree: Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.

Note:
1. Make in-place changes, that is, modify the nodes given a binary tree to get the required mirror tree.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
2
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 
1 3 2 -1 -1 5 4 -1 -1
Sample Output 1:
1 3 2 7 6 5 4 -1 -1 -1 -1 -1 -1 -1 -1 
1 2 3 4 5 -1 -1 -1 -1 -1 -1
Explanation To Sample Input 1:

In a mirror, objects on the left appear to be on the right, and objects on the right appear to be on the left.

Similarly, in the above figure, 

At level 1: Since only the node with value 1 is present, it stays as at root in the mirror tree as well.

At level 2: Subtree with root 2 appears on the left and the subtree with root 3 appears on the right in the actual tree, their positions are swapped in the mirror tree. Now, subtree with root 3 comes on the left and subtree with root 2 on the right.

At level 3: Nodes 6 and 7 change positions and nodes 4 and 5 also change their positions.
Sample Input 2:
1
10 12 6 -1 -1 15 4
Sample Output 2:
10 6 12 4 15 -1 -1 -1 -1 -1 -1
*/
#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void mirrorTree(BinaryTreeNode<int> *root) {
    if(!root){
        return;
    }
    BinaryTreeNode<int> *rgt=root->right;
    root->right=root->left;
    root->left=rgt;
    mirrorTree(root->left);
    mirrorTree(root->right);
}