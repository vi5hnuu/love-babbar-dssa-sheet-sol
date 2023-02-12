/*
Problem Statement
Given a binary tree with ‘root’. Your task is to find the sum of all the left leaf nodes.
Properties of leaf:-
In a binary tree, a leaf is a node such that it does not have any children. Node ‘1’ is always the root of the binary tree. Left leaves are those nodes that are the left child of their parent and a leaf node.
Example:
Let’s say you have a binary tree as follows:-

Node 4 and Node 5 are leaf nodes and left child of their parent. Node 6 is a leaf node but not the left child of its parent node 3. Therefore return ‘4+5= 9’ as the answer.
Note:
You do not need to print anything; it has already been taken care of. Just implement the function.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
2
1 2 -1 3 -1 -1 -1
1 2 3 4 -1 -1 5 6 -1 -1 7 -1 -1 -1 -1
Sample Output 1:
3
6
Sample Output 1 Explanation:
Test case 1:

Node 3 is a left leaf.

Therefore the answer is 3.

Test case 2:

Node 7 is a leaf node but it is not the left child of their parent. Node 6 is a leaf node and the left child of its parent node 4.

Therefore the answer is 6.
Sample Input 2:
2
1 2 3 4 5 -1 -1 -1 -1 -1 -1
1 2 -1 -1 -1
Sample Output 2:
4
2
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
void sumOfLeftLeaves(TreeNode<int> *root,int &sum,bool pLeft){//side is left of parent or not
    if(!root){
        return;
    }
    if(!root->left && !root->right && pLeft){
        sum+=root->val;
    }
    sumOfLeftLeaves(root->left,sum,true);
    sumOfLeftLeaves(root->right,sum,false);
}
int sumOfLeftLeaves(TreeNode<int> *root){
    int sum=0;
    sumOfLeftLeaves(root,sum,false);
    return sum;
}