/*
Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
Note: 'X' shape consists of one or more adjacent X's (diagonals not included).
 

Example 1:

Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
Output: 3
Explanation: 
The grid is-
X(Red)      O    X(Green)
O       X(Blue)     O
X(Blue) X(Blue) X(Blue)
So, X with same colour are adjacent to each 
other vertically for horizontally (diagonals 
not included). So, there are 3 different groups 
in the given grid.

Example 2:

Input: grid = {{X,X},{X,X}}
Output: 1
Expanation: 
The grid is- 
X X
X X
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there is only 1 group
in the given grid.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function xShape() which takes grid as input parameter and returns the count of total X shapes.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 100
*/


class Solution{
private:
    void xShape(vector<vector<char>>& grid,const int &rows,const int &cols,int i,int j){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]=='O'){
            return;
        }
        grid[i][j]='O';
        xShape(grid,rows,cols,i,j+1);
        xShape(grid,rows,cols,i,j-1);
        xShape(grid,rows,cols,i+1,j);
        xShape(grid,rows,cols,i-1,j);
    }
public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='X'){
                    count++;
                    xShape(grid,rows,cols,i,j);
                }
            }
        }
        return count;
    }
};