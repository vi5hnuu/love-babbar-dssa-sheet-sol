/*
Given two linked lists that represent two large positive numbers. The task is to subtract the given two numbers represented by the linked list. Subtract the smaller from the larger one.

Example 1:

Input:
L1 = 1->0->0
L2 = 1->2
Output: 8 8
Explanation:  12 subtracted from 100
gives us 88 as result.

Your Task:
The task is to complete the function subLinkedList() which should subtract the numbers represented by the linked list and return the head of the linked list representing the result.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Length of the Linked List <= 10000
*/


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method
Node *reverseLL(Node *head){
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

int ll2Asc(Node *l1,Node *l2){
    /*
    return -> 0 -> both same
              1 -> 1st bigger
              2 -> 2nd bigger
              
    assume both ll are of same length.
        -> if same digits->skip in both
            ->if both ll ends at same time -> return 0 (both num are same)
        ->if num1!=num2 make decision which one is bigger ll and traverse whole ll
            -> if both ll ends at same time -> decision was correct
            -> l1 ends earlier -> l2 is bigger -> swap with l1
            -> l2 ends earlier -> l1 is bigger -> swap with l2
    */
    while(l1 && l2 && (l1->data==l2->data)){
        l1=l1->next;
        l2=l2->next;
    }
    if(!l1 && !l2){
        return 0;
    }else if(!l1){
        return 2;
    }else if(!l2){
        return 1;
    }
    bool firstbigger= l1->data>l2->data;
    while(l1 && l2){
        l1=l1->next;
        l2=l2->next;
    }
    if(!l1 && !l2){
        return firstbigger ? 1 : 2;
    }
    return l1 ?  1 : 2;
}
Node *trimLeadingZero(Node *ll){
    if(!ll){
        return NULL;
    }
    while(ll && ll->data==0){
        Node *tmp=ll;
        ll=ll->next;
        delete tmp;
    }
    return ll;
}

Node *subtractLL(Node *from,Node *val){
    //from is always bigger than val
    /*
    9 8 7 6 5 4 3 2 1(head[from])
            5 6 7 8 9
    -----------------
    9 8 7 5 9 7 5 3 2
    -----------------
    */
    Node *res=NULL;
    bool borrow=false;
    while(from && val){
        if(borrow){
            if(from->data==0){
                from->data=10;//borrow from left val
            }else{
                borrow=false;
            }
            //release borrow
           from->data--;//clear cur borrow
        }
        
        if((from->data-val->data)<0){//we need borrow
            int calcVal=10+from->data-val->data;
            borrow=true;
            Node *t= new Node(calcVal);
            t->next=res;
            res=t;
        }else{//no need of borrow
            Node *t= new Node(from->data-val->data);
            t->next=res;
            res=t;
        }
        from=from->next;
        val=val->next;
    }
    while(from){
        if(borrow){
            if(from->data==0){
                from->data=10;//borrow from left val [0+10(borrow from left)]
            }else{
                borrow=false;
            }
            //release borrow
           from->data--;//clear cur borrow
        }
        Node *t=new Node(from->data);
        from=from->next;
        t->next=res;
        res=t;
    }
    return res;
}
Node* subLinkedList(Node* l1, Node* l2){
    l1=trimLeadingZero(l1);
    l2=trimLeadingZero(l2);
    
    int ans=ll2Asc(l1,l2);
    if(ans==0){
        // cout<<"Both same.\n";
        return new Node(0);
    }
    if(ans==2){
        // cout<<"second bigger.\n";
        swap(l1,l2);
    }else{
        // cout<<"first bigger.\n";
    }
    Node *nl1=reverseLL(l1);
    Node *nl2=reverseLL(l2);
    Node *rres = subtractLL(nl1,nl2);//reverse result
    return trimLeadingZero(rres);
}


/*
16
0 2 5 2 6 9 6 7 2 4 5 0 2 1 7 5
15
7 0 4 7 9 1 4 5 6 0 8 9 0 0 6
*/

