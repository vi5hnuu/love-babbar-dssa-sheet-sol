/*
1023. Camelcase Matching
Medium
704
259
Companies
Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.

A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

Constraints:

1 <= pattern.length, queries.length <= 100
1 <= queries[i].length <= 100
queries[i] and pattern consist of English letters.
*/

//Not a good solution 😂😂😂
// class Trie {
//     class Node{
//         public:
//             char character;
//             vector<Node*> children{};
//             bool eow{};//end of word
//             Node(char c){
//                 this->character=c;
//             }
//     };
//     Node *root{};

//     bool match(Node *root,int fromq,const string &query,int fromp,const string &pattern){

//         Node *rt=root;
//         while(fromq<query.length()){
//             Node *tmp=new Node(query[fromq]);
//             rt->children.push_back(tmp);
//             if(query[fromq]==pattern[fromp]){
//                 fromp++;
//             }else if(query[fromq]>='A' && query[fromq]<='Z' && (fromp>=pattern.length() || query[fromq]!=pattern[fromp])){
//                 return false;
//             }
//             rt=tmp;
//             fromq++;
//         }
//         return fromp>=pattern.length();
//     }
//     void releaseMemory(Node *root){
//         if(!root){
//             return;
//         }
//         cout<<"deleting "<<root->character<<endl;
//         for(Node *node:root->children){
//             releaseMemory(node);
//         }
//         delete root;
//     }
// public:
//     Trie() {
//         root=new Node('/');
//     }
//     ~Trie(){
//         releaseMemory(root);
//         root=nullptr;
//     }
    
//     bool match(string query,string pattern) {
//         return match(root,0,query,0,pattern);
//     }
// };

// class Solution {
// public:
//     vector<bool> camelMatch(vector<string>& queries, string pattern) {
//         // if you can insert lowercase English letters pattern
//         //we can only skip small case letter eg. "ForceFeedBack", pat="FoBaT"
//                                              //   11   x
//         int qlen=queries.size();
//         vector<bool> res(qlen,false);
//         for(int i=0;i<qlen;i++){
//             res[i]=Trie{}.match(queries[i],pattern);
//         }
//         return res;
//     }
// };

///////////////////////////
class Solution {
private:
    bool matchPatter(const string &query,const string &pattern){
        int fromp=0;
        int plen=pattern.length();
        for(const char &c:query){
            if(fromp<plen && pattern[fromp]==c){
                fromp++;
            }else if(c>='A' && c<'Z' && (fromp>plen || c!=pattern[fromp])){
                return false;
            }
        }
        return fromp>=plen;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        // if you can insert lowercase English letters pattern
        //we can only skip small case letter eg. "ForceFeedBack", pat="FoBaT"
                                             //   11   x
        int qlen=queries.size();
        vector<bool> res(qlen,false);
        for(int i=0;i<qlen;i++){
            res[i]=matchPatter(queries[i],pattern);
        }
        return res;
    }
};
