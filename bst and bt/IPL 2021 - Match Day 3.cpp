/*
Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.

Today is matchday 3 and it is between Geek's favorite team Royal Challengers Banglore and the most powerful batting team - Sunrisers Hyderabad. Virat Kholi captain of the team RCB tried everything to win the trophy but never succeeded. He went to guruji to seek the blessing, but the guruji gave him a problem and asked him to solve it. Guruji gave him a tree-like structure, asked him to stand at the target node and find the sum of all nodes within a maximum distance of k from the target node. can Kholi solve this problem to qualify for the next round?

Note: The target node should be included in the sum.


Example 1:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 9, K = 1
Output:
22
Explanation:
Nodes within distance 1 from 9 are 9, 5, 7, 1  
Example 2:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 40, K = 2
Output:
113
Explanation:
Nodes within distance 2 from 40 are 40, 19, 50, 4

Your Task:
You don't need to read input or print anything. Complete the function sum_at_distK() which takes the root of the tree, target, and K  as input parameter and returns the sum of all nodes within a max distance of k from the target


Constraints:
1 ≤ N, Node Value ≤ 105
1 ≤ K ≤ 20
*/


// class Solution{
// private:
//     void buildAdj(Node *root,unordered_map<int,vector<int>> &adj,Node *par){
//         if(!root){
//             return;
//         }
//         if(par){
//             adj[par->data].push_back(root->data);
//             adj[root->data].push_back(par->data);
//         }
//         buildAdj(root->left,adj,root);
//         buildAdj(root->right,adj,root);
//     }
// public:
//     int sum_at_distK(Node* root, int target, int k){
//         unordered_map<int,vector<int>> adj;
//         unordered_map<int,bool> visited;
//         //directed graph
//         buildAdj(root,adj,NULL);
        
//         queue<int> nodes;
//         nodes.push(target);
//         visited[target]=true;
        
//         int sum=0;
//         while(!nodes.empty() && k>0){
//             int sz=nodes.size();
//             while(sz>0){
//                 sz--;
//                 int node=nodes.front();
//                 nodes.pop();
//                 sum+=node;
//                 for(int neighbour:adj[node]){
//                     if(!visited[neighbour]){
//                         visited[neighbour]=true;
//                         nodes.push(neighbour);
//                     }
//                 }
//             }
//             k--;
//         }
//         while(!nodes.empty()){
//             int node=nodes.front();
//             nodes.pop();
//             sum+=node;
//         }
//         return sum;
//     }
// };
//////////////
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
    int nodesWithinDistK(Node *root,int k){
        if(!root || k<0){
            return 0;
        }
        if(k==0){
            return root->data;
        }
        return root->data+nodesWithinDistK(root->left,k-1)+nodesWithinDistK(root->right,k-1);
    }
public:
    int sum_at_distK(Node* root,int target, int k){
        vector<Node*> path2Target;
        if(!initilizePath(root,target,path2Target)){
            return {};
        }
        
        int pathSize=path2Target.size();
        int atDistWithinKNodes=0;
        for(int i=0;i<path2Target.size() && k>=0;i++){
            if(i==0){
                atDistWithinKNodes+=nodesWithinDistK(path2Target[i],k);
            }else{
                if(path2Target[i]->left==path2Target[i-1]){//at dist k-1 in right subtree
                    atDistWithinKNodes+=path2Target[i]->data+nodesWithinDistK(path2Target[i]->right,k-1);
                }else{//at dist k-1 in left subtree
                    atDistWithinKNodes+=path2Target[i]->data+nodesWithinDistK(path2Target[i]->left,k-1);
                }
            }
            k-=1;
        }
        return atDistWithinKNodes;
    }
};