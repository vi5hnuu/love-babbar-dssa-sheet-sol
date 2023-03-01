/*
Given a Binary Tree, write a function to check whether the given Binary Tree is Complete Binary Tree or not. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes should be as much close to left as possible.


Example 1:
Input:
       1
      / \
     2   3
Output:
Complete Binary Tree
Example 2:

Input:
              1
            /   \
          2      3
           \    /  \
            4  5    6
Output:
Not Complete Binary Tree
Constraints:
1<=Number of Node<=100
0 <= Data of a node <= 106

Your Task:
You don't need to take input. Just complete the function isCompleteBT() that takes root node as a parameter and returns true, if the tree is Complete else returns false.

 
*/


class Solution{
public:    
    bool isCompleteBT(Node* root){
        if(!root){
            return true;
        }
        queue<Node*> nodes;
        nodes.push(root);
        
        int cCount=1;
        while(!nodes.empty()){
            int sz=nodes.size();
            int cpySz=sz;
            
            bool hasNextLevel=false;
            bool missingFound=false;
            while(sz>0){
                sz--;
                Node *node=nodes.front();
                nodes.pop();
                if(node->left){
                    if(missingFound){
                        return false;
                    }
                    hasNextLevel=true;
                    nodes.push(node->left);
                }else{
                    missingFound=true;
                }
                if(node->right){
                    if(missingFound){
                        return false;
                    }
                    hasNextLevel=true;
                    nodes.push(node->right);
                }else{
                    missingFound=true;
                }
            }
            if(hasNextLevel && cCount!=cpySz){
                return false;
            }
            cCount*=2;
            
        }
        return true;
    }
};