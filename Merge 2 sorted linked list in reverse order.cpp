/*
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in decreasing order.

Input:
First line of input contains number of testcases T. For each testcase, first line of input conatains length of both linked lists N and M respectively. Next two lines contains N and M elements of two linked lists.

Output:
For each testcase, print the merged linked list which is in non-increasing order.

User Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Constraints:
1 <=T<= 50
1 <= N, M <= 1000

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4

Output:
40 20 15 10 5 3 2
4 2 1 1 

Explanation:
Testcase 1: After merging the two lists in decreasing order, we have new lists as 40->20->15->10->5->3->2.
*/


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

Node * mergeResult(Node *node1,Node *node2){
    Node *decrLst=NULL;
    
    while(node1 && node2){
        if(node1->data<=node2->data){
            Node *nxt=node1->next;
            if(!decrLst){
                decrLst=node1;
                decrLst->next=NULL;
            }else{
                node1->next=decrLst;
                decrLst=node1;
            }
            node1=nxt;
        }else{
            Node *nxt=node2->next;
            if(!decrLst){
                decrLst=node2;
                decrLst->next=NULL;
            }else{
                node2->next=decrLst;
                decrLst=node2;
            }
            node2=nxt;
        }
    }
    while(node1){
        Node *tmp=node1->next;
        node1->next=decrLst;
        decrLst=node1;
        node1=tmp;
    }
    while(node2){
        Node *tmp=node2->next;
        node2->next=decrLst;
        decrLst=node2;
        node2=tmp;
    }
    return decrLst;
}