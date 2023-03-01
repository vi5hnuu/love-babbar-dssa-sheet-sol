/*
Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List starting from the left most leaf. Modify the original tree to make the DLL thus removing the leaf nodes from the tree. Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Note: The generated output will contain the inorder traversal of the modified tree, the DLL from left to right and the DLL from right to left.

Example 1:

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7

Explanation:
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.
Example 2:

Input :
        1
      /   \
     2     3
    / \   
   4   5 

Output: 
Modified Tree :
        1
      /   
     2    

Doubly Link List :
4 <-> 5 <-> 3

Your Task:  
You don't need to read input or print anything. Complete the function convertToDLL() which takes the root of the given tree as input parameter and returns the head of the doubly link list.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 10^4
*/


/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
// return the head of the DLL and remove those node from the tree as well.
void convertToDLL(Node *root,Node *par,Node *&head,Node *&tail){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        if(!head){
            head=tail=root;
        }else{
            tail->right=root;
            root->left=tail;
            tail=root;
        }
        if(par){
            if(par->left==root){
                par->left=NULL;
            }else{
                par->right=NULL;
            }
        }
        return;
    }
    convertToDLL(root->left,root,head,tail);
    convertToDLL(root->right,root,head,tail);
}
Node *convertToDLL(Node *root){
    Node *head=NULL,*tail=NULL;
    convertToDLL(root,NULL,head,tail);
    return head;
}