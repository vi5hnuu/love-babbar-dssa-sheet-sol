/*
Given a singly linked list: A0→A1→...→An-2→An-1, reorder it to: A0→An-1→A1→An-2→A2→An-3→...
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the node's values.

Example 1:

Input:
LinkedList: 1->2->3
Output: 1 3 2
Explanation:
Here n=3, so the correct
order is A0→A2→A1
Example 2:

Input:
Explanation: 1->7->3->4
Output: 1 4 7 3
Explanation:
Here n=4, so the correct
order is A0→A3→A1→A2
Your Task:
The task is to complete the function reorderList() which should reorder the list as required. The reorder list is automatically printed by the driver's code.

Note: Try to solve without using any auxilliary space.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 5*105
0 <= A[ i ] <= 105
*/


/*
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
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int lenLL(Node *head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    Node* reverseLL(Node *head){
        if(!head){
            return NULL;
        }
        Node *nHead=head;
        head=head->next;
        nHead->next=NULL;
        while(head){
            Node *tmp=head;
            head=head->next;
            tmp->next=nHead;
            nHead=tmp;
        }
        return nHead;
    }
    void printLL(Node *head){
        while(head){
            cout<<(head->data)<<" ";
            head=head->next;
        }
    }
public:
    void reorderList(Node* head) {//1->7->3->4
        if(!head || !head->next){
            return;
        }
        int len=lenLL(head);
        int skip=ceil(len*1.0/2);
        
        Node *cpHead=head;
        while(cpHead && skip>1){//1->7->
            cpHead=cpHead->next;
            skip--;
        }
        
        Node *rest=cpHead->next;//head=>1->7->NULL
        cpHead->next=NULL;
        // printLL(head);cout<<endl;
        rest=reverseLL(rest);//4->3->NULL
        // printLL(rest);cout<<endl;
        ////////////
        Node *temp=head;
        
        //merge rest into head list.....
        while(rest){
            Node *rt=temp->next;
            temp->next=rest;
            rest=rest->next;
            temp->next->next=rt;
            temp=rt;
        }
    }
};
