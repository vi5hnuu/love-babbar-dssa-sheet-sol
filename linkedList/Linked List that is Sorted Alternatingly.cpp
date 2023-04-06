/*
Given a Linked list of size N, the list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

 

Example 1:

Input:
LinkedList: 1->9->2->8->3->7
Output: 1 2 3 7 8 9
Explanation: After sorting the given
list will be 1-> 2-> 3-> 7-> 8-> 9.
 

Example 2:

Input:
LinkedList: 13->99->21->80->50
Output: 13 21 50 80 99
Explanation: After sorting the given list 
will be 12-> 21-> 50-> 80-> 99.
 

Your Task:
You do not need to read input or print anything. The task is to complete the function sort() which should sort the linked list in non-decreasing order. 

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= Number of nodes <= 100
0 <= Values of the linked list <= 103
*/


Node* joinLL(Node *l1,Node *l2){
    if(!l1){
        return l2;
    }else if(!l2){
        return l1;
    }
    Node *nHead=NULL;
    Node *nTail=NULL;
    while(l1 && l2){
        if(l1->data<=l2->data){
            Node *tmp=l1;
            l1=l1->next;
           if(nHead){
               nTail->next=tmp;
               nTail=tmp;
           } else{
               nHead=nTail=tmp;
           }
        }else{
            Node *tmp=l2;
            l2=l2->next;
           if(nHead){
               nTail->next=tmp;
               nTail=tmp;
           } else{
               nHead=nTail=tmp;
           }
        }
    }
    if(l1){
        nTail->next=l1;
    }else{
        nTail->next=l2;
    }
    return nHead;
}
void sort(Node **head){
    Node *l1=NULL,*l1Tail=NULL;
    Node *l2=NULL;
    
    Node *hd=*head;
    bool l1turn=true;
    while(hd){
        Node *temp=hd;
        hd=hd->next;
        if(l1turn){
            if(l1){
                l1Tail->next=temp;
                l1Tail=temp;
            }else{
               l1=temp;
               l1Tail=temp;
            }
        }else{
            if(l2){
                temp->next=l2;
                l2=temp;
            }else{
               l2=temp;
               l2->next=NULL;
            }
        }
        l1turn=!l1turn;
    }
    l1Tail->next=NULL;
    
    *head=joinLL(l1,l2);
}