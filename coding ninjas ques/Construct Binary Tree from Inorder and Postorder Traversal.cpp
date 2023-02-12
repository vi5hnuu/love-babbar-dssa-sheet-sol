/*
Problem Statement
Ninja has been given a postorder and inorder traversal of a Binary Tree of type integer with ‘N’ nodes stored in an array/list ‘POST_ ORDER’ and ‘IN_ORDER’. Ninja has to create the binary tree using the given two arrays/lists and return the root of that tree.
Note:
Assume that the Binary Tree contains only unique elements.
For Example:
Let's assume: ‘IN_ORDER’ = [9, 3, 15, 20, 7]  and ‘POST_ORDER’= [9, 15, 7, 20, 3].
We get the following binary tree from Inorder and Postorder traversal:

Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
1
7
4 5 2 6 7 3 1
4 2 5 1 6 3 7
Sample Output 1:
1 2 3 4 5 6 7
Explanation for Sample Output 1:
For sample test case 1: 

We get the following Binary Tree from the given Inorder and Postorder traversal:

Sample Input 2:
1
6
2 9 3 6 10 5
2 6 3 9 5 10
Sample Output 2:
5 6 10 2 3 9
Explanation for Sample Output 2:
For sample test case 1: 

We get the following Binary Tree from the given Inorder and Postorder traversal:

*/
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder,int &postIdx,int si,int sj) {
	if(si>sj){
          return NULL;
     }
     TreeNode<int> *root=new TreeNode<int>(postOrder[postIdx]);
     postIdx--;
     for(int i=si;i<=sj;i++){
          if(inOrder[i]==root->data){
               //postorder
               root->right=getTreeFromPostorderAndInorder(postOrder,inOrder,postIdx,i+1,sj);
               root->left=getTreeFromPostorderAndInorder(postOrder,inOrder,postIdx,si,i-1);
          }
     }
     return root;
}

//inorder-> LDR
//postorder->LRD
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) {
	int len=postOrder.size();
     int postIdx=len-1;
     return getTreeFromPostorderAndInorder(postOrder,inOrder,postIdx,0,len-1);
}
