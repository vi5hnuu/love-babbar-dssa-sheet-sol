/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode *head=NULL;
//         ListNode *temp=NULL;

        
      
        
//         while(true){
//             int min=INT_MAX;
//             for(int i=0;i<lists.size();i++){
//                 if(lists[i]!=NULL && lists[i]->val<min){
//                     min=lists[i]->val;
//                 }
//             }
//             for(int i=0;i<lists.size();i++){
//                 if(lists[i]!=NULL && lists[i]->val==min){
//                     if(head==NULL){
//                         head=lists[i];
//                         lists[i]=lists[i]->next;
//                         head->next=NULL;
//                         temp=head;
//                     }else{
//                     temp->next=lists[i];
//                     lists[i]=lists[i]->next;
//                     temp=temp->next;
//                         temp->next=NULL;
//                     }
//                 }
//             }
            
//             int empty_count=0;
//             for(int i=0;i<lists.size();i++){
//                 if(lists[i]==NULL)
//                     empty_count++;
//             }
//             if(empty_count==lists.size())
//                 break;
//             else
//                 empty_count=0;
//         }
//         return head;
//     }
// };
/////////////////////////////////////////////////////////
class Comparator{
public:
    bool operator()(ListNode *node1,ListNode *node2){
        return node1->val>node2->val;
    }
}nc;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL;
        ListNode *temp=NULL;

        priority_queue<ListNode*,vector<ListNode*>,decltype(nc)> pq;
        for(ListNode *list:lists){
            if(list){
                pq.push(list);
            }
        }
        while(!pq.empty()){
            ListNode *lst=pq.top();
            pq.pop();
            if(!head){
                head=lst;
                lst=lst->next;
                if(lst){
                    pq.push(lst);
                }
                head->next=nullptr;
                temp=head;
            }else{
                temp->next=lst;
                temp=temp->next;
                lst=lst->next;
                if(lst){
                    pq.push(lst);
                }
            }
        }

        return head;  
    }
};