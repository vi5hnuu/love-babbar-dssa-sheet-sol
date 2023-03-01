/*
Given a sorted doubly linked list and an element X, your need to insert the element X into correct position in the sorted DLL.

Example:

Input:
LinkedList:

X = 9
Output:

Your Task:
You only need to complete the function sortedInsert() that takes head reference and x as arguments and returns the head of the modified list. The printing and checking tasks are done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Number of nodes <= 103

View Bookmarked Problems 
*/


/*structure of the node of the DLL is as
struct Node {
	int data;
	struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
//Return the head after insertion
Node* sortedInsert(Node * head, int x){
    Node *nNode=new Node{x};
    if(!head){
        return nNode;
    }
    
    
    Node *cHead=head;
    while(cHead){
        if(cHead->data>=x){
            if(cHead==head){
                nNode->next=cHead;
                cHead->prev=nNode;
                head=nNode;
            }else{
                nNode->next=cHead;
                nNode->prev=cHead->prev;
                nNode->prev->next=nNode;
                nNode->next->prev=nNode;
            }
            break;
        }
        if(!cHead->next){//when attached to last node
            cHead->next=nNode;
            nNode->prev=cHead;
            break;
        }
        cHead=cHead->next;
    }
    return head;
}