/*
Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

Example 1:

Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8
Your Task:
You task is to complete the function findIntersection() which takes the heads of the 2 input linked lists as parameter and returns the head of intersection list. Returned list will be automatically printed by driver code.
Note: The order of nodes in this list should be same as the order in which those particular nodes appear in input list 1.

Constraints:
1 <= n,m <= 104

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)
*/


/* structure of list node:
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
public:
    Node* findIntersection(Node* head1, Node* head2){
        if(!head1 || !head2){
            return NULL;
        }
        unordered_set<int> st;
        while(head2){
            st.insert(head2->data);
            head2=head2->next;
        }
        Node *nhead=NULL,*nTail=NULL;
        while(head1){
            if(st.count(head1->data)){
                if(!nhead){
                    nhead=nTail=head1;
                }else{
                    nTail->next=head1;
                    nTail=head1;
                }
            }
            head1=head1->next;
        }
        nTail->next=NULL;
        return nhead;
    }
};