/*
Given a linked list and a value x, partition it such that all nodes less than x come first, then all nodes with value equal to x and finally nodes with value greater than x. The original relative order of the nodes in each of the three partitions should be preserved. The partition must work in-place.
 
Example 1:
Input:
1->4->3->2->5->2->3,
x = 3
Output:
1->2->2->3->3->4->5
Explanation: 
Nodes with value less than 3 come first, 
then equal to 3 and then greater than 3.
Example 2:
Input:
1->4->2->10 
x = 3
Output: 
1->2->4->10
Explanation:
Nodes with value less than 3 come first,
then equal to 3 and then greater than 3.
Your task:
You don't need to read input or print anything. Your task is to complete the function partition() which takes the head of the inked list and an integer x as input, and returns the head of the modified linked list after arranging the values according to x.
 
Expected time complexity : O(n)
Expected Auxiliary Space: O(n)
 
Constraints:
1 <= N <= 105
1 <= k <= 105
*/


/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

Node* partition(Node* head, int x) {
    if(!head){
        return NULL;
    }
    Node *hd[3]{NULL};//less,equal,greater
    Node *tl[3]{NULL};
    
    while(head){
        if(head->data==x){
            if(!hd[1]){
                hd[1]=tl[1]=head;
            }else{
                tl[1]->next=head;
                tl[1]=tl[1]->next;
            }
        }else if(head->data<x){
            if(!hd[0]){
                hd[0]=tl[0]=head;
            }else{
                tl[0]->next=head;
                tl[0]=tl[0]->next;
            }
        }else{
            if(!hd[2]){
                hd[2]=tl[2]=head;
            }else{
                tl[2]->next=head;
                tl[2]=tl[2]->next;
            }
        }
        head=head->next;
    }
    
    if(hd[0]){
        if(hd[1]){
            tl[0]->next=hd[1];
            tl[1]->next=hd[2];
        }else{
            tl[0]->next=hd[2];
        }
    }else{
       if(hd[1]){
            tl[1]->next=hd[2];
        }
    }
    if(tl[2]){
        tl[2]->next=NULL;
    }else if(tl[1]){
        tl[1]->next=NULL;
    }
    return hd[0] ? hd[0] : (hd[1] ? hd[1] : hd[2]);
}