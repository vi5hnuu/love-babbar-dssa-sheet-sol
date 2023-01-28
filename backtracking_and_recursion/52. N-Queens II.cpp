/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 9
*/


class Solution {
public:
    int totalNQueens(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++)
            ans.push_back(string(n,'.'));
        
        return help(0,ans);
    }
    private:
    int help(int rowIdx,vector<string> &ans){
        if(rowIdx==ans.size()){
            return 1;
        }
        int count=0;
        for(int j=0;j<ans[rowIdx].size();j++){
            if(safe(rowIdx,j,ans)){
                ans[rowIdx][j]='Q';
                count+=help(rowIdx+1,ans);
                ans[rowIdx][j]='.';
            }
        }
        return count;
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