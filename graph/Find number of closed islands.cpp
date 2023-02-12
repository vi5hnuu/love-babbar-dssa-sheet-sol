/*
Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. Find the number of closed islands in the given matrix.

A closed island is known as the group of 1s
that is surrounded by only 0s on all the four
sides (excluding diagonals). If any 1 is at
the edges of the given matrix then it is not
considered as the part of the connected
island as it is not surrounded by all 0's.

Example 1:

Input:
N = 5, M = 8
mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 0, 1}, 
           {0, 1, 0, 1, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 1, 0}, 
           {0, 0, 0, 0, 0, 0, 0, 1}}
Output:
2
Explanation:
mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 0, 1}, 
           {0, 1, 0, 1, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 1, 0}, 
           {0, 0, 0, 0, 0, 0, 0, 1}} 
There are 2 closed islands. 
The islands in dark are closed because
they are completely surrounded by 0s (water). 
There are two more islands in the last
column of the matrix, but they are not
completely surrounded by 0s. 
Hence they are not closed islands. 
Example 2:

Input:
N = 3, M = 3
mat[][] = {{1, 0, 0},
           {0, 1, 0},
           {0, 0, 1}}
Output:
1

Your task:
You dont need to read input or print anything. Your task is to complete the function closedIslands() which takes two integers N and M, and a 2D binary matrix mat as input parameters and returns the number of closed islands.


Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)


Constraints:
1 ≤ N,M ≤ 500
*/


class Solution {
private:
    bool isLeakeddfs(int i,int j,vector<vector<int>> &matrix,int &N,int &M){
        if(i<0 || j<0 || i>=N || j>=M){//crossed boundry
            return true;
        }
        if(matrix[i][j]==0){
            return false;
        }
        matrix[i][j]=0;
        
        //[not executing some fun will leave 1 in matrix even though they should be remove for this path if this path is invalid]
        // return isLeakeddfs(i,j+1,matrix,N,M)|| 
        // isLeakeddfs(i,j-1,matrix,N,M)||
        // isLeakeddfs(i+1,j,matrix,N,M)||
        // isLeakeddfs(i-1,j,matrix,N,M);
        
        //making whole path invalid if this path is invalid is necessary
        bool a=isLeakeddfs(i,j+1,matrix,N,M); 
        bool b=isLeakeddfs(i,j-1,matrix,N,M);
        bool c=isLeakeddfs(i+1,j,matrix,N,M);
        bool d=isLeakeddfs(i-1,j,matrix,N,M);
        return a||b||c||d; //then return true or false
    }
public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int closedIslands=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j]){
                    closedIslands+=!isLeakeddfs(i,j,matrix,N,M);
                }
            }
        }
        return closedIslands;
    }
};