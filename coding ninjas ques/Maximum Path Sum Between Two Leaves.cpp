/*
You are given a non-empty binary tree where each node has a non-negative integer value. Return the maximum possible sum of path between any two leaves of the given tree.

The path is also inclusive of the leaf nodes and the maximum path sum may or may not go through the root of the given tree.

If there is only one leaf node in the tree, then return -1.

Input Format
The first line of input contains an integer 'T' representing the number of test cases. Then the test cases follow.

The only line of each test case contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 on its place.

For example, the input for the tree depicted in the below image would be :

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1
Explanation :

Level 1 :
The root node of the tree is 1

Level 2 :
Left child of 1 = 2
Right child of 1 = 3

Level 3 :
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5 :
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.
The input ends when all nodes at the last level are null(-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
For each test case, print a single integer representing the maximum path sum between two leaf nodes of the given tree.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N <= 5000
0 <= data <= 10^5

Where 'N' is the number of nodes in the tree.

Time limit: 1 sec
*/


#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long postOrder(TreeNode<int> *root,long long &mx,int &lfCount){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        lfCount++;
    }
    long long left=postOrder(root->left,mx,lfCount);
    long long right=postOrder(root->right,mx,lfCount);
    mx=max(left+right+root->val,mx);
    return root->val+max(left,right);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    long long mx=INT_MIN;
    int lfCount=0;
    // cout<<"lfcount "<<lfCount;
    postOrder(root,mx,lfCount);
    return (lfCount==1 || mx==INT_MIN ? -1 : mx);
}