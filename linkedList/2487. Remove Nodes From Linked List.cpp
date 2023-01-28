/*
You are given the head of a linked list.

Remove every node which has a node with a strictly greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
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
//     ListNode* removeNodes(ListNode* head) {
//         stack<ListNode*> stck;

//         while(head){
//             if(stck.empty()){
//                 stck.push(head);
//                 head=head->next;
//             }else if(stck.top()->val<head->val){
//                 delete stck.top();
//                 stck.pop();
//             }else{
//                 stck.push(head);
//                 head=head->next;
//             }
//         }
//         if(stck.empty()){
//             return nullptr;
//         }
//         ListNode *newHead=stck.top();
//         newHead->next=nullptr;
//         stck.pop();
//         while(!stck.empty()){
//             stck.top()->next=newHead;
//             newHead=stck.top();
//             stck.pop();
//         }

//         return newHead;
//     }
// };
////////////////////////////////
class Solution {
private:
    ListNode* reverse(ListNode *head){
        if(!head){
            return nullptr;
        }
        ListNode *newHead=head;
        head=head->next;
        newHead->next=nullptr;
        while(head){
            ListNode *tmp=head;
            head=head->next;
            tmp->next=newHead;
            newHead=tmp;
        }
        return newHead;
    }
    void printList(ListNode *head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        // printList(head);
        ListNode *temp=head;
        while(temp->next){
            if(temp->next->val<temp->val){
                ListNode *t=temp->next->next;
                    delete temp->next;
                    temp->next=t;
            }else{
                temp=temp->next;
            }
        }
        return reverse(head);
    }
};