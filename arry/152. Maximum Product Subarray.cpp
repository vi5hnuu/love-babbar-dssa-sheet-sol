// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//using kadane's algo
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0],mn=nums[0];
        int mxp=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(mx,mn);
            mx=max(nums[i],mx*nums[i]);
            mn=min(nums[i],mn*nums[i]);
            mxp=max(mxp,mx);
        }
    return mxp;
    }
};