/*
Problem Statement
Ninja has a binary tree. He wants to find the sum of multiplication of each node of the binary tree with its mirror node. Help Ninja to find the sum.
The mirror of a node is a node that is present at the mirror position in the opposite subtree at the root. The mirror of the root node is the node itself.
The answer can be very large, so print answer modulo 1000000007.
For Example :

In this example, The mirror of 2 will be 4, the mirror of 3 will be 9 and the mirror of 7 will be 6 so the final answer is (5 * 5) + (2 * 4) + (3 * 9) + (7 * 6) = 102. 
Note :
Every Node has a mirror node in the given tree.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1 :
2
3 2 1 -1 -1 -1 -1
1 2 3 -1 4 5 -1 -1 -1 -1 -1
Sample Output 1 :
11
27
Explanation For Sample Output 1 :

For the First Test Case, the mirror of 3 is 3 itself and the mirror of 2 is 1. So the final answer will be (3 * 3) + (2 * 1) = 11.

For the second Test Case, The mirror of 2 will be 3 and the mirror of 4 will be 5. So the final answer is (1 * 1) + (2 * 3) + (4 * 5) = 27. 
Sample Input 2 :
2
5 5 5 -1 -1 -1 -1
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2 :
50
65
*/
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->data = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int mirrorMultiplication(TreeNode<int> *root) {
    queue<TreeNode<int> *> nodes;
    nodes.push(root);

    int sum=0;
    while(!nodes.empty()){
        int sz=nodes.size();
        vector<int> levelVals;
        while(sz>0){
            sz--;
            TreeNode<int> *node=nodes.front();
            nodes.pop();
            levelVals.push_back(node->data);
            if(node->left){
                nodes.push(node->left);
            }
            if(node->right){
                nodes.push(node->right);
            }
        }
        int i=0;
        int j=levelVals.size()-1;
        while(i<=j){
            sum=(sum+levelVals[i]*levelVals[j])%1000000007;
            i++;
            j--;
        }
    }
    return sum;
}