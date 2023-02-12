/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1). 

Example 2:

Input:
N=8
knightPos[ ] = {7, 7}
targetPos[ ] = {1, 5}
Output:
4
Explanation:
Knight takes 4 steps to reach from
(7, 7) to (1, 5):
(4, 5) -> (6, 5) -> (5, 3) -> (7, 2) -> (1, 5).
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.If it cannot reach the target position return -1.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
*/


class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    //BFS
	    int ki=KnightPos[0]-1;
	    int kj=KnightPos[1]-1;
	    int ti=TargetPos[0]-1;
	    int tj=TargetPos[1]-1;
	    if(ki==ti && kj==tj){
	        return 0;
	    }
	    queue<pair<int,int>> nodes;
	    nodes.push({ki,kj});
	    vector<vector<bool>> visited(N,vector<bool>(N,false));
	    visited[ki][kj]=true;
	    
	    int x[8]={1,1,-1,-1,-2,-2,2,2};
	    int y[8]={2,-2,2,-2,1,-1,1,-1};
	    int step=0;
	    while(!nodes.empty()){
	        int sz=nodes.size();
	    
	        while(sz>0){
	            sz--;
	            auto pos=nodes.front();
	            nodes.pop();
	            
	            for(int del=0;del<8;del++){
	                    int i=pos.first+x[del];
	                    int j=pos.second+y[del];
	                    if(i>=0 && i<N && j>=0 && j<N && !visited[i][j]){
	                        if(i==ti && j==tj){
	                            return step+1;
	                        }
	                        visited[i][j]=true;
	                        nodes.push({i,j});
	                        
	                    }
	            }
	        }
	        step++;
	    }
	    return -1;
	}
};
