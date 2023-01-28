/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/

/*
instead of makigng children empty vector we can actually make 26 size vector whrein letters are store like a at first index etc..
this way we can directly check if we should create new node if no match found or move to next node for matching. This become O(1) operation. Obviously now each node will have 26 size array.
*/

class Dictonary{
private:
    class Node{
        public:
            char character;
            bool eow{};
            vector<Node*> children;

            Node(char c){
                this->character=c;
            }
    };
    void insert(Node *root,int from,const string &word){
        if(from>=word.length()){
            return;
        }
        bool nodeFound=false;
        for(Node *node:root->children){
            if(node->character==word[from]){
                // cout<<"collide "<<word[from]<<endl;
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
                // cout<<"Inserting "<<word[from]<<endl;
                if(from==word.length()-1){
                    tmp->eow=true;
                }
                rt->children.push_back(tmp);
                rt=tmp;
                from++;
            }
        }
    }
    int lastIndexOf(Node *root,int from,const string &word){
        //send index of first unmatched character or -1 or word.length()
        if(from>=word.length()){
            return from;
        }
        for(Node *node:root->children){
            if(node->character==word[from]){
                // cout<<"found : "<<word[from]<<" eow = "<<node->eow<<endl;
                    if(node->eow==true){
                        return from+1;
                    }
                return lastIndexOf(node,from+1,word);
            }
        }
        return -1;
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
    Node *root;
public:
    Dictonary(const vector<string> &words){
        root=new Node('/');
        for(const string &word:words){
            insert(word);
        }
    }
    ~Dictonary(){
        releaseMemory(root);
        root=nullptr;
    }
    int lastIndexOf(const string &word){
        return lastIndexOf(root,0,word);
    }
    void insert(const string &word){
        insert(root,0,word);
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Dictonary dict(dictionary);

        istringstream ss(sentence);
        string ans="";
        bool addSpace=false;
        for(string s;ss>>s;){
            if(addSpace){
                ans+=" ";
            }
            int idx=dict.lastIndexOf(s);
            if(idx!=-1){
                ans+=s.substr(0,idx);
            }else{
                ans+=s;
            }
            addSpace=true;
        }
        return ans;
    }
};