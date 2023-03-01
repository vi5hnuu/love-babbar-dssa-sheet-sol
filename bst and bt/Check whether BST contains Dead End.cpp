/*
Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Examples:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that 
              we cant insert any element.       

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at 
              node 9.  

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the no of nodes of the BST . Second line of each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.

Output:
The output for each test case will be 1 if the BST contains a dead end else 0.
 

Constraints:
1<=T<=100
1<=N<=200
 

Example(To be used only for expected output):
Input:
2
6
8 5 9 7 2 1
6
8 7 10 9 13 2
Output:
1
1
*/


/*
The Node structure is
  struct Node {
    int data;
    Node * right, * left;
  };
*/

/*You are required to complete below method */
bool isDeadEnd(Node *root,int low,int high){
    if(!root){
        return false;
    }
    if(!root->left && !root->right){
        if(low>=high){
            return true;//dead end
        }else{
            return false;
        }
    }
    return isDeadEnd(root->left,low,root->data-1) || isDeadEnd(root->right,root->data+1,high);
}
bool isDeadEnd(Node *root)
{
    return isDeadEnd(root,1,INT_MAX);
}