/*
Problem Statement

Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
2
1 2 4 3 -1 5 6 -1 -1 -1 -1 -1 -1 
1 2 3 4 -1 -1 -1 -1 -1
Sample Output 1:
True
False
Explanation For Sample Output 1:
In the first test case, all the leaves of the binary tree (3,5, and 6) are at the same level (level 3). So True is returned.

Diagram of the Binary Tree given in the first test case of Sample Input 1.

In the second test case, all the leaves of the binary tree (3 and 4) are not at the same level (leaf 3 is at level 2 and leaf 4 is at level 3). So False is returned.

Diagram of the Binary Tree given in the second test case of Sample Input 1.

Sample Input 2:
2
1 2 3 -1 -1 4 -1 -1 -1
1 2 -1 3 -1 4 -1 -1 -1
Sample Output 2:
False
True
*/


#include <bits/stdc++.h> 
/*
    
    Following is the Tree node structure for you referance:

    class TreeNode{
    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*/
bool CheckLeafLevel(TreeNode<int>* root,int &leafLevel,int height=0){
    if(!root){
        return true;
    }
    if(!root->left && !root->right){
        if(leafLevel==-1){
            leafLevel=height;
        }else if(leafLevel!=height){
            return false;
        }
    }

    if(!CheckLeafLevel(root->left,leafLevel,height+1)){
        return false;
    }
    return CheckLeafLevel(root->right,leafLevel,height+1);
}
bool CheckLeafLevel(TreeNode<int>* root){
    int leafLevel=-1;
    return CheckLeafLevel(root,leafLevel);
}