/*
Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even positions node are together.
Assume the first element to be at position 1 followed by second element at position 2 and so on.
Note: You should place all odd positioned nodes first and then the even positioned ones. (considering 1 based indexing). Also, the relative order of odd positioned nodes and even positioned nodes should be maintained.

Example 1:

Input:
LinkedList: 1->2->3->4
Output: 1 3 2 4 
Explanation: 
Odd elements are 1, 3 and even elements are 
2, 4. Hence, resultant linked list is 
1->3->2->4.
Example 2:

Input:
LinkedList: 1->2->3->4->5
Output: 1 3 5 2 4 
Explanation: 
Odd elements are 1, 3, 5 and even elements are
2, 4. Hence, resultant linked list is
1->3->5->2->4.
Your Task:
The task is to complete the function rearrangeEvenOdd() which rearranges the nodes in the linked list as required and doesn't return anything.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ Size of the linked list ≤ 104
0 ≤ value of linked list ≤ 103
*/


/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head){
       if(!head){
           return;
       }
       Node *cpyHead=head;
       Node *odd=NULL,*oddTail=NULL;
       Node *even=NULL,*evenTail=NULL;
       bool oddP=true;
       while(head){
           if(oddP){
               if(odd){
                   oddTail->next=head;
                   oddTail=oddTail->next;
               }else{
                  odd=oddTail=head;
               }
           }else{
               if(even){
                   evenTail->next=head;
                   evenTail=evenTail->next;
               }else{
                  even=evenTail=head; 
               }
           }
           head=head->next;
           oddP=!oddP;
       }
        if(evenTail){
            evenTail->next=NULL;
        }
        oddTail->next=even;
        cpyHead->next=odd->next;
    }
};