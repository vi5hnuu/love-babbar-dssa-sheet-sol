/*
Problem Statement
You are given a binary tree, where the data present in each node is an integer. You have to find whether the given tree is symmetric or not.
Symmetric tree is a binary tree, whose mirror image is exactly the same as the original tree.
For Example:

Detailed explanation ( Input/output format, Notes, Constraints, Images )
Input Format:
The only line of input contains the binary tree node elements in the level order form. The values of nodes are separated by a single space in a single line. In case a node is null, we take -1 in its place.

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
Output Format:
The output consists of a single line containing "Symmetric" if the given tree is symmetric, else "Asymmetric".
Note:
You are not required to print the expected output; it has already been taken care of, Just implement the function.
Constraints:
0 <= N <= 10^5
1 <= Data <= 10^5

Where 'N' denotes the number of nodes in the given binary tree and 'Data' denotes the node value.

Time limit: 1sec
Sample Input 1:
1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
Symmetric
Explanation For Sample 1:
This is a symmetric tree:

Sample Input 2:
1 2 3 4 -1 -1 -1 -1 -1
Sample Output 2:
Asymmetric
Explanation For Sample 2:
This is an asymmetric tree:

*/
/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
//test cases passed but i think it is wrong..
/*
eg level => 1 2 2 1

//match
start 1->left ==> 5
end 1->right ==> 5

//algo says yes but its not mirror
start 2->left=10
end 2->left=10

weak test case for question ig...2nd sol is correct...the rec one....
*/
bool isSymmetric(BinaryTreeNode<int>* root){
  if (!root) {
      return true;
  }
    queue<BinaryTreeNode<int>*> nodes;
    nodes.push(root);

    while(!nodes.empty()){
        int sz=nodes.size();
        vector<int> level;
        while (sz > 0) {
            sz--;
           BinaryTreeNode<int> *node=nodes.front();
           nodes.pop();
            level.push_back(node->data);
           if(node->left){
               nodes.push(node->left);
           }
           if(node->right){
               nodes.push(node->right);
           }
        }
        int len=level.size();
        int i=0,j=len-1;
        while(i<j){
            if(level[i]!=level[j]){
                return false;
            }
            i++;
            j--;
        }
    }
    return true;
}

//////////////
/*
Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: True
Explanation: Tree is mirror image of
itself i.e. tree is symmetric
Example 2:

Input:
         5
       /   \
      10     10
     /  \     \
    20  20     30
Output: False
Your Task:
You don't need to read input or print anything. Your task is to complete the function isSymmetric() which takes the root of the Binary Tree as its input and returns True if the given Binary Tree is the same as the Mirror image of itself. Else, it returns False.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0<=Number of nodes<=100
*/

class Solution{
private:
    bool isSymmetric(Node *root1,Node *root2){
        if(!root1 && !root2){
            return true;
        }
        if((root1 && !root2) || (!root1 && root2) || (root1->data != root2->data)){
            return false;
        }
        return isSymmetric(root1->left,root2->right) &&
               isSymmetric(root1->right,root2->left);
    }    
public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
        if(!root){
            return true;
        }
	    return isSymmetric(root->left,root->right);
    }
};