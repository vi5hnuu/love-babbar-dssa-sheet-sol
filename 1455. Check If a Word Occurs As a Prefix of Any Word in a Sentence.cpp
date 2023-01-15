/*
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.
*/


// class Solution {
// private:
//     bool isPrefixOf(const string &of,const string &word){
//         int wlen=word.length();
//         int oflen=of.length();
//         if(wlen>oflen){
//             return false;
//         }
//         for(int i=0;i<wlen;i++){
//             if(of[i]!=word[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     int isPrefixOfWord(string sentence, string searchWord) {
//         int swlen=searchWord.length();
//         istringstream ss(sentence);
//         int idx=0;
//         for(string s;ss>>s;){
//             if(isPrefixOf(s,searchWord)){
//                 return idx+1;
//             }
//             idx++;
//         }
//         return -1;
//     }
// };
////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int swlen=searchWord.length();
        int i=0;
        int spaces=0;

        //**separated by a single space

        bool found=false;
        char lastC=' ';
        for(const char &c:sentence){
            if(c==' '){
                spaces++;
                i=0;
            }
            if(c==searchWord[i]){
                if(i==0){
                    if(lastC==' '){
                        i++;
                    }
                }else{
                    i++;
                }
            }else{// abcd  | ad
                i=0; //or if(i>0) i=0; a matched , when b,c come reset else for d it match and                  return that match found
            }
            if(i==swlen){
                found=true;
                break;
            }
            lastC=c;
        }
        return found ? spaces+1 : -1;
    }
};