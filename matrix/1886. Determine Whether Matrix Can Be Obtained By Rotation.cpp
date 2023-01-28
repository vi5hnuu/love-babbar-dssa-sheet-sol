/*
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

Example 1:


Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
Example 2:


Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
Example 3:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 

Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.
*/


class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();

        bool deg0=true;
        bool deg90=true;
        bool deg180=true;
        bool deg270=true;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //max rotation 4 [0(given),90,180,270]
                
                //0 degree
                if(mat[i][j]!=target[i][j]) deg0=false;
                if(mat[i][j]!=target[n-1-j][i]) deg90=false;
                if(mat[i][j]!=target[n-1-i][n-1-j]) deg180=false;
                if(mat[i][j]!=target[j][n-1-i]) deg270=false;
            }
        }
        return deg0 || deg90 || deg180 || deg270;
    }
};

