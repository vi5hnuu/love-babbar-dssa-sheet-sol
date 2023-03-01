/*
Given a binary tree and a node, print all cousins of given node in order of their appearance. Note that siblings should not be printed.

Example 1:

Input : 
             1
           /   \
          2     3
        /   \  /  \
       4    5  6   7

Given node : 5
Output : 6 7
Explanation :
Nodes 6 and 7 are on the same level 
as 5 and have different parents.

Example 2 :

Input :
         9
        /
       5
Given node : 5
Output : -1
Explanation :
There no other nodes than 5 in the same level.
Your task :
You don't have to read input or print anything. Your task is to complete the function printCousins() which takes the root node of the tree and the node whose cousins need to be found, as input and returns a list containing the cousins of the given node in order of their appearance in the tree. If there is no cousin of the given node, return -1 as the first element of the list.
 
Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n)
 
Constraints :
1 <= n <=10^5
*/


/*
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find){
        if(!root){
            return vector<int>{-1};
        }
        queue<Node*> nodes;
        nodes.push(root);
        vector<int> cousins;
        bool targetFound=false;
        Node *par=NULL;
        while(!nodes.empty() && !targetFound){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                Node *node=nodes.front();
                nodes.pop();
                if(node->left==node_to_find || node->right==node_to_find){
                    targetFound=true;
                    par=node;
                }
                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);
                }
            }
        }
        while(!nodes.empty()){
            Node *node=nodes.front();
            nodes.pop();
            if(!(par->left==node || par->right==node)){
                cousins.push_back(node->data);
            }
        }
        if(cousins.empty()){
            cousins.push_back(-1);
        }
        return cousins;
    }
    
};
