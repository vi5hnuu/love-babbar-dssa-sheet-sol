/*
You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.

Note:
Two ways are considered different if sets of indexes of elements chosen by these ways are different.

Input is given such that the answer will fit in a 32-bit integer.
For Example:
If N = 4 and tar = 3 and the array elements are [1, 2, 2, 3], then the number of possible ways are:
{1, 2}
{3}
{1, 2}
Hence the output will be 3.
Input Format :
The first line of the input contains an integer, 'T’, denoting the number of test cases.

The first line of each test case will contain two space-separated integers ‘N’ and “tar”, denoting the size of the array and the target sum.

The second line of each test case contains ‘N’ space-separated integers denoting elements of the array.
Output Format :
For each test case, print the number of ways that satisfy the condition mentioned in the problem statement.

Print a separate line for each test case.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 100
0 <= nums[i] <= 1000
1 <= tar <= 1000

Time limit: 1 sec
*/

#include <bits/stdc++.h> 

// int findWays(vector<int>& nums,int idx,int tar) {
//     if(tar<0){
//         return 0;
//     }
//     if(idx>=nums.size()){
//         return tar==0;
//     }
//     int take=findWays(nums,idx+1,tar-nums[idx]);
//     int notTake=findWays(nums,idx+1,tar);
//     return take+notTake;
// }
// int findWays(vector<int>& nums, int tar) {
//     //1 <= tar <= 1000
//     return findWays(nums,0,tar);
// }
////////////////////////////////////////////
// int findWays(vector<int>& nums,int idx,int tar,vector<vector<int>> &memo) {
//     if(tar<0){
//         return 0;
//     }
//     if(idx>=nums.size()){
//         return tar==0;
//     }
//     if(memo[idx][tar]!=-1){
//         return memo[idx][tar];
//     }
//     int take=findWays(nums,idx+1,tar-nums[idx],memo);
//     int notTake=findWays(nums,idx+1,tar,memo);
//     return memo[idx][tar]=take+notTake;
// }
// int findWays(vector<int>& nums, int tar) {
//     //1 <= tar <= 1000
//     int len=nums.size();
//     vector<vector<int>> memo(len,vector<int>(tar+1,-1));
//     return findWays(nums,0,tar,memo);
// }
////////////////////////////////////////////////////
int findWays(vector<int>& nums, int tar) {
    //1 <= tar <= 1000
    int len=nums.size();
    vector<vector<int>> dp(tar+1,vector<int>(len,0));
    /*
    1
    5 3
    1 0 2 0 3 
    */
  
      
    if(nums[0]<=tar) //column 0 settled
        dp[nums[0]][0]=1;
    
    if(nums[0]==0) 
        dp[0][0]=2;//in recursion it is counted check that..but in dp its not
    else{
        dp[0][0]=1;
    }// eg tar=1 nums[0]=0 -> ways=2 empty+[0] i.e take+nottake
        /*
        eg [0,1] -> [0] | [1]<-generate x ways
        total ways = 2*x => take zero+dont take zero

        or

        [0,0,0,1]
        solve for [1] x ways
        1<<3 * x total ways
        */
    for(int i=0;i<tar+1;i++){
        for(int j=1;j<len;j++){
                dp[i][j]=dp[i][j-1];
                if(i>=nums[j]){
                    dp[i][j]+=dp[i-nums[j]][j-1];
                }
        }
    }
    return dp[tar][len-1];
}
