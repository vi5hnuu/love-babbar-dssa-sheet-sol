#include <bits/stdc++.h> 
/*
template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

*/

// int countBST(int &l,int &r,BinaryTreeNode<int> *root){
//   if (!root) {
//       return 0;
//   }
//   if (root->data > r) {
//       return countBST(l,r,root->left);
//   }
//   if (root->data < l) {
//       return countBST(l,r,root->right);
//   }

//   if (l <= root->data && r >= root->data) {
//       return 1+countBST(l,r,root->left)+countBST(l,r,root->right);
//   }
// }
// vector<int> bstQueries(BinaryTreeNode<int> *root, int q, vector<pair<int, int>> queries) {
// 		vector<int> ans;
//         for (auto query : queries) {
//             ans.push_back(countBST(query.first,query.second,root));    
//         }
//         return ans;
// }
///////////////////////////////////
#include <bits/stdc++.h> 
/*
template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

*/

// int countBST(int &l,int &r,BinaryTreeNode<int> *root){
//     while(root && root->data > r){root=root->left;}
//     while(root && root->data < l){root=root->right;}
//     if (!root) {
//         return 0;
//     }
//     int ans=countBST(l,r,root->left)+countBST(l,r,root->right);
//     if (root->data >= l && root->data <= r) {
//         return 1+ans;
//     }
//     return ans;
// }
//////////////////////////////////////////////////////////////
void inorder(BinaryTreeNode<int> *root,vector<int> &in){
    if(!root){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
int binSearchL(vector<int> &nums, int limitL, int limitR) {
    int low=0,high=nums.size()-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if(nums[mid]<limitL){
            low=mid+1;
        }else if(nums[mid]>limitR){
            high=mid-1;
        }else{
            if(mid==0 || nums[mid-1]<limitL){
                return mid;
            }
            high=mid-1;
        }
    }
    return -1;
}
int binSearchR(vector<int> &nums, int limitL, int limitR) {
    int nlen=nums.size();
    int low=0,high=nlen-1;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if(nums[mid]<limitL){
            low=mid+1;
        }else if(nums[mid]>limitR){
            high=mid-1;
        }else{
            if(mid==nlen-1 || nums[mid+1]>limitR){
                return mid;
            }
            low=mid+1;
        }
    }
    return -1;
}
vector<int> bstQueries(BinaryTreeNode<int> *root, int q, vector<pair<int, int>> queries) {
		vector<int> ans;
        vector<int> in;
        inorder(root,in);
        int isz=in.size();
        for (auto query : queries) {
            int l=query.first;
            int r=query.second;
            if(in[0]>r || in[isz-1]<l){
                ans.push_back(0);//not found any
                continue;
            }
            int i=binSearchL(in,l,r);
            if(i<0){
                ans.push_back(0);//not found any
                continue;
            }
            int j=binSearchR(in,l,r);  
            ans.push_back(j-i+1);
        }
        return ans;
}