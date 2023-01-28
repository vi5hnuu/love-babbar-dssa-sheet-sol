/*
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

 

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000
 

Constraints:

1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n - 1
*/

/*
//TLE 11 / 22
// class Solution {
// private:
//     double knightRemainInsideMoves(int n, int moves, int row, int column) {
//         if(moves==0){
//             if(row<0 || column<0 || row>=n || column>=n){
//                 return 0;
//             }else{
//                 return 1;;
//             }
//         }
//         if(row<0 || column<0 || row>=n || column>=n){
//                 return 0;
//         }
//         double total=knightRemainInsideMoves(n,moves-1,row-2,column+1)+
//                 knightRemainInsideMoves(n,moves-1,row-2,column-1)+
//                 knightRemainInsideMoves(n,moves-1,row+2,column+1)+
//                 knightRemainInsideMoves(n,moves-1,row+2,column-1)+
//                 knightRemainInsideMoves(n,moves-1,row+1,column-2)+
//                 knightRemainInsideMoves(n,moves-1,row-1,column-2)+
//                 knightRemainInsideMoves(n,moves-1,row+1,column+2)+
//                 knightRemainInsideMoves(n,moves-1,row-1,column+2);
//         return total;
//     }
// public:
//     double knightProbability(int n, int k, int row, int column) {
//         double insideCount=knightRemainInsideMoves(n,k,row,column);
//         double totalOcc=pow(8,k);
//         return insideCount/totalOcc;
//     }
// };
//////////////////////////////////////////////////////////
// class Solution {
// private:
//     double knightRemainInsideMoves(int n, int moves, int row, int column,vector<vector<vector<double>>> &memo) {
//         if(moves==0){
//             if(row<0 || column<0 || row>=n || column>=n){
//                 return 0;
//             }else{
//                 return 1;;
//             }
//         }
//         if(row<0 || column<0 || row>=n || column>=n){
//                 return 0;
//         }
//         if(memo[row][column][moves]!=-1.0){
//             return memo[row][column][moves];
//         }
//         double total=memo[row][column][moves]=knightRemainInsideMoves(n,moves-1,row-2,column+1,memo)+
//                 knightRemainInsideMoves(n,moves-1,row-2,column-1,memo)+
//                 knightRemainInsideMoves(n,moves-1,row+2,column+1,memo)+
//                 knightRemainInsideMoves(n,moves-1,row+2,column-1,memo)+
//                 knightRemainInsideMoves(n,moves-1,row+1,column-2,memo)+
//                 knightRemainInsideMoves(n,moves-1,row-1,column-2,memo)+
//                 knightRemainInsideMoves(n,moves-1,row+1,column+2,memo)+
//                 knightRemainInsideMoves(n,moves-1,row-1,column+2,memo);
//         return total;
//     }
// public:
//     double knightProbability(int n, int k, int row, int column) {
//         vector<vector<vector<double>>> memo(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
//         double insideCount=knightRemainInsideMoves(n,k,row,column,memo);
//         double totalOcc=pow(8,k);
//         return insideCount/totalOcc;
//     }
// };
//////////////////////////////////////////////////////////
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n,vector<double>(n,0.0));
        dp[row][column]=1;//1 horse at this position

        for(int move=1;move<=k;move++){
            vector<vector<double>> temp(n,vector<double>(n,0.0));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[i][j]+= (i-2>=0 && j+1<n) ? dp[i-2][j+1] : 0;
                    temp[i][j]+= (i-2>=0 && j-1>=0) ? dp[i-2][j-1] : 0;
                    temp[i][j]+= (i+2<n && j+1<n) ? dp[i+2][j+1] : 0;
                    temp[i][j]+= (i+2<n && j-1>=0) ? dp[i+2][j-1] : 0;
                    temp[i][j]+= (i+1<n && j-2>=0) ? dp[i+1][j-2] : 0;
                    temp[i][j]+= (i-1>=0 && j-2>=0) ? dp[i-1][j-2] : 0;
                    temp[i][j]+= (i+1<n && j+2<n) ? dp[i+1][j+2] : 0;
                    temp[i][j]+= (i-1>=0 && j+2<n) ? dp[i-1][j+2] : 0;
                }
            }
            dp=temp;
        }
        double countIn=0.0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                countIn+=dp[i][j];
            }
        }
        return countIn/pow(8,k);
    }
};

/////////////////////////////////////////////
class Solution {
private:
    double knightRemainInsideMoves(int n, int moves, int row, int column,vector<vector<double>> &memo) {
        if(moves==0){
            if(row<0 || column<0 || row>=n || column>=n){
                return 0;
            }else{
                return 1;;
            }
        }
        if(row<0 || column<0 || row>=n || column>=n){
                return 0;
        }
        if(memo[row*n+column][moves]!=-1.0){
            return memo[row*n+column][moves];
        }
        double total=memo[row*n+column][moves]=knightRemainInsideMoves(n,moves-1,row-2,column+1,memo)+
                knightRemainInsideMoves(n,moves-1,row-2,column-1,memo)+
                knightRemainInsideMoves(n,moves-1,row+2,column+1,memo)+
                knightRemainInsideMoves(n,moves-1,row+2,column-1,memo)+
                knightRemainInsideMoves(n,moves-1,row+1,column-2,memo)+
                knightRemainInsideMoves(n,moves-1,row-1,column-2,memo)+
                knightRemainInsideMoves(n,moves-1,row+1,column+2,memo)+
                knightRemainInsideMoves(n,moves-1,row-1,column+2,memo);
        return total;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> memo(n*n,vector<double>(k+1,-1.0));
        double insideCount=knightRemainInsideMoves(n,k,row,column,memo);
        double totalOcc=pow(8,k);
        return insideCount/totalOcc;
    }
};
*/