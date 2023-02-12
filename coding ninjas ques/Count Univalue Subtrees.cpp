/*
Problem Statement
You are given a binary tree. Return the count of unival sub-trees in the given binary tree. In unival trees, all the nodes, below the root node, have the same value as the data of the root.
For example: for the binary tree, given in the following diagram, the number of unival trees is 5.

Detailed explanation ( Input/output format, Notes, Constraints, Images )
Input Format:
The first line of input contains an integer T, the number of test cases.

The next T lines, where each line contains elements in the level order form. The input consists of values of nodes separated by a single space in a single line. In case a node is null, we take -1 on its place.

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
The sequence will be put together in a single line separated by a single space. Hence, for the above depicted tree, the input will be given as:

1    
1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
For every test case print single line containing an integer i.e the count of unival trees.
Note
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
0 <= N <= 10^5
0 <= data <= 10^4, where data is the value for a node.

Time Limit: 1sec
Sample Input 1:
1 1 1 -1 -1 -1 -1
Sample Output 1:
3
Sample Input 2:
1 2 3 2 -1 3 4 -1 -1 3 3 -1 -1 -1 -1 -1 -1
Sample Output 2:
6
Explanation To Sample Input 2:
The input binary tree will be represented as 

In the above diagram, the orange marked nodes are the root nodes of the unival sub-trees for the given binary tree.

*/
/*************************************************************
 
    Following is the Binary Tree node structure

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
//-1 -> no left or right child
//-2 any subtree do not hav left and right child equal
/*
1
1 1 1 1 1 1 2 -1 -1 -1 -1 1 -1 2 2 -1 -1 -1 -1 -1 -1
*/
int countUnivalTrees(BinaryTreeNode<int> *root,int &count){
    if(!root){
        return -1;
    }
    if(!root->left && !root->right){
        count++;
        return root->data;
    }
    int lft=countUnivalTrees(root->left,count);
    int rgt=countUnivalTrees(root->right,count);
    if(lft==-2 || rgt==-2){
        return -2;
    }
    if(lft>0 && rgt>0){
        if(root->data==lft && lft==rgt){
            count++;
        }else{
            return -2;//break sequence
        }
    }else if(lft>0){
        if(root->data==lft){
            count++;
        }else{
            return -2;//break sequence
        }
    }else{
        if(root->data==rgt){
            count++;
        }else{
            return -2;//break sequence
        }
    }
    return root->data;
}
int countUnivalTrees(BinaryTreeNode<int> *root){
    if(!root){
        return 0;
    }
    int count=0;
    countUnivalTrees(root,count);
    return count;
}