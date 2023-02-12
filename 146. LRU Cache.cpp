/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/


// class LRUCache {
// private:
//     unordered_map<int,int> mp;
//     deque<pair<int,int>> lru;
//     int cap;
// public:
//     LRUCache(int capacity) {
//         this->cap=capacity;
//     }
//     void popKey(int key){
//         if(lru.empty()){
//             return;
//         }
//         if(lru.front().first==key){
//             lru.pop_front();
//             return;
//         }
//         auto pr=lru.front();
//         lru.pop_front();
//         popKey(key);
//         lru.push_front(pr);
//     }
//     int get(int key) {
//         auto itr=mp.find(key);
//         if(itr!=mp.end()){
//             int val=itr->second;
//             popKey(key);
//             lru.push_front({key,val});
//             return val;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         auto itr=mp.find(key);
//         if(itr==mp.end()){
//             lru.push_front({key,value});
//         }else{
//             popKey(key);
//             lru.push_front({key,value});
//         }
//         mp[key]=value;
//         if(lru.size()>cap){
//             auto pr=lru.back();
//             mp.erase(pr.first);
//             lru.pop_back();
//         }
//     }
// };
///////////////
class Node{//doubly circular ll
public:
    int key;
    int val;
    Node *left;
    Node *right;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        left=right=this;
    }
};
class LRUCache {
private:
    unordered_map<int,Node*> mp;
    Node *root{};
    int cap;
    int size{};
public:
    LRUCache(int capacity) {
        this->cap=capacity;
    }
    // void printLru(){
    //     int c=cap;
    //     while(root && c>0){
    //         cout<<root->key<<" "<<root->val<<endl;
    //         root=root->right;
    //         c--;
    //     }
    // }

    /*
    if not present return -1
    else take node-> join chain -> bring node to front
    */
    int get(int key) {
        auto itr=mp.find(key);
        if(itr==mp.end()){
            return -1;
        }
        Node *node=itr->second;
        if(root!=node){
            Node *lft=node->left;
            lft->right=node->right;
            node->right->left=lft;
            addFront(node);
        }
        return root->val;
    }
    
    /*
    if not present add to front -> if size>cap -> delete last
    else take node -> join chain -> bring it to front.
    */
    void put(int key, int value) {
        auto itr=mp.find(key);
        if(itr==mp.end()){
            Node *temp=new Node{key,value};
            mp[key]=temp;
            size++;
            addFront(temp);
        }else{
            Node *node=itr->second;
            node->val=value;
            if(root!=node){
                Node *lft=node->left;
                lft->right=node->right;
                node->right->left=lft;
                addFront(node);
            } 
        }
        if(size>cap){
            deleteLast();
            size--;
        }
    }
    void addFront(Node *node){
            if(!root){
                root=node;
                return;
            }
            Node *lft=root->left;
            lft->right=node;
            node->left=lft;
            node->right=root;
            root->left=node;
            root=node;
    }
    void deleteLast(){
        if(root==root->left){
            mp.erase(root->key);
            root=NULL;
            delete root;
            return;
        }
        Node *del=root->left;
        del->left->right=root;
        root->left=del->left;
        mp.erase(del->key);
        delete del;
    }
};
////////////////////////////
//////////////////////////////////////
class LRUCache {
private:
    unordered_map<int,pair<int,list<int>::iterator>> cache; //key with its iterator,val
    list<int> order;//key
    int cap;
    int size{};
public:
    LRUCache(int capacity) {
        this->cap=capacity;
    }

    int get(int key) {
        auto itr=cache.find(key);
        if(itr==cache.end()){
            return -1;
        }
        int val=itr->second.first;
        order.erase(itr->second.second);
        order.push_front(key);
        cache[key]={val,order.begin()};
        return val;
    }
    
    /*
    if not present add to front -> if size>cap -> delete last
    else take node -> join chain -> bring it to front.
    */
    void put(int key, int value) {
        auto itr=cache.find(key);
        if(itr==cache.end()){
            order.push_front(key);
            cache[key]={value,order.begin()};
            size++;
        }else{
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key]={value,order.begin()};
        }
        if(size>cap){
            cache.erase(order.back());
            order.pop_back();
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */