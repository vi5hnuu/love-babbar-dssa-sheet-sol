/*
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105
*/

/*
    [1,5,4,2,9,9,9], k = 3

    map for first k elements...
    1->1
    5->1
    4->1
    duplicateElCount=0
    sum=10
    mx=10
    /////////
    [5,4,2,9,9,9], k = 3

    map for first k elements...
    1->0
    5->1
    4->1
    2->1
    duplicateElCount=0
    sum=12
    mx=12
    /////////////
    [4,2,9,9,9], k = 3

    map for first k elements...
    1->0
    5->0
    4->1
    2->1
    9->1
    duplicateElCount=0
    sum=15
    mx=15
    ////////////
    [2,9,9,9], k = 3

    map for first k elements...
    1->0
    5->0
    4->0
    2->1
    9->2
    duplicateElCount=1
    sum=..
    mx=15
    ///////////
    [9,9,9], k = 3

    map for first k elements...
    1->0
    5->0
    4->0
    2->1
    9->3
    duplicateElCount=1
    sum=..
    mx=15

    return mx;
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int duplicateElCount=0;
        long long sum=0;
        long long mx=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
                duplicateElCount++;
            }
        }
        if(duplicateElCount==0){
            mx=sum;
        }

        int delInd=0;
        for(int j=k;j<n;j++){
            sum-=nums[delInd];
            cout<<duplicateElCount<<" "<<mp[nums[delInd]]<<endl;
            if(mp[nums[delInd]]==2){
                --duplicateElCount;
            }
            mp[nums[delInd]]--;

            sum+=nums[j];
            mp[nums[j]]++;
            if(mp[nums[j]]==2){
                duplicateElCount++;
            }
            if(duplicateElCount==0){
                mx=max(mx,sum);
            }
            delInd++;
        }
        return mx;
    }
};