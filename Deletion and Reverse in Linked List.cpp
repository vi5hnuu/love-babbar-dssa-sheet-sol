/*
Given a Circular Linked List of size N. The task is to delete the given node (excluding the first and last node) in the circular linked list and then print the reverse of the circular linked list.

 

Example 1:


Input:
5
2 5 7 8 10
8

Output:
10 7 5 2
Explanation: 
After deleting 8 from the given circular linked 
list, it has elements as 2, 5, 7, 10. Now, 
reversing this list will result in 10, 7, 5, 2.
 

Example 2:

Input:
4
1 7 8 10
8

Output:
10 7 1

Explanation:
After deleting 8 from the given circular linked 
list, it has elements as 1, 7,10. Now, reversing 
this list will result in 10, 7, 1.
 

Your Task:
You don't need to read, input, or print anything. Your task is to complete the function deleteNode( ), which takes Node head, and integer key as input parameters, and delete the node with data key. Also Complete function reverse() which reverses the linked list.

 

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= data <= 100
*/


/* structure for a node 
struct Node
{
	int data;
	struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key){
    Node *hd=*head;
    while(hd->next->data!=key){
        hd=hd->next;
    }
    Node *dl=hd->next;
    hd->next=dl->next;
    delete dl;
}

/* Function to reverse the linked list */
 void reverse(struct Node **head){
     //break cycle
     Node *hd=(*head)->next;
     (*head)->next=NULL;
     ////////////////////
     Node *nHead=hd;
     Node *nTail=hd;
     hd=hd->next;
     while(hd){
         Node *tmp=hd;
         hd=hd->next;
         tmp->next=nHead;
         nHead=tmp;
     }
     nTail->next=nHead;
     *head=nHead->next;
}