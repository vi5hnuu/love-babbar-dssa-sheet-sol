/*
Given a binary tree, find the depth of the deepest odd level leaf node in a binary tree. If there is no leaf at odd level then return 0.
Consider that level starts with 1. Depth of a leaf node is number of nodes on the path from root to leaf (including both leaf and root).

Example 1:

Input: 
          1
        /    \
       2      3
      / \    / \
     4   5  6   7
Output: 3
Explanation: In the above tree 4,5,6 and 7 are
odd level leaf nodes at depth 3.So the answer is 3.
Example 2:

Input: 
     1
    / \
    2   4
Output: 0
Your task:

You don't need to read input or print anything. Your task is to complete the function depthOfOddLeaf() which takes root node of the tree as input parameter and returns an integer denoting the maximum depth of a odd level leaf node of the tree. If there is no such leaf node return 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<=T<=1000
1<=n<=1000
1<=data of node<=1000
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
    int depthOfOddLeaf(Node *root,int lvl){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right && lvl&1){
            return lvl;
        }
        return max(depthOfOddLeaf(root->left,lvl+1),depthOfOddLeaf(root->right,lvl+1));
    }
public:
    int depthOfOddLeaf(Node *root){
        return depthOfOddLeaf(root,1);
    }
};