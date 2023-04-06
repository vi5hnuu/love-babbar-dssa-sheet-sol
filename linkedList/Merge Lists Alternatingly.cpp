/*
Given two linked lists, your task is to complete the function mergeList() which inserts nodes of second list into first list at alternate positions of first list.

Input:
First line of input contains number of testcases T. For each testcase there will be 4 lines. First line consists of the length of the first linked list, next line contains elements of the linked list inreverse order. Third line contains length of another linked list and next line contains elements of the linked list.

Output:
For each test case first print space separated vales of the first linked list, then in the next line print space separated values of the second linked list.

User Task:
The task is to complete the function mergeList() which should merge the two lists as required.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
2
9 10
6
5 4 3 2 1 6
5
99 88 77 66 55
5
55 44 33 22 11

Output:
10 6 9 12 3 4 5
55 11 66 22 77 33 88 44 99 55

Explanation:
Testcase 1:

The two linked list are 10 -> 9 and 6 -> 1-> 2 -> 3 -> 4 -> 5

After merging the two lists as required, the new list is like: 10-> 6-> 9-> 1-> 2-> 3-> 4-> 5.
*/


/*
structure of the node of the linked list is
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};
*/


void mergeList(struct Node **p, struct Node **q){
    Node *l1=*p;
    Node *l2=*q;
    if(!l2){
        return;
    }
    if(!l1){
        *p=*q;
        *q=NULL;
        return;
    }
    
    Node *tail=NULL;
    while(l1 && l2){
        Node *temp=l2;
        l2=l2->next;
        
        
        Node *l1rest=l1->next;
        l1->next=temp;
        temp->next=l1rest;
        if(!temp->next){
            tail=temp;
        }
        l1=l1rest;
    }
    if(!l1){
        *q=l2;//rest l2
    }
    if(!l2){
        *q=NULL;
    }
    
}