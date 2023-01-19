/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> p;
//         for(int i=0;i<nums.size();i++)
//             p.push(nums[i]);
        
//         for(int i=1;i<k;i++)
//             p.pop();
        
//         int z=p.top();
//         p.pop();
//         return z;
//     }
// };


//store only k elemems in priority_queue... max space O(nums.size()) ..single traversal
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
        for(int i=0;i<k;i++)
            p.push(-nums[i]);
        
        for(int i=k;i<nums.size();i++){
            if(-nums[i]<p.top()){
                p.pop();
                p.push(-nums[i]);
            }
        }
        
        int z=p.top();
        p.pop();
        return -z;
    }
};