/*
A string is considered beautiful if it satisfies the following conditions:

Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.

Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
Example 2:

Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.
Example 3:

Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.
 

Constraints:

1 <= word.length <= 5 * 105
word consists of characters 'a', 'e', 'i', 'o', and 'u'.
*/


// class Solution {
// public:
//     int longestBeautifulSubstring(string word) {
//         int wlen=word.length();
//         int maxLen=0;

//         int rnCount=0;
//         unordered_map<char,bool> vowels;
//         for(int i=0;i<wlen;i++){
//             if(i==0 || word[i]>=word[i-1]){
//                 vowels[word[i]]=true;
//                 rnCount++;
//             }else{
//                 maxLen=(vowels.size()==5) ? max(maxLen,rnCount) : maxLen;
//                 rnCount=1;
//                 vowels=unordered_map<char,bool>();
//                 vowels[word[i]]=true;
//             }
//         }
//         maxLen=(vowels.size()==5) ? max(maxLen,rnCount) : maxLen;
//         return maxLen;
//     }
// };
////////////////////////////////////////
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int wlen=word.length();
        int maxLen=0;

        int rnCount=0;
        int vowelsCount=0;
        for(int i=0;i<wlen;i++){
            if(i==0 || word[i]>=word[i-1]){
                vowelsCount=(i==0 || word[i]>word[i-1]) ? vowelsCount+1 : vowelsCount; 
                rnCount++;
            }else{
                maxLen=(vowelsCount==5) ? max(maxLen,rnCount) : maxLen;
                rnCount=1;
                vowelsCount=1;
            }
        }
        maxLen=(vowelsCount==5) ? max(maxLen,rnCount) : maxLen;
        return maxLen;
    }
};