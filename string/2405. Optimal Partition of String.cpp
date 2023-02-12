/*
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

 

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
 

Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.
*/


// class Solution {
// public:
//     int partitionString(string s) {
//         vector<int> freq(26,0);
        
//         int k=0;
//         for(int i=0;i<s.length();i++){
//             freq[s[i]-'a']++;
//             if(freq[s[i]-'a']==2){
//                 k++;
//                 freq=vector<int>(26,0);
//                 freq[s[i]-'a']++;
//             }
//         }
//         k++;
//         return k;
        
//     }
// };


////////////////////
//since int can hold 32 bits we can use int as 'freq'
class Solution {
public:
    int partitionString(string s) {
        int freq=0;
        
        int k=0;
        for(int i=0;i<s.length();i++){
            if(freq & (1<<(s[i]-'a'))){
                k++;
                freq=0;
                freq=freq | (1<<(s[i]-'a'));
            }else{
                freq=freq | (1<<(s[i]-'a'));
            }
        }
        k++;
        return k;
        
    }
};