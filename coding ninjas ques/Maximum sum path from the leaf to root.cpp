/*
You are given a binary tree of 'N' nodes.

Your task is to find the path from the leaf node to the root node which has the maximum path sum among all the root to leaf paths.

For Example:


All the possible root to leaf paths are:
3, 4, -2, 4 with sum 9
5, 3, 4 with sum 12
6, 3, 4 with sum 13
Here, the maximum sum is 13. Thus, the output path will be 6, 3, 4.
Note:
There will be only 1 path with max sum.
Input Format:
The very first line of input contains an integer 'T' denoting the number of queries or test cases. 

The first and only line of every test case contains elements of the binary tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take 0 in its place.

For example, the level order input for the tree depicted in the above image would be :

4
-2 3
4 0 5 6
0 3 0 0 0 0
0 0
Explanation :

Level 1 :
The root node of the tree is 4

Level 2 :
Left child of 4 = -2
Right child of 4 = 3

Level 3 :
Left child of -2 = 4
Right child of -2 = null (0)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (0)
Right child of 4 = 3
Left child of 5 = null (0)
Right child of 5 = null (0)
Left child of 6 = null (0)
Right child of 6 = null (0)

Level 5 :
Left child of 3 = null (0)
Right child of 3 = null (0)
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

4 -2 3 4 0 5 6 0 7 0 0 0 0 0 0
Output Format:
For each test case, print integers representing the path from the leaf node to the root node which has the maximum sum separated by spaces in a single line. 
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Constraints:
1 <= T <= 100
1 <= N <= 3000
-10 ^ 5 <= DATA <= 10 ^ 5, DATA != 0

where 'T' is the number of test cases, 'N' is the number of nodes in the tree and 'DATA' is the value of each node.

Time limit: 1 sec
*/


#include <bits/stdc++.h> 
/***********************************

    Following is the BinaryTreeNode class structure
    
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

    };
***********************************/
void maxSumPath(BinaryTreeNode<int> *root,vector<int> &path,vector<int> &temp,int &mx,int sum=0){
    if(!root){
        return;
    }
    sum+=root->data;
    temp.push_back(root->data);
    if(!root->left && !root->right){
        if(sum>mx){
            mx=sum;
            path=temp;
        }
    }
    maxSumPath(root->left,path,temp,mx,sum);
    maxSumPath(root->right,path,temp,mx,sum);
    temp.pop_back();
}
vector<int> maxSum(BinaryTreeNode<int> *root){
    vector<int> path;    
    vector<int> temp;
    int mx=INT_MIN;
    maxSumPath(root,path,temp,mx);
    int i=0,j=path.size()-1;
    while(i<j){
        swap(path[i],path[j]);
        i++;
        j--;
    }
    return path;
}