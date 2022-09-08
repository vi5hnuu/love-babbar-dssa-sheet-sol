class Solution {
   int kthSmallest(TreeNode* root, int k,int &pos) {
         if(!root)
            return -1;
        int res=kthSmallest(root->left,k,pos);
        if(res!=-1)
            return res;
        pos++;
        if(pos==k)    
            return root->val;
        return kthSmallest(root->right,k,pos);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
       int pos=0;
        return kthSmallest(root,k,pos);
    }
};