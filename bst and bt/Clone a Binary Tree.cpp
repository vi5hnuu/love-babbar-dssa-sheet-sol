/*
Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.


Example 1:

Input:

Output: 1
Explanation: The tree was cloned successfully.

Your Task:
No need to read input or print anything. Complete the function cloneTree() which takes root of the given tree as input parameter and returns the root of the cloned tree. 

Note: The output is 1 if the tree is cloned successfully. Otherwise output is 0.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

// class Solution{
// private:
//     void cloneTree(Node *root,unordered_map<Node*,Node*> &mp){
//         if(!root){
//             return;
//         }
//         Node *nroot=new Node(root->data);
//         mp[root]=nroot;
//         if(mp[root->left]){
//             nroot->left=mp[root->left];
//         }else{
//           cloneTree(root->left,mp);
//           nroot->left=mp[root->left];
//         }
//         if(mp[root->right]){
//             nroot->right=mp[root->right];
//         }else{
//           cloneTree(root->right,mp); 
//           nroot->right=mp[root->right];
//         }
        
//         if(mp[root->random]){
//             nroot->random=mp[root->random];
//         }else{
//             cloneTree(root->random,mp);
//             nroot->random=mp[root->random];
//         }
//     }
// public:
//     Node* cloneTree(Node *root){
//         if(!root){
//             return NULL;
//         }
//       unordered_map<Node*,Node*> mp;//old->new node
//       cloneTree(root,mp);
//       return mp[root];
//     }
// };
///////////
class Solution{
private:
    Node* cloneTree(Node *root,unordered_map<Node*,Node*> &mp){
        if(!root){
            return NULL;
        }
        Node *nroot=new Node(root->data);
        mp[root]=nroot;
        if(mp[root->left]){
            nroot->left=mp[root->left];
        }else{
           nroot->left=cloneTree(root->left,mp);
        }
        if(mp[root->right]){
            nroot->right=mp[root->right];
        }else{
           nroot->right=cloneTree(root->right,mp);
        }
        
        if(mp[root->random]){
            nroot->random=mp[root->random];
        }else{
            nroot->random=cloneTree(root->random,mp);
        }
        return nroot;
    }
public:
    Node* cloneTree(Node *root){
        if(!root){
            return NULL;
        }
       unordered_map<Node*,Node*> mp;//old->new node
       return cloneTree(root,mp);
    }
};