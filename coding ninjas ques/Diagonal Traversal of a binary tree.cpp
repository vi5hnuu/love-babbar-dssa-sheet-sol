#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:
    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void diagonalTraversal(TreeNode<int> *root,map<int,vector<int>> &diagonalsEls,int diagonalIdx){
    if(!root){
        return;
    }
    diagonalsEls[diagonalIdx].push_back(root->data);
    diagonalTraversal(root->left,diagonalsEls,diagonalIdx+1);
    diagonalTraversal(root->right,diagonalsEls,diagonalIdx);
}
vector<int> diagonalTraversal(TreeNode<int> *root) {
    //right take same diagonal number ....go left increase diagonal number
    vector<int> diagonal;
    map<int,vector<int>> diagonalsEls;
    diagonalTraversal(root,diagonalsEls,0);
    map<int,vector<int>>::const_iterator itr=diagonalsEls.cbegin();
    
    
    while(itr!=diagonalsEls.cend()){
        for(int el:itr->second){
            diagonal.push_back(el);
        }
        itr++;
    }
    return diagonal;
    
}