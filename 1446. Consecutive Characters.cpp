/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/

class Solution {
public:
    int maxPower(string s) {
        int len=s.length();
        int power=0;
        int n=1;
        for(int i=1;i<len;i++){
            if(s[i-1]!=s[i]){
                power=max(power,n);
                n=0;
            }
            n++;
        }
        return max(power,n);
    }
};