/*
Given a Binary Tree of N nodes. Find the vertical width of the tree.

Example 1:

Input:
          1
       /    \
      2      3
     / \    / \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.



The above tree contains 6 vertical lines.
 

Example 2:

Input:
      1
    /  \
   2    3
Output: 3
 

Your Task:

You don't have to read input or print anything. Your task is to complete the function verticalWidth() which takes root as the only parameter, and returns the vertical width of the binary tree.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

 

Constraints:
0 <= Number of nodes <= 105
*/


void verticalWidth(Node *root,int &mn,int &mx,int inum){
    if(!root){
        return;
    }
    mn=min(mn,inum);
    mx=max(mx,inum);
    verticalWidth(root->left,mn,mx,inum-1);
    verticalWidth(root->right,mn,mx,inum+1);
}
int verticalWidth(Node* root)
{
    if(!root){
        return 0;
    }
    int mn=INT_MAX;
    int mx=INT_MIN;
    verticalWidth(root,mn,mx,0);
    return mx-mn+1;
}