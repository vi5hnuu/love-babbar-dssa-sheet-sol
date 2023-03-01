/*
Given a linked list and positions m and n. Reverse the linked list from position m to n.

Example 1:

Input :
N = 10
Linked List = 1->7->5->3->9->8->10
                      ->2->2->5->NULL
m = 1, n = 8
Output : 2 10 8 9 3 5 7 1 2 5 
Explanation :
The nodes from position 1 to 8 
are reversed, resulting in 
2 10 8 9 3 5 7 1 2 5.

Example 2:

Input:
N = 6
Linked List = 1->2->3->4->5->6->NULL
m = 2, n = 4
Output: 1 4 3 2 5 6
Explanation:
Nodes from position 2 to 4 
are reversed resulting in
1 4 3 2 5 6.
Your task :
You don't need to read input or print anything. Your task is to complete the function reverseBetween() which takes the head of the linked list and two integers m and n as input and returns the head of the new linked list after reversing the nodes from position m to n.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
 
Constraints:
1<=N<=10^5
*/


/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution{
private:
    
public:
    Node* reverseBetween(Node* head, int m, int n){
        if(m==n){
            return head;
        }
        n--;m--;//0 based position
        
        int diff=n-m;
        Node *cHead=head;//begin from where to reverse
        Node *prev=NULL;//after m skip -> prev is end of that list
        while(cHead && m>0){
            prev=cHead;
            cHead=cHead->next;
            m--;
        }
        
        Node *rUptoM=NULL,*tail=NULL;//reverse
        while(cHead && diff>=0){
            Node *nxt=cHead->next;
            if(!rUptoM){
                rUptoM=tail=cHead;
                rUptoM->next=NULL;
            }else{
                cHead->next=rUptoM;
                rUptoM=cHead;
            }
            cHead=nxt;
            diff--;
        }
        if(prev){//means m!=0
            prev->next=rUptoM;
            tail->next=cHead;
            return head;
        }else{//m==0
            tail->next=cHead;
            return rUptoM;
        }
    }
};