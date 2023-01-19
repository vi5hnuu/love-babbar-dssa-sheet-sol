/*
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
*/

// TLE 76 / 94 
// class Solution {
// public:
//     int findPaths(int m, int n, int maxMove, int i, int j) {
//         if(i<0 || j<0 || j>=n || i>=m){
//             return 1;
//         }
//         if(maxMove<=0){
//             return 0;
//         }

//         //some of balls vibrate but maxMoves got us as it will terminate the otherwise
//         //infinite recursion
//         int total=findPaths(m,n,maxMove-1,i,j+1)+
//         findPaths(m,n,maxMove-1,i,j-1)+
//         findPaths(m,n,maxMove-1,i+1,j)+
//         findPaths(m,n,maxMove-1,i-1,j);
//         return total%1000000007;
//     }
// };
/////////////////////////////////////////////////////////
// class Solution {
// private:
//     long long findPaths(int m, int n, int maxMove, int i, int j,vector<vector<vector<long long>>> &memo) {
//         if(i<0 || j<0 || j>=n || i>=m){
//             return 1;
//         }
//         if(maxMove<=0){
//             return 0;
//         }
//         if(memo[i][j][maxMove]!=-1){
//             return memo[i][j][maxMove];
//         }
//         //some of balls vibrate but maxMoves got us as it will terminate the otherwise
//         //infinite recursion
//         long long total=findPaths(m,n,maxMove-1,i,j+1,memo)+
//                         findPaths(m,n,maxMove-1,i,j-1,memo)+
//                         findPaths(m,n,maxMove-1,i+1,j,memo)+
//                         findPaths(m,n,maxMove-1,i-1,j,memo);
//         return memo[i][j][maxMove]=total%1000000007;
//     }
// public:
//     long long findPaths(int m, int n, int maxMove, int i, int j) {
//         vector<vector<vector<long long>>> memo(m,vector<vector<long long>>(n,vector<long long>(maxMove+1,-1)));
//         return findPaths(m,n,maxMove,i,j,memo);
//     }
// };
////////////////////////////////////
class Solution {
private:
    long long findPaths(int m, int n, int maxMove, int i, int j,vector<vector<vector<long long>>> &memo) {
        if(i<0 || j<0 || j>=n || i>=m){
            return 1;
        }
        if(maxMove<=0){
            return 0;
        }
        if(memo[i][j][maxMove]!=-1){
            return memo[i][j][maxMove];
        }
        //some of balls vibrate but maxMoves got us as it will terminate the otherwise
        //infinite recursion
        long long total=findPaths(m,n,maxMove-1,i,j+1,memo)+
                        findPaths(m,n,maxMove-1,i,j-1,memo)+
                        findPaths(m,n,maxMove-1,i+1,j,memo)+
                        findPaths(m,n,maxMove-1,i-1,j,memo);
        return memo[i][j][maxMove]=total%1000000007;
    }
    void printMatrix(const vector<vector<long long>> &matrix){
        int rows=matrix.size();
        int cols=matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<matrix[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
public:
    long long findPaths(int m, int n, int maxMove, int x, int y) {
        const int M=1000000007;
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        dp[x][y]=1;//football

        int count=0;
        for(int move=1;move<=maxMove;move++){
            cout<<"Move : "<<move-1<<endl;
            printMatrix(dp);
            vector<vector<long long>> temp(m,vector<long long>(n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if (i == m - 1) count = (count + dp[i][j]) % M;
                    if (j == n - 1) count = (count + dp[i][j]) % M;
                    if (i == 0) count = (count + dp[i][j]) % M;
                    if (j == 0) count = (count + dp[i][j]) % M;

                    temp[i][j] = (((i > 0 ? dp[i - 1][j] : 0) +
                                  (i < m - 1 ? dp[i + 1][j] : 0)) % M +
                                  ((j > 0 ? dp[i][j - 1] : 0) +
                                   (j < n - 1 ? dp[i][j + 1] : 0)) % M) % M;
                }
            }
            cout<<"\nCount : "<<count;
            cout<<"\n--------------------------------------\n";

            dp=temp;
        }
        return count;
    }
};

/*
m=5
n=5
maxMove=10
startRow=2
startCol=2

dp[x][y]=1 : in code represent 1 bootball

Move : 0 ====> 1 bootball
This pic depict that if we add boundry of matrix then we get 
count of all footballs that will reached out of boundry in 1 move
0  0  0  0  0  
0  0  0  0  0  
0  0  1  0  0  
0  0  0  0  0  
0  0  0  0  0  

Count : 0
--------------------------------------
Move : 1 ====> 4 bootball
This pic depict that if we add boundry of matrix then we get 
count of all footballs that will reached out of boundry in 2 move
0  0  0  0  0  
0  0  1  0  0  
0  1  0  1  0  
0  0  1  0  0  
0  0  0  0  0  

Count : 0
--------------------------------------
Move : 2
This pic depict that if we add boundry of matrix then we get 
count of all footballs that will reached out of boundry in 3 move
0  0  1  0  0  
0  2  0  2  0  
1  0  4  0  1  
0  2  0  2  0  
0  0  1  0  0  

Count : 4
--------------------------------------
Move : 3
0  3  0  3  0  
3  0  9  0  3  
0  9  0  9  0  
3  0  9  0  3  
0  3  0  3  0  

Count : 28
--------------------------------------
Move : 4
    up            up 
 <- 6  0  15  0  6->  
  0  24  0  24  0  
  15  0  36  0  15  
  0  24  0  24  0  
  6  0  15  0  6  

Count : 136
--------------------------------------
Move : 5
0  45  0  45  0  
45  0  99  0  45  
0  99  0  99  0  
45  0  99  0  45  
0  45  0  45  0  

Count : 496
--------------------------------------
Move : 6
90  0  189  0  90  
0  288  0  288  0  
189  0  396  0  189  
0  288  0  288  0  
90  0  189  0  90  

Count : 1972
--------------------------------------
Move : 7
0  567  0  567  0  
567  0  1161  0  567  
0  1161  0  1161  0  
567  0  1161  0  567  
0  567  0  567  0  

Count : 6508
--------------------------------------
Move : 8
1134  0  2295  0  1134  
0  3456  0  3456  0  
2295  0  4644  0  2295  
0  3456  0  3456  0  
1134  0  2295  0  1134  

Count : 24760
--------------------------------------
Move : 9
This pic depict that if we add boundry of matrix then we get 
count of all footballs that will reached out of boundry in 10 move

0  6885  0  6885  0  
6885WASTE MATRIX0  6885  
0   WASTE MATRIX  0  
6885WASTE MATRIX0  6885  
0  6WASTE MATRIX  0  

Count : 79840
--------------------------------------
*/
