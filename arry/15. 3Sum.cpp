/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//    if(nums.size()<3)
//        return {};
//    sort(nums.begin(),nums.end());
   
//    vector<vector<int>> triplets;
        
//   for(int i=0;i<nums.size()-2;i++){
//     int p=i;
      
//     int q=i+1;
//     int r=nums.size()-1;
//       while(q<r){
//           if(nums[q]+nums[r]+nums[p]==0){
//               triplets.push_back({nums[p],nums[q],nums[r]});
//               q++;
//               r--;
//           }
//           else if(nums[q]+nums[r]+nums[p]<0){
//               q++;
//           }
//           else
//           r--;
//       }
//   }

//     set<vector<int>> s( triplets.begin(), triplets.end() );
//     triplets.assign( s.begin(), s.end() );
//     return  triplets;
//     }
// };
////////////////////////////////////////////
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//    if(nums.size()<3)
//        return {};
//    sort(nums.begin(),nums.end());
   
//    set<vector<int>> triplets;
        
//   for(int i=0;i<nums.size()-2;i++){
//     int p=i;
      
//         int q=i+1;
//         int r=nums.size()-1;
//         while(q<r){
//             if(nums[q]+nums[r]+nums[p]==0){
//                 triplets.insert({nums[p],nums[q],nums[r]});
//                 q++;
//                 r--;
//             }
//             else if(nums[q]+nums[r]+nums[p]<0){
//                 q++;
//             }
//             else
//             r--;
//         }
//     }
//         vector<vector<int>> trips;
//         trips.assign(triplets.begin(), triplets.end());
//         return trips;
//     }
// };
/////////////////////////////////////////////
class Solution {
private:
    int binSearch(vector<int> &nums,int start,int end,int target){
        int l=start;
        int h=end-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int len=nums.size();
    if(nums.size()<3)
       return {};
   sort(nums.begin(),nums.end());
   
   set<vector<int>> triplets;
        
  for(int i=0;i<len-2;i++){
        int p=i;
        int q=i+1;
        int lastIndex=len;
        while(q<len){
            //nums[p]+nums[q]+x=0
            //x=-(nums[p]+nums[q]);
            int rem=-(nums[p]+nums[q]);
            int idx=binSearch(nums,q+1,lastIndex,rem);
            if(idx>=0){
                lastIndex=idx;
                triplets.insert({nums[p],nums[q],nums[idx]});
            }
            q++;
        }
    }
    vector<vector<int>> trips;
    trips.assign(triplets.begin(), triplets.end());
    return trips;
    }
};
///////////////////////////////////
class Solution {
private:
    int binSearch(vector<int> &nums,int start,int end,int target){
        int l=start;
        int h=end-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int len=nums.size();
    if(nums.size()<3)
       return {};
   sort(nums.begin(),nums.end());
   
   vector<vector<int>> triplets;
        
  for(int i=0;i<len-2;i++){
        while(i>0 && i<len && nums[i]==nums[i-1]){i++;}//remove duplicates
        int q=i+1;
        int lastIndex=len;
        while(q<len){
            //nums[i]+nums[q]+x=0
            //x=-(nums[i]+nums[q]);
            int rem=-(nums[i]+nums[q]);
            int idx=binSearch(nums,q+1,lastIndex,rem);
            if(idx>=0){
                lastIndex=idx;
                triplets.push_back({nums[i],nums[q],nums[idx]});
            }
            q++;
            while(q<len && nums[q]==nums[q-1]){q++;}//remove duplicates
        }
    }
    return triplets;
    }
};