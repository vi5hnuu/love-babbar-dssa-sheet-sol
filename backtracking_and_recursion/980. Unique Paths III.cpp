/*
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:


Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.
*/


// class Solution {
// private:
//     int uniquePathsIII(vector<vector<int>> &grid,vector<vector<bool>> &visited,int si,int sj,int &empty){
//         int rows=grid.size();
//         int cols=grid[0].size();

//         if(si<0 || si>=rows || sj<0 || sj>=cols || visited[si][sj] || grid[si][sj]==-1){
//             return 0;
//         }
        
//         if(grid[si][sj]==2){
//             if(empty==0){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }

//         visited[si][sj]=true;
//         empty--;
//         int ans=uniquePathsIII(grid,visited,si,sj+1,empty)+
//                uniquePathsIII(grid,visited,si,sj-1,empty)+
//                uniquePathsIII(grid,visited,si-1,sj,empty)+
//                uniquePathsIII(grid,visited,si+1,sj,empty);
//         empty++;
//         visited[si][sj]=false;
//         return ans;
//     }
// public:
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         int rows=grid.size();
//         int cols=grid[0].size();

//         int empty=0;
//         int si=-1;
//         int sj=-1;

//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(grid[i][j]==1){
//                     si=i;
//                     sj=j;
//                 }else if(grid[i][j]==0){
//                     empty++;
//                 }
//             }
//         }
//         empty++; // for 1
//         vector<vector<bool>> visited(rows,vector<bool>(cols,false));
//         return uniquePathsIII(grid,visited,si,sj,empty);
//     }
// };
/////////////////////////////////////////////
// class Solution {
// private:
//     int uniquePathsIII(vector<vector<int>> &grid,vector<int> &visited,int si,int sj,int &empty){
//         int rows=grid.size();
//         int cols=grid[0].size();

//         if(si<0 || si>=rows || sj<0 || sj>=cols || visited[si]&(1<<sj) || grid[si][sj]==-1){
//             return 0;
//         }
        
//         if(grid[si][sj]==2){
//             if(empty==0){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }

//         visited[si]=visited[si]|(1<<sj);
//         empty--;
//         int ans=uniquePathsIII(grid,visited,si,sj+1,empty)+
//                uniquePathsIII(grid,visited,si,sj-1,empty)+
//                uniquePathsIII(grid,visited,si-1,sj,empty)+
//                uniquePathsIII(grid,visited,si+1,sj,empty);
//         empty++;
//         visited[si]=visited[si] & ~(1<<sj);
//         return ans;
//     }
// public:
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         int rows=grid.size();
//         int cols=grid[0].size();

//         int empty=0;
//         int si=-1;
//         int sj=-1;

//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(grid[i][j]==1){
//                     si=i;
//                     sj=j;
//                 }else if(grid[i][j]==0){
//                     empty++;
//                 }
//             }
//         }
//         empty++; // for 1
//         vector<int> visited(rows,0);
//         return uniquePathsIII(grid,visited,si,sj,empty);
//     }
// };
////////////////////////////////
class Solution {
private:
    int uniquePathsIII(vector<vector<int>> &grid,int si,int sj,int &empty){
        int rows=grid.size();
        int cols=grid[0].size();

        if(si<0 || si>=rows || sj<0 || sj>=cols || grid[si][sj]==-1){
            return 0;
        }
        
        if(grid[si][sj]==2){
            if(empty==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        grid[si][sj]=-1;//make it obstable
        empty--;
        int ans=uniquePathsIII(grid,si,sj+1,empty)+
               uniquePathsIII(grid,si,sj-1,empty)+
               uniquePathsIII(grid,si-1,sj,empty)+
               uniquePathsIII(grid,si+1,sj,empty);
        empty++;
        grid[si][sj]=0;
        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int empty=0;
        int si=-1;
        int sj=-1;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }else if(grid[i][j]==0){
                    empty++;
                }
            }
        }
        empty++; // for 1
        return uniquePathsIII(grid,si,sj,empty);
    }
};
//////////memoization dont work here because a cell may be visited twice
/*
for example you are at i,j and at this index you calculated that there are 6 valid path that visit grid[m][n]==2
now after some time throught different path but somehow you came again at i,j and you return 6 which will be wrong
because the path you took before i,j may collide with path you took afterword....visualize it
*/