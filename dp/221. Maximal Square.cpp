/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int side=INT_MIN;
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }else{
                    if(i==rows-1 || j==cols-1){
                        if(matrix[i][j]=='1')
                            dp[i][j]=1;
                        else
                            dp[i][j]=0;
                    }else{
                        dp[i][j]=1+min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]));
                    }
                }
                side=max(side,dp[i][j]);
            }
        }
        return side*side;
    }
};