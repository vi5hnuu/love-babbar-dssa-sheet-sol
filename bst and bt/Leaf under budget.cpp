/*
Given a binary tree and a budget. Assume you are at the root of the tree(level 1), you need to maximise the count of leaf nodes you can visit in your budget if the cost of visiting a leaf node is equal to the level of that leaf node.

Example 1:

Input: 
                  10
                /    \
               8      2
             /      /   \
            3      3     6
                    \
                     4
and budget = 8
Output: 2
Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
In budget 8 one can visit Max 2 Leaf Nodes.
Example 2:

Input: 
            1
       /   \
      2     3
     / \   / \
    4   5 6   7
and budget = 5
Output: 1
Your Task:

You don't need to read input or print anything. Your task is to complete the function getCount() which takes root node of the tree and a integer denoting the budget as input parameters and returns an integer denoting the count of visited leaf nodes of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<=T<=103
1<=N<=104
1<=budget<=104
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
class Solution{
private:
    void leafsTree(Node *root,priority_queue<int,vector<int>,greater<>> &nodes,int lvl){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            nodes.push(lvl);
            return;
        }
        leafsTree(root->left,nodes,lvl+1);
        leafsTree(root->right,nodes,lvl+1);
    }
public:
    int getCount(Node *root, int k){
        priority_queue<int,vector<int>,greater<>> nodes;
        leafsTree(root,nodes,1);
        
        int count=0;
        int sm=0;
        while(sm<=k && !nodes.empty()){
            sm+=nodes.top();
            nodes.pop();
            count++;
        }
        return sm<=k ? count : count-1;
    }
};