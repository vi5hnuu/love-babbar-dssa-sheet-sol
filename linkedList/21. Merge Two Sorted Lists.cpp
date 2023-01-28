/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode *head=NULL;
//         ListNode *temp=NULL;
//         if(list1==NULL)
//             return list2;
//         if(list2==NULL)
//             return list1;
//         else{  
//             while(true){
//                 int min=INT_MAX;
//                 if(list1!=NULL && list1->val<min)
//                     min=list1->val;
//                 if(list2!=NULL && list2->val<min)
//                     min=list2->val;  
//                 if(head==NULL){
//                     head=list1;
//                     temp=head;
//                     list1=list1->next;
//                     head->next=NULL;
//                 }
//                 else{
//                     if(list1!=NULL && list1->val==min){
//                         temp->next=list1;
//                         list1=list1->next;
//                         temp=temp->next;
//                         temp->next=NULL;
//                     }
//                     if(list2!=NULL && list2->val==min){
//                         temp->next=list1;
//                         list2=list2->next;
//                         temp=temp->next;
//                         temp->next=NULL;
//                     }
//                 }
//                 if(list1==NULL && list2==NULL)
//                     break;
//                 }
//             }
//             return head;
//     }
// };

//////////////////////////
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l1=list1;
        ListNode *l2=list2;
        ListNode *head=NULL;
        ListNode *temp=NULL;
        if(l1==NULL)
            return list2;
        if(l2==NULL)
            return list1;
        
        if(l1->val>l2->val)
            swap(l1,l2);
        head=l1;
        temp=head;
        l1=l1->next;
        head->next=NULL;
        
        while(l1 && l2){
            if(l1->val<l2->val)
            {
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
                temp->next=NULL;
                
            }
            else if(l1->val>l2->val)
            {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
                temp->next=NULL;
            }
            else{
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
                temp->next=NULL;
                
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
                temp->next=NULL;
            }
        }
        while(l1){
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
            temp->next=NULL;
        }
        while(l2){
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
            temp->next=NULL;
        }
        return head;
    }
};