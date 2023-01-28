/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        vector<bool> rowZero(rows,false);        
        vector<bool> colZero(rows,false);        

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    rowZero[i]=true;
                    colZero[j]=true;
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(rowZero[i] || colZero[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
//////////////////////////////////////////////////////////////
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        bool zeroCol=false;
        bool zeroRow=false;
        
        for(int i=0;i<rows;i++){//check for first col
            if(matrix[i][0]==0){
                zeroCol=true;
                break;
            }
        }
        for(int i=0;i<cols;i++){//check for first row
            if(matrix[0][i]==0){
                zeroRow=true;
                break;
            }
        }
        //store states of all elements except of first row and first col in first row and first col
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }
        //fill zero for all elements except of first row and first col.
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        if(zeroCol)
        for(int i=0;i<rows;i++){//fill first col
            matrix[i][0]=0;
        }
        
        if(zeroRow)
        for(int i=0;i<cols;i++){//fill first row
            matrix[0][i]=0;
        }
    }
};