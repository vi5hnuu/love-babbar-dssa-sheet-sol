/*
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 104
*/

//DO BFS



class Solution {
private:
    void buildAdjancyList(Node *root,int par,unordered_map<int,vector<int>> &adj){
        if(!root){
            return;
        }
        if(par!=-1){
            adj[par].push_back(root->data);
            adj[root->data].push_back(par);
        }
        buildAdjancyList(root->left,root->data,adj);
        buildAdjancyList(root->right,root->data,adj);
    }
public:
    int minTime(Node* root, int target) 
    {
        unordered_map<int,vector<int>> adj;
        buildAdjancyList(root,-1,adj);
        unordered_map<int,bool> visited;
        queue<int> nodes;
        nodes.push(target);
        visited[target]=true;
        
        int time=0;
        while(!nodes.empty()){
            int sz=nodes.size();
            //burn this level
            while(sz>0){
                sz--;
                int node=nodes.front();
                nodes.pop();
                for(int neighbour:adj[node]){
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        nodes.push(neighbour);   
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};


////////////////////////////////


class Solution {
private:
    bool initilizePath2Target(Node *root,int &target,vector<Node*> &path2target){
        if(!root){
            return false;
        }
        if(root->data==target){
            path2target.push_back(root);
            return true;
        }
        if(initilizePath2Target(root->left,target,path2target) || initilizePath2Target(root->right,target,path2target)){
            path2target.push_back(root);
            return true;
        }
        return false;
    }
    int height(Node *root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
public:
    int minTime(Node* root, int target) {
        vector<Node*> path2Target;
        if(!initilizePath2Target(root,target,path2Target)){
            return 0;//target not found.
        }
        int sz=path2Target.size();
        int time=0;
        int upTreeEdgeCount=0;
        for(int i=0;i<sz;i++){
            if(i==0){
                time=max(time,height(path2Target[i]));
            }else{
                upTreeEdgeCount+=1;
                if(path2Target[i]->left==path2Target[i-1]){
                   time=max(time,upTreeEdgeCount+1+height(path2Target[i]->right)); 
                }else{
                    time=max(time,upTreeEdgeCount+1+height(path2Target[i]->left));
                }
            }
        }
        return time;
        }
    };