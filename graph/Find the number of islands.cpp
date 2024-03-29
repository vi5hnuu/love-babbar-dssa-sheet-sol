/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/

class Solution {
    private:
    void traverseIsland(const vector<vector<char>> &grid,int i,int j,vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || visited[i][j]){
            return;
        }
        
        visited[i][j]=true;
         traverseIsland(grid,i-1,j,visited);
         traverseIsland(grid,i,j+1,visited);
         traverseIsland(grid,i,j-1,visited);
         traverseIsland(grid,i+1,j,visited);
         traverseIsland(grid,i-1,j-1,visited);
         traverseIsland(grid,i-1,j+1,visited);
         traverseIsland(grid,i+1,j-1,visited);
         traverseIsland(grid,i+1,j+1,visited);
       
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {//grid is like adjacency list[not exactly as it contain zero]
        int islands=0;
        
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]!='0' && !visited[i][j]){
                    islands++;
                    traverseIsland(grid,i,j,visited);
                }
            }
        }
        return islands;
    }
};
//////////////////////////////////////////////////////////////
class Solution {
    private:
    void traverseIsland(vector<vector<char>> &grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        
         grid[i][j]='0';//convert it to water
         traverseIsland(grid,i-1,j);
         traverseIsland(grid,i,j+1);
         traverseIsland(grid,i,j-1);
         traverseIsland(grid,i+1,j);
         traverseIsland(grid,i-1,j-1);
         traverseIsland(grid,i-1,j+1);
         traverseIsland(grid,i+1,j-1);
         traverseIsland(grid,i+1,j+1);
       
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {//grid is like adjacency list[not exactly as it contain zero]
        int islands=0;
        
        int rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]!='0'){
                    islands++;
                    traverseIsland(grid,i,j);
                }
            }
        }
        return islands;
    }
};


class Solution {
    private://bfs
    void traverseIsland(vector<vector<char>> &grid,int i,int j,const int &r,const int &c){
        queue<pair<int,int>> pq;
        pq.push({i,j});
        grid[i][j]='0';
        
        //adj
        while(!pq.empty()){
            auto pos=pq.front();
            pq.pop();
            
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    int xi=pos.first+x;
                    int yi=pos.second+y;
                    if(xi>=0 && xi<r && yi>=0 && yi<c && grid[xi][yi]=='1'){
                        grid[xi][yi]='0';
                        pq.push({xi,yi});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {//grid is like adjacency list[not exactly as it contain zero]
        int islands=0;
        
        int rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]!='0'){
                    islands++;
                    traverseIsland(grid,i,j,rows,cols);
                }
            }
        }
        return islands;
    }
};