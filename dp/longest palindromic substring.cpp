// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        int sz=s.length();
        vector<vector<bool>> dp(sz,vector<bool>(sz,false));
        int start=-1,end=-1;
        for(int gap=0;gap<sz;gap++){
            for(int i=0,j=gap;j<sz;i++,j++){
                if(gap==0){
                    dp[i][j]=true;
                }
                else if(gap==1){
                    if(s[i]==s[j])
                        dp[i][j]=true;
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j]=true;
                }
                
                if(dp[i][j]){
                    start=i;
                    end=j;
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};


//https://www.youtube.com/watch?v=XmSOWnL6T_I