/*
Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.

Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.
 

Example 1:

Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False
 

Constraints:

1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case English letters.
All the strings in dictionary are distinct.
1 <= searchWord.length <= 100
searchWord consists of only lower-case English letters.
buildDict will be called only once before search.
At most 100 calls will be made to search.
*/


class MagicDictionary {
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
    bool search(Node *root,int from,const string &word,bool oneDeleted=false){
         if(from==word.length()-1 && root->children.size()==0){//wordlen>this word
                return false;
         }
        bool ans=false;
        for(Node *node:root->children){//hello,hallo -> hello
            if(node->character==word[from]){
                if(from==word.length()-1){
                    if(node->eow && oneDeleted){//sure
                        return true;
                    }else{
                        continue;//not sure
                    }
                }
                ans= ans || search(node,from+1,word,oneDeleted);
            }else if(!oneDeleted){
                if(from==word.length()-1){
                    if(node->eow && !oneDeleted){//sure
                        return true;
                    }else{
                        continue;//not sure
                    }
                }
                ans=ans || search(node,from+1,word,true);
            }
        }
        return ans;
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
    MagicDictionary() {
        root=new Node('/');
    }
    ~MagicDictionary(){
        releaseMemory(root);
        root=nullptr;
    }
    
    void buildDict(vector<string> words) {
        for(string &word:words){
            this->insert(root,0,word);
        }
    }
    
    bool search(string word) {
        return search(root,0,word);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */