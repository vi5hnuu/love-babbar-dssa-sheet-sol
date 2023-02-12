/*
Problem Statement
You have been given a Binary Tree of 'N' nodes. Your task is to find and return the deepest right leaf node. In case of multiple answers, return the rightmost node.
For Example:
For the given binary tree: 

Output: 9

Explanation: The deepest right nodes are 3 and 9 but 9 is the rightmost, thus 9 is the answer.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
1 2 3 -1 -1 -1 -1
Sample Output 1:
3
Explanation To Sample Output 1:
The input binary tree will be represented as:

From the above representation, the leaves node are 2 and 3. But 3 is the right child of its parent but 2 is the left child of its parent. Thus, 3 should be the answer.
Sample Input 2:
1 2 3 -1 4 4 -1 -1 5 6 -1 -1 -1 -1 -1
Sample Output 2:
5
Explanation To Sample Output 2:
The input binary tree will be represented as: 

From the above representation, the leaves node are 5 and 6. But 5 is the right child of its parent but 6 is the left child of its parent. Thus, 5 should be the answer.
*/
#include <bits/stdc++.h> 
/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
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

***********************************************************/
/*
1 2 3 -1 4 5 6 7 8 -1 -1 9 -1 -1 -1 -1 -1 -1 -1 => 8
1 -1 -1 => -1
1 2 3 4 -1 5 -1 -1 -1 6 -1 -1 -1 => -1
*/
BinaryTreeNode<int>* deepestRightLeaf(BinaryTreeNode<int>* root) {
	if(!root){
		return NULL;
	}
    queue<BinaryTreeNode<int>*> nodes;
	nodes.push(root);

	BinaryTreeNode<int> *rmdLeaf=NULL;
	while(!nodes.empty()){
		int sz=nodes.size();

		bool foundInThisLevel=false;
		while(sz>0){
			sz--;
			BinaryTreeNode<int> *node=nodes.front();
			nodes.pop();

			if(node->left){
				nodes.push(node->left);
			}
			if(node->right){
				nodes.push(node->right);
				rmdLeaf=node->right;
				foundInThisLevel=true;
			}else{
				if(node->left && !foundInThisLevel){//we didn't found leaf at this level and we have left child only at this node
					rmdLeaf=NULL;
				}
			}
		}
	}
	return rmdLeaf;
}