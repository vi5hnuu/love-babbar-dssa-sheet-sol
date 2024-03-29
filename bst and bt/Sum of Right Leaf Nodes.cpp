/*
Given a Binary Tree of size N, your task is to complete the function rightLeafSum(), which should return the sum of all the leaf nodes that are the right child of their parent of the given binary tree.
Example 1:

Input :
         52
        /    \
      12      55
     /  \     /  \
    83   6   17  82
   /    /  \   
  56   61  35
Output :
117
Explanation:
All the right leaf nodes
presents are 35, 82 which
sums up to 117
Example 2:

Input:
         12
        /  \    
     20     30
    /  \     /
  40   60  90

Output:
60

Explanation:
The only right leaf node is present is 60
Constraints:
1<=T<=100
1<=N<=100

Your task :

You don't have to read input or print anything. Your task is to complete the function rightLeafSum() that takes the root of the tree as input and return the sum of all 
the right leaf node of the input tree.
*/


/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// right leaf nodes
class Solution{
private:
    int rightLeafSum(Node *root,bool toLeftOfPar){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right && !toLeftOfPar){
            return root->data;
        }
        return rightLeafSum(root->left,true)+rightLeafSum(root->right,false);
    }
public:
    int rightLeafSum(Node* root){
        return rightLeafSum(root,true);
    }
};