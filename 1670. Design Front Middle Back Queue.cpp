// Design a queue that supports push and pop operations in the front, middle, and back.

// Implement the FrontMiddleBack class:

// FrontMiddleBack() Initializes the queue.
// void pushFront(int val) Adds val to the front of the queue.
// void pushMiddle(int val) Adds val to the middle of the queue.
// void pushBack(int val) Adds val to the back of the queue.
// int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
// int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
// int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
// Notice that when there are two middle position choices, the operation is performed on the frontmost middle position choice. For example:

// Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
// Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
 

// Example 1:

// Input:
// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
// [[], [1], [2], [3], [4], [], [], [], [], []]
// Output:
// [null, null, null, null, null, 1, 3, 4, 2, -1]

// Explanation:
// FrontMiddleBackQueue q = new FrontMiddleBackQueue();
// q.pushFront(1);   // [1]
// q.pushBack(2);    // [1, 2]
// q.pushMiddle(3);  // [1, 3, 2]
// q.pushMiddle(4);  // [1, 4, 3, 2]
// q.popFront();     // return 1 -> [4, 3, 2]
// q.popMiddle();    // return 3 -> [4, 2]
// q.popMiddle();    // return 4 -> [2]
// q.popBack();      // return 2 -> []
// q.popFront();     // return -1 -> [] (The queue is empty)
 

// Constraints:

// 1 <= val <= 109
// At most 1000 calls will be made to pushFront, pushMiddle, pushBack, popFront, popMiddle, and popBack.


/*
class FrontMiddleBackQueue {
    queue<int> q1;
    queue<int> q2;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {//O(n)
        //can be refactored the duplicate code
        if(!q1.empty()){
            q2.push(val);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }else{
            q1.push(val);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    
    void pushMiddle(int val) {//o(n)
        if(!q1.empty()){
            int sz=q1.size();
            for(int i=0;i<sz/2;i++){
                q2.push(q1.front());
                q1.pop();
            }
            q2.push(val);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }else{
           int sz=q2.size();
            for(int i=0;i<sz/2;i++){
                q1.push(q2.front());
                q2.pop();
            }
            q1.push(val);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            } 
        }
    }
    
    void pushBack(int val) {//O(1)
        if(!q1.empty()){
            q1.push(val);
        }else{
            q2.push(val);
        }
    }
    
    int popFront() {//O(1)
        int ele=-1;
        if(!q1.empty()){
            ele=q1.front();
            q1.pop();
        }
        else if(!q2.empty()){
            ele=q2.front();
            q2.pop();
        }
        return ele;
    }
    
    int popMiddle() {//O(n)
       int ele=-1;
        if(!q1.empty()){
            int sz=q1.size();
            int to=ceil(sz*1.0/2)-1;
            for(int i=0;i<to;i++){
                q2.push(q1.front());
                q1.pop();
            }
            ele=q1.front();
            q1.pop();
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }else if(!q2.empty()){
           int sz=q2.size();
            int to=ceil(sz*1.0/2)-1;
            for(int i=0;i<to;i++){
                q1.push(q2.front());
                q2.pop();
            }
            ele=q2.front();
            q2.pop();
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        return ele; 
    }
    
    int popBack() {//O(n)
        int ele=-1;
        if(!q1.empty()){
            int sz=q1.size();
            for(int i=0;i<sz-1;i++){
                q2.push(q1.front());
                q1.pop();
            }
            ele=q1.front();
            q1.pop();
        }else if(!q2.empty()){
           int sz=q2.size();
            for(int i=0;i<sz-1;i++){
                q1.push(q2.front());
                q2.pop();
            }
            ele=q2.front();
            q2.pop(); 
        }
        return ele;
    }
};
*/

    
class FrontMiddleBackQueue {
    deque<int> q1;
    public:
    FrontMiddleBackQueue() {
        
    }
    void pushFront(int val) {//O(1) amortized
       q1.push_front(val);
    }
    
    void pushMiddle(int val) {//o(n)
        if(!q1.empty()){
            int sz=q1.size();
            int rep=sz/2;
            while(rep>0){
                q1.push_back(q1.front());
                q1.pop_front();
                rep--;
            }
            q1.push_front(val);
            rep=sz/2;
            while(rep>0){
                q1.push_front(q1.back());
                q1.pop_back();
                rep--;
            }
        }else{
            q1.push_back(val);
        }
    }
    
    void pushBack(int val) {//O(1)
        q1.push_back(val);
    }
    
    int popFront() {//O(1)
        int ele=-1;
        if(!q1.empty()){
            ele=q1.front();
            q1.pop_front();
        }
        return ele;
    }
    
    int popMiddle() {//O(n)
       int ele=-1;
        if(!q1.empty()){
            int sz=q1.size();
            int to=ceil(sz*1.0/2)-1;
            int rep=to;
            while(rep>0){
                q1.push_back(q1.front());
                q1.pop_front();
                rep--;
            }
            ele=q1.front();
            q1.pop_front();
            rep=to;
            while(rep>0){
                q1.push_front(q1.back());
                q1.pop_back();
                rep--;
            }
        }
        return ele; 
    }
    
    int popBack() {//O(1) amortized
        int ele=-1;
        if(!q1.empty()){
            ele=q1.back();
            q1.pop_back();
        }
        return ele;
    }
};
