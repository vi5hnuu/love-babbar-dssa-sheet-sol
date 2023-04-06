/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/


class Solution {
private:
    bool compareFreq(vector<int> &s1,vector<int> &s2){
        for(int i=0;i<26;i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int s1len=s1.length();
        int s2len=s2.length();
        if(s1len>s2len){
            return false;
        }
        vector<int> s1freq(26,0),s2freq(26,0);
        for(char c:s1){
            s1freq[c-'a']++;
        }
        for(int i=0;i<s1len;i++){
            s2freq[s2[i]-'a']++;
        }
        if(compareFreq(s1freq,s2freq)){
            return true;
        }
        int release=0;
        int acquire=s1len;
        while(acquire<s2len){
            s2freq[s2[release++]-'a']--;
            s2freq[s2[acquire++]-'a']++;
            if(compareFreq(s1freq,s2freq)){
                return true;
            }
        }
        return false;
    }
};