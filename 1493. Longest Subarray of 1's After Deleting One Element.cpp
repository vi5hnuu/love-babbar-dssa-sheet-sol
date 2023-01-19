/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

// class Solution {
// private:
//     int longestSubarray(const vector<int> &nums,const int &skipIdx) const{
//         int mx1s=0;
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             if(i!=skipIdx){
//                 if(nums[i]==1){
//                     count++;
//                 }else{
//                     mx1s=max(mx1s,count);
//                     count=0;
//                 }
//             }
//         }
//         mx1s=max(mx1s,count);
//         return mx1s;
//     }
// public:
//     int longestSubarray(vector<int>& nums) {
//         int mx=INT_MIN;
//         for(int skipIdx=0;skipIdx<nums.size();skipIdx++){
//             if(nums[skipIdx]==0){
//                 mx=max(mx,longestSubarray(nums,skipIdx));
//             }
//         }
//         return mx==INT_MIN ? nums.size()-1 : mx;
//     }
// };

/////////////////////////////////////
//[0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0] (X)
//[0,0,0,0,0,0,0,1,1,1,->0<-,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0] (ok)
//[0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]   (X)

//max length of ones can increase only of we remove zero from sequence '101'.
// class Solution {
// private:
//     int longestSubarray(const vector<int> &nums,const int &skipIdx) const{
//         int mx1s=0;
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             if(i!=skipIdx){
//                 if(nums[i]==1){
//                     count++;
//                 }else{
//                     mx1s=max(mx1s,count);
//                     count=0;
//                 }
//             }
//         }
//         mx1s=max(mx1s,count);
//         return mx1s;
//     }
//     bool allZeros(const vector<int> &nums) const{
//         for(const int &n:nums){
//             if(n!=0){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     int longestSubarray(vector<int>& nums) {
//         int n=nums.size();
//         int mx=INT_MIN;
//         if(allZeros(nums)){
//             return 0;
//         }else{
//             mx=longestSubarray(nums,-1);
//         }

//         for(int skipIdx=0;skipIdx<n;skipIdx++){
//             if(skipIdx!=0 && skipIdx!=n-1 && nums[skipIdx]==0 &&(nums[skipIdx-1]==1 && nums[skipIdx+1]==1)){
//                 mx=max(mx,longestSubarray(nums,skipIdx));
//             }
//         }
//         return mx==n ? mx-1 : mx;
//     }
// };

////////////////////////////
//[0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1]...worst -> 14 traversal of same array........
// class Solution {
// private:
//     int longestSubarray(const vector<int> &nums,const int &skipIdx) const{
//         int mx1s=0;
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             if(i!=skipIdx){
//                 if(nums[i]==1){
//                     count++;
//                 }else{
//                     mx1s=max(mx1s,count);
//                     count=0;
//                 }
//             }
//         }
//         mx1s=max(mx1s,count);
//         return mx1s;
//     }
//     bool allZeros(const vector<int> &nums) const{
//         for(const int &n:nums){
//             if(n!=0){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     int longestSubarray(vector<int>& nums) {
//         int n=nums.size();
//         int mx=INT_MIN;
        
//         for(int skipIdx=0;skipIdx<n;skipIdx++){
//             if(skipIdx!=0 && skipIdx!=n-1 && nums[skipIdx]==0 &&(nums[skipIdx-1]==1 && nums[skipIdx+1]==1)){
//                 mx=max(mx,longestSubarray(nums,skipIdx));
//             }
//         }

//         if(mx==INT_MIN){
//             if(allZeros(nums)){
//                 return 0;
//             }else{
//                 mx=longestSubarray(nums,-1);
//             }
//         }
//         return mx==n ? mx-1 : mx;
//     }
// };
////////////////////////////////////////////////
//[0,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,0,1,1]
//[1,1,1,1,1,0,1,1]
//[1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,0,1,1]
//[1,1,1,1,1,1,1]
//[0,1,1,1,0,1,1,0]
//[0,0,0,0,0,0]
class Solution {
private:
    bool allZeros(const vector<int> &nums) const{
        for(const int &n:nums){
            if(n!=0){
                return false;
            }
        }
        return true;
    }
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=0;

        int count=0;

        bool firstSeq=true;// '101' seq
        int firstSeqMax1s=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }else{
                mx=max(mx,count);
                if(i!=0 && i!=n-1 && nums[i-1] && nums[i+1]){
                    if(firstSeq){
                        firstSeqMax1s=count;
                        firstSeq=false;
                    }else{
                        firstSeqMax1s=count-=firstSeqMax1s;
                    }
                }else{
                    firstSeqMax1s=count-=firstSeqMax1s;
                }
            }
            cout<<count<<" "<<i<<endl;

        }
        mx=max(mx,count);        
       return mx==n ? mx-1 : mx;
    }
};