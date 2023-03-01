/*
Given a Binary Tree of size N, find all the nodes which don't have any sibling. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order.

Note: Root node can not have a sibling so it cannot be included in our answer.

Example 1:

Input :
       37
      /   
    20
    /     
  113 

Output: 20 113
Explanation: 20 and 113 dont have any siblings.

Example 2:

Input :
       1
      / \
     2   3 

Output: -1
Explanation: Every node has a sibling.

Your Task:  
You dont need to read input or print anything. Complete the function noSibling() which takes the root of the tree as input parameter and returns a list of integers containing all the nodes that don't have a sibling in sorted order. If all nodes have a sibling, then the returning list should contain only one element -1.


Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(Height of the tree)


Constraints:
1 ≤ N ≤ 10^4
All nodes have distinct values.
*/


vector<int> noSibling(Node* node){
    queue<Node*> nodes;
    nodes.push(node);
    
    vector<int> ans;    
    while(!nodes.empty()){
        int sz=nodes.size();
        while(sz>0){
            sz--;
            Node *tmp=nodes.front();
            nodes.pop();
            if(tmp->left){
                if(!tmp->right){
                    ans.push_back(tmp->left->data);
                }
                nodes.push(tmp->left);
            }
            if(tmp->right){
                if(!tmp->left){
                    ans.push_back(tmp->right->data);
                }
                nodes.push(tmp->right);
            }
        }
    }
    if(ans.empty()){
        ans.push_back(-1);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
