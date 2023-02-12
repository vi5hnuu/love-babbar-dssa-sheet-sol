/*
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in 
orange.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500
*/


class Solution{
private:
    int dfsArea(int i,int j,vector<vector<int>> &grid,const int &r,const int &c){
        grid[i][j]=0;//mark visited [area counted]
        
        int count=1;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                int xi=i+x;
                int yj=j+y;
                if(xi>=0 && xi<r && yj>=0 && yj<c && grid[xi][yj]){
                    count+=dfsArea(xi,yj,grid,r,c);
                }
            }
        }
        return count;
    }
public:
    int findMaxArea(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        
        int mxArea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]){
                  int area=dfsArea(i,j,grid,rows,cols);
                  mxArea=max(mxArea,area);
                }
            }
        }
        return mxArea;
    }
};