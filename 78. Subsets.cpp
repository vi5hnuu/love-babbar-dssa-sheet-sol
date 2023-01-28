/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/


// class Solution {
// private:
//     void f(int ind,vector<vector<int>>& ans,vector<int> &ans2,vector<int>& nums){
//         for(int i=ind;i<nums.size();i++){
//             ans2.push_back(nums[i]);
//             f(i+1,ans,ans2,nums);
//             ans2.pop_back();
//         }
//         ans.push_back(ans2);
//     }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> ans2;
//         f(0,ans,ans2,nums);
//         return ans;
//     }
// };

//////////
class Solution {
private:
    void f(int ind,vector<vector<int>>& ans,vector<int> &ans2,vector<int>& nums){
        ans.push_back(ans2);
        for(int i=ind;i<nums.size();i++){
            ans2.push_back(nums[i]);
            f(i+1,ans,ans2,nums);
            ans2.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ans2;
        f(0,ans,ans2,nums);
        return ans;
    }
};

//all subset starting with 1 -> 1,12,123,13
//all subset starting with 2 -> 2,23
//all subset starting with 3 -> 3
