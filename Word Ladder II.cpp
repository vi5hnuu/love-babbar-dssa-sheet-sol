/*
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here.


Example 1:

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
Example 2:

Input:
startWord = "gedk", targetWord = "geek", 
wordList = {"geek", "gefk"}
Output:
"gedk" -> "geek"

Your Task:
You don't need to read or print anything, Your task is to complete the function findSequences() which takes startWord, targetWord and wordList as input parameter and returns a list of list of strings of the shortest transformation sequence from startWord to targetWord.
Note: You don't have to return -1 in case of no possible sequence. Just return the Empty List.


Expected Time Compelxity: O(N*(logN * M * 26))
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|


Constraints:
1 ≤ N ≤ 100
1 ≤ M ≤ 10
*/


/*
79
ljjjk
ljjll
kklll
jklkl
lkjkk
klklk
llkjj
ljlll
kjjlk
jljjj
jlkjk
kjjjk
llklk
lklll
llkkj
jkllk
jjllk
kkljl
llljk
kkkkl
lljkj
ljkll
jklkj
jklkk
kjllj
ljllk
jlkjl
jjjlj
kjjjl
jjlll
jjjjj
klllj
kjlkj
lkjjj
kkjlj
llkkl
jjjjl
kjkll
jkjjk
ljljl
kklkj
jjkkj
kjkkl
jllkj
lkjkj
lkjjk
jjljl
kjjkl
jkjlk
lljlk
kkllj
jkkkj
ljkjj
klkjk
ljjjj
kkjkj
lkllk
jkllj
lljjj
kljkk
ljjjl
kkllk
kljlk
lkklk
jljll
llkll
jjkjk
jlkkl
llkjl
kkjkk
kjkkk
kkklj
jkkjj
kjklk
klkjj
jlkkk
lkljj
klkkj
jlkll
lkljl
jljll


Expected outPut
lkljl ljljl ljlll ljkll llkll jlkll jljll
lkljl lklll ljlll ljkll llkll jlkll jljll

see the difference between wordLadder1 and wordLadder2
at index 1 and index 2 is the difference
in wordladder1 all we need was length of transformation but here we need the sequence itself
*/
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord){
            return {{beginWord}};
        }
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(words.find(endWord)==words.end()){
            return {{}};
        }
        queue<vector<string>> nodes;
        nodes.push({beginWord});
        
        vector<vector<string>> allSeq;
        int len=beginWord.length();
        
        unordered_set<string> wordUsedInLevel;
        wordUsedInLevel.insert(beginWord);
        while(!nodes.empty() && words.size()>0){
            unordered_set<string>::iterator itr=wordUsedInLevel.begin();
            while(itr!=wordUsedInLevel.end()){
                words.erase(*itr);
                itr++;
            }
            wordUsedInLevel.clear();
            //////////////////
            int sz=nodes.size();
            while(sz>0){
                sz--;
                auto seq=nodes.front();
                nodes.pop();
                string curW=seq.back();
                if(curW==endWord){
                    allSeq.push_back(seq);
                    continue;
                }
                for(int i=0;i<len;i++){
                    char ori=curW[i];
                    for(int j=0;j<26;j++){
                        char ch=static_cast<char>(j+'a');
                        curW[i]=ch;
                       if(words.find(curW)!=words.end()){
                           seq.push_back(curW);
                           nodes.push(seq);
                           wordUsedInLevel.insert(curW);
                           seq.pop_back();
                       }
                    }
                    curW[i]=ori;
                }
            }
        }
        return allSeq;
    }
};