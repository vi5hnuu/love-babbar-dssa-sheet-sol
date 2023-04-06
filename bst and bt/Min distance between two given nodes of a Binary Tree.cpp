/*
Given a binary tree and two node values your task is to find the minimum distance between them.
The given two nodes are guaranteed to be in the binary tree and nodes are numbered from 1 to N.
Please Note that a and b are not always leaf node.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 105
*/


class Solution{
private:
    // bool path2EitherVal(Node *root,int a,int b,vector<Node*> &path){
    //     if(!root){
    //         return false;
    //     }
    //     bool foundAny=path2EitherVal(root->left,a,b,path) || path2EitherVal(root->right,a,b,path);
    //     path.push_back(root);
    //     if(root->data==a || root->data==b){//fill reverse path [will create problem]
            /*
            16 10 72 7
            10 16
            
            path : 10 16
            */
    //         return true;
    //     }
    //     if(!foundAny){
    //         path.pop_back();
    //     }
    //     return foundAny;
    // }
    bool path2EitherVal(Node *root,int a,int b,vector<Node*> &path){
        if(!root){
            return false;
        }
        path.push_back(root);
        if(root->data==a || root->data==b){//fill direct path
            return true;
        }
        bool foundAny=path2EitherVal(root->left,a,b,path) || path2EitherVal(root->right,a,b,path);
        if(!foundAny){
            path.pop_back();
        }
        return foundAny;
    }
    bool dist2Either(Node *root,int a,int b,int &dist){
        if(!root){
            return false;
        }
        dist++;
        if(root->data==a || root->data==b){
            return true;
        }
        int lft=dist2Either(root->left,a,b,dist);
        if(lft) return true;
        int rgt=dist2Either(root->right,a,b,dist);
        if(rgt) return true;
        dist--;
        return false;
    }
    void printPath(vector<Node*> &nodes){
        for(auto node:nodes){
            cout<<node->data<<" ";
        }
    }
public:
    int findDist(Node* root, int a, int b) {
        if(a==b || !root){
            return 0;
        }
        vector<Node*> path;
        path2EitherVal(root,a,b,path);
        // printPath(path);cout<<endl;
        int plen=path.size();
        
        for(int i=plen-1;i>=0;i--){
            Node *&node=path[i];
            int dist1=0;
            if(i==plen-1){
                dist2Either(node->left,a,b,dist1);
                if(dist1>0)return dist1;
                dist2Either(node->right,a,b,dist1);
                if(dist1>0)return dist1;
            }else{
                if(node->left==path[i+1]){
                    dist2Either(node->right,a,b,dist1);
                }else{
                    dist2Either(node->left,a,b,dist1);
                }
                 if(dist1>0){
                     return dist1+(plen-i-1);
                 };
            }
        }
        return -1;//will never occur if nodes are in tree
    }
};