/*
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.

Example 1:

Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.
Example 2:

Input:
grid[][] = {{1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1}}
source = {0, 0}
destination = {3, 4}
Output:
-1
Explanation:
The path is not possible between source and 
destination, hence return -1.
Your Task:

You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a 2D integer array grid, source cell and destination cell as an input parameters and returns the shortest distance between source and destination cell.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:

1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
The source and destination cells are always inside the given matrix.
The source and destination cells always contain 1.
*/


//TLE DFS based
// class Solution {
// private:
//     int getMin(initializer_list<int> nums){
//         int mn=INT_MAX;
//         for(int n:nums){
//             mn=min(mn,n);
//         }
//         return mn;
//     }
//     int dfs(int si,int sj,int &di,int &dj,vector<vector<int>> &grid,int &r,int &c){
//         if(si<0 || si>=r || sj<0 || sj>=c || grid[si][sj]==0){
//             return INT_MAX;
//         }
//         if(si==di && sj==dj){
//             return 0;
//         }
//         grid[si][sj]=0;
//         int ad=dfs(si,sj+1,di,dj,grid,r,c);
//         int bd=dfs(si,sj-1,di,dj,grid,r,c);
//         int cd=dfs(si+1,sj,di,dj,grid,r,c);
//         int dd=dfs(si-1,sj,di,dj,grid,r,c);
//         grid[si][sj]=1;
//         int mn=getMin({ad,bd,cd,dd});
//         return (mn==INT_MAX ? INT_MAX : mn+1);
//     }
// public:
//     int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
//                      pair<int, int> destination) {
//         int rows=grid.size();
//         int cols=grid[0].size();
//         int res=dfs(source.first,source.second,destination.first,destination.second,grid,rows,cols);
    
//         return res==INT_MAX ? -1 : res;                     
//     }
// };

///////////////////////////////
//BFS BASED
class Solution {
private:
    int getMin(initializer_list<int> nums){
        int mn=INT_MAX;
        for(int n:nums){
            mn=min(mn,n);
        }
        return mn;
    }
    int bfs(int si,int sj,int &di,int &dj,vector<vector<int>> &grid,int &r,int &c){
        if(si==di && sj==dj){
            return 0;
        }
        queue<pair<int,int>> nodes;
        nodes.push({si,sj});
        grid[si][sj]=0;
        int level=0;
        int xi[4]={0,0,1,-1};
        int xj[4]={1,-1,0,0};
        while(!nodes.empty()){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                auto pos=nodes.front();
                nodes.pop();
                for(int i=0;i<4;i++){
                    int x=pos.first+xi[i];
                    int y=pos.second+xj[i];
                    if(x>=0 && x<r && y>=0 && y<c && grid[x][y]){
                        grid[x][y]=0;
                        nodes.push({x,y});
                        
                        if(x==di && y==dj){
                            return level+1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int rows=grid.size();
        int cols=grid[0].size();
        int res=bfs(source.first,source.second,destination.first,destination.second,grid,rows,cols);
    
        return res;                     
    }
};