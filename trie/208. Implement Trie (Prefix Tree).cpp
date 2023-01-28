/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/


/*
instead of makigng children empty vector we can actually make 26 size vector whrein letters are store like a at first index etc..
this way we can directly check if we should create new node if no match found or move to next node for matching. This become O(1) operation. Obviously now each node will have 26 size array.
*/

class Trie {
    class Node{
        public:
            char character;
            vector<Node*> children{};
            bool eow{};//end of word
            Node(char c){
                this->character=c;
            }
    };
    Node *root{};

    void insert(Node *root,int from,const string &word){
        if(from>=word.length()){
            return;
        }
        bool nodeFound=false;
        for(Node *node:root->children){
            if(node->character==word[from]){
                cout<<"collide "<<word[from]<<endl;
                if(from==word.length()-1){
                    node->eow=true;
                }
                nodeFound=true;
                insert(node,from+1,word);
                break;
            }
        }
        if(!nodeFound){
            Node *rt=root;
            while(from<word.length()){
                Node *tmp=new Node(word[from]);
                cout<<"Inserting "<<word[from]<<endl;
                if(from==word.length()-1){
                    tmp->eow=true;
                }
                rt->children.push_back(tmp);
                rt=tmp;
                from++;
            }
        }
    }
    bool search(Node *root,int from,const string &word,bool prefix=false){
        if(from>=word.length()){
            return true;
        }
        for(Node *node:root->children){
            if(node->character==word[from]){
                cout<<"found :(prefix="<<prefix<<") "<<word[from]<<" eow = "<<node->eow<<endl;
                if(!prefix && (from==word.length()-1)){
                    if((node->eow)!=true){
                        return false;
                    }else{
                        return true;
                    }
                }
                return search(node,from+1,word,prefix);
            }
        }
        return false;
    }
    void releaseMemory(Node *root){
        if(!root){
            return;
        }
        cout<<"deleting "<<root->character<<endl;
        for(Node *node:root->children){
            releaseMemory(node);
        }
        delete root;
    }
public:
    Trie() {
        root=new Node('/');
    }
    ~Trie(){
        releaseMemory(root);
        root=nullptr;
    }
    
    void insert(string word) {
        this->insert(root,0,word);
    }
    
    bool search(string word) {
        return search(root,0,word);
    }
    
    bool startsWith(string prefix) {
        return search(root,0,prefix,true);
    }
};

/*
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */