/*
Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.

Example 1:

Input:
            1
          /   \
         2     3

Output: -4

Explanation:
sum at odd levels - sum at even levels
= (1)-(2+3) = 1-5 = -4

Example 2:

Input:
            10
          /    \
        20      30
       /  \         
     40    60      

Output: 60

Explanation:
sum at odd levels - sum at even levels
= (10+40+60) - (20+30)
= 110 - 50
= 60

Your Task:  
You dont need to read input or print anything. Complete the function getLevelDiff() which takes root node as input parameter and returns an integer.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^5
*/


class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       queue<Node*> nodes;
       nodes.push(root);
       
       bool evenLvl=true;
       int sum=0;
       while(!nodes.empty()){
           int sz=nodes.size();
           while(sz>0){
               sz--;
               Node *node=nodes.front();
               nodes.pop();
               if(evenLvl){
                   sum+=node->data;
               }else{
                   sum-=node->data;
               }
               if(node->left){
                   nodes.push(node->left);
               }
               if(node->right){
                   nodes.push(node->right);
               }
           }
           evenLvl=!evenLvl;
       }
       return sum;
    }
};