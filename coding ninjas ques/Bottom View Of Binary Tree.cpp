/*
Given a binary tree, print its bottom view from left to right. Assume, the left and the right child make a 45-degree angle with the parent.

A binary tree is a tree in which each parent node has at most two children.

A node will be in the bottom-view if it is the bottom-most node at its horizontal distance from the root.

Note :
1. The horizontal distance of the root from itself is 0. The horizontal distance of the right child of the root node is 1 and the horizontal distance of the left child of the root node is -1. 

2. The horizontal distance of node 'n' from root = horizontal distance of its parent from root + 1, if node 'n' is the right child of its parent.

3. The horizontal distance of node 'n' from root = horizontal distance of its parent from the root - 1, if node 'n' is the left child of its parent.

4. If more than one node is at the same horizontal distance and is the bottom-most node for that horizontal distance, including the one which is more towards the right.

5. You are not required to print the output explicitly, it has already been taken care of. Just implement the function and return the answer, which is the sequence of nodes from left to right in the bottom view.
For example, for the given Binary Tree 

Below is the bottom view of the binary tree.

1 is the root node, so its horizontal distance = 0.
Since 2 lies to the left of 0, its horizontal distance = 0-1= -1
3 lies to the right of 0, its horizontal distance = 0+1 = 1
Similarly, horizontal distance of 4 = Horizontal distance of 2 - 1= -1-1=-2
Horizontal distance of 5 = Horizontal distance of 2 + 1=  -1+1 = 0
Horizontal distance of 6 = 1-1 =0
Horizontal distance of 7 = 1+1 = 2

The bottom-most node at a horizontal distance of -2 is 4.
The bottom-most node at a horizontal distance of -1 is 2.
The bottom-most node at a horizontal distance of 0 is 5 and 6. However, 6 is more towards the right, so 6 is included.
The bottom-most node at a horizontal distance of 1 is 3.
The bottom-most node at a horizontal distance of 2 is 7.

Hence, the bottom view would be 4 2 6 3 7
Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next ‘T’ lines represent the ‘T’ test cases.

The first line of input contains the elements of the tree in the level order form separated by a single space.
If any node does not have a left or right child, take -1 in its place. Refer to the example below.
Example :

Elements are in the level order form. The input consists of values of nodes separated by a single space in a single line. In case a node is null, we take -1 in its place.

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

The first not-null node (of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

The input ends when all nodes at the last level are null (-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 

The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format :
For each test case, the bottom view of the binary tree will be printed on a separate line with all the nodes included in the bottom view separated by a single space.
Constraints :
1 <= T <= 100
1 <= N <= 3000
-10^9 <= DATA <= 10^9

 Time Limit: 1 sec
*/


#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
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

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> *root) {
  if (!root) {
    return {};
  }
    
    map<int,int> roof; // x coordinate -> vertical elements

    //vertical order traversal -> we push roof only
    queue<pair<BinaryTreeNode<int>*,int>> nodes;
    nodes.push({root,0});
    while (!nodes.empty()) {
        int sz=nodes.size();
        while (sz > 0) {
            sz--;
            auto data=nodes.front();
            nodes.pop();
            BinaryTreeNode<int> *node=data.first;
            int xCord=data.second;
            
            roof[xCord]=node->data;
            if(node->left){
                nodes.push({node->left,xCord-1});
            }
            if (node->right) {
                nodes.push({node->right,xCord+1});
            }
        }
    }
    map<int,int>::iterator itr=roof.begin();
    vector<int> topView;
    while (itr != roof.end()) {
        topView.push_back(itr->second);
        itr++;
    }
    return topView;
}
