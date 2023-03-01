/*
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Example:
Input:
2
8
2 1
9 1 3 5 9 4 10 1
6
6 1
1 2 3 4 5 6 

Output: 
9 1 5 9 10 1
1 2 3 4 5 6

Explanation:
Deleting one node after skipping the M nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains a number of elements in the linked list, and the next M and N respectively space-separated. The last line contains the elements of the linked list.

Output:
The function should not print any output to the stdin/console.

Your Task:
The task is to complete the function linkdelete() which should modify the linked list as required.

Constraints:

size of linked list <= 1000

1 <= N + M <= size of linked list
*/


/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

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
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        while(head){
            int m=M;
            int n=N;
            while(head && m>1){
                head=head->next;
                --m;
            }
            if(!head){
                return;
            }
            while(head->next && n>0){
                Node *nxt=head->next;
                head->next=nxt->next;
                delete nxt;
                n--;
            }
            if(head)
                head=head->next;
        }
    }
};