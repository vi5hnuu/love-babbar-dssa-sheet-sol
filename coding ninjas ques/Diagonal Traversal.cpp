/*
Problem Statement
You have been given a binary tree of integers. You have to return all the diagonal paths of the binary tree. A diagonal path is one in which all the nodes pass through -1 slope line.
A binary tree is a tree in which each parent node has at most two children.
Note:
Order of return of diagonal path’s array/vector: The rightmost diagonal path must come first, and so on.
Every parent node comes first then the child node. In other words, return the diagonal element from top to bottom.
Example
Consider the given binary tree.

There are 4 diagonal paths:
1 3 6
2 5 9
4 8
7
You need to return ‘1 3 6 2 5 9 4 8 7’.

Let's consider this example

Diagonal paths are:
1 3 6
2 5
4

You need to return ‘1 3 6 2 5 4’.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
2
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
1 2 3 -1 -1 4 5 -1 -1 -1 -1
Sample Output 1:
 1 3 7 2 5 6 4
 1 3 5 2 4
Explanation For Sample Test 1:

It is clear that '1 3 7' is the first diagonal path '2 5 6' is the second and '4' is the third diagonal path. But 5 and 6 have the same level and same diagonal path, so we need to consider a node that comes first in the pre-order traversal.
Hence the diagonal path of the above binary tree is 1 3 7 2 5 6 4.

Test case 2:

It is clear that the first diagonal path is '1 3 5', and the second is '2 4'.
Hence diagonal binary tree traversal when combined is '1 3 5 2 4'.
Sample Input 2:
2
1 -1 2 3 4 -1 -1 -1 -1
1 2 3 -1 -1 4 -1 -1 -1
Sample Output 2:
1 2 4 3
1 3 2 4

*/
#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Tree node structure.
    
    class BinaryTreeNode {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*************************************************************/
void diagonalPath(BinaryTreeNode<int>* root,map<int,vector<int>> &mp,int diagIdx) {
    if(!root){
        return;
    }
    mp[diagIdx].push_back(root->data);
    diagonalPath(root->left,mp,diagIdx+1);   
    diagonalPath(root->right,mp,diagIdx);
}
vector<int> diagonalPath(BinaryTreeNode<int>* root) {
    map<int,vector<int>> mp;
    diagonalPath(root,mp,0);
    vector<int> diagEls;
    map<int,vector<int>>::const_iterator itr=mp.cbegin();
    while(itr!=mp.cend()){
        for(int n:itr->second){
            diagEls.push_back(n);
        }
        itr++;
    }
    return diagEls;    
}