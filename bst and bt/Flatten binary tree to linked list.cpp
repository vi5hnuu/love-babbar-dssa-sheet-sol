/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
Example 2:

Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5  
Explanation : 
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.
Your task:
You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linkes list without using any auxiliary space.
Note : The driver code prints the inorder traversal of the flattened binary tree.
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
 
Constraints :
1<=n<=10^5
*/




/*
class Solution {
 private:
    TreeNode* rightMost(TreeNode* root) {
        if(!root)
            return NULL;
        while(root->right){
            root=root->right;
        }
        return root;
    }
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode *temp=root;
        while(temp){
            if(temp->left){
                TreeNode *ltree=temp->left;
                TreeNode *rtree=temp->right;
                temp->left=NULL;
                TreeNode *rmost=rightMost(ltree);
                temp->right=ltree;
                rmost->right=rtree;
            }else{
                temp=temp->right;
            }
        }
    }
};
*/


class Solution
{
    private:
    Node* postorder(Node *root){
        if(!root)
            return NULL;
        
        postorder(root->left);
        postorder(root->right);
        Node *temp=root->right;
        root->right=root->left;
        if(root->right){
            Node *x=root->right;
            while(x->right){
                x=x->right;
            }
            x->right=temp;
        }else{
            root->right=temp;
        }
        root->left=NULL;
        return root;
    }
    public:
    void flatten(Node *root)
    {
        postorder(root);
    }
};