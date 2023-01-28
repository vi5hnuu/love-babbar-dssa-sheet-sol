/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

//TLE
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int sum=nums[i];
//             for(int j=i+1;j<n;j++){
//                 if(sum==k){
//                     count++;
//                 }
//                 sum+=nums[j];
//             }
//                if(sum==k){
//                     count++;
//                 }
//         }
//         return count;
//     }
// };

//////////////////////////////////////////
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> prefix; // sum->time it occur
        prefix[0]=1;

        int sum=0;
        int sumEqK=0;
        for(const int &num:nums){
            sum+=num;
            if(prefix.find(sum-k)!=prefix.end()){
                sumEqK+=prefix[sum-k];
            }
            prefix[sum]++;
        }
        return sumEqK;
    }
};