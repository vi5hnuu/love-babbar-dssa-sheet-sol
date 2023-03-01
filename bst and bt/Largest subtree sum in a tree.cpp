/*
Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

Example 1:

Input:
              1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output: 28
Explanation: 
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.

Example 2:
Input:
               1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output: 7
Explanation: 
Subtree with largest sum is : 
  -2
 /  \ 
4    5
Also, entire tree sum is also 7.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findLargestSubtreeSum() which takes the root of a binary tree and returns an integer.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 10^5
-10^3 <= tree.val <= 10^3
*/


class Solution {
private:
    int findLargestSubtreeSum(Node* root,int &mx){
        if(!root){
            return INT_MIN;
        }
        if(!root->right && !root->left){
            mx=max(mx,root->data);
            return root->data;
        }
        int lftTreeMAx=findLargestSubtreeSum(root->left,mx);
        int rgtTreeMAx=findLargestSubtreeSum(root->right,mx);
        
        if(lftTreeMAx==INT_MIN){
            mx=max(mx,(root->data+rgtTreeMAx));
            return root->data+rgtTreeMAx;
        }else if(rgtTreeMAx==INT_MIN){
            mx=max(mx,(root->data+lftTreeMAx));
            return root->data+lftTreeMAx;
        }else{
             mx=max(mx,(root->data+lftTreeMAx+rgtTreeMAx));
            return root->data+lftTreeMAx+rgtTreeMAx;
        }
    }
public:
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root){
        int mx=INT_MIN;
        findLargestSubtreeSum(root,mx);
        return mx;
    }
};