// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //acquire and realease
        int sz=s.length();
        int ans=0;
        map<char,int> mp;
        
        int i=-1,j=-1;
        while(true){
            bool l1=false,l2=false;
            
            //acquire untill invalid
            while(i<sz-1){
                l1=true;
                i++;
                mp[s[i]]++;
                if(mp[s[i]]==2){//invalid
                        break;                    
                }else{
                    //is this biggest of all substring we ever got
                    if((i-j)>ans){
                        ans=i-j;
                    }
                }
            }
            
            //relaease untill valid
            while(j<i){
                l2=true;
                j++;
                mp[s[j]]--;
                if(mp[s[j]]==1){
                    break;
                }
            }
            if(!l1 && !l2){
                break;
            }
        }
        
        return ans;
    }
};