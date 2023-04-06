/*
Given a singly linked list, remove all the nodes which have a greater value on their right side.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Your Task:
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ size of linked list ≤ 1000
1 ≤ element of linked list ≤ 1000
Note: Try to solve the problem without using any extra space.
*/


// class Solution
// {
//     public:
//     Node *compute(Node *head){
//       if(!head){
//           return NULL;
//       }
//       stack<Node*> nodes;
//       Node *nHead=NULL;
//       while(head){
//           if(nodes.empty()){
//               nHead=head;
//               nodes.push(head);
//               head=head->next;
//           }else if(head->data>nodes.top()->data){
//               Node *del=nodes.top();
//               nodes.pop();
//               if(!nodes.empty()){
//                   nodes.top()->next=head;
//               }
//               delete del;
//           }else{
//               nodes.push(head);
//               head=head->next;
//           }
//       }
//       return nHead;
//     }
// };
//////////////////////////////
// class Solution
// {
//     public:
//     Node *compute(Node *head){
//       if(!head){
//           return NULL;
//       }
//       Node *temp=compute(head->next);
//       if(!temp){
//           return head;
//       }
//       if(head->data<temp->data){
//           delete head;
//           return temp;
//       }
//       head->next=temp;
//       return head;
//     }
    
// };
//////////////////////////
class Solution{
private:
    Node* reverseLL(Node *head){
        if(!head){
            return NULL;
        }
        Node *nHead=head;
        head=head->next;
        nHead->next=NULL;
        while(head){
            Node *tmp=head;
            head=head->next;
            tmp->next=nHead;
            nHead=tmp;
        }
        return nHead;
    }
    void refactorLL(Node *head){
        if(!head){
            return;
        }
        Node *nHead=head;
        while(nHead && nHead->next){
            if(nHead->next->data<nHead->data){
                Node *del=nHead->next;
                nHead->next=del->next;
                delete del;
            }else{
                nHead=nHead->next;
            }
        }
    }
    void printLL(Node *head){
        while(head){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
public:
    Node *compute(Node *head){
       if(!head){
           return NULL;
       }
      head=reverseLL(head);
      //printLL(head);cout<<endl;
      refactorLL(head);
      return reverseLL(head);
    }
    
};