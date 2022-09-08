// Given an array of integers nums, sort the array in ascending order.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]

class Solution {
    private:
    void merge(vector<int> &nums,int low,int mid,int high){//high incl.
            //low to mid and mid+1 to high
            int i=low,j=mid+1;
            vector<int> temp(high-low+1);
            int index=0;
            while(i<=mid && j<=high){
                if(nums[i]<nums[j]){
                    temp[index++]=nums[i++];
                }else{
                    temp[index++]=nums[j++];
                }
            }
        while(i<=mid){
            temp[index++]=nums[i++];
        }
        while(j<=high){
            temp[index++]=nums[j++];
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void sortArray(vector<int>& nums,int low,int high) {
            if(low>=high)
                return;
            
            int mid=low+(high-low)/2;
            sortArray(nums,low,mid);
            sortArray(nums,mid+1,high);
            merge(nums,low,mid,high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
          vector<int> newnum(nums); 
          sortArray(newnum,0,nums.size()-1);
          return newnum;
    }
};