/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
 

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?
*/


// 1 <= nums[i] <= 1000 no neg no aloweded as there can be infinite solution 
// eg [2,-2] : {-2,2},{-2,-2,2,2} ...........

//so if neg are allowed in the given array then we have to limit how many times we can use a given number...
//one of the imp test case 


//TLE 9 / 15
// class Solution {
// private:
//     int combinationSum4(vector<int>& nums,int sum, int target) {
//         if(sum>target){
//             return 0;
//         }
//         if(sum==target){
//             return 1;
//         }
//         int b=0;
//         for(const int &n:nums){
//             b+=combinationSum4(nums,sum+n,target);
//         }
//         return b;
//     }
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         return combinationSum4(nums,0,target);
//     }
// };
////////////////////////
// class Solution {
// private:
//     int combinationSum4(vector<int>& nums,int sum, int target,vector<int> &memo) {
//         if(sum>target){
//             return 0;
//         }
//         if(sum==target){
//             return 1;
//         }
//         if(memo[sum]!=-1){
//             return memo[sum];
//         }
//         int b=0;
//         for(const int &n:nums){
//             b+=combinationSum4(nums,sum+n,target,memo);
//         }
//         return memo[sum]=b;
//     }
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         int mx=INT_MIN;
//         for(const int &n:nums){
//             mx=max(mx,n);
//         }
//         vector<int> memo(target+mx,-1);
//         return combinationSum4(nums,0,target,memo);
//     }
// };
//////////////////////////////////////////////////////////////////
// class Solution {
// private:
//     int combinationSum4(vector<int>& nums,int target,vector<int> &memo) {
//         if(target==0){
//             return 1;
//         }
//         if(memo[target]!=-1){
//             return memo[target];
//         }
//         int b=0;
//         for(const int &n:nums){
//             if(target-n>=0)
//                 b+=combinationSum4(nums,target-n,memo);
//         }
//         return memo[target]=b;
//     }
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int> memo(target+1,-1);
//         return combinationSum4(nums,target,memo);
//     }
// };
//////////////////////////////////////////////////////////////////
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;
        // for(int i=1;i<=target;i++){
        //     int b=0;
        //     for(const int &n:nums){
        //         if(target-n>=0)
        //             b+=combinationSum4(nums,target-n,memo);
        //     }
        // }

        ////////
         for(int i=1;i<=target;i++){
             cout<<dp[i-1]<<" ";
            for(const int &n:nums){
                if(i-n>=0){
                    dp[i]+=dp[i-n];
                }
            }
        }
        return dp[target];
    }
};

//why above dp fails...same thing is done by recursive sol..so why dp failed...
/*
[10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]

target = 999

1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 0 0 0 8 0 0 0 0 0 0 0 0 0 16 0 0 0 0 0 0 0 0 0 32 0 0 0 0 0 0 0 0 0 64 0 0 0 0 0 0 0 0 0 128 0 0 0 0 0 0 0 0 0 256 0 0 0 0 0 0 0 0 0 512 0 0 0 0 0 0 0 0 0 1024 1 0 0 0 0 0 0 0 0 2048 2 0 0 0 0 0 0 0 0 4096 5 0 0 0 0 0 0 0 0 8192 12 0 0 0 0 0 0 0 0 16384 28 0 0 0 0 0 0 0 0 32768 64 0 0 0 0 0 0 0 0 65536 144 0 0 0 0 0 0 0 0 131072 320 0 0 0 0 0 0 0 0 262144 704 0 0 0 0 0 0 0 0 524288 1536 0 0 0 0 0 0 0 0 1048576 3328 0 0 0 0 0 0 0 0 2097152 7168 1 0 0 0 0 0 0 0 4194304 15360 3 0 0 0 0 0 0 0 8388608 32768 9 0 0 0 0 0 0 0 16777216 69632 25 0 0 0 0 0 0 0 33554432 147456 66 0 0 0 0 0 0 0 67108864 311296 168 0 0 0 0 0 0 0 134217728 655360 416 0 0 0 0 0 0 0 268435456 1376256 1008 0 0 0 0 0 0 0 536870912 2883584 2400 0 0 0 0 0 0 0 1073741824 6029312 5632 0 0 0 0 0 0 0 
*/

