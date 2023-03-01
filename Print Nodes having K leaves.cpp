/*
Given a binary tree and an integer value K, the task is to find all nodes data in the given binary tree having exactly K leaves in sub-tree rooted with them.

NOTE: Nodes should be printed in the order in which they appear in postorder traversal.

Example 1:

Input:
K = 1
      0
    /   \
   1     2
Output: -1
Explanation: There is no node in this
tree which has one leaf in the sub tree
below it.
Example 2:

Input:
K = 2
          0
        /   \
       1     2
           /  
          4
        /   \
       5     9
Output: 4 2
Explanation: Nodes with data 2 and 4, have
2 leaves in the subtree below it.
Your Task:
Just complete the function btWithKleaves() and returns the answer (as a vector in CPP, as an ArrayList in java, and as list in python)

Note: If no node is found the list returned should contain only one value -1.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 1000
1 <= K <= 1000
1 <= value of nodes <= 10000

 
*/


/*The Node is defined as follows:
struct Node
{
    int data ;
    struct Node * left, * right ;
};
*/


class Solution{
private:
    int btWithKleaves(Node *root, int &k,vector<int> &res){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        int lftLeaveCount=btWithKleaves(root->left,k,res);
        int rgtLeaveCount=btWithKleaves(root->right,k,res);
        if(lftLeaveCount+rgtLeaveCount==k){
            res.push_back(root->data);
        }
        return lftLeaveCount+rgtLeaveCount;
    }
public:
    vector<int> btWithKleaves(Node *ptr, int k){ 
        vector<int> res;
        btWithKleaves(ptr,k,res);
        if(res.empty()){
            res.push_back(-1);
        }
        return res;
    }

};