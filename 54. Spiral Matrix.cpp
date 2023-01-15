/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int rows=matrix.size();
//         int cols=matrix[0].size();

//         vector<int> spiralOrder;

//         int col=0;
//         int row=0;

//         //condition : when row is odd +1 loop, when col is odd +1 loop
//         while((row<ceil(rows*1.0/2)) && (col<ceil(cols*1.0/2))){
//             //to right
//             for(int i=col;i<cols-col;i++){
//                 spiralOrder.push_back(matrix[row][i]);
//             }
//             //to bottom
//             for(int j=row+1;j<rows-row;j++){
//                 spiralOrder.push_back(matrix[j][cols-1-col]);
//             }
//             //to left [the row we go right cannot be the row we go left]
//             for(int k=cols-2-col;(row!=(rows-1-row)) && k>=col;k--){
//                 spiralOrder.push_back(matrix[rows-1-row][k]);
//             }
//             //to up [the column we go down cannot be column we go up]
//             for(int l=rows-2-row;((cols-1-col)!=col) && l>row;l--){
//                 spiralOrder.push_back(matrix[l][col]);
//                 cout<<matrix[l][col]<<endl;
//             }
//             col++;
//             row++;
//         }
//         return spiralOrder;
//     }
// };

////////////////////////////////////////////

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<int> spiralOrder;

        int sc=0;
        int ec=cols-1;
        int sr=0;
        int er=rows-1;

        while(sr<=er && sc<=ec){
            //to right
            for(int i=sc;i<=ec;i++){
                spiralOrder.push_back(matrix[sr][i]);
                // cout<<matrix[sr][i]<<"|";
            }
            sr++;
            //to bottom
            for(int j=sr;j<=er;j++){
                spiralOrder.push_back(matrix[j][ec]);
                // cout<<matrix[j][ec]<<"*";
            }
            ec--;
            //to left
            for(int k=ec;er!=(sr-1) && k>=sc;k--){
                spiralOrder.push_back(matrix[er][k]);
                // cout<<matrix[er][k]<<"+";
            }
            er--;
            //to up
            for(int l=er;sc!=(ec+1) && l>=sr;l--){
                spiralOrder.push_back(matrix[l][sc]);
                // cout<<matrix[l][sc]<<"-";
            }
            sc++;
        }
        return spiralOrder;
    }
};