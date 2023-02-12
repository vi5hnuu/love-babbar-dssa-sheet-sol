/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
Example 2:

Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.
Your Task:

You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.

Expected Time Complexity: O(n * m)

Expected Space Complexity: O(n * m)

Constraints:

1 <= n, m <= 500
grid[i][j] == 0 or 1
*/


class Solution {
private://or bfs
    void invalidate(int sr,int sc,vector<vector<int>> &grid,vector<vector<bool>> &invalidCells,const int &r,const int &c){
        if(sr<0 || sc<0 || sr>=r || sc>=c || invalidCells[sr][sc] || grid[sr][sc]==0){
            return;
        }
        invalidCells[sr][sc]=true;
        invalidate(sr,sc+1,grid,invalidCells,r,c);
        invalidate(sr,sc-1,grid,invalidCells,r,c);
        invalidate(sr+1,sc,grid,invalidCells,r,c);
        invalidate(sr-1,sc,grid,invalidCells,r,c);
    }
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> invalidCells(rows,vector<bool>(cols,false));
        
        //invalidate all path that start from cell with '1'
        for(int i=0;i<rows;i++){
            if(grid[i][0]==1 && !invalidCells[i][0]){//path is invalid and entry not marked->mark it
                invalidate(i,0,grid,invalidCells,rows,cols);
            }
            if(grid[i][cols-1]==1 && !invalidCells[i][cols-1]){//path is invalid and entry not marked->mark it
                invalidate(i,cols-1,grid,invalidCells,rows,cols);
            }
        }
        
        for(int i=1;i<cols-1;i++){
            if(grid[0][i]==1 && !invalidCells[0][i]){//path is invalid and entry not marked->mark it
                invalidate(0,i,grid,invalidCells,rows,cols);
            }
            if(grid[rows-1][i]==1 && !invalidCells[rows-1][i]){//path is invalid and entry not marked->mark it
                invalidate(rows-1,i,grid,invalidCells,rows,cols);
            }
        }
        
        ///////count valid '1'
        
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && !invalidCells[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};
