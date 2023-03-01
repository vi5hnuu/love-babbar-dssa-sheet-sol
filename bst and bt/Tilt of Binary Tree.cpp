/*
Given a binary tree of size N+1, your task is to complete the function tiltTree(), that return the tilt of the whole tree. The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null nodes are assigned tilt to be zero. Therefore, tilt of the whole tree is defined as the sum of all nodes’ tilt.

Examples 1:

Input: 
       1
      / \
     2   3
Output: 1
Explanation:
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Example 2:

Input:
        4 
       / \
      2   9 
     / \   \
    3   5   7 
Output: 15 
Explanation:
Tilt of node 3 : 0 
Tilt of node 5 : 0 
Tilt of node 7 : 0
Tilt of node 2 : |3-5| = 2 
Tilt of node 9 : |0-7| = 7 
Tilt of node 4 : |(3+5+2)-(9+7)| = 6 
Tilt of binary tree : 0 + 0 + 0 + 2 + 7 + 6 = 15
Your Task:
You don't need to read input or print anything. Your task is to complete the function tiltTree() which takes root node of the tree as input parameter and returns an integer denoting the tilt of the tree. If the tree is empty, return 0. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Constraints:
1<=T<=100
0<=N<=500
*/


/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution{
private:
    int tiltTree(Node *root,int &tilt){
        if(!root){
            return 0;
        }
        int val=root->data;
        int lft=tiltTree(root->left,tilt);
        int rgt=tiltTree(root->right,tilt);
        root->data=abs(lft-rgt);
        tilt+=root->data;
        return val+lft+rgt;
    }
public:
    // Your are required to complete this function
    // function should return the tilt of the tree
    int tiltTree(Node *root){
        int tilt=0;
        tiltTree(root,tilt);
        return tilt;
    }
};