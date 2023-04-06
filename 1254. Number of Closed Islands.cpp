/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

// class Solution {
// private:
//     int closedIsland(vector<vector<int>> &grid,int r,int c,int i,int j){
//         if(i<0 || i>=r || j>=c || j<0){
//             return 0;
//         }
//         if(grid[i][j]!=0){
//             return 1;
//         }
//         grid[i][j]=-1;
//         int aa=closedIsland(grid,r,c,i+1,j);
//         int bb=closedIsland(grid,r,c,i-1,j);
//         int cc=closedIsland(grid,r,c,i,j+1);
//         int dd=closedIsland(grid,r,c,i,j-1);
//         return aa && bb && cc && dd;
//     }
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         int r=grid.size();
//         int c=grid[0].size();

//         int islands=0;
//         for(int i=0;i<r;i++){
//             for(int j=0;j<c;j++){
//                 if(grid[i][j]==0){
//                     islands+=(closedIsland(grid,r,c,i,j));
//                 }
//             }
//         }
//         return islands;
//     }
// };
/////////////////////////////
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void spreadLand(vector<vector<int>> &grid,int r,int c,int i,int j){
        if(i<0 || i>=r || j>=c || j<0 || grid[i][j]==1){
            return;
        }
        grid[i][j]=1;
        spreadLand(grid,r,c,i+1,j);
        spreadLand(grid,r,c,i-1,j);
        spreadLand(grid,r,c,i,j+1);
        spreadLand(grid,r,c,i,j-1);
    }
    void acquireIsland(vector<vector<int>> &grid,int r,int c,int i,int j){
        if(i<0 || i>=r || j>=c || j<0 || grid[i][j]==1){
            return;
        }
        grid[i][j]=1;
        acquireIsland(grid,r,c,i+1,j);
        acquireIsland(grid,r,c,i-1,j);
        acquireIsland(grid,r,c,i,j+1);
        acquireIsland(grid,r,c,i,j-1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        for(int i=0;i<r;i++){
            if(grid[i][0]==0){
                spreadLand(grid,r,c,i,0);
            }
             if(grid[i][c-1]==0){
                spreadLand(grid,r,c,i,c-1);
            }
        }
        for(int j=0;j<c;j++){
            if(grid[0][j]==0){
                spreadLand(grid,r,c,0,j);
            }
             if(grid[r-1][j]==0){
                spreadLand(grid,r,c,r-1,j);
            }
        }
        int islands=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    acquireIsland(grid,r,c,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};