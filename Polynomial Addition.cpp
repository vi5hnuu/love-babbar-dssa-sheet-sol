/*
Given two polynomial numbers represented by a linked list. The task is to complete the function addPolynomial() that adds these lists meaning adds the coefficients who have the same variable powers.
Note:  Given polynomials are sorted in decreasing order of power.

Example 1:

Input:
LinkedList1:  (1,x2) 
LinkedList2:  (1,x3)
Output:
1x^3 + 1x^2
Explanation: Since, x2 and x3 both have
different powers as 2 and 3. So, their
coefficient can't be added up.
Example 2:

Input:
LinkedList1:  (1,x3) -> (2,x2)
LinkedList2:  (3,x3) -> (4,x2)
Output:
4x^3 + 6x^2
Explanation: Since, x3 has two different
coefficients as 3 and 1. Adding them up
will lead to 4x3. Also, x2 has two
coefficients as 4 and 2. So, adding them
up will give 6x2.
Your Task:
The task is to complete the function addPolynomial() which should add the polynomial with same powers return the required polynomial in decreasing order of the power in the form of a linked list.
Note: Try to solve the question without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N, M <= 105
1 <= x, y <= 106
*/


/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2){
        Node *head=NULL,*tail=NULL;
        while(p1 && p2){
            int pc1=p1->coeff;
            int pc2=p2->coeff;
            int pow1=p1->pow;
            int pow2=p2->pow;
            
            if(pow1==pow2){
                Node *tmp=new Node(pc1+pc2,pow1);
                if(!head){
                    head=tail=tmp;
                }else{
                    tail->next=tmp;
                    tail=tail->next;
                }
                p1=p1->next;
                p2=p2->next;
            }else if(pow1>pow2){
                Node *tmp=new Node(pc1,pow1);//clone
                if(!head){
                    head=tail=tmp;
                }else{
                    tail->next=tmp;
                    tail=tail->next;
                }
                p1=p1->next;
            }else{
                Node *tmp=new Node(pc2,pow2);
                if(!head){
                    head=tail=tmp;
                }else{
                    tail->next=tmp;
                    tail=tail->next;
                }
                p2=p2->next;
            }
        }
        while(p1){
            tail->next=new Node(p1->coeff,p1->pow);
            tail=tail->next;
            p1=p1->next;
        }
        while(p2){
            tail->next=new Node(p2->coeff,p2->pow);
            tail=tail->next;
            p2=p2->next;
        }
        return head;
    }
};
