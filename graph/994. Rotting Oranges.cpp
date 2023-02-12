/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

// class Solution {
//     class Position{
//         public:
//             int i{};
//             int j{};
//             int time{};
//     };
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int rows=grid.size();
//         int cols=grid[0].size();

//         queue<Position> rottenOranges;
//         int toRot=0;
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(grid[i][j]==2){
//                     rottenOranges.push({i,j,0});
//                 }else if(grid[i][j]==1){
//                     toRot++;
//                 }
//             }
//         }
//         int time=0;
//         while(!rottenOranges.empty()){
//             Position p=rottenOranges.front();
//             rottenOranges.pop();
//             bool anyRot=false;
//             if(p.j+1<cols && grid[p.i][p.j+1]==1){
//                 grid[p.i][p.j+1]=2;
//                 toRot--;
//                 anyRot=true;
//                 rottenOranges.push({p.i,p.j+1,p.time+1});
//             }
//             if(p.j-1>=0 && grid[p.i][p.j-1]==1){
//                 grid[p.i][p.j-1]=2;
//                 toRot--;
//                 anyRot=true;
//                 rottenOranges.push({p.i,p.j-1,p.time+1});
//             }
//             if(p.i+1<rows && grid[p.i+1][p.j]==1){
//                 grid[p.i+1][p.j]=2;
//                 toRot--;
//                 anyRot=true;
//                 rottenOranges.push({p.i+1,p.j,p.time+1});
//             }
//             if(p.i-1>=0 && grid[p.i-1][p.j]==1){
//                 grid[p.i-1][p.j]=2;
//                 toRot--;
//                 anyRot=true;
//                 rottenOranges.push({p.i-1,p.j,p.time+1});
//             }
//             time=anyRot ? max(time,p.time+1) : time;
//             if(toRot==0){
//                 return time;
//             }
//         }
//         if(toRot==0){
//                 return time;
//         }else{
//             return -1;
//         }
//     }
// };

/////////////////////
// class Solution {
//     class Position{
//         public:
//             int i{};
//             int j{};
//             int time{};
//     };
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int rows=grid.size();
//         int cols=grid[0].size();

//         queue<Position> rottenOranges;
//         int toRot=0;
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(grid[i][j]==2){
//                     rottenOranges.push({i,j,0});
//                 }else if(grid[i][j]==1){
//                     toRot++;
//                 }
//             }
//         }
//         int time=0;
//         while(!rottenOranges.empty()){
//             Position p=rottenOranges.front();
//             rottenOranges.pop();
//             bool anyRot=false;
//             if(p.j+1<cols && grid[p.i][p.j+1]==1){
//                 grid[p.i][p.j+1]=2;
//                 toRot--;
//                 anyRot=true;
//                 rottenOranges.push({p.i,p.j+1,p.time+1});
//             }
//             if(p.j-1>=0 && grid[p.i][p.j-1]==1){
//                 grid[p.i][p.j-1]=2;
//                 toRot--;
//                 anyRot=true;
//                 rottenOranges.push({p.i,p.j-1,p.time+1});
//             }
//             if(p.i+1<rows && grid[p.i+1][p.j]==1){
//                 grid[p.i+1][p.j]=2;
//                 toRot--;
//                 anyRot=true;
//                 rottenOranges.push({p.i+1,p.j,p.time+1});
//             }
//             if(p.i-1>=0 && grid[p.i-1][p.j]==1){
//                 grid[p.i-1][p.j]=2;
//                 toRot--;
//                 anyRot=true;
//                 rottenOranges.push({p.i-1,p.j,p.time+1});
//             }
//             time=anyRot ? max(time,p.time+1) : time;
//             if(toRot==0){
//                 return time;
//             }
//         }
//         if(toRot==0){
//                 return time;
//         }else{
//             return -1;
//         }
//     }
// };

/////////////////////
class Solution {
    class Position{
        public:
            int i{};
            int j{};
            int time{};
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        queue<Position> rottenOranges;
        int toRot=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    rottenOranges.push({i,j,0});
                }else if(grid[i][j]==1){
                    toRot++;
                }
            }
        }
        if(rottenOranges.empty() && toRot>0){
            return -1;
        }else if(toRot==0){
            return 0;
        }
        int time=0;
        while(!rottenOranges.empty()){
            Position p=rottenOranges.front();
            rottenOranges.pop();
            bool anyRot=false;
            if(p.j+1<cols && grid[p.i][p.j+1]==1){
                grid[p.i][p.j+1]=2;
                toRot--;
                anyRot=true;
                rottenOranges.push({p.i,p.j+1,p.time+1});
            }
            if(p.j-1>=0 && grid[p.i][p.j-1]==1){
                grid[p.i][p.j-1]=2;
                toRot--;
                anyRot=true;
                rottenOranges.push({p.i,p.j-1,p.time+1});
            }
            if(p.i+1<rows && grid[p.i+1][p.j]==1){
                grid[p.i+1][p.j]=2;
                toRot--;
                anyRot=true;
                rottenOranges.push({p.i+1,p.j,p.time+1});
            }
            if(p.i-1>=0 && grid[p.i-1][p.j]==1){
                grid[p.i-1][p.j]=2;
                toRot--;
                anyRot=true;
                rottenOranges.push({p.i-1,p.j,p.time+1});
            }
            time=anyRot ? p.time+1 : time;
            if(toRot==0){
                return time;
            }
        }
        return -1;
    }
};