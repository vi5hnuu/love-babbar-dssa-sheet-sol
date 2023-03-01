/*
Given the binary Tree of and two-node values. Check whether the two-node values are cousins of each other or not.

Example 1:

Input:
      1
    /   \
   2     3
a = 2, b = 3
Output: 0

Example 2:

Input:
       1
     /   \ 
    2     3
   /       \
  5         4 
a = 5, b = 4
Output: 1
Explanation: Here, nodes 5 and 4 are
at the same level and have different
parent nodes. Hence, they both are cousins 

Your Task:
You don't need to read input or print anything. Your task is to complete the function isCousins() that takes the root node of the tree (having all nodes distinct), and two integers 'a' and 'b' as inputs. It returns true if the nodes with given values 'a' and 'b' are Cousins of each other and returns false otherwise. 
Two nodes value are cousins of each other if they are at the same level and have different parents. (The driver code will print 1 if the returned values is true,otherwise 0.)

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000


Note: The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/


bool isCousins(Node *root, int a, int b)
{
   queue<Node*> nodes;
   nodes.push(root);
   
   while(!nodes.empty()){
       int sz=nodes.size();
       
       bool afound=false;
       bool bfound=false;
       while(sz>0){
           sz--;
           Node *node=nodes.front();
           nodes.pop();
           
           
           
           
           if(node->left){
               if(node->left->data==a){
                   afound=true;
               }else if(node->left->data==b){
                   bfound=true;
               }
               nodes.push(node->left);
           }
           if(node->right){
               if(node->right->data==a){
                   afound=true;
               }else if(node->right->data==b){
                   bfound=true;
               }
               nodes.push(node->right);
           }
           
           if(afound && bfound){
               if((!node->left && !node->right) || (node->left && !node->right) || (!node->left && node->right)){
                   return true;
               }else{
                   if((node->left->data==a && node->right->data==b) || (node->left->data==b && node->right->data==a)){
                       return false;
                   }else{
                       return true;
                   }
               }
           }
       }
   }
    return false;
}