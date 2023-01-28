/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int lenOfLinkedList(ListNode *head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* revList(ListNode* head){
        if(!head)
            return NULL;
        
        ListNode *nhead=head;
        ListNode *cur=head;
        head=head->next;
        while(head){
            cur->next=head;
            head=head->next;
            cur=cur->next;
        }
        cur->next=NULL;
        return nhead;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(k==0)
            return head;
        int len=lenOfLinkedList(head);
        int multiple=k/len;
        int remains=k%len;
        if(multiple%2!=0){
            head=revList(head);
        }
        if(remains==0)
            return head;
        int jumps=len-remains-1;
        ListNode *temp=head;
        while(jumps){
            temp=temp->next;
            jumps--;
        }
        ListNode *rest=temp->next;
        ListNode *newHead=rest;
        temp->next=NULL;
        while(rest->next){
            rest=rest->next;
        }
        rest->next=head;
        return newHead;
    }
};