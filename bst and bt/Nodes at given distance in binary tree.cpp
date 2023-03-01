/*
Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
Note: You have to return list in sorted order.

Example 1:

Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.

Example 2:

Input:      
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    
Target Node = 7
K = 2
Output: 1 24
Your Task:  
You don't need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(Height of tree)


Constraints:
1 ≤ N ≤ 103
1 ≤ data of node ≤ 104
1 ≤ target ≤ 104
1 ≤ k ≤ 20
*/

/*
class Solution
{
private:
    void buildAdjList(Node *root,int par,unordered_map<int,vector<int>> &adj){
        if(!root){
            return;
        }
        if(par!=-1){
            adj[root->data].push_back(par);
            adj[par].push_back(root->data);
        }
        buildAdjList(root->left,root->data,adj);
        buildAdjList(root->right,root->data,adj);
    }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        
        //undirected graph adjacency list
        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> visited;
        buildAdjList(root,-1,adj);
        
        queue<int> nodes;
        nodes.push(target);
        visited[target]=true;
        int dist=k;
        vector<int> res;
        while(!nodes.empty()){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                int node=nodes.front();
                nodes.pop();
                if(dist==0){
                    res.push_back(node);
                }
                for(int neighbour:adj[node]){
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        nodes.push(neighbour);
                    }
                }
            }
            if(dist==0){
                break;
            }
            dist--;
        }
        sort(res.begin(),res.end());
        return res;
    }
};
*/

class Solution{
private:
    bool initilizePath(Node *root,int target,vector<Node*> &path){
        if(!root){
            return false;
        }
        if(root->data==target){
            path.push_back(root);
            return true;
        }
        if(initilizePath(root->left,target,path) || initilizePath(root->right,target,path)){
            path.push_back(root);
            return true;
        }
        return false;
    }
    //nodesAtDistK down the tree
    void nodesDistK(Node *root,int k,vector<int> &atDistKNodes){
        if(!root || k<0){
            return;
        }
        if(k==0){
            atDistKNodes.push_back(root->data);
            return;
        }
        nodesDistK(root->left,k-1,atDistKNodes);
        nodesDistK(root->right,k-1,atDistKNodes);
    }
public:
    vector<int> KDistanceNodes(Node* root,int target, int k){
        vector<Node*> path2Target;
        if(!initilizePath(root,target,path2Target)){
            return {};
        }
        
        int pathSize=path2Target.size();
        vector<int> atDistKNodes;
        for(int i=0;i<path2Target.size() && k>=0;i++){
            if(i==0){
                nodesDistK(path2Target[i],k,atDistKNodes);
            }else{
                if(k==0){
                  atDistKNodes.push_back(path2Target[i]->data);
                }else if(path2Target[i]->left==path2Target[i-1]){//at dist k-1 in right subtree
                    nodesDistK(path2Target[i]->right,k-1,atDistKNodes);
                }else{//at dist k-1 in left subtree
                    nodesDistK(path2Target[i]->left,k-1,atDistKNodes);
                }
            }
            k-=1;
        }
        sort(atDistKNodes.begin(),atDistKNodes.end());
        return atDistKNodes;
    }
};