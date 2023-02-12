/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/


//TLE
/*
class Solution {
private:
    int minPathSum(const vector<vector<int>>& grid,int i,int j) {
        if(i>=grid.size() || j>=grid[0].size())
            return -1;
        
        int down=minPathSum(grid,i+1,j);
        int right=minPathSum(grid,i,j+1);
        if(down!=-1 && right!=-1)//he can go to both sides but we chose the min of this
            return grid[i][j]+min(down,right);
        else if(down!=-1){//he can only go down
            return grid[i][j]+down;
        }
        else if(right!=-1){//he can go only right
            return grid[i][j]+right;
        }else{ //final destination
            return grid[i][j];
        }
    }    
public:
    int minPathSum(vector<vector<int>>& grid) {
        return minPathSum(grid,0,0);
    }
};
*/
/////////////////////////////////////////
// class Solution {
// private:
//     int minPathSum(const vector<vector<int>>& grid,int i,int j) {
//         if(i>=grid.size() || j>=grid[0].size())
//             return INT_MAX;
        
//         int down=minPathSum(grid,i+1,j);
//         int right=minPathSum(grid,i,j+1);
//         int mnlr=min(down,right);
//         return grid[i][j]+(mnlr==INT_MAX ? 0 : mnlr);
//     }    
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         return minPathSum(grid,0,0);
//     }
// };
////////////////////////////////////////
// class Solution {
// private:
//     int minPathSum(const vector<vector<int>>& grid,int i,int j,vector<vector<int>> &memo) {
//         if(i>=grid.size() || j>=grid[0].size())
//             return -1;
        
//         if(memo[i][j]>0){
//             return memo[i][j];
//         }
//         int down=minPathSum(grid,i+1,j,memo);
//         int right=minPathSum(grid,i,j+1,memo);
//         if(down!=-1 && right!=-1)//he can go to both sides but we chose the min of this
//             return memo[i][j]=grid[i][j]+min(down,right);
//         else if(down!=-1){//he can only go down
//             return memo[i][j]=grid[i][j]+down;
//         }
//         else if(right!=-1){//he can go only right
//             return memo[i][j]=grid[i][j]+right;
//         }else{ //final destination
//             return memo[i][j]=grid[i][j];
//         }
//     }    
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         vector<vector<int>> memo(grid.size(),vector<int>(grid[0].size(),-1));
//         return minPathSum(grid,0,0,memo);
//     }
// };
//////////////////////////////////////////
class Solution {
private:
    int minPathSum(const vector<vector<int>>& grid,int i,int j,vector<vector<int>> &memo) {
        if(i>=grid.size() || j>=grid[0].size())
            return INT_MAX;
        
        if(memo[i][j]>0){
            return memo[i][j];
        }
        int down=minPathSum(grid,i+1,j,memo);
        int right=minPathSum(grid,i,j+1,memo);
        int mnlr=min(down,right);        
        return memo[i][j]=grid[i][j]+(mnlr==INT_MAX ? 0 : mnlr);
    }    
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(),vector<int>(grid[0].size(),-1));
        return minPathSum(grid,0,0,memo);
    }
};
//////////////////////////////////////////
// class Solution {  
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int rows=grid.size();
//         int cols=grid[0].size();
//         vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));

//         for(int row=rows-1;row>=0;row--){
//             for(int col=cols-1;col>=0;col--){
//                 if((col+1)>=cols && (row+1)>=rows){
//                     dp[row][col]=grid[row][col];
//                 }else if((col+1)>=cols && (row+1)<rows){
//                     dp[row][col]=grid[row][col]+dp[row+1][col];
//                 }else if((col+1)<cols && (row+1)>=rows){
//                     dp[row][col]=grid[row][col]+dp[row][col+1];
//                 }else{
//                     dp[row][col]=grid[row][col]+min(dp[row][col+1],dp[row+1][col]);
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };