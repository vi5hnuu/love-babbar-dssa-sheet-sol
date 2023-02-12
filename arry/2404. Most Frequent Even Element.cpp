/*
Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.

 

Example 1:

Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.
Example 2:

Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.
Example 3:

Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.
 

Constraints:

1 <= nums.length <= 2000
0 <= nums[i] <= 105
*/


// class Comparator{
// public:
//     bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
//         if(p1.second==p2.second){
//             return p1.first<p2.first;
//         }
//         return p1.second>p2.second;
//     }
// };
// class Solution {
// public:
//     int mostFrequentEven(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         bool even=false;
//         for(int n:nums){
//             mp[n]++;
//             if(n%2==0){
//                 even=true;
//             }
//         }
//         if(!even){
//             return -1;
//         }
//         vector<pair<int,int>> els(mp.begin(),mp.end());
//         sort(els.begin(),els.end(),Comparator{});
//         for(int i=0;i<nums.size();i++){
//             if(els[i].first%2==0){
//                 return els[i].first; 
//             }
//         }
//         return -1;
//     }
// };
//////////////////////////////
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        bool even=false;
        for(int n:nums){
            if(n%2==0){
                mp[n]++;
                even=true;
            }
        }
        if(!even){
            return -1;
        }
        map<int,int>::const_iterator itr=mp.cbegin();
        int sm=INT_MAX;
        int freq=-1;
        while(itr!=mp.cend()){
            if(itr->second>freq){
                sm=itr->first;
                freq=itr->second;
            }
            itr++;
        }
        return sm;
    }
};