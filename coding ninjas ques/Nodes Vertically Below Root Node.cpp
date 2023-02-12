/*
Problem Statement
King Greg’s kingdom is divided like a binary tree such that the capital of the empire was in the North, and all the remaining cities are below the capital city. One day King Greg wanted to know all the cities which are in the South(Vertically below) of the capital city, But Greg is too busy managing his kingdom, so you have to help Greg find all the cities vertically below the capital city.
If there is no node vertically below the root node, return -1.
For Example :

In this tree, cities 5 and 6 are directly below the capital city; hence, the answer is 5, 6.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1 :
2
1 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1
11 5 8 -1 -1 -1 -1
Sample Output 1 :
5
-1
Explanation For Sample Output 1 :

In the first test case, Node 5 is the only node vertically below the root node; hence the answer is 5, 6.

In the second test case, No node is directly below the root node; hence we return -1.
Sample Input 2 :
2
5 6 10 2 3 5 9  -1 -1 -1 -1 -1 -1 -1 -1
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2 :
3 5
5 6
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
void verticallyBelowNodes(TreeNode<int> *root,vector<int> &belowRoot,int idx) {
    if(!root){
        return;
    }
    if(idx==0){
        belowRoot.push_back(root->data);
    }
    verticallyBelowNodes(root->left,belowRoot,idx-1);
    verticallyBelowNodes(root->right,belowRoot,idx+1);
}
vector<int> verticallyBelowNodes(TreeNode<int> *root) {
    vector<int> belowRoot;
    verticallyBelowNodes(root->left,belowRoot,-1);//left
    verticallyBelowNodes(root->right,belowRoot,1);//right
    return belowRoot.size()==0 ? vector<int>{-1} : belowRoot;
}