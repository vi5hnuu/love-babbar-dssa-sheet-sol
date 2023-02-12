/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.


Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.


 

Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes the grid as an input parameter and returns a matrix of the same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/


class Solution {
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int rows=grid.size();
	    int cols=grid[0].size();
	    
	    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
	    vector<vector<int>> distance(rows,vector<int>(cols,0));
	    
	    queue<pair<int,int>> que;
	    for(int i=0;i<rows;i++){
	        for(int j=0;j<cols;j++){
	            if(grid[i][j]==1){
	                que.push({i,j});
	                visited[i][j]=true;
	            }
	        }
	    }
	    //for all initial ones there is zero in distacnce matrix already
	    int step=1;
	    while(!que.empty()){
	        int sz=que.size();
	        while(sz>0){
	            sz--;
	            auto pos=que.front();
	            que.pop();
	            int ai[4]={0,0,1,-1};
	            int aj[4]={1,-1,0,0};
	            for(int j=0;j<4;j++){
	                int x=pos.first+ai[j];
	                int y=pos.second+aj[j];
	                if(x>=0 && x<rows && y>=0 && y<cols && !visited[x][y]){
    	                distance[x][y]=step;
    	                visited[x][y]=true;
    	                que.push({x,y});
	                }
	            }
	        }
	        step++;
	    }
	    return distance;
	}
};