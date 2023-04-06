/*
Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3
M=4
A=[[1,0,0,0], 
[1,1,0,1],[0,1,1,1]]
X=2
Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
Example 2:

Input:
N=3
M=4
A=[[1,1,1,1],
[0,0,0,1],[0,0,0,1]]
X=0
Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).

Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.


Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(N*M)

 

Constraints:
1 <= N,M <= 250

0 <= X < N

0 <= Y < M
0 <= A[i][j] <= 1
*/


class Solution {
private:
    bool isValidPos(int nxi,int nyi,int N,int M,vector<vector<int>> &A){
        if(nxi<0 || nyi<0 || nxi>=N || nyi>=M || A[nxi][nyi]!=1){
            return false;
        }
        return true;
    }
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[X][Y]==0 || A[0][0]==0){
            return -1;
        }
        if(X==Y && X==0){
            return 0;
        }
        queue<pair<int,int>> nodes;
        nodes.push({0,0});
        A[0][0]=0;
        
        int steps=0;
        int xi[4]={0,0,1,-1};
        int yi[4]={1,-1,0,0};
        while(!nodes.empty()){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                pair<int,int> pos=nodes.front();
                nodes.pop();
                int x=pos.first;
                int y=pos.second;
                for(int i=0;i<4;i++){
                    int nxi=x+xi[i];
                    int nyi=y+yi[i];
                    if(nxi==X && nyi==Y){
                        return steps+1;
                    }
                    if(isValidPos(nxi,nyi,N,M,A)){
                        nodes.push({nxi,nyi});
                        A[nxi][nyi]=0;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};