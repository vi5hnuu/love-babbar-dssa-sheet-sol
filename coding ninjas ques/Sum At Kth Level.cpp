/*
Problem Statement
You are given a ‘root’ of the binary tree, and you have to return the sum of all nodes present at the Kth level from the top. The root node is considered as level 1, and below it is level 2, and so on.
Note:
A binary tree is a tree in which each node has at most 2 children.
Example:
For Example, the root node is given as follows :
‘ROOT’ = 1 2 3 4 -1 -1 5 -1 -1 -1 -1 and ‘K’ = 2, Then the sum of all nodes at K-level will be 5. This is because 2 and 3 are present at level 2 and 2 + 3 = 5. Therefore 5 is the answer.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Input Format:
The first line of input contains a single integer ‘T’, representing the number of test cases or queries to be run. 

The first line of each test case contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

The second line of each test case contains a single integer ‘K’, which denotes the level.
Constraints:
1 <= ‘T’ <= 10
1 <= ‘N’ <= 1000
0 <= data <= 10^3
0 <= ‘K’ <= ‘N’

Time Limit: 1 sec.
Output Format :
For every test case, print a single line that contains a single integer which denotes the sum of all nodes at the Kth level.

The output of each test case is printed in a separate line.
Note:
You don’t have to print anything, it has already been taken care of. Just implement the function. 
Sample Input 1:
2
1 2 3 4 -1 -1 5 -1 -1 -1 -1
2
1 2 3 4 -1 -1 5 -1 -1 -1 -1
3
Sample Output 1:
5
9
Explanation of the Sample Input 1:
For the first test case, the nodes at level 2 are 2 and 3; therefore, their sum will be our answer. 2 + 3 = 5. Therefore the final answer is 5.

For the second test case, the nodes at level 3 are 4 and 5; therefore, their sum will be our answer. 4 + 5 = 9. Therefore the final answer is 9.
Sample Input 2:
2
9 10 11 -1 -1 -1 -1 
1
9 10 11 -1 -1 -1 -1
2
Sample Output 2:
9
21
*/


#include <bits/stdc++.h> 
/**********************************************************************

Following is the Binary Tree node structure already written:

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

**********************************************************************/

int sumAtKthLevel(BinaryTreeNode<int>* root, int k){
    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);

    int level=1;
    while(!nodes.empty()){
        int sz=nodes.size();
        int sum=0;
        while(sz>0){
            sz--;
            BinaryTreeNode<int> *node=nodes.front();
            nodes.pop();
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                nodes.push(node->left);
            }
            if(node->right){
                nodes.push(node->right);
            }
        }
        if(level==k){
            return sum;
        }
        level++;
    }
    return 0;
}