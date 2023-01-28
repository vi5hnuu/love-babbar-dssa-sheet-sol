/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //for each row
        int row=0;
        int bitcols[9]={0};
        for(int i=0;i<3;i++){
            
            int col=0;
            int bitrow[3]={0};
            //3 times per row
            for(int j=0;j<3;j++){
                int eachCube=0;//index 1-9
                //cube
                for(int x=row;x<row+3;x++){
                    for(int y=col;y<col+3;y++){
                        if(board[x][y]!='.'){
                            //validating each cube
                            int digit=board[x][y]-'0';
                            if(((eachCube>>digit)&1)==1){
                                return false;
                            }else{
                                eachCube=eachCube| (1<<digit);
                            }
                            //validating rows
                            if(((bitrow[x%3]>>digit)&1)==1){
                                return false;
                            }else{
                                bitrow[x%3]=bitrow[x%3]| (1<<digit);
                            }
                           
                            //validating cols
                            if(((bitcols[y]>>digit)&1)==1){
                                return false;
                            }else{
                                bitcols[y]=bitcols[y] | (1<<digit);
                            }
                        
                        }
                    }
                }
                col+=3;
            }
            row+=3;
        }
            return true;
    }
};