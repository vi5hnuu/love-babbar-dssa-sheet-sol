// Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

// Example 1:


// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]
// Example 2:


// Input: root1 = [1,null,8], root2 = [8,1]
// Output: [1,1,8,8]
 

// Constraints:

// The number of nodes in each tree is in the range [0, 5000].
// -105 <= Node.val <= 105

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
class Solution {
    void inorder(TreeNode* root,vector<int> &res){
        if(!root)
            return;
        
        //inorder
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    void merge(const vector<int> &v1,const vector<int> &v2,vector<int> &res){
        int i=0,j=0,k=0;
        int len1=v1.size(),len2=v2.size();
        while(i<len1 && j<len2){
            if(v1[i]<v2[j]){
                res[k++]=v1[i++];
            }else{
                res[k++]=v2[j++];
            }
        }
        while(i<len1){
            res[k++]=v1[i++]; 
        }
        while(j<len2){
            res[k++]=v2[j++]; 
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        inorder(root1,res1);
        inorder(root2,res2);
        vector<int> res3(res1.size()+res2.size());
        merge(res1,res2,res3);
        return res3;
    }
};
*/


//single iteration
class Solution {
private:
    void pushLeft(stack<TreeNode*> &s, TreeNode* node) {
        while(node){
            s.push(node);
            node=node->left;
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1,s2;
        pushLeft(s1,root1);
        pushLeft(s2,root2);
        while(!s1.empty() || !s2.empty()){
            stack<TreeNode *> &tmp = (s1.empty() ? s2 : (s2.empty() ? s1 : (s1.top()->val>s2.top()->val ? s2 : s1)));
            auto node=tmp.top();
            tmp.pop();
            res.push_back(node->val);
            pushLeft(tmp,node->right);
        }
        return res;
    }
};