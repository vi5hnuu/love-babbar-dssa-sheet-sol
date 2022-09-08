// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

class Solution {
private:
    string reverseStr(string str){
        for(int i=0,len=str.length();i<len/2;i++){
            char c=str[i];
            str[i]=str[len-1-i];
            str[len-1-i]=c;
        }
        return str;
    }    
public:
    int longestPalindromeSubseq(string s) {
        string revStr=reverseStr(s);
        int len=s.length();
        int dp[len+1][len+1];
        for(int i=0;i<=len;i++)
            dp[0][i]=dp[i][0]=0;
       
        //LCS
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++){
                if(s[i]==revStr[j])
                    dp[i+1][j+1]=1+dp[i][j];
                else
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        
        return dp[len][len];
    }
};