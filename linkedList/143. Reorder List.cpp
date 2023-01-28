/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
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
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if(!head || !head->next || !head->next->next)
//             return;
//         int size=0;
//         ListNode *temp=head;
//         stack<ListNode*> nodes;
//         while(temp){
//             size++;
//             nodes.push(temp);
//             temp=temp->next;
//         }
//         temp=head;
//         ListNode *prev=NULL;
//         for(int i=0;i<size/2;i++){
//             ListNode *rest=temp->next;
//             temp->next=nodes.top();
//             nodes.top()->next=rest;
//             prev=nodes.top();
//             temp=nodes.top()->next;
//             nodes.pop();
//         }
//         temp->next=NULL;
//     }
// };
//////////////////////
class Solution {
private:
    int lenLL(ListNode *head){
        if(!head){
            return 0;
        }
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* revLL(ListNode *head){
        if(!head){
            return NULL;
        }
        ListNode *nh{};
        while(head){
            ListNode *tmp=head;
            head=head->next;
            tmp->next=nh;
            nh=tmp;
        }
        return nh;
    }
    void printLL(ListNode *head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return;
        }
        
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //rev half
        ListNode *hlf=revLL(slow->next);
        slow->next=NULL;
        // printLL(hlf);
        //merge
        ListNode *newHead=head;
        ListNode *tail=newHead;
        head=head->next;

        int count=0;
        while(head||hlf){
            if(count&1){
                tail->next=head;
                head=head->next;
            }else{
                tail->next=hlf;
                hlf=hlf->next;
            }
            tail=tail->next;
            count++;
        }
    }
};
















