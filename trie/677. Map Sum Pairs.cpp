/*
Design a map that allows you to do the following:

Maps a string key to a given value.
Returns the sum of the values that have a key with a prefix equal to a given string.
Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
 

Example 1:

Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 

Constraints:

1 <= key.length, prefix.length <= 50
key and prefix consist of only lowercase English letters.
1 <= val <= 1000
At most 50 calls will be made to insert and sum.
*/


class MapSum {
    class Node{
        public:
            char character;
            int val{};
            vector<Node*> children{};
            bool eow{};//end of word
            Node(char c){
                this->character=c;
            }
    };
    Node *root{};

    void insert(Node *root,int from,const string &key,int val){
        if(from>=key.length()){
            return;
        }
        bool nodeFound=false;
        for(Node *node:root->children){
            if(node->character==key[from]){
                // cout<<"collide "<<key[from]<<endl;
                if(from==key.length()-1){
                    node->eow=true;
                    node->val=val;
                }
                nodeFound=true;
                insert(node,from+1,key,val);
                break;
            }
        }
        if(!nodeFound){
            Node *rt=root;
            while(from<key.length()){
                Node *tmp=new Node(key[from]);
                // cout<<"Inserting "<<key[from]<<endl;
                if(from==key.length()-1){
                    tmp->eow=true;
                    tmp->val=val;
                }
                rt->children.push_back(tmp);
                rt=tmp;
                from++;
            }
        }
    }
    int collectValsFor(Node *root,int from,const string &prefix,bool pMatched){
        int plen=prefix.length();

        int valsCol=0;
        for(Node *node:root->children){//hello,hallo -> hello
            if(from<plen){
                if(node->character==prefix[from]){
                    if(from==plen-1){
                        pMatched=true;
                    }
                    if(pMatched && node->eow){
                        valsCol+=node->val;
                    }
                    valsCol+=collectValsFor(node,from+1,prefix,pMatched);
                }else{
                   continue;
                }
            }else{
                if(node->eow){
                    valsCol+=node->val;
                }
                valsCol+=collectValsFor(node,from,prefix,pMatched);
            }
        }
        return valsCol;
    }
    void releaseMemory(Node *root){
        if(!root){
            return;
        }
        // cout<<"deleting "<<root->character<<endl;
        for(Node *node:root->children){
            releaseMemory(node);
        }
        delete root;
    }
public:
    MapSum() {
        root=new Node('/');
    }
    ~MapSum(){
        releaseMemory(root);
        root=nullptr;
    }
    
    void insert(string key,int val) {
        insert(root,0,key,val);
    }
    
    int sum(string prefix) {
        return collectValsFor(root,0,prefix,false);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */