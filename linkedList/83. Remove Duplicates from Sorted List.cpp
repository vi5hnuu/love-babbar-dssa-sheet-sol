/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode *temp=head;
//         if(temp==NULL)
//             return NULL;
//         while(temp && temp->next!=NULL){
//             int value=temp->val;
//             while(temp && temp->next && temp->val==temp->next->val){
//                 ListNode *del=temp->next;
//                 temp->next=del->next;
               
//                 delete del;
//             }
//              if(temp)
//                 temp=temp->next;
            
//         }
//         return head;
//     }
// };
/////////////////////////////
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        ListNode *prev=NULL;
        ListNode *hd=head;
        while(head){
            if(prev && head->val==prev->val){
                ListNode *tmp=head->next;
                prev->next=tmp;
                delete head;
                head=tmp;
                continue;
            }
            prev=head;
            head=head->next;
        }
        return hd;
    }
};