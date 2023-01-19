/*
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
 

Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
*/

//TLE 43 / 56 time O(n*max(wordlen,len of words2)*max(wordlen,26)) , space O(1) 
// class Solution {
// private:
//     vector<int> freqCounter(const string &str){
//         vector<int> freq(26,0);
//         for(const char &c:str){
//             freq[c-'a']++;
//         }
//         return freq;
//     }
// public:
//     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
//         vector<string> res;
//         for(const string &wordA:words1){
//             vector<int> afreq=freqCounter(wordA);

//             bool allHasSubset=true;
//             for(const string wordB:words2){
//                 vector<int> bfreq=freqCounter(wordB);
//                 int i=0;
//                 if(wordB.length()<=wordA.length()){
//                     for(;i<26;i++){
//                         if(bfreq[i]!=0 && (afreq[i]<bfreq[i])){
//                             break;
//                         }
//                     }
//                 }
//                 if(i!=26){
//                     allHasSubset=false;
//                 }
//             }
//             if(allHasSubset){
//                 res.push_back(wordA);
//             }
//         }
//         return res;
//     }
// };
//////////////////////////////////////////////
class Solution {
private:
    vector<int> freqCounter(const string &str){
        vector<int> freq(26,0);
        for(const char &c:str){
            freq[c-'a']++;
        }
        return freq;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> count(26,0),temp;
        for(const string wordB:words2){
            vector<int> tmp=freqCounter(wordB);
            for(int i=0;i<26;i++){
                count[i]=max(count[i],tmp[i]);
            }
        }
        for(const string &wordA:words1){
            vector<int> afreq=freqCounter(wordA);
            int i=0;
            for(;i<26;i++){
                if(afreq[i]<count[i]){
                    break;
                }
            }
            if(i==26){
                res.push_back(wordA);
            }
        }
        return res;
    }
};