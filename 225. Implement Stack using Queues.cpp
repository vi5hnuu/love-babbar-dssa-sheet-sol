/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 

Follow-up: Can you implement the stack using only one queue?
*/

class MyStack {
    private:
    queue<int> q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
     if(!q1.empty()){
         q1.push(x);
     }else{
         q2.push(x);
     }   
    }
    
    int pop() {
        if(!q1.empty()){
            int sz=q1.size();
            while(sz>1){
                sz--;
                q2.push(q1.front());
                q1.pop();
            }
            int ans=q1.front();
            q1.pop();
            return ans;
        }else{
              int sz=q2.size();
            while(sz>1){
                sz--;
                q1.push(q2.front());
                q2.pop();
            }
            int ans=q2.front();
            q2.pop();
            return ans;
        }
    }
    
    int top() {
        int ans=this->pop();
        if(!q1.empty())
            q1.push(ans);
        else
            q2.push(ans);
        return ans;
    }
    
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        else
            return false;
    }
};


/////////////Single queue
class MyStack {
    private:
    queue<int> q;
    int tp;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        tp=x;
    }
    
    int pop() {
        int sz=q.size();
        while(sz-1>0){
            sz--;
            q.push(q.front());
            tp=q.front();
            q.pop();
        }
        int popped=q.front();
        q.pop();
        return popped;
    }
    
    int top() {
       return tp;
    }
    
    bool empty() {
       return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */