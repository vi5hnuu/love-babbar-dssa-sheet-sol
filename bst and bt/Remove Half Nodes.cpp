/*
Given A binary Tree. Your task is to remove all the half nodes (which has only one child).

Example 1:

Input:
         7
       /   \
      7     8
     / 
    2
Output: 2 7 8 
Example 2:

Input:
         2
       /   \
      7     5
       \      \
        9      1
       /  \
      11   4
Output: 11 9 4 2 1 
Your Task:
You don't need to read input or print anything. Your task is to complete the function RemoveHalfNodes() which takes the root node of the tree as input and returns the root node of the modified tree after removing all the half nodes, ie the ones having just a single child node. (The inorder traversal of the returned tree is printed by the driver's code.)
For example consider the below tree.


Nodes 7, 5 and 9 are half nodes as one of their child is Null. We need to remove all such half nodes and return the root pointer of following new tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Binary Tree).

Constraints:
1<=Number of nodes<=104

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified tree after removing all the half nodes.
Node* RemoveHalfNodes(Node *root,Node *par){
    if(!root){
        return NULL;
    }
    if((!root->left && root->right) || (root->left && !root->right)){
        if(!par){
            return NULL;
        }
        if(!root->left){
            if(par->left==root){
                par->left=root->right;
            }else{
                par->right=root->right;
            }
        }else{
            if(par->left==root){
                par->left=root->left;
            }else{
                par->right=root->left;
            }
        }
        root=par;//new root
        //no need of par to set prev par or NULL because we have no child or both child after this operation
    }
    RemoveHalfNodes(root->left,root);//return ifnored
    RemoveHalfNodes(root->right,root);//return ignored
    return root;
}
Node *RemoveHalfNodes(Node *root){
    return RemoveHalfNodes(root,NULL);
}