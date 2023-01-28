/*
Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word. 

 

Example 1:

Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:

Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 30
words[i] consists of lowercase English letters.
*/

class Trie {
    class Node{
        public:
            char character;
            vector<Node*> children;
            bool eow{};//end of word
            Node(char c){
                children=vector<Node*>(26,nullptr);
                this->character=c;
            }
    };
    Node *root{};

    void insert(Node *root,int from,const string &word){
        if(from>=word.length()){
            return;
        }

        Node *existingNode=root->children[word[from]-'a'];
        if(existingNode!=nullptr){
            if(from==word.length()-1){
                existingNode->eow=true;
            }
            insert(existingNode,from+1,word);
        }else{
            Node *rt=root;
            while(from<word.length()){
                Node *tmp=new Node(word[from]);
                if(from==word.length()-1){
                    tmp->eow=true;
                }
                // cout<<"Inserting "<<word[from]<<" "<<tmp->eow<<endl;
                rt->children[word[from]-'a']=tmp;
                rt=tmp;
                from++;
            }
        }
    }
    string longestWordSeq(Node *root){
        if(!root){
            return "";
        }

        string longestWord="";
        for(Node *node:root->children){//calling lexicographically
            if(node && node->eow){
                string wrd=node->character+longestWordSeq(node);
                if(longestWord.length()<wrd.length()){
                    longestWord=wrd;
                }
            }
        }

        return longestWord;
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
    Trie() {
        root=new Node('/');
    }
    Trie(vector<string> &words) {
        root=new Node('/');
        for(string &word:words){
            this->insert(word);
        }
    }
    ~Trie(){
        releaseMemory(root);
        root=nullptr;
    }
    
    void insert(string word) {
        this->insert(root,0,word);
    }
    
    string longestWordSeq() {
        return longestWordSeq(root);
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie dict{words};
        return dict.longestWordSeq();
    }
};