/*
//Same problem as partition into two equal subsets but here we search for sum equal to half or slightly less....

PROBLEM STATEMENT
You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.

You just need to find the minimum absolute difference considering any valid division of the array elements.

Note:

1. Each element of the array should belong to exactly one of the subset.

2. Subsets need not be contiguous always. For example, for the array : {1,2,3}, some of the possible divisions are a) {1,2} and {3}  b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset. 
Input Format:
The first line of input contains the integer T, denoting the number of test cases.

The first line of each test case contains an integer N, denoting the size of the array.

The second and the last line of each test case contains N space-separated integers denoting the array elements.
Output Format:
For each test case, return the minimum possible absolute difference in a separate line. 
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^3
0 <= ARR[i] <= 10^3
0 <= SUM <= 10^4, 

where SUM denotes the sum of all elements in the array for a given test case.

Time Limit: 1sec
*/


#include <bits/stdc++.h> 
// int minSubsetSumDifference(vector<int>& nums,int idx,int n,int mnmztarget) {
//     if(mnmztarget<0){
//         return INT_MAX;
//     }
//     if(idx==n){
//         return mnmztarget;
//     }
//     int take=minSubsetSumDifference(nums,idx+1,n,mnmztarget-nums[idx]);
//     if(take==0){//made sum==target...what can be min than this [we can save next recursion in case this happens]
//           return take;
//     }
//     int notTake=minSubsetSumDifference(nums,idx+1,n,mnmztarget);
//     return min(take,notTake);
// }
// int minSubsetSumDifference(vector<int>& nums,int n) {
//     int sum=0;
//     for(const int &n:nums){
//             sum+=n;
//     }
    
//     int hlfSum=ceil(sum*1.0/2);

//     int maxHlfSumMade=hlfSum-minSubsetSumDifference(nums,0,n,hlfSum); 
// //     cout<<"MAX : "<<maxHlfSumMade<<endl;
//     return abs(sum-2*(maxHlfSumMade));
// }
//////////////////////////////////////////////////////////////
int minSubsetSumDifference(vector<int>& nums,int idx,int n,int mnmztarget,vector<vector<int>> &memo) {
    if(mnmztarget<0){
        return INT_MAX;
    }
    if(idx==n){
        return mnmztarget;
    }
    if(memo[idx][mnmztarget]!=-1){
        return memo[idx][mnmztarget];
    }
    int take=minSubsetSumDifference(nums,idx+1,n,mnmztarget-nums[idx],memo);
    if(take==0){//made sum==target...what can be min than this [we can save next recursion in case this happens]
          return memo[idx][mnmztarget]=take;
    }
    int notTake=minSubsetSumDifference(nums,idx+1,n,mnmztarget,memo);
    return memo[idx][mnmztarget]=min(take,notTake);
}
int minSubsetSumDifference(vector<int>& nums,int n) {
    int sum=0;
    for(const int &n:nums){
            sum+=n;
    }
    
    int hlfSum=ceil(sum*1.0/2);
    vector<vector<int>> memo(n,vector<int>(hlfSum+1,-1));
        
    int maxHlfSumMade=hlfSum-minSubsetSumDifference(nums,0,n,hlfSum,memo); 
//     cout<<"MAX : "<<maxHlfSumMade<<endl;
    return abs(sum-2*(maxHlfSumMade));
}
//////////////////////////////////////////////////////////////
// int minSubsetSumDifference(vector<int>& nums,int n) {
//     int sum=0;
//     for(const int &n:nums){
//             sum+=n;
//     }
    
//     int hlfSum=ceil(sum*1.0/2);
//     vector<vector<int>> dp(n,vector<int>(hlfSum+1,0));

//     int maxSumCanMake=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<hlfSum+1;j++){
//             if(j==0){
//                 dp[i][j]=1;
//             }else if(i==0){
//                 dp[i][j]=nums[i]==j ? 1 : 0; 
//             }else{
//                 if(dp[i-1][j] || (j>=nums[i] && dp[i-1][j-nums[i]])){
//                     dp[i][j]=1;
//                 }else{
//                     dp[i][j]=0;
//                 }
//             }
//             if(i==n-1){
//                 if(dp[i][j]){
//                     maxSumCanMake=j;
//                 }
//             }
//         }
//     }
//     return abs(sum-2*maxSumCanMake);
// }