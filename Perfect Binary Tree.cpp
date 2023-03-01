/*
Given a Binary Tree, write a function to check whether the given Binary Tree is a prefect Binary Tree or not. A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.

Example 1:

Input: 
          7
      /  \
     4    9
Output: YES
Explanation: 
As the root node 7 has two children and 
two leaf nodes 4 and 9 are at same level 
so it is a perfect binary tree.
Example 2:

Input: 
                   7
              /   \
             3     8
           /   \     \
          2     5     10
        /
       1
Output: NO
Your task:

You don't need to read input or print anything. Your task is to complete the function isPerfect() which takes root node of the tree as input parameter and returns a boolean value.If the tree is a perfect binary tree return true other wise return false.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<=T<=10^5
1<=N<=10^5
1<=data of node<=10^5
*/


/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    bool isPerfect(Node *root){
        if(!root){
            return true;
        }
        queue<Node *> nodes;
        nodes.push(root);
        
        
        while(!nodes.empty()){
            int sz=nodes.size();
            bool cavity=false;
            bool hasNextLevel=false;
            while(sz>0){
                sz--;
                Node *node=nodes.front();
                nodes.pop();
                if(!node->left || !node->right){
                    cavity=true;
                }
                if(node->left){
                    if(cavity){
                        return false;
                    }
                    hasNextLevel=true;
                    nodes.push(node->left);
                }
                if(node->right){
                    if(cavity){
                        return false;
                    }
                    hasNextLevel=true;
                    nodes.push(node->right);
                }
            }
            if(hasNextLevel && cavity){
                return false;
            }
        }
        return true;
    }
};
