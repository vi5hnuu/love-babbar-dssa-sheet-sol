/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

// class Solution {
//     void dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited,int i,int j){
//         if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0' || visited[i][j]){
//             return;//way closed
//         }
//         visited[i][j]=true;
//         dfs(grid,visited,i-1,j);
//         dfs(grid,visited,i,j+1);
//         dfs(grid,visited,i,j-1);
//         dfs(grid,visited,i+1,j);
        
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int rows=grid.size();
//         int cols=grid[0].size();

//         vector<vector<bool>> visited(rows,vector<bool>(cols,false));
//         int count=0;
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(!visited[i][j] && grid[i][j]=='1'){
//                     dfs(grid,visited,i,j);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

//////////////////////////////////////////////////////////

class Solution {
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'){
            return;//way closed
        }
        grid[i][j]='0';
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};