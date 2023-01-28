/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/


// class Solution {
//     vector<string> ans;
//     vector<vector<string>> all;
// public:
//     vector<vector<string>> solveNQueens(int n) {
        
//         for(int i=1;i<=n;i++)
//             ans.push_back(string(n,'.'));
        
//         help(0,ans);
//         return all;
//     }
//     private:
//     void help(int i,vector<string> &v){
//         if(i==v.size()){
//             all.push_back(ans);
            
//         }
//         else{
//             for(int j=0;j<v[i].size();j++){
//                 if(safe(i,j,v)){
//                     v[i][j]='Q';
//                     help(i+1,v);
//                     v[i][j]='.';
//                 }
//             }

//         }
//     }
//     bool safe(int row,int col ,vector<string> &v){
//         int x=row,y=col;
//         while(x>=0 && y>=0){
//             if(v[x][y]=='Q') return false;

//             x--;
//             y--;
//         }
//         x=row,y=col;
//         while(x>=0 && y>=0){
//             if(v[x][y]=='Q') return false;

//             x--;
//         }
//         x=row,y=col;
//         while(x>=0 && y>=0){
//             if(v[x][y]=='Q') return false;

//             x--;
//             y++;
//         }
//         return true;
//     }
// };

/////////////////////////////
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allPossibleAnswers;
        vector<string> ans;
        for(int i=1;i<=n;i++)
            ans.push_back(string(n,'.'));
        
        help(allPossibleAnswers,0,ans);
        return allPossibleAnswers;
    }
    private:
    void help( vector<vector<string>> &res,int rowIdx,vector<string> &ans){
        if(rowIdx==ans.size()){
            res.push_back(ans);
            return;
        }
        for(int j=0;j<ans[rowIdx].size();j++){
            if(safe(rowIdx,j,ans)){
                ans[rowIdx][j]='Q';
                help(res,rowIdx+1,ans);
                ans[rowIdx][j]='.';
            }
        }
    }
    bool safe(int row,int col ,vector<string> &v){
        int x=row,y=col;
        while(x>=0 && y>=0){//up left diagonal check
            if(v[x][y]=='Q') 
                return false;

            x--;
            y--;
        }
        x=row,y=col;
        while(x>=0 && y>=0){//up
            if(v[x][y]=='Q') 
                return false;

            x--;
        }
        x=row,y=col;
        while(x>=0 && y>=0){//right diagonal check
            if(v[x][y]=='Q') 
                return false;

            x--;
            y++;
        }
        return true;
    }
};