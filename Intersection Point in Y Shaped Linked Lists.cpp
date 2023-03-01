/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       
Your Task:
You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
Challenge : Try to solve the problem without using any extra space.

 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ N + M ≤ 2*105
-1000 ≤ value ≤ 1000

 
*/


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// class Solution{
// private:
//     int lenLL(Node *head){
//         int len=0;
//         while(head){
//             len++;
//             head=head->next;
//         }
//         return len;
//     }
// public:
//     int intersectPoint(Node* head1, Node* head2){
//         int l1=lenLL(head1);
//         int l2=lenLL(head2);
//         if(l1<l2){
//             swap(head1,head2);
//         }
//         int diff=abs(l1-l2);
//         while(diff>0){
//             head1=head1->next;
//             diff--;
//         }
//         while(head1 && head2){
//             if(head1==head2){
//                 return head1->data;
//             }
//             head1=head1->next;
//             head2=head2->next;
//         }
//         return -1;
//     }
// };
///////////////////////
class Solution{
public:
    int intersectPoint(Node* head1, Node* head2){
        Node *cur1=head1,*cur2=head2;
        bool travel1=true,travel2=true;
        while(travel1 || travel2){
            cur1=cur1->next;
            cur2=cur2->next;
            if(!cur1){
                cur1=head2;
                travel1=false;
            }
            if(!cur2){
                cur2=head1;
                travel2=false;
            }
        }
        while(cur1 && cur2){
            if(cur1==cur2){
                return cur1->data;
            }
           cur1=cur1->next;
            cur2=cur2->next;
        }
        return -1;
    }
};