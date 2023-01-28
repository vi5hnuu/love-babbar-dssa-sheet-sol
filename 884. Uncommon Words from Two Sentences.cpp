/*
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
*/


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        istringstream ss1(s1);
        for(string str;ss1>>str;){
            mp[str]++;
        }

        //////////
        istringstream ss2(s2);
        for(string str;ss2>>str;){
            mp[str]++;
        }

        ///////////
        unordered_map<string,int>::const_iterator itr=mp.cbegin();
        vector<string> res;
        while(itr!=mp.cend()){
            if(itr->second==1){
                res.push_back(itr->first);
            }
            itr++;
        }
        return res;
    }
};