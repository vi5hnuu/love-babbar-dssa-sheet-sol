/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
*/


class Solution {
private:
    void getShape(int i,int j,pair<int,int> &base,vector<vector<int>> &grid,int &r,int &c,vector<pair<int,int>> &shape,set<vector<pair<int,int>>> &shapes){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        shape.push_back({i-base.first,j-base.second});
        getShape(i,j+1,base,grid,r,c,shape,shapes);
        getShape(i,j-1,base,grid,r,c,shape,shapes);
        getShape(i+1,j,base,grid,r,c,shape,shapes);
        getShape(i-1,j,base,grid,r,c,shape,shapes);
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> shapes;
        
        int rows=grid.size();
        int cols=grid[0].size();
        
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>> shape;
                    pair<int,int> base=make_pair(i,j);
                    getShape(i,j,base,grid,rows,cols,shape,shapes);
                    shapes.insert(shapes.end(),shape);
                }
            }
        }
        return shapes.size();
    }
};