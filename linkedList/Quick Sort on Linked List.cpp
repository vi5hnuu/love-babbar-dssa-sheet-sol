/*
Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

Input:
In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set *headRef to head of resultant linked list.

User Task:
The task is to complete the function quickSort() which should set the *headRef to head of the resultant linked list.

Constraints:
1<=T<=100
1<=N<=200

Note: If you use "Test" or "Expected Output Button" use below example format

Example:
Input:
2
3
1 6 2
4
1 9 3 8

Output:
1 2 6
1 3 8 9

Explanation:
Testcase 1: After sorting the nodes, we have 1, 2 and 6.
Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.
*/


/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */



/*

ls_p    p   gt_p
NULL    Y   Y
Y       Y   NULL
NULL    Y   NULL
*/

pair<node*,node*> joinLL(pair<node*,node*> &l,pair<node*,node*> &m,pair<node*,node*> &r){
    /*
    -> m will always have valid first and second
    */
    if(l.first){
        l.second->next=m.first;
        m.second->next=r.first;
        if(r.first){
            return {l.first,r.second};
        }else{
            return {l.first,m.second};
        }
    }else{
       m.second->next=r.first;
       if(r.first){
            return {m.first,r.second};
        }else{
            return {m.first,m.second};
        }
    }
}
pair<node*,node*> quickSort(node *head) {
    if(!head || !head->next){//min 2 element required
        return {head,head};
    }
    //assuming head is pivot
    int pivot=head->data;
    node *ls_p=NULL,*ls_pt=NULL;
    node *gt_p=NULL,*gt_pt=NULL;
    node *eq_p=NULL,*eq_pt=NULL;
    while(head){
        node *tmp=head;
        head=head->next;
        
        if(tmp->data==pivot){
            if(!eq_p){
               eq_p=eq_pt=tmp;
            }else{
                eq_pt->next=tmp;
                eq_pt=tmp;
            }
        }else if(tmp->data<pivot){
            if(!ls_p){
               ls_p=ls_pt=tmp;
            }else{
                ls_pt->next=tmp;
                ls_pt=tmp;
            }
        }else{
            if(!gt_p){
               gt_p=gt_pt=tmp;
            }else{
                gt_pt->next=tmp;
                gt_pt=tmp;
            }
        }
    }
    if(ls_pt)ls_pt->next=NULL;
    if(gt_pt)gt_pt->next=NULL;
    if(eq_pt)eq_pt->next=NULL;
    
    auto pr_l=quickSort(ls_p);
    auto pr_r=quickSort(gt_p);
    pair<node*,node*> pivotBound={eq_p,eq_pt};
    
    return joinLL(pr_l,pivotBound,pr_r);
}
void quickSort(struct node **headRef) {
   auto p=quickSort(*headRef);
   *headRef=p.first;
}