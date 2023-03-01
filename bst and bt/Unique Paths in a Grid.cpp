/*
You are given a matrix grid of n x  m size consisting of values 0 and 1. A value of 1 means that you can enter that cell and 0 implies that entry to that cell is not allowed.

You start at the upper-left corner of the grid (1, 1) and you have to reach the bottom-right corner (n, m) such that you can only move in the right or down direction from every cell.

Your task is to calculate the total number of ways of reaching the target modulo (109+7).
Note: The first (1, 1) and last cell (n, m) of the grid can also be 0


Example 1:

Input:
n = 3, m = 3
grid[][] = {{1, 1, 1};
            {1, 0, 1};
            {1, 1, 1}}
Output:
2
Explanation:
1 1 1
1 0 1
1 1 1
This is one possible path.
1 1 1
1 0 1
1 1 1
This is another possible path.
Example 2:

Input:
n = 1, m = 3
grid = {{1, 0, 1}}
Output :
0
Explanation:
There is no possible path to reach the end.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function uniquePaths() which takes 2 integers n, and m, and a matrix of size n*m as input and returns the number of unique paths from cell (1,1) to (n,m) modulo (109+7)


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)


Constraints:
1 ≤ n*m ≤ 106
*/


// class Solution {
// private:
//     int uniquePaths(int i,int j,vector<vector<int>> &grid,int &r,int &c){
//         if(i>=r || j>=c || grid[i][j]==0 || grid[i][j]==-1){
//             return 0;
//         }
//         if(i==r-1 && j==c-1){
//             return 1;
//         }
//         grid[i][j]=-1;
//         int ways=(uniquePaths(i+1,j,grid,r,c)+uniquePaths(i,j+1,grid,r,c));
//         grid[i][j]=1;
//         return ways%1000000007;
        
//     }
// public:
//     int uniquePaths(int n, int m, vector<vector<int>> &grid) {
//         if(grid[n-1][m-1]==0){
//             return 0;
//         }
//         return uniquePaths(0,0,grid,n,m);
//     }
// };
////////////////////
//1099 /1115
// class Solution {
// private:
//     int uniquePaths(int i,int j,vector<vector<int>> &grid,int &r,int &c,unordered_map<int,int> &memo){
//         if(i>=r || j>=c || grid[i][j]==0 || grid[i][j]==-1){
//             return 0;
//         }
//         if(i==r-1 && j==c-1){
//             return 1;
//         }
//         auto itr=memo.find(i*c+j);
//         if(itr!=memo.end()){
//             return itr->second;
//         }
//         grid[i][j]=-1;
//         int ways=(uniquePaths(i+1,j,grid,r,c,memo)+uniquePaths(i,j+1,grid,r,c,memo));
//         grid[i][j]=1;
//         return memo[i*c+j]=ways%1000000007;
        
//     }
// public:
//     int uniquePaths(int n, int m, vector<vector<int>> &grid) {
//         if(grid[n-1][m-1]==0 || grid[0][0]==0){
//             return 0;
//         }
//         unordered_map<int,int> memo;
//         return uniquePaths(0,0,grid,n,m,memo);
//     }
// };
////////////////////
class Solution {
public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(grid[n-1][m-1]==0 || grid[0][0]==0){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        dp[n-1][m-1]=1;
        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=dp[i+1][m-1]==0 ? 0 : grid[i][m-1];
        }
        for(int i=m-2;i>=0;i--){
            dp[n-1][i]=dp[n-1][i+1]==0 ? 0 : grid[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(grid[i][j]!=0){
                    dp[i][j]=(dp[i+1][j]+dp[i][j+1])%1000000007;
                }
            }
        }
        return dp[0][0];
    }
};