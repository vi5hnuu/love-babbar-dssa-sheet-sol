// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int sz=s.length();
        vector<vector<bool>> dp(sz,vector<bool>(sz,false));
        
        for(int gap=0;gap<sz;gap++){
            for(int i=0,j=gap;j<sz;i++,j++){
                if(gap==0){
                    dp[i][j]=true;
                }else if(gap==1){
                    if(s[i]==s[j])
                        dp[i][j]=true;
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j]=true;
                }
                if(dp[i][j])
                    count++;
            }
        }
        return count;
    }
};