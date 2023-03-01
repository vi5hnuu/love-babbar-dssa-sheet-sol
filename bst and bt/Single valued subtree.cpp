/*
Given a binary tree, count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value. 

Example 1

Input :
              5
             / \
            1   5
           / \   \
          5   5   5
Output : 4
Explanation : 
There are 4 subtrees with single values. Three leaf nodes and the subtree whose root is the right child of the root. 
Example 2:

Input:
              5
             / \
            4   5
           / \   \
          4   4   5   
Output: 5
Explanation: 
There are five subtrees with single values.
Your task :
You don't have to read input or print anything. Your task is to complete the function singlevalued() which takes the root of the tree as input and returns the count of single valued subtrees.
 
Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n)
 
Constraints :
1 <= n <= 10^5
*/


/* Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution{//-vs means no more single value subtree up the tree
private:
    int sngVal(Node *root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        int lft=sngVal(root->left);
        int rgt=sngVal(root->right);
        if((lft<0 || rgt<0)|| (root->left && root->left->data!=root->data) || (root->right && root->right->data!=root->data)){
            //lft<0 -> single value property failed to left
            //rgt<0 -> single value property failed to right
            //e g -2 from right and 3 from left means
            /*
            2 single value tree in left exist
            3 on right
            return -(abs(-2)+3) -> -5 total 5 single val tree [as left is -ve curr node cannot make single value tree]
            */
            return -(abs(lft)+abs(rgt));
        }
        return 1+lft+rgt;
    }
public:
    int singlevalued(Node *root){
        return abs(sngVal(root));
    }
    
};