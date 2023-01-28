// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.


class Solution {
private:
    bool contains(const vector<int> &v,int n){
        vector<int>::const_iterator itr=v.cbegin();
        while(itr!=v.cend()){
            if(*itr==n)
                return true;
            itr++;
        }
        return false;
    }
    void permute(vector<int>& nums,vector<vector<int>> &res,vector<int> &ans) {
        
        if(ans.size()==nums.size()){
            res.push_back(ans);
            return;
        }
        for(const int &x:nums){
                if(!contains(ans,x)){
                    ans.push_back(x);
                    permute(nums,res,ans);
                    ans.pop_back();
                }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        permute(nums,res,tmp);
        return res;
    }
};
/////////////////////////////
class Solution {
private:
    void permute(vector<int>& nums,vector<vector<int>> &res,vector<int> &ans,int &chosenBits) {
        int nlen=nums.size();
        if(ans.size()==nlen){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nlen;i++){
            if(!(chosenBits&(1<<i))){
                ans.push_back(nums[i]);
                chosenBits=chosenBits | (1<<i);
                permute(nums,res,ans,chosenBits);
                chosenBits=chosenBits & ~(1<<i);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        //1 <= nums.length <= 6
        int chosenBits=0;
        permute(nums,res,tmp,chosenBits);
        return res;
    }
};

