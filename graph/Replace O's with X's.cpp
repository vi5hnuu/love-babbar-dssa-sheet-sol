/*
Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes n, m and mat as input parameters ad returns a 2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/


//2 traversal for each component...
// class Solution{
// private:
//     bool isLeaked(int sr,int sc,vector<vector<char>> &mat){
//         if(sr<0 || sc<0 || sr>=mat.size() || sc>=mat[0].size()){
//             return true;
//         }
//         if(mat[sr][sc]=='X'){
//             return false;
//         }
//         mat[sr][sc]='X';
//         bool ans=isLeaked(sr,sc+1,mat) ||
//             isLeaked(sr,sc-1,mat) ||
//             isLeaked(sr+1,sc,mat) ||
//             isLeaked(sr-1,sc,mat);
//         mat[sr][sc]='O';
//         return ans;
//     }
//     void fillX(int sr,int sc,vector<vector<char>> &mat){
//         if(mat[sr][sc]=='X'){
//             return;
//         }
//         mat[sr][sc]='X';
//         fillX(sr,sc+1,mat);
//         fillX(sr,sc-1,mat);
//         fillX(sr+1,sc,mat);
//         fillX(sr-1,sc,mat);
//     }
// public:
//     vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
//         int rows=mat.size();
//         int cols=mat[0].size();
        
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(mat[i][j]=='O'){
//                     if(!isLeaked(i,j,mat)){
//                         fillX(i,j,mat);
//                     }
//                 }
//             }
//         }
//         return mat;
//     }
// };
/////////////////////////////////////////////
class Solution{
private:
    void invalidate(int sr,int sc,vector<vector<char>> &mat,vector<vector<bool>> &invalid){
        if(sr<0 || sc<0 || sr>=mat.size() || sc>=mat[0].size() || mat[sr][sc]=='X' || invalid[sr][sc]){
            return;
        }
        invalid[sr][sc]=true;
        invalidate(sr,sc+1,mat,invalid);
        invalidate(sr,sc-1,mat,invalid);
        invalidate(sr+1,sc,mat,invalid);
        invalidate(sr-1,sc,mat,invalid);
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        vector<vector<bool>> invalids(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){//1st last col boundry 'O' dfs invalidate
            if(mat[i][0]=='O' && !invalids[i][0]){//path should be invalid but is not marked
                invalidate(i,0,mat,invalids);
            }
            if(mat[i][m-1]=='O' && !invalids[i][m-1]){//path should be invalid but is not marked
                invalidate(i,m-1,mat,invalids);    
            }
        }
        for(int i=1;i<m-1;i++){//1st lastrest
            if(mat[0][i]=='O' && !invalids[0][i]){//path should be invalid but is not marked
                invalidate(0,i,mat,invalids);
            }
            if(mat[n-1][i]=='O' && !invalids[n-1][i]){//path should be invalid but is not marked
                invalidate(n-1,i,mat,invalids);    
            }
        }
        ////////////////fill mat
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && !invalids[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};