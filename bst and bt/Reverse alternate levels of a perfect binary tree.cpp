/*
Given a complete binary tree, reverse the nodes present at alternate levels.

Example 1:

Input:
             1
          /   \
        3      2

Output:

             1
          /   \
        2      3

Explanation: Nodes at level 2 are reversed.
Example 2:

Input:
              1
          /      \
         2        3
       /  \      /  \
     42   51   63   72

Output:
             1
          /      \
         3        2
       /  \      /  \
     42   51   63   72

Explanation:
Nodes at level 2 are reversed.
Level 1 and 3 remain as it is.

Your Task:  
You dont need to read input or print anything. Complete the function reverseAlternate() which takes root node as input parameter and modifies the given tree in-place.

Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^4
*/


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


void reverseAlternate(Node *rootA,Node *rootB,int lvl){
    if(!rootA && !rootB){
        return;
    }
    if(lvl&1){
        swap(rootA->data,rootB->data);
    }
    reverseAlternate(rootA->left,rootB->right,lvl+1);
    reverseAlternate(rootA->right,rootB->left,lvl+1);
}
void reverseAlternate(Node *root){
    if(!root){
        return;
    }
    reverseAlternate(root->left,root->right,1);
}