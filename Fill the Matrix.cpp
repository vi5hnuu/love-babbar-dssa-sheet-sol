/*
Given a matrix with dimensions N x M, entirely filled with zeroes except for one position at co-ordinates X and Y containing '1'. Find the minimum number of iterations in which the whole matrix can be filled with ones.
Note: In one iteration, '1' can be filled in the 4 neighbouring elements of a cell containing '1'.


Example 1:

Input:
N = 2, M = 3
X = 2, Y = 3
Output: 3 

Explanation: 3 is the minimum possible 
number of iterations in which the
matrix can be filled.
Example 2:

Input:
N = 1, M = 1
X = 1, Y = 1 
Output: 0

Explanation: The whole matrix is 
already filled with ones.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minIterations() which takes the dimensions of the matrix N and M and the co-ordinates of the initial position of '1' ie X and Y as input parameters and returns the minimum number of iterations required to fill the matrix.


Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N, M ≤ 103
1 ≤ X ≤ N
1 ≤ Y ≤ M 
*/


class Solution{   
public://BFS
    int minIteration(int N, int M, int x, int y){    
        queue<pair<int,int>> nodes;
        nodes.push({x-1,y-1});
        
        
        vector<vector<int>> grid(N,vector<int>(M,0));
        grid[x-1][y-1]=1;
        int itrs=-1;
        int p_r[4]={1,-1,0,0};
        int p_c[4]={0,0,1,-1};
        while(!nodes.empty()){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                auto itr=nodes.front();
                nodes.pop();
                for(int i=0;i<4;i++){
                    int r=itr.first+p_r[i];
                    int c=itr.second+p_c[i];
                    if(r>=0 && r<N && c>=0 && c<M && grid[r][c]!=1){
                        grid[r][c]=1;
                        nodes.push({r,c});
                    }
                }
            }
            itrs++;
        }
        return itrs;
    }
};