/*
Problem Statement
Your friends gifted you a lot of things on your birthday, and now it's your turn to give some return gifts to them. You went to a gift store and decided to buy some Binary Search Trees (BST).
There is no salesperson in the store. So you are supposed to guess the price of a given BST, which is the minimum value in its nodes.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Input Format:
The first line contains 'T', denoting the number of test cases.
For each Test :
    The first line contains an integer, 'N'.
    The second line contains an array 'A' of 'N' space-separated integers, with a positive integer representing a node and -1 representing a NULL value.

The input array 'A' denotes Level Order traversal of the BST.
(Note that 'N' is not the number of nodes in the BST,  only positive integers in 'A' denote nodes of BST).
Output Format:
For each test case, print one integer, denoting the price of a given BST, i.e., minimum node value in it.
Note:
You are not required to print the expected output. It has already been taken care of. Just implement the function.
Constraints -
1 <= 'T' <= 10
1 <= 'N' <= 10^5
1 <= A[i] <= 10^6 or A[i] = -1,  i ∈ (1, N)
Note - The sum of 'N' over all test cases does not exceed 2 * 10^5.

Time Limit: 1 sec
Sample Input 1:
2
13
5 4 6 3 -1 -1 7 1 -1 -1 -1 -1 -1
7
9 -1 10 -1 11 -1 -1
Sample Output 1
1
9
Explanation For Sample Input 1:
For Case 1:

Given input looks like the tree drawn above. It can be seen that the minimum value in the tree is 1.

For Case 2:

    Given input looks like the tree drawn above. It can be seen that the minimum value in the tree is 9.
Sample Input 2:
2
7
20 8 22 -1 -1 -1 -1
15
40 9 50 4 12 -1 -1 -1 -1 10 14 -1 -1 -1 -1
Sample Output 2:
8
4
*/
#include <bits/stdc++.h> 
/*
Structure of the Node of the BST is :

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
*/

int findPrice(Node* root)
{
    if(!root){
        return INT_MAX;
    }
    int lft=findPrice(root->left);
    int rgt=findPrice(root->right);
    return min(min(lft,rgt),root->data);
}