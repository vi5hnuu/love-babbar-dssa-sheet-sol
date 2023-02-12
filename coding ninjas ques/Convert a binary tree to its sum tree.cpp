/*
Problem Statement
Given a binary tree of integers, you are supposed to modify the given binary tree to a sum tree where each node value is replaced by the sum of the values of both left and right subtrees in the given tree. The value of leaf nodes is changed to zero.
Example:
Below is the example showing the input tree and its sum tree.  

Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1 :
2
1 -2 1 3 1 -1 -1 -1 -1 -1 -1 
5 -1 1 -8 4 6 -1 -1 -1 -1 -1 
Sample Output 1 :
3 4 0 0 0 -1 -1 -1 -1 -1 -1 
3 -1 2 6 0 0 -1 -1 -1 -1 -1 
Explanation Of Sample Output 1 :
In test case 1, 

The level order traversal of the modified tree will be {3, 4, 0, 0, 0, -1, -1, -1, -1, -1, -1} where -1 denotes the null nodes.

In test case 2,  the level order traversal of the modified tree will be {3, -1, 2, 6, 0, 0, -1, -1, -1, -1, -1} where -1 denotes the null nodes.
Sample Input 2 :
2
1 2 3 -1 4 5 -1 -1 -1 -1 -1
2 1 3 4 -1 -1 5 -1 -1 -1 -1 
Sample Output 2 :
14 4 5 -1 0 0 -1 -1 -1 -1 -1 
13 4 5 0 -1 -1 0 -1 -1 -1 -1 
Explanation Of Sample Output 2 :
In test case 1, the level order traversal of the modified tree will be {14, 4, 5, -1, 0, 0, -1, -1, -1, -1, -1} where -1 denotes the null nodes. 

In test case 2,  the level order traversal of the modified tree will be {13, 4, 5, 0, -1, -1, 0, -1, -1, -1, -1} where -1 denotes the null nodes.
*/


/************************************************************

    Following is the Binary Tree node class:
        
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
    };

************************************************************/
int modify2SumTree(TreeNode<int> *root) {
    if(!root){
        return 0;
    }
    //replace and return old value
    int oldleft=modify2SumTree(root->left);
    int oldright=modify2SumTree(root->right);
    int curVal=root->data;
    root->data=oldleft+oldright;
    return curVal+oldleft+oldright;
}
TreeNode<int>* convertToSumTree(TreeNode<int> *root) {
    modify2SumTree(root);
    return root;
}