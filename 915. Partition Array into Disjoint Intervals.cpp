/*
Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.

Test cases are generated such that partitioning exists.

 

Example 1:

Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
 

Constraints:

2 <= nums.length <= 105
0 <= nums[i] <= 106
There is at least one valid answer for the given input.
*/


//[5,9,3,8,6] invalid test case....
//TLE 53 / 66 
//Worst solution 😂😂😂
// class Solution {
// private:
//     bool canPartitionAt(vector<int> &nums,int idx){
//         int mx=INT_MIN;
//         for(int i=0;i<=idx;i++){
//             mx=max(mx,nums[i]);
//         }
//         int mn=INT_MAX;
//         for(int j=idx+1;j<nums.size();j++){
//             mn=min(mn,nums[j]);
//         }
//         return mx<=mn;
//     }
// public:
//     int partitionDisjoint(vector<int>& nums) {
//         for(int i=0;i<nums.size()-1;i++){
//             if(canPartitionAt(nums,i)){
//                 return i+1;
//             }
//         }
//         return 0;
//     }
// };
//////////////////////////////////////////////////////////
// class Solution {
// public:
//     int partitionDisjoint(vector<int>& nums) {
//         int len=nums.size();
//         vector<int> min2right(len,0);
//         min2right[len-1]=INT_MAX;
//         for(int i=len-2;i>=0;i--){
//             min2right[i]=min(min2right[i+1],nums[i+1]);
//         }
//         int k=0;
//         int mx2cur=0;
//         for(int i=0;i<len;i++){
//             mx2cur=max(mx2cur,nums[i]);
//             if(mx2cur<=min2right[i]){
//                 return i+1;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int prevparmax=nums[0];
        int pidx=0;
        int runMax=nums[0];

        for(int i=1;i<nums.size();i++){
            if(prevparmax>nums[i]){
                pidx=i;
                prevparmax=runMax;
            }else{
                runMax=max(runMax,nums[i]);
            }
        }
        return pidx+1;
    }
};

/*
Explaination of last solution :

eg : [3 2 1 7 10,1,15]

        prevparmax=3;
        int pidx=0;
        int runMax=3;

    for(i=1 to 5 incl.)
        .....

-when values go down we are 100% sure that partition will align with 
 that value.....

3->2(pi) | prevparmax=3
3->2->1(pi) | prevparmax=3
[3->2->1]->7 | runMax=7 , prevparmax=3
[3->2->1]->7->10 | runMax=10 ,prevparmax=3
[3->2->1]->7->10 | runMax=10 ,prevparmax=3
[3->2->1]->7->10->1(pi) | runMax=10 ,prevparmax=10
[3->2->1]->7->10->1->15 | runMax=15 ,prevparmax=10

-certain observation
    --when graph goes down partition goes with it
    --if prev partition max value < cur nums[i] value we dont disturb 
      previous partition index because current i can never be our pi 
      instead we simply capture the max values we are getting in our
      way.
    --if we get a value < prev partition index this time we know that 
      this can be pi. so now this is pi we update the prevParMax. 
      which we stored in runMax. 
      eg. [3,2(pi),1(pi),100(i🤌),200(i🤌),300(i🤌),1(pi),600(i🤌)]
      eg. [3,3(i🤌),3(i🤌),3(i🤌),3(i🤌),3(i🤌),2(pi),1(pi),7(i🤌)]
      eg. [1,1(i🤌),1(i🤌),1(i🤌)]


    i hope you got i🤌 (it😂😂😂).


    let's connect : https://www.linkedin.com/in/vi5hnukumar/
*/