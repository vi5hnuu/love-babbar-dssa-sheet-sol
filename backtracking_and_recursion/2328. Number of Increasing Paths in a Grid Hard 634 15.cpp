/*
You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

 

Example 1:


Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.
Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
1 <= grid[i][j] <= 105
*/


//TLE 135 / 138
class Solution {
private:
    //0 <= matrix[i][j] <= 231 - 1
    int longestIncreasingPath(vector<vector<int>> &grid,int r,int c,int i,int j){
        if(grid[i][j]==-1){
            return 0;
        }
        int state=grid[i][j];
        grid[i][j]=-1;
        int left=(j-1>=0 ? (grid[i][j-1]>state ? longestIncreasingPath(grid,r,c,i,j-1) : 0) : 0);
        int right=(j+1<c ? (grid[i][j+1]>state? longestIncreasingPath(grid,r,c,i,j+1) : 0) : 0);
        int up=(i-1>=0 ? (grid[i-1][j]>state ? longestIncreasingPath(grid,r,c,i-1,j) : 0) : 0);
        int down=(i+1<r ? (grid[i+1][j]>state ? longestIncreasingPath(grid,r,c,i+1,j) : 0) : 0);
        grid[i][j]=state;
        return (1+left+right+up+down)%mod;
    }
public:
    const int mod=1000000007;
    int countPaths(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                count=(count+longestIncreasingPath(grid,rows,cols,i,j)%mod)%mod;
            }
        }
        return count;
    }
};
////////////////////////////////////////
// class Solution {
// private:
//     //0 <= matrix[i][j] <= 231 - 1
//     int longestIncreasingPath(vector<vector<int>> &grid,int r,int c,int i,int j,vector<vector<int>> &memo){
//         if(grid[i][j]==-1){
//             return 0;
//         }
//         if(memo[i][j]!=-1){
//             return memo[i][j];
//         }
//         int state=grid[i][j];
//         grid[i][j]=-1;
//         int left=(j-1>=0 ? (grid[i][j-1]>state ? longestIncreasingPath(grid,r,c,i,j-1,memo) : 0) : 0);
//         int right=(j+1<c ? (grid[i][j+1]>state? longestIncreasingPath(grid,r,c,i,j+1,memo) : 0) : 0);
//         int up=(i-1>=0 ? (grid[i-1][j]>state ? longestIncreasingPath(grid,r,c,i-1,j,memo) : 0) : 0);
//         int down=(i+1<r ? (grid[i+1][j]>state ? longestIncreasingPath(grid,r,c,i+1,j,memo) : 0) : 0);
//         grid[i][j]=state;
//         return memo[i][j]=(1+left+right+up+down)%mod;
//     }
// public:
//     const int mod=1000000007;
//     int countPaths(vector<vector<int>>& grid) {
//         int rows=grid.size();
//         int cols=grid[0].size();

//         int count=0;
//         vector<vector<int>> memo(rows,vector<int>(cols,-1));
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 count=(count+longestIncreasingPath(grid,rows,cols,i,j,memo)%mod)%mod;
//             }
//         }
//         return count;
//     }
// };