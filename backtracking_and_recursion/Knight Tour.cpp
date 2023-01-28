/*
You are given a chessboard consisting of ‘N’ rows and ’M’ columns. Rows are numbered from 0 to ‘N-1’ and columns are numbered from 0 to ‘M-1’. Cell(i, j) is the cell at the intersection of the ith row and the jth column.

A knight is a chess piece that can move from cell (x1, y1) to the cell (x2, y2) if one of the following conditions is met:

|x1−x2| = 2 and |y1−y2| = 1, or

|x1−x2| = 1 and |y1−y2| = 2.

A knight cannot move outside the chessboard.

Initially a knight is placed at the cell(0, 0) of this chessboard, Moving according to the rules of chess, the knight must visit each cell exactly once. Find out the order of each cell in which they are visited.

Note :

1. There are multiple possible orders in which a knight can visit each cell of the chessboard exactly once. You can find any valid order.
2. It may be possible that there is no possible order to visit each cell exactly once. In that case, return a matrix having all the values equal to -1. 
Example :

Consider an 8*8 chessboard, one possible order for visiting each cell exactly once is shown in the image below. Numbers in cells indicate the move number of the Knight. 

Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases.

The next T lines represent the ‘T’ test cases.

The first line of each test case contains two space-separated integers ‘N’ and ‘M’ representing the number of rows and columns in the chessboard respectively.
Output Format :
For each test case, In a separate line print ‘Possible’ If knight tour exist otherwise print ’Impossible’
Note :

You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N, M <= 8

Where ‘T’ is the total number of test cases, ‘N’, ‘M’ is the number of rows and columns respectively.

Time limit: 1 sec
*/


#include <bits/stdc++.h> 

bool knightTour(vector<vector<int>> &path,int rows, int cols,int i,int j,int counter=0) {
        if(counter==rows*cols){
            return true;
        }
        if(i<0 || j<0 || i>=rows || j>=cols || path[i][j]>=0){
            return false;
        }

        path[i][j]=counter;
        bool ans=knightTour(path,rows,cols,i-1,j+2,counter+1)||
                 knightTour(path,rows,cols,i-1,j-2,counter+1)||
                 knightTour(path,rows,cols,i+1,j+2,counter+1)||
                 knightTour(path,rows,cols,i+1,j-2,counter+1)||
                 knightTour(path,rows,cols,i-2,j+1,counter+1)||
                 knightTour(path,rows,cols,i-2,j-1,counter+1)||
                 knightTour(path,rows,cols,i+2,j+1,counter+1)||
                 knightTour(path,rows,cols,i+2,j-1,counter+1);
        if(!ans)
            path[i][j]=-1;
        return ans;
}
vector<vector<int>> knightTour(int rows, int cols) {
    vector<vector<int>> path(rows,vector<int>(cols,-1));
    knightTour(path,rows,cols,0,0);
    // for(auto &v:path){
    //     for(int n:v){
    //         cout<<n<<" ";
    //     }
    //     cout<<endl;
    // }
    return path;
}