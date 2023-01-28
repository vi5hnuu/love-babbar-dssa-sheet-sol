/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/


//TLE 135 / 138
// class Solution {
// private:
//     int getMax(initializer_list<int> nums){
//         int mx=INT_MIN;
//         for(const int &n:nums){
//             mx=max(mx,n);
//         }
//         return mx;
//     }
//     //0 <= matrix[i][j] <= 231 - 1
//     int longestIncreasingPath(vector<vector<int>> &grid,int r,int c,int i,int j){
//         if(grid[i][j]==-1){
//             return 0;
//         }
        
//         int state=grid[i][j];
//         grid[i][j]=-1;
//         int left=1+(j-1>=0 ? (grid[i][j-1]>state ? longestIncreasingPath(grid,r,c,i,j-1) : 0) : 0);
//         int right=1+ (j+1<c ? (grid[i][j+1]>state? longestIncreasingPath(grid,r,c,i,j+1) : 0) : 0);
//         int up=1+ (i-1>=0 ? (grid[i-1][j]>state ? longestIncreasingPath(grid,r,c,i-1,j) : 0) : 0);
//         int down=1+ (i+1<r ? (grid[i+1][j]>state ? longestIncreasingPath(grid,r,c,i+1,j) : 0) : 0);
//         grid[i][j]=state;
//         return getMax({left,right,up,down});
//     }
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         int rows=matrix.size();
//         int cols=matrix[0].size();

//         int mx=INT_MIN;
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 mx=max(mx,longestIncreasingPath(matrix,rows,cols,i,j));
//             }
//         }
//         return mx;
//     }
// };
////////////////////////////////////////
class Solution {
private:
    int getMax(initializer_list<int> nums){
        int mx=INT_MIN;
        for(const int &n:nums){
            mx=max(mx,n);
        }
        return mx;
    }
    //0 <= matrix[i][j] <= 231 - 1
    int longestIncreasingPath(vector<vector<int>> &grid,int r,int c,int i,int j,vector<vector<int>> &memo){
        if(grid[i][j]==-1){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int state=grid[i][j];
        grid[i][j]=-1;
        int left=1+(j-1>=0 ? (grid[i][j-1]>state ? longestIncreasingPath(grid,r,c,i,j-1,memo) : 0) : 0);
        int right=1+ (j+1<c ? (grid[i][j+1]>state? longestIncreasingPath(grid,r,c,i,j+1,memo) : 0) : 0);
        int up=1+ (i-1>=0 ? (grid[i-1][j]>state ? longestIncreasingPath(grid,r,c,i-1,j,memo) : 0) : 0);
        int down=1+ (i+1<r ? (grid[i+1][j]>state ? longestIncreasingPath(grid,r,c,i+1,j,memo) : 0) : 0);
        grid[i][j]=state;
        return memo[i][j]=getMax({left,right,up,down});
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        int mx=INT_MIN;
        vector<vector<int>> memo(rows,vector<int>(cols,-1));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mx=max(mx,longestIncreasingPath(matrix,rows,cols,i,j,memo));
            }
        }
        return mx;
    }
};