/*
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
Return nums after the rearrangement.

 

Example 1:

Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
Example 2:

Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation: 
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
 

Constraints:

1 <= nums.length <= 105
-106 <= nums[i] <= 106
pivot equals to an element of nums.
*/


//1 traversal + 3 extra array + 1 return array
// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int> lt,eq,gt;
//         for(const int &n:nums){
//             if(n<pivot){
//                 lt.push_back(n);
//             }else if(n==pivot){
//                 eq.push_back(n);
//             }else{
//                 gt.push_back(n);
//             }
//         }

//         vector<int> res(nums.size(),0);
//         int i=0;
//         for(const int &l:lt){
//             res[i++]=l;
//         }
//         for(const int &e:eq){
//             res[i++]=e;
//         }
//         for(const int &g:gt){
//             res[i++]=g;
//         }
//         return res;
//     }
// };
///////////////////////////////////////
//3 traversal + 1 return array
// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int> res(nums.size(),0);
//         int i=0;
//         for(const int &n:nums){
//             if(n<pivot){
//                 res[i++]=n;
//             }
//         }
//         for(const int &n:nums){
//             if(n==pivot){
//                 res[i++]=n;
//             }
                
//         }
//         for(const int &n:nums){
//             if(n>pivot){
//                 res[i++]=n;
//             }
//         }

//         return res;
//     }
// };
////////////////////////////
//2 traversal + 1 return array
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size(),0);
        
        int l=0,e=0,g=0;
        for(const int &n:nums){
            if(n<pivot){
                l++;
            }else if(n==pivot){
                e++;
            }
        }
        g=l+e;
        e=l;
        l=0;
        for(const int &n:nums){
            if(n<pivot){
                res[l++]=n;
            }else if(n==pivot){
                res[e++]=n;
            }else{
                res[g++]=n;
            }
        }

        return res;
    }
};