/*
Given a Binary Tree of size N, find the sum of all the leaf nodes that are at minimum level of the given binary tree.
Example 1:

Input: 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \ 
 7    2      
Output:
sum = 5 + 8 = 13
Example 2:

Input: 
            1
      /    \
     2      3
    / \    / \
   4   5  6   7
Output: 22
Your Task:
You don't need to read input or print anything. Your task is to complete the function minLeafSum() which takes root node of the tree as input parameter and returns an integer denoting the sum of all the leaf nodes that are at minimum level of the given binary tree. If the tree is empty, return 0. 
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1<=N<=103
1<=data on node<=103
*/


//User function Template for C++
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
    int minLeafSum(Node *root){
        if(!root){
            return 0;
        }
        queue<Node*> nodes;
        nodes.push(root);
        
        bool lockMinLevel=false;
        int sumLeafs=0;
        while(!nodes.empty()){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                Node *node=nodes.front();
                nodes.pop();
                if(!node->left && !node->right){
                    sumLeafs+=node->data;
                    lockMinLevel=true;
                }
                if(!lockMinLevel && node->left){
                    nodes.push(node->left);
                }
                if(!lockMinLevel && node->right){
                    nodes.push(node->right);
                }
            }
            if(lockMinLevel){
                break;
            }
        }
        return sumLeafs;
    }
};