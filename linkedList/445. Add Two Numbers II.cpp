/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
*/


// class Solution {
// private:
//     ListNode* revList(ListNode *head){
//         if(!head){
//             return NULL;
//         }
//         ListNode *nHead=head;
//         head=head->next;
//         nHead->next=NULL;
//         while(head){
//             ListNode *tmp=head->next;
//             head->next=nHead;
//             nHead=head;
//             head=tmp;
//         }
//         return nHead;
//     }
// public:
//      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         l1=revList(l1);
//         l2=revList(l2);
//         int sum_adj=l1->val+l2->val;
//         int carry=sum_adj/10;
//         //cout<<endl<<"Carry :"<<carry<<endl;
//         struct ListNode *head=new ListNode(sum_adj%10);
//         struct ListNode *p=head;
        
//             l1=l1->next;
//             l2=l2->next;
            
//         while(l1!=NULL && l2!=NULL){    
//             sum_adj=l1->val+l2->val+carry;
//             carry=sum_adj/10;
//             p->next=new ListNode(sum_adj%10);
//             p=p->next;
//             l1=l1->next;
//             l2=l2->next;
//         }
//     //if(l1!=NULL){
//         while(l1!=NULL){
//             sum_adj=l1->val+carry;
//             carry=sum_adj/10;
//             p->next=new ListNode(sum_adj%10);
//             p=p->next;
        
//             l1=l1->next;
//         }
//     //}
//         //if(l2!=NULL){
//         while(l2!=NULL){
//             sum_adj=l2->val+carry;
//             carry=sum_adj/10;
//             p->next=new ListNode(sum_adj%10);
//             p=p->next;
//             l2=l2->next;
//         }
//     //}
//         if(carry!=0){
//             p->next=new ListNode(carry);
//         }
//     return revList(head);
//     }
// };
///////////////////////////////////////
class Solution {
private:
    int lenghtLL(ListNode *head){
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
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }else if(!l2){
            return l1;
        }

        int len1=lenghtLL(l1);
        int len2=lenghtLL(l2);
        
        ListNode *nhead=NULL;
        while(l1 || l2){
            int n1=0;
            int n2=0;
            if(len1<=len2){
                n2=l2->val;
                l2=l2->next;
                len2--;
            }
            if(len2+1<=len1){
                n1=l1->val;
                l1=l1->next;
                len1--;
            }
            ListNode *temp=new ListNode(n1+n2);
            temp->next=nhead;
            nhead=temp;
        }
        /*
        7   2   4   3
            9   6   4
        
        rev add : 7 10  11   7
        nomalize with rev again : 7 0 2 8-> 8 2 0 7
        */
        //normalizing
        ListNode *res=NULL;
        int carry=0;
        while(nhead){
            int sum=carry+nhead->val;
            carry=sum/10;
            sum=sum%10;
            nhead->val=sum;
            
            ListNode *tmp=nhead->next;
            nhead->next=res;
            res=nhead;
            nhead=tmp;
        }
        if(carry>0){
            ListNode *tmp=new ListNode(carry);
            tmp->next=res;
            res=tmp;
        }
        return res;
    }
};