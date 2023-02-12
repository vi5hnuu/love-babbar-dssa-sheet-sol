/*
Problem Statement
You have been given a Binary Tree of integers. You are supposed to return the largest subtree sum in the given Binary Tree.
The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
Example :
For the given binary tree:

Subtree with the largest sum is highlighted in the above image. The sum is (-2 + 4 + 7) = 9
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Input Format :
The first line contains an integer 'T' which denotes the number of test cases. 

The first line of each test case contains elements of the tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.
Example:
The input for the tree depicted in the below image would be :

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

Explanation:
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

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1
Note:
1. The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

2. The input ends when all nodes at the last level are null(-1).
Output Format:
For each test case, return an integer which denotes the largest subtree sum in the given binary tree.
Note :
You don't need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 50
0 <= N <= 10000
-10^3 <= data <= 10^3 and data != -1

Where ‘N’ is the total number of nodes in the binary tree, and 'data' is the value of the binary tree node.

Time limit: 1 sec
Sample Input 1 :
2
1 -2 3 4 7 -9 2 -1 -1 -1 -1 -1 -1 -1 -1
1 2 3 -1 -1 -1 -1
Sample Output 1 :
9
6
Explanation Of Sample Input 1 :
 In test case 1,

Subtree with the largest sum is highlighted in the above image. The sum is (-2 + 4 + 7) = 9

In test case 2, the subtree with the largest sum is the tree itself. The sum is (1 + 2 + 3) = 6.
Sample Input 2:
2
-2 -4 1 -5 -1 -1 -1 -1 -1
-10 8 11 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
1
11
Explanation Of Sample Output 2:
In test case 1, the largest subtree sum will be formed by just selecting the node with value 1 and thus the largst subtree sum is 1.

In test case 2, the largest subtree sum will be formed by just selecting the node with value 11 and thus the largst subtree sum is 11.

*/
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// long long largestSubtreeSum(TreeNode<int> *root,int &mx) {
//     if(!root->left && !root->right){
//         mx=max(mx,root->data);
//         return root->data;
//     }
//     if(root->left && root->right){
//         int lft=largestSubtreeSum(root->left,mx);
//         int rgt=largestSubtreeSum(root->right,mx);
//         int cSum=lft+rgt+root->data;
//         mx=max(mx,max(max(lft,rgt),cSum));
//         return cSum;
//     }else if(root->left){
//         int lft=largestSubtreeSum(root->left,mx);
//         mx=max(mx,max(lft,lft+root->data));
//         return lft+root->data;
//     }else{
//         int rgt=largestSubtreeSum(root->right,mx);
//         mx=max(mx,max(rgt,rgt+root->data));
//         return rgt+root->data;
//     }
// }

// int largestSubtreeSum(TreeNode<int> *root) {
//     if(!root){
//         return -1;    
//     }
// 	int mx=INT_MIN;
//     largestSubtreeSum(root,mx);
//     return mx;
// }
/////////////////////////////////
int getMax(initializer_list<int> nums){
    int mx=INT_MIN;
    for(int n:nums){
        mx=max(mx,n);
    }
    return mx;
}
long long largestSubtreeSum(TreeNode<int> *root,int &mx) {
    if(!root){//-1 out of input range
        return -1;    
    }
    if(!root->left && !root->right){
        mx=max(mx,root->data);
        return root->data;
    }
    int lft=largestSubtreeSum(root->left,mx);
    int rgt=largestSubtreeSum(root->right,mx);
    if(lft!=-1 && rgt!=-1){
        mx=getMax({mx,lft,rgt,lft+rgt+root->data});
        return lft+rgt+root->data;
    }else if(rgt!=-1){
        mx=getMax({mx,rgt,rgt+root->data});
        return rgt+root->data;
    }else{
        mx=getMax({mx,lft,lft+root->data});
        return lft+root->data;
    }
}

int largestSubtreeSum(TreeNode<int> *root) {
    
	int mx=INT_MIN;
    largestSubtreeSum(root,mx);
    return mx;
}