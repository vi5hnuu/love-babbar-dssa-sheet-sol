/*
Problem Statement
You are given an N-ary tree where every node has at most ‘N’ child nodes. You need to find the level order traversal of this tree
Note:
Note that the level order traversal must not contain any null values, simply return the tree in level order.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
1
1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 
Sample Output 1:
1 2 3 4 5 6
Explanation Of Sample Input 1:
In the first test case, 
Given tree:

The level order traversal of the above tree is: 1 2 3 4 5 6 
Sample Input 2:
2
1 2 3 4 5 -1 6 7 8 -1 9 -1 -1 -1 -1 -1 -1 -1
1 2 -1 -1
Sample Output 2:
1 2 3 4 5 6 7 8 9
1 2
Explanation Of Sample Input 2:
In the first test case, 
Given tree:

The level order traversal of the above tree is: 1 2 3 4 5 6 7 8 9

In the second test case, 
Given tree:

The level order traversal of the above tree is: 1 2

*/
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *child;
        vector<TreeNode<T> *> child;
	    TreeNode(T data)
	    {
		    this->data = data;
		    child = new vector<TreeNode<T> *>;
	    }
    };

************************************************************/

vector<int> levelOrder(TreeNode<int> *root)
{
    vector<int> level;
    queue<TreeNode<int> *> nodes;
    nodes.push(root);

    while(!nodes.empty()){
        TreeNode<int> *node=nodes.front();
        nodes.pop();
        level.push_back(node->data);
        for(auto cld:node->child){
            nodes.push(cld);
        }
    }
    return level;
}
