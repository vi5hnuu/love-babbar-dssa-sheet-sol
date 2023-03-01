/*
Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note: It is guaranteed that the node exists in the tree.


Example 1:



Input:
     K = 2
     Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.
 

Example 2:

Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1<=N<=104
1<= K <= 100
*/


int kthAnc(Node *root, int &k, int &node){
    if(!root){
        return -1;
    }
    if(root->data==node){
        k--;
        return root->data;
    }
    int a=kthAnc(root->left,k,node);
    if(a>0){
        if(k==0){
            return a;
        }else{
            k--;
            return root->data;
        }
    }
    int b=kthAnc(root->right,k,node);
    if(b>0){
        if(k==0){
            return b;
        }else{
            k--;
            return root->data;
        }
    }
    return -1;
}

int kthAncestor(Node *root, int k, int node){
    k++;
    int ans= kthAnc(root,k,node);   

    return k==0 ? ans : -1;
}