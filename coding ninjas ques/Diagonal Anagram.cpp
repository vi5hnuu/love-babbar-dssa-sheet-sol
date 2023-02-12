/*
Problem Statement
You are given two Binary Trees. You need to return true if the diagonals of trees are anagram to each other, otherwise you need to return false.
Diagonals of the binary tree are :

There are three diagonals :
Diagonal 1 : 8 10 14
Diagonal 2 : 3 6 7 13
Diagonal 3 : 1 4
For Example:
For the given binary trees: 
 

Output: True

Explanation: There are 3 diagonals in each tree.
Tree1:                                      
Diagonal 1: 5 10 9             
Diagonal 2: 6 3 5               
Diagonal 3: 2   

Tree2:
Diagonal 1: 5 9 10
Diagonal 2: 3 6 5
Diagonal 3: 2

Since diagonal 1 of tree 1 is an anagram of diagonal 1 of tree 2, similarly diagonal 2 of tree 1 is an anagram of diagonal 2 of tree 2 and similarly with diagonal 3. 
Thus, its output should be True.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
5 6 10 2 3 5 9 -1 -1 -1 -1 -1 -1 -1 -1
5 3 9 2 6 5 10 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
True
Explanation To Sample Input 1:
There are 3 diagonals in each tree.
Tree1:                                      
Diagonal 1: 5 10 9             
Diagonal 2: 6 3 5               
Diagonal 3: 2                     

Tree2:
Diagonal 1: 5 9 10
Diagonal 2: 3 6 5
Diagonal 3: 2
Since diagonal 1 of tree 1 is an anagram of diagonal 1 of tree 2, similarly diagonal 2 of tree 1 is an anagram of diagonal 2 of tree 2 and similarly with diagonal 3.

Thus, its output should be True.
Sample Input 2:
1 2 3 -1 -1 -1 -1
3 2 -1 -1 
Sample Output 2:
False
*/


#include <bits/stdc++.h> 
/**********************************************************
    Following is the Binary Tree Node class structure.

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
void diagonalAnagram(BinaryTreeNode<int> *root1,BinaryTreeNode<int> *root2, map<int,int> &dXor,bool &isAnagram,int diagIdx=0){
	if(!root1 && !root2){
		return;
	}
	if((!root1 && root2) || (root1 && !root2)){
		isAnagram=false;
		return;
	}
	dXor[diagIdx]^=root1->data;
	dXor[diagIdx]^=root2->data;
	if(dXor[diagIdx]>0){//we cannot return bacause xor can be zero in future [over head of traversing full tree]
		isAnagram=false;
	}else{
		isAnagram=true;
	}
	diagonalAnagram(root1->right,root2->right,dXor,isAnagram,diagIdx);
	diagonalAnagram(root1->left,root2->left,dXor,isAnagram,diagIdx-1);
}
bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    map<int,int> dXor;
	bool isAnagram=true;
	diagonalAnagram(root1,root2,dXor,isAnagram);
	return isAnagram;
}
