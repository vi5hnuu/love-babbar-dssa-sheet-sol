/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //51 / 52
 //because level order can create more nulls than actual node->val
// class Codec {
// private:
//     vector<TreeNode*> getNodes(string &s){
//         istringstream ss(s);
//         vector<TreeNode*> nodes;
//         for(string node;ss>>node;){
//             if(node=="N"){
//                 nodes.push_back(NULL);
//             }else{
//                 nodes.push_back(new TreeNode(stoi(node)));
//             }
//         }
//         return nodes;
//     }
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if(!root){
//             return "N";
//         }
//         //level order traversal
//         queue<TreeNode*> nodes;
//         nodes.push(root);

//         string serial="";
        
//         bool nextLevelHasValidNode=true;
//         while(!nodes.empty() && nextLevelHasValidNode){
//             int sz=nodes.size();
//             bool anyValidNode=false;
//             while(sz>0){
//                 TreeNode *node=nodes.front();
//                 // if(node){
//                 //     cout<<node->val<<" ";
//                 // }else{
//                 //     cout<<"N ";
//                 // }
//                 nodes.pop();
//                 if(!node){
//                     serial+="N ";
//                     nodes.push(NULL);
//                     nodes.push(NULL);
//                 }else{
//                     serial+=to_string(node->val)+" ";
//                     nodes.push(node->left);
//                     nodes.push(node->right);
//                     if(node->left || node->right)
//                         anyValidNode=true;
//                 }
//                 sz--;
//             }
//             // cout<<endl;
//             nextLevelHasValidNode=anyValidNode;
//         }
//         serial=serial.substr(0,serial.length()-1);
//         // cout<<serial;
//         return serial;
//     }

//     // Decodes your encoded data to tree.
//     //1 2 3 N N 4 5
//     TreeNode* deserialize(string data) {
//         vector<TreeNode*> rawNodes=getNodes(data);
//         if(!rawNodes[0]){
//             return NULL;
//         }
//         TreeNode *root=rawNodes[0];
//         queue<TreeNode*> achilds;//nodes with which rawNodes will get attached to
//         achilds.push(root);
//         int nodesInLevel=2;
//         int idx=1;
//         while(idx<rawNodes.size()){
//             int count=nodesInLevel;
//             while(count>0){
//                 count-=2;
//                 TreeNode *attachTo= achilds.front();
//                 achilds.pop();
//                 TreeNode *lft=rawNodes[idx++];
//                 TreeNode *rght=rawNodes[idx++];
//                 achilds.push(lft);
//                 achilds.push(rght);
//                 if(!attachTo){
//                     continue;
//                 }
//                 attachTo->left=lft;
//                 attachTo->right=rght;
//             }
//             // cout<<endl;
//             nodesInLevel*=2;
//         }
//         return root;
//     }
// };
//////////////////////////////
class Codec {
private:
//preorder
    void serialize(TreeNode* root,ostringstream &os) {
        if(!root){
            os<<"# ";
            return;
        }
        os<<(root->val)<<" ";
        serialize(root->left,os);
        serialize(root->right,os);
    }
    TreeNode* deserialize(istringstream &inp) {
        string node;
        inp>>node;
        if(node=="#"){
            return nullptr;
        }
        TreeNode *root=new TreeNode(stoi(node));
        root->left=deserialize(inp);
        root->right=deserialize(inp);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        serialize(root,os);
        string serial=os.str();
        cout<<serial<<endl;
        return serial;
    }

    TreeNode* deserialize(string data) {
        istringstream inp(data);
        return deserialize(inp);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));