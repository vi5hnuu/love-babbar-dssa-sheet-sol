/*
Given a Binary Tree and a target key, you need to find all the ancestors of the given target key.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7
Key: 7
Ancestor: 4 2 1
Example 1:

Input:
        1
      /   \
     2     3
target = 2
Output: 1
Example 2:

Input:
         1
       /   \
      2     3
    /  \   /  \
   4    5 6    8
  /
 7
target = 7
Output: 4 2 1
Your Task:
Your task is to complete the function Ancestors() that finds all the ancestors of the key in the given binary tree.
Note:
The return type is
cpp: vector
Java: ArrayList
python: list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for the recursion stack.

Constraints:
1 ≤ N ≤ 103
1 ≤ data of node ≤ 104
*/


//User function template for C++

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution{
    private:
    /*
    ancestors top to bottom
    bool Ancestors(struct Node *root,vector<int> &res,int target)
    {
         if(!root)
            return false;
        if(root->data==target)
            return true;
        res.push_back(root->data);
        if(Ancestors(root->left,res,target) || Ancestors(root->right,res,target)){
            return true;
        }
        res.pop_back();
        return false;
    }
    */
    //anceestor bottom to top
    bool Ancestors(struct Node *root,vector<int> &res,int target)
    {
         if(!root)
            return false;
        if(root->data==target)
            return true;
        if(Ancestors(root->left,res,target) || Ancestors(root->right,res,target)){
        res.push_back(root->data);
            return true;
        }
        return false;
    }
  public:
    vector<int> Ancestors(struct Node *root, int target)
    {
         vector<int> res;
         Ancestors(root,res,target);
         return res;
    }
};