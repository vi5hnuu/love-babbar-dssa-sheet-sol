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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *odd=NULL,*even=NULL;
        ListNode *oddCur=NULL,*evnCurr=NULL;
        bool turn=true;
        while(head){
            if(turn){
                if(!odd){
                    odd=oddCur=head;
                }else{
                    oddCur->next=head;
                    oddCur=oddCur->next;
                }
            }else{
                if(!even){
                    even=evnCurr=head;
                }else{
                    evnCurr->next=head;
                    evnCurr=evnCurr->next;
                }
            }
            turn=!turn;
            head=head->next;
        }
        oddCur->next=even;
        if(evnCurr)
        evnCurr->next=NULL;
        return odd;
    }
};


// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]