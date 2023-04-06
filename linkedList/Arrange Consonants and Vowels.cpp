/*
Given a singly linked list of size N containing only English Alphabets. Your task is to complete the function arrangeC&V(), that arranges the consonants and vowel nodes of the list it in such a way that all the vowels nodes come before the consonants while maintaining the order of their arrival.

Input:
The function takes a single argument as input, the reference pointer to the head of the linked list. There will be T test cases and for each test case the function will be called separately.

Output:
For each test case output a single line containing space separated elements of the list.

User Task:
The task is to complete the function arrange() which should arrange the vowels and consonants as required.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
6
a e g h i m
3
q r t

Output:
a e i g h m
q r t

Explanation:
Testcase 1: Vowels like a, e and i are in the front, and consonants like g, h and m are at the end of the list.
*/


bool isVowel(char alpha){
    return alpha=='a' || alpha=='e' || alpha=='i' || alpha=='o' || alpha=='u';
}
Node* arrange(Node *head){
    Node *v=NULL,*vt=NULL;
    Node *c=NULL,*ct=NULL;
    
    while(head){
        Node *tmp=head;
        head=head->next;
        if(isVowel(tmp->data)){
            if(!v){
               v=vt=tmp;
            }else{
                vt->next=tmp;
                vt=tmp;
            }
        }else{
            if(!c){
               c=ct=tmp;
            }else{
                ct->next=tmp;
                ct=tmp;
            }
        }
    }
    if(c) ct->next=NULL;
    if(v){
        vt->next=c;
        return v;
    }
    return c;
}