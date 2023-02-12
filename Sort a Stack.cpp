/*
PROBLEM STATEMENT
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.
Input Format:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow.

The first line of each test case contains an integer 'N', the number of elements in the stack.

The second line of each test contains 'N' space separated integers.
Output Format:
The only line of output of each test case should contain 'N' space separated integers denoting the stack in a sorted order.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Constraints:
1 <= 'T' <= 100
1 <=  'N' <= 100
1 <= |'V'| <= 10^9

Where |V| denotes the absolute value of any stack element.

Time limit: 1 sec
APPROACH 1
The idea of the solution is very simple. 

First, we will hold all values in a Call Stack until the stack becomes empty.
When the stack becomes empty, insert all held items one by one(from the call stack) in sorted order.
We will do this by using a function sortedInsert() which will sort these elements.
In the sortedInsert() function we will first check if the stack is empty and if the current element is greater than the top element of the stack, if these conditions are met then we push that current element to the stack.
Then we pop the top element of the stack and again recursively call the stack with the remaining elements.
Now we push the earlier top element which we popped in step 5 back into the stack.
Finally, we will print our sorted stack.
Let us understand this with the help of an example.
Consider we have the following stack.
5 <- top of the stack
-2
9
-7
3
First, we will pop all the elements of the stack. After popping, the call stack frame looks like:
5 <- stack frame #1
-2 <- stack frame #2
9 <- stack frame #3
-7 <- stack frame #4
3 <- stack frame #5
Now our stack is empty and sortedInsert() function is called. It inserts 3(from stack frame #5) the bottom of the stack.
3 <- Top of the stack
Now next element i.e. -7 (from stack frame #4) is picked. Since -7 <3, -7 is inserted at the bottom of the stack. Now stack becomes:
3 <- Top of the stack
-7
Now next element i.e. 9 (from stack frame #3) is picked. Since 9 is not smaller than any current value in the stack, it is inserted at the top of the stack. Now stack becomes:
9 <- Top of the stack
3
-7
Now next element i.e. -2 (from stack frame #2) is picked. Since -2 <3, -2 is inserted below 3. Now stack becomes:
9 <- Top of the stack
3
-2
-7
Now the final element i.e. 5  (from stack frame #1) is picked. Since 5 <9, 5 is inserted below 9. Now, stack finally becomes:
9 <- Top of the stack
5
3
-2
-7
*/


#include <bits/stdc++.h> 
using namespace std;

void insertAtRightPlace(stack<int> &stck,int x) {
  if (stck.empty() || stck.top()<x) {
	  stck.push(x);
		return;
  }
  int tmp=stck.top();
  stck.pop();
  insertAtRightPlace(stck,x);
  stck.push(tmp);
}

void sortStack(stack<int> &stck){
  if (stck.empty()) {
	  return;
  }
    int tmp=stck.top();
	stck.pop();
	sortStack(stck);
	insertAtRightPlace(stck,tmp);
}