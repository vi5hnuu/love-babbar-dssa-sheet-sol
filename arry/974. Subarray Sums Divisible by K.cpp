/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104
*/

// class Solution {
// private:

// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         map<int,int> remainder;
//         remainder[0]=1;
//         int sum=0;
//         int ans=0;

//         for(const int &num : nums){
//             sum+=num;
//             int rem=sum%k;
//             if(rem<0)
//                 rem+=k;
//             if(remainder.find(rem)==remainder.end()){
//                 remainder[rem]=1;
//             }else{
//                 ans+=remainder[rem];
//                 remainder[rem]++;
//             }
//         }
//         return ans;
//     }
// };
/////////////////////////////////////
/*

remcount[0]=1;

if 0..x is leave rem 'r' then if 0...y leave rem 'r' given y>x then x+1 to y is div by k(given num)
*/

class Solution {
private:

public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remainder(k,0);
        remainder[0]=1;
        int sum=0;
        int ans=0;

        for(const int &num : nums){
            sum+=num;
            int rem=sum%k;
            if(rem<0)
                rem+=k;
            if(!remainder[rem]){
                remainder[rem]=1;
            }else{
                ans+=remainder[rem];
                remainder[rem]++;
            }
        }
        return ans;
    }
};