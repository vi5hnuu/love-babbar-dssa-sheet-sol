/*
Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact BST from it's given preorder traversal. 
In Pre-Order traversal, the root node is visited before the left child and right child nodes.

Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
Example 2:

Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104
*/


class Solution{
private:
    Node *buildBst(int *pre,int sz,int low,int high){
        if(low>high){
            return NULL;
        }
        Node *root=newNode(pre[low]);
        int nlow=low+1;
        while(nlow<sz && pre[nlow]<pre[low]){
            nlow++;
        }
        
        root->left=buildBst(pre,sz,low+1,nlow-1);
        root->right=buildBst(pre,sz,nlow,high);
        return root;
    }
public:
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size){
        return buildBst(pre,size,0,size-1);
    }
};