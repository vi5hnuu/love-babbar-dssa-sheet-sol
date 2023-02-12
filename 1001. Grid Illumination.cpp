/*
There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.

You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.

When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.

You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].

Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.

 

Example 1:


Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.

The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0. Then, we turn off all lamps in the red rectangle.

Example 2:

Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
Output: [1,1]
Example 3:

Input: n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
Output: [1,1,0]
 

Constraints:

1 <= n <= 109
0 <= lamps.length <= 20000
0 <= queries.length <= 20000
lamps[i].length == 2
0 <= rowi, coli < n
queries[j].length == 2
0 <= rowj, colj < n
*/


#define ll long long
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        /*
        r-> how many lamp in ith row
        c-> how many lamp in jth col
        r_c-> lamp at r+c | bottom up right diagonal
        c_r-> lamp at r-c+n-1 | bottom up left diagonal
        cell->lamp at cell
        */
        unordered_map<ll,ll> r,c,r_c,c_r,cell;
        for(auto &lamp : lamps){
            ll i=lamp[0];
            ll j=lamp[1];
            if(cell[i*n+j]==0){
                cell[i*n+j]=1;
                r[i]++;
                c[j]++;
                r_c[i+j]++;
                c_r[i-j+n-1]++;
            }
        }
        int ri[9]={0,0,0,1,-1,1,1,-1,-1};
        int ci[9]={0,1,-1,0,0,1,-1,1,-1};
        vector<int> ans;
        for(auto &query:queries){
            ll i=query[0];
            ll j=query[1];

            // cout<<cell[i*n+j]<<" "<<r[i]<<" "<<c[j]<<" "<<c_r[i-j+n-1]<<" "<<r_c[i+j]<<endl;
            if(cell[i*n+j]>0 || r[i]>0 || c[j]>0 || c_r[i-j+n-1]>0 || r_c[i+j]>0){
                //update adj lamps
                for(int rm=0;rm<9;rm++){
                    ll ix=i+ri[rm];
                    ll iy=j+ci[rm];
                    if(ix>=0 && ix<n && iy>=0 && iy<n){
                        if(cell[ix*n+iy]>0){//lamp here
                        // cout<<"turning off "<<(ix*iy+iy)<<endl;
                            cell[ix*n+iy]=0;
                            r[ix]--;
                            c[iy]--;
                            r_c[ix+iy]--;
                            c_r[ix-iy+n-1]--;
                        }
                    }
                }
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};