/*
Given a binary tree, find its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:

Input:
            1
          /   \
         3     2
        /
       4           

Output: 3
Explanation:
Maximum depth is between nodes 1 and 4 since
maximum depth is defined as  the number of
nodes along the shortest path from the root
node down to the farthest leaf node.

Example 2:

Input:
             10
          /     \
        20       30
          \        \  
          40        60
                   /
                  2 

Output: 4

Explanation:
Maximum depth is between nodes 10 and 2 . 
Hence the path length from 10 to 2 is 4.
 


Your Task:  
You don't need to read input or print anything. Complete the function maxDepth() which takes the root node as an input parameter and returns the maximum depth.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of the tree)
 

Constraints:
1 ≤ N ≤ 10^5
*/


/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        if(!root){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};