/*
Given a singly linked list of 0s and 1s, the task is to find its decimal equivalent. Decimal Value of an empty linked list is considered as 0.

Since the answer can be very large, answer modulo 1000000007 should be printed.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains 

Output:
The function should return should decimal equivalent modulo 1000000007.

User Task:
The task is to complete the function decimalValue() which should find the decimal value of the given binary value in the linked list.

Constraints:
1 <= T <= 200
0 <= N <= 100
Data of Node is either 0 or 1

Example:
Input:
2
3
0 1 1    
4
1 1 1 0

Output:
3
14

Explanation:
Testcase 1: 1*20 + 1*21 + 0*22 =  1 + 2 + 0 = 3.
*/


/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

// Should return decimal equivalent modulo 1000000007 of binary linked list 
int lenLinkList(Node *head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
void printList(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
long long unsigned getPow2(int n){
    //64 bits only for shifting....we n can be 100
    //one sol is directly use pow function or use bit manip which is best...
    long long unsigned curVal=((long long unsigned)1<<(n/2))%1000000007;
    curVal=(curVal*curVal)%1000000007;
    if(n&1){
        curVal=(curVal*2)%1000000007;
    }
    return curVal;
}
long long unsigned int decimalValue(Node *head){
    // printList(head);
    long long unsigned ans=0L;
    int pow=lenLinkList(head);
    while(head){
        pow--;
        
        ans=(ans+head->data*getPow2(pow))%1000000007;
        head=head->next;
    }
    return ans%1000000007;
}
