/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103
*/


class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
        
        vector<vector<int>> dp(x,vector<int>(y,0)); // x rows(s1 verticle) | y cols (s2 horizontal)
        dp[0][0]=s2[0]==s1[0];
        for(int i=1;i<y;i++){//row1
            dp[0][i]= s2[i]==s1[0] || dp[0][i-1];
        }
        for(int j=1;j<x;j++){//col1
            dp[j][0]= s1[j]==s2[0] || dp[j-1][0];
        }
        
        for(int l=1;l<x;l++){
            for(int m=1;m<y;m++){
                if(s1[l]==s2[m]){
                    dp[l][m]=1+dp[l-1][m-1];
                }else{
                    dp[l][m]=max(dp[l-1][m],dp[l][m-1]);
                }
            }
        }
        return dp[x-1][y-1];
    }
};