/*
Given a binary tree, find the largest value in each level.


Example 1:

Input:
        1
       / \
      2   3 
Output:
1 3
Explanation:
At 0 level, values of nodes are {1}
                 Maximum value is 1
At 1 level, values of nodes are {2,3}
                Maximum value is 3
Example 2:

Input:
        4
       / \
      9   2
     / \   \
    3   5   7 
Output:
4 9 7
Explanation:
At 0 level, values of nodes are {4}
                 Maximum value is 4
At 1 level, values of nodes are {9,2}
                 Maximum value is 9
At 2 level, values of nodes are {3,5,7}
                 Maximum value is 7
 

Your Task:

You don't need to read input or print anything.Your task is to complete the function maximumValue() that takes root node as input parameter and returns a list of integers containing the maximum value at each level. The size of the resultant list should be equal to the height of the binary tree and result[i] should store the maximum value at level i.


Expected Time Complexity: O(N), where N is the number of nodes.
Expected Auxiliary Space: O(H), where H is the height of binary tree.


Constraints:
1 ≤ Number of nodes ≤ 10^4
1 ≤ Data of a node ≤ 10^5
*/


/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
    vector<int> maximumValue(Node* root) {
        vector<int> maxs;
        
        queue<Node*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()){
            int sz=nodes.size();
            int mx=INT_MIN;
            while(sz>0){
                sz--;
                Node *node=nodes.front();
                nodes.pop();
                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);
                }
                mx=max(mx,node->data);
            }
            maxs.push_back(mx);
        }
        return maxs;
    }
};