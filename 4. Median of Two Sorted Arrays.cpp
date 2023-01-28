/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int len1=nums1.size();
//         int len2=nums2.size();
//         int i=0;
        
        
//         if(len1<len2){
//             while(i<nums1.size())
//             nums2.push_back(nums1[i++]);
//             sort(nums2.begin(),nums2.end());
//             int newlength=nums2.size();
//             return newlength%2==0 ?(nums2[newlength/2]+nums2[newlength/2-1])/2.0  : nums2[newlength/2];
//         }
//         else{
//             while(i<nums2.size())
//             nums1.push_back(nums2[i++]);
//             sort(nums1.begin(),nums1.end());
//             int newlength=nums1.size();
//             return newlength%2==0 ?(nums1[newlength/2]+nums1[newlength/2-1])/2.0  : nums1[newlength/2]
//         }
//     }
// };

////////////////////////////////
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int len1=nums1.size();
//         int len2=nums2.size();

//         vector<int> narr(len1+len2,0);
//         int i=0;
//         int j=0,k=0;
//         while(j<len1 && k<len2){
//             if(nums1[j]<nums2[k]){
//                 narr[i++]=nums1[j++];
//             }else{
//                 narr[i++]=nums2[k++];
//             }
//         }
//         while(j<len1){
//             narr[i++]=nums1[j++];
//         }
//         while(k<len2){
//             narr[i++]=nums2[k++];
//         }

//         if((len1+len2)&1){
//             return narr[(len1+len2)/2];
//         }else{
//             return (narr[(len1+len2)/2]+narr[(len1+len2)/2-1])*1.0/2;
//         }
//     }
// };
//////////////////////////////////////////////////
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int len1=nums1.size();
//         int len2=nums2.size();

//         vector<int> narr(len1+len2,0);
//         int i=0;
//         int j=0,k=0;
//         while(j<len1 && k<len2){
//             if(nums1[j]<nums2[k]){
//                 narr[i++]=nums1[j++];
//             }else{
//                 narr[i++]=nums2[k++];
//             }
//         }
//         while(j<len1){
//             narr[i++]=nums1[j++];
//         }
//         while(k<len2){
//             narr[i++]=nums2[k++];
//         }

//         if((len1+len2)&1){
//             return narr[(len1+len2)/2];
//         }else{
//             return (narr[(len1+len2)/2]+narr[(len1+len2)/2-1])*1.0/2;
//         }
//     }
// };

/////////////////////////////////////////////////////////////////
// class Solution {
// private:
//     void checkMedian(vector<int>& nums1, vector<int>& nums2,int &ma1,int &ma2,int j,int k,int nlen,bool j_will_inc){
//         if(j_will_inc){
//              if((j+k)==nlen/2){
//                 ma2=nums1[j];
//             }
//             if((j+k)==nlen/2-1){
//                 ma1=nums1[j];
//             }
//         }else{
//             if((j+k)==nlen/2){
//                 ma2=nums2[k];
//             }
//             if((j+k)==nlen/2-1){
//                 ma1=nums2[k];
//             }
//         }
//     }
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int len1=nums1.size();
//         int len2=nums2.size();
//         int nlen=len1+len2;
//         int i=0;
//         int j=0,k=0;

//         int ma1=0,ma2=0;
//         while(j<len1 && k<len2){
//             if(nums1[j]<nums2[k]){
//                 checkMedian(nums1,nums2,ma1,ma2,j,k,nlen,true);
//                 j++;
//             }else{
//                 checkMedian(nums1,nums2,ma1,ma2,j,k,nlen,false);
//                 k++;
//             }
//         }
//         while(j<len1){
//             checkMedian(nums1,nums2,ma1,ma2,j,k,nlen,true);               
//             j++;
//         }
//         while(k<len2){
//             checkMedian(nums1,nums2,ma1,ma2,j,k,nlen,false);
//             k++;
//         }
//         if(nlen&1){
//             return ma2;
//         }else{
//             return (ma1+ma2)*1.0/2;
//         }
//     }
// };
///////////////////////////////////////////////////
// class Solution {
// private:
//     void checkMedian(int val,int &ma1,int &ma2,int count,int nlen){
//              if(count==nlen/2){
//                 ma2=val;
//             }
//             if(count==nlen/2-1){
//                 ma1=val;
//             }
//     }
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int len1=nums1.size();
//         int len2=nums2.size();
//         int nlen=len1+len2;
//         int i=0;
//         int j=0,k=0;

//         int ma1=0,ma2=0;
//         int count=0;
//         while(j<len1 && k<len2){
//             if(nums1[j]<nums2[k]){
//                 checkMedian(nums1[j],ma1,ma2,count,nlen);
//                 count++;
//                 j++;
//             }else{
//                 checkMedian(nums2[k],ma1,ma2,count,nlen);
//                 count++;
//                 k++;
//             }
//         }
//         while(j<len1){
//             checkMedian(nums1[j],ma1,ma2,count,nlen);               
//             count++;
//             j++;
//         }
//         while(k<len2){
//             checkMedian(nums2[k],ma1,ma2,count,nlen);
//             count++;
//             k++;
//         }
//         if(nlen&1){
//             return ma2;
//         }else{
//             return (ma1+ma2)*1.0/2;
//         }
//     }
// };
///////////////////////////////////////////////
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        //finding partition in smaller array...
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }        

        int low=0,high=m;
        while(low<=high){
            int mid1=(low+(high-low)/2);
            int mid2=(m+n+1)/2-mid1;

            int max_l1= mid1==0 ? INT_MIN : nums1[mid1-1];
            int min_r1=mid1==m ? INT_MAX : nums1[mid1];

            int max_l2= mid2==0 ? INT_MIN : nums2[mid2-1];
            int min_r2=mid2==n ? INT_MAX : nums2[mid2];
            
            if((max_l1<=min_r2) && (max_l2<=min_r1)){//found the partition
                if((m+n)&1){
                    return max(max_l1,max_l2);
                }else{
                    return (max(max_l1,max_l2)+min(min_r1,min_r2))*1.0/2;
                }
            }else if(max_l1>min_r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
        }
        return -1;
    }
};