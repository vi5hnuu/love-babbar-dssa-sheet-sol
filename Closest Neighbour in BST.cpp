/*
Given a binary search tree and a number N, find the greatest number in the binary search tree that is less than or equal to N. 



Example 1 :

Input : N = 24
Output : 21
Explanation : The greatest element in the tree which 
              is less than or equal to 24, is 21. 
              (Searching will be like 5->12->21)
 

Example 2 :

Input : N = 4
Output : 3
Explanation : The greatest element in the tree which 
              is less than or equal to 4, is 3. 
              (Searching will be like 5->2->3)

Your task :

You don't need to read input or print anything. Your task is to complete the function findMaxForN() which takes the root of the BST, and the integer N as input paramters and returns the greatest element less than or equal to N in the given BST.

 

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1<=N<=103
*/


/*
Structure of the Node of the BST is as
struct Node {
	int key;
	Node* left, *right;
};
*/
/*
   'N' is the element 
   'size' is the total element in BST
  */
int findMaxForN(Node* root, int N)
{
    if(!root){
        return -1;
    }
    if(root->key>N){
        return findMaxForN(root->left,N);
    }else{
        int val=findMaxForN(root->right,N);
        if(root->key>val && root->key<=N){
            return root->key;
        }
        return val;
    }
}