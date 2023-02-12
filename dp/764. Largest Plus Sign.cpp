/*
You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.

Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

 

Example 1:


Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
Example 2:


Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
 

Constraints:

1 <= n <= 500
1 <= mines.length <= 5000
0 <= xi, yi < n
All the pairs (xi, yi) are unique.
*/


/*
//5 grids needed
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        //You have an n x n
        vector<vector<int>> grid(n,vector<int>(n,1));
        for(const vector<int> &zeroVec:mines){
            grid[zeroVec[0]][zeroVec[1]]=0;
        }
        
        vector<vector<int>> rt,lt,tp,bt;
        rt=lt=tp=bt=grid;
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                // how many 1's to left dp
                if(lt[i][n-1-j]==0){
                    lt[i][n-1-j]=0;
                }else{
                    lt[i][n-1-j]=1+ ((n-1-j-1)>=0 ? lt[i][n-1-j-1] : 0);
                }
                
                //how many 1's to right dp
                if(rt[i][j]==0){
                    rt[i][j]=0;
                }else{
                    rt[i][j]=1+ (j+1<n ? rt[i][j+1] : 0);
                }

                // how many 1's to bottom dp
                if(bt[j][i]==0){
                    bt[j][i]=0;
                }else{
                    bt[j][i]=1+ (j+1<n ? bt[j+1][i] : 0);
                }

                //how many 1's to top dp
                if(tp[n-1-j][i]==0){
                    tp[n-1-j][i]=0;
                }else{
                    tp[n-1-j][i]=1+ ((n-1-j-1)>=0 ? tp[n-1-j-1][i] : 0);
                }
            }
        }

        int maxPlusSize=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout<<lt[i][j]<<" "<<rt[i][j]<<" "<<tp[i][j]<<" "<<bt[i][j]<<endl;
                int mn=min(lt[i][j],min(rt[i][j],min(tp[i][j],bt[i][j])));
                maxPlusSize=max(maxPlusSize,mn);
            }
        }
        return maxPlusSize;
    }
};
*/

//combining 5 grids in to 1 => total 1 grids
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        //You have an n x n
        vector<vector<int>> grid(n,vector<int>(n,n));
        for(const vector<int> &zeroVec:mines){
            grid[zeroVec[0]][zeroVec[1]]=0;
        }
        
        for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n; j++, k--) {
            grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));  // left direction
            grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0 ? 0 : r + 1));  // right direction
            grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));  // up direction
            grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0 ? 0 : d + 1));  // down direction
        }
    }

        int maxPlusSize=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxPlusSize=max(maxPlusSize,grid[i][j]);
            }
        }
        return maxPlusSize;
    }
};