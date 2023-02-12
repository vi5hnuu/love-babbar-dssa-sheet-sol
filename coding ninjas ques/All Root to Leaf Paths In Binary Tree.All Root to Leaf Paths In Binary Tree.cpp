/*
You are given an arbitrary binary tree consisting of 'N' nodes numbered from 1 to 'N'. Your task is to print all the root to leaf paths of the binary tree.

A leaf of a binary tree is the node which does not have a left child and a right child.

For Example :
Given a binary tree :

All the root to leaf paths are :
1 2 4
1 2 5 
1 3
Note :

1. Two nodes may have the same value associated with it.
2. The root node will be fixed and will be provided in the function.
3. Note that the nodes in a path will appear in a fixed order. For example, 1 2 3 is not the same as 2 1 3.
4. Each path should be returned as a string consisting of nodes in order and separated by a space.
5. The path length may be as small as ‘1’.
Input Format :
The first line of the input contains a single integer 'T', representing the number of test cases.

The first line of each test case contains an integer 'N', which denotes the number of nodes in the tree.

The second line of each test case will contain the values of the nodes of the tree in the level order form ( -1 for 'NULL' node) Refer to the example for further clarification.
Example :
Consider the binary tree

The input of the tree depicted in the image above will be like : 

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
For each test case, print all the root to leaf path nodes.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10^2
1 <= N <= 3*10^3

Time Limit : 1 sec
*/

#include <bits/stdc++.h> 
/********************************************************************

    Following is the Binary Tree node structure:

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
    };
    
********************************************************************/
void allRootToLeaf(BinaryTreeNode < int > * root,vector<string> &paths,string path=""){
    if(!root){
        return;
    }
    path=path+to_string(root->data)+" ";
    if(!root->left && !root->right){
        paths.push_back(path);
    }
    allRootToLeaf(root->left,paths,path);
    allRootToLeaf(root->right,paths,path);
}
vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
   vector < string > paths;
   allRootToLeaf(root,paths);
   return paths;
}