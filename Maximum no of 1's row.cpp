/*
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

Example 1:

Input:
N = 3, M = 4
Mat[] = {{0 1 1 1},
         {0 0 1 1},
         {0 0 1 1}}
Output: 0
Explanation: Row 0 has 3 ones whereas
rows 1 and 2 have just 2 ones.

Example 2:

Input: 
N = 2, M = 2
Mat[] = {{0 1},
         {1 1}}
Output: 1
Explanation: Row 1 has 2 ones whereas
row 0 has just a single one. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxOnes () which takes a 2D array Mat[][] and its dimensions N and M as inputs and returns the row index with the maximum number of 1s (0-based index). If there are multiple rows with the maximum number of ones, then return the row with the smaller index.


Expected Time Complexity: O(NLogM).
Expected Auxiliary Space: O(1).


Constraints:
1 <= N, M <= 40
0 <= M[ ][ ] <= 1
*/


class Solution{
private:
    int maxOnes(vector<int> &zo){
        int sz=zo.size();
        if(zo[sz-1]==0){
            return 0;
        }
        int low=0;
        int high=sz-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(zo[mid]==1){
              if((mid==0 || zo[mid-1]==0) || mid+1==sz){
                  return sz-mid;
              }else{
                  high=mid-1;
              }
            }else{
                low=mid+1;
            }
        }
        return 0;
    }
public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M){
            int mx=0;
            int idx=-1;
            for(int i=0;i<N;i++){
                int m=maxOnes(Mat[i]);
                if(m>mx){
                    mx=m;
                    idx=i;
                }
            }
            return idx;
        }
};