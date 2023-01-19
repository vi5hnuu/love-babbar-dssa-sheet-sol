/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]<=0){
                i++;
                continue;
            }else if(nums[i]==(i+1)){
                nums[i]=-1;
            }else{
                const int temp=nums[nums[i]-1];
                if(temp<0){
                    nums[nums[i]-1]--;
                    nums[i]=0;
                }else{
                    nums[nums[i]-1]=-1;
                    nums[i]=temp;
                }
            }
        }
        vector<int> ans;
        for(int j=0;j<n;j++){
            if(nums[j]==-2){
                ans.push_back(j+1);
            }
        }
        return ans;
    }
};