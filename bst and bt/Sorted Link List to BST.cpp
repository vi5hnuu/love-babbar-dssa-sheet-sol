/*
Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
Note: There might be nodes with the same value.

Example 1:

Input:
Linked List: 1->2->3->4->5->6->7
Output:
4 2 1 3 6 5 7
Explanation :
The BST formed using elements of the 
linked list is,
        4
      /   \
     2     6
   /  \   / \
  1   3  5   7  
Hence, preorder traversal of this 
tree is 4 2 1 3 6 5 7
Example 2:

Input:
Linked List : 1->2->3->4
Ouput:
3 2 1 4
Explanation:
The BST formed using elements of the 
linked list is,
      3   
    /  \  
   2    4 
 / 
1
Hence, the preorder traversal of this 
tree is 3 2 1 4
Your task :
You don't have to read input or print anything. Your task is to complete the function sortedListToBST(), which takes head of the linked list as an input parameter and returns the root of the BST created.
 
Expected Time Complexity: O(N), N = number of Nodes
Expected Auxiliary Space: O(N), N = number of Nodes
 
Constraints:
1 ≤ Number of Nodes ≤ 106
1 ≤ Value of each node ≤ 106
*/


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
private:
    void LTclone(LNode *head,vector<TNode*> &nodes){
        while(head){
            nodes.push_back(new TNode(head->data));
            head=head->next;
        }
    }
    TNode *TLBST(vector<TNode*> &nodes,int low,int high){
        if(low>high){
            return NULL;
        }
        int m=(low+high+1)/2;
        nodes[m]->left=TLBST(nodes,low,m-1);
        nodes[m]->right=TLBST(nodes,m+1,high);
        return nodes[m];
    }
public:
    TNode* sortedListToBST(LNode *head) {
        vector<TNode*> nodes;
        LTclone(head,nodes);
        return TLBST(nodes,0,nodes.size()-1);
    }
};