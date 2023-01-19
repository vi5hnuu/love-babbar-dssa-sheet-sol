/*
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.

For Example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
APPROACH 1
We can try all possible array subsets and take them as the first subset. The elements not included in this subset will be taken in the second subset. Let ‘S1’, ‘S2’ be the sum of elements of these two subsets. We then check whether the condition S1 - S2 = D is satisfied or not.

If satisfied, increment the count.

 

The steps are as follows:

Declare a variable ‘ans’ and initialize it to 0. Also, store the sum of all array elements in another variable, ‘total_sum.’
Generate all subsets of the array. We can do it recursively or iteratively.
For generating subsets iteratively, create a variable ‘mask’ that starts from 0 till 2^N - 1.
Now, if the i_th bit is set in this variable mask, it means we can take the i_th element of the array into our first subset; otherwise, we ignore it. We can write a for loop which iterates from 0 to N - 1 to check for each element if it is present in our subset.
 
Note that we don’t have to create the subset explicitly. We only have to maintain a variable that stores the sum of this subset.

Let the sum of the subset be ‘S1’. Then the sum of the elements of the other subset is ‘S2’ = total_sum - S1.
Check if the condition S1 - S2 = D is valid. If it’s true, then increment the ans.
*/

#include <bits/stdc++.h> 
// int countPartitions(vector<int> &nums,int n,int idx,int sums1,int sum,int d){
//     if(idx>=n){
//         return (sums1-(sum-sums1))==d;
//     }
//     if((sums1-(sum-sums1))>d){
//         return 0;
//     }
//     int notTake=countPartitions(nums,n,idx+1,sums1,sum,d);
//     int take=countPartitions(nums,n,idx+1,sums1+nums[idx],sum,d);
//     return (take+notTake)%(1000000007); 
// }
// int summation(const vector<int> &nums,int from,int to){
//     int sum=0;
//     for(int i=from;i<to;i++){
//         sum+=nums[i];
//     }
//     return sum;
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int sum=summation(arr,0,n);
//     if(d>sum){
//         return 0;
//     }
//     if(d==sum){
//         return 1;
//     }
//     if((sum-d)%2!=0){
//         return 0;
//     }
//     return countPartitions(arr,n,0,0,sum,d);
// }
////////////////////////////////////////
// int countPartitions(vector<int> &nums,int n,int idx,int sums1,int sum,int d,vector<vector<int>> &memo){
//     if(idx>=n){
//         return (sums1-(sum-sums1))==d;
//     }
//     if((sums1-(sum-sums1))>d){
//         return 0;
//     }
//     if(memo[idx][sums1]!=-1){
//         return memo[idx][sums1];
//     }
//     int notTake=countPartitions(nums,n,idx+1,sums1,sum,d,memo);
//     int take=countPartitions(nums,n,idx+1,sums1+nums[idx],sum,d,memo);
//     return memo[idx][sums1]=(take+notTake)%(1000000007); 
// }
// int summation(const vector<int> &nums,int from,int to){
//     int sum=0;
//     for(int i=from;i<to;i++){
//         sum+=nums[i];
//     }
//     return sum;
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int sum=summation(arr,0,n);
//     if(d>sum){
//         return 0;
//     }
//     if(d==sum){
//         return 1;
//     }
//     if((sum-d)%2!=0){
//         return 0;
//     }
//     vector<vector<int>> memo(n,vector<int>(sum,-1));
//     return countPartitions(arr,n,0,0,sum,d,memo);
// }
//////////////////////////////////////
// int countPartitions(vector<int> &nums,int n,int idx,int sums1,int sum,int d,vector<vector<int>> &memo){
//     if(idx>=n){
//         return (sums1-(sum-sums1))==d;
//     }
//     if((sums1-(sum-sums1))>d){
//         return 0;
//     }
//     if(memo[idx][sums1]!=-1){
//         return memo[idx][sums1];
//     }
//     int notTake=countPartitions(nums,n,idx+1,sums1,sum,d,memo);
//     int take=countPartitions(nums,n,idx+1,sums1+nums[idx],sum,d,memo);
//     return memo[idx][sums1]=(take+notTake)%(1000000007); 
// }
// int summation(const vector<int> &nums,int from,int to){
//     int sum=0;
//     for(int i=from;i<to;i++){
//         sum+=nums[i];
//     }
//     return sum;
// }
// int countPartitions(int n, int d, vector<int> &arr) {
//     int sum=summation(arr,0,n);
//     if(d>sum){
//         return 0;
//     }
//     if(d==sum){
//         return 1;
//     }
//     if((sum-d)%2!=0){
//         return 0;
//     }
//     //(sums1-(sum-sums1))>d => sums1=(d+sum)/2
//     vector<vector<int>> memo(n,vector<int>((d+sum)/2+1,-1));
//     return countPartitions(arr,n,0,0,sum,d,memo);
// }
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////