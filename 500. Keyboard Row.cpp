/*
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

 

Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:

Input: words = ["omk"]
Output: []
Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
 

Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase). 
*/


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int row1=0,row2=0,row3=0; 
        for(char c:"qwertyuiop"s){
            row1=row1 | (1<<(c-'a'));
        }
        for(char c:"asdfghjkl"s){
            row2=row2 | (1<<(c-'a'));
        }
        for(char c:"zxcvbnm"s){
            row3=row3 | (1<<(c-'a'));
        }

        ///////////
        vector<string> res;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            bool matched=true;
            cout<<word[0]<<endl;
            if(row1&(1<<(word[0]-'a'))){
                for(const char &c:word){
                    if(!(row1&(1<<(c-'a')))){
                        matched=false;
                        break;
                    }
                }
                if(matched){
                    res.push_back(words[i]);
                }
            }else if(row2&(1<<(word[0]-'a'))){
                for(const char &c:word){
                    if(!(row2&(1<<(c-'a')))){
                        matched=false;
                        break;
                    }
                }
                if(matched){
                    res.push_back(words[i]);
                }
            }else{
                for(const char &c:word){
                    if(!(row3&(1<<(c-'a')))){
                        matched=false;
                        break;
                    }
                }
                if(matched){
                    res.push_back(words[i]);
                }
            }
        }
        return res;
    }
};