/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         priority_queue<pair<int,int>> maxHeap;

//         int i=0;
//         while(i<k){
//             maxHeap.push({nums[i],i});
//             i++;
//         }
//         res.push_back(maxHeap.top().first);

//         while(i<nums.size()){
//             maxHeap.push({nums[i],i});
//             while(maxHeap.top().second<=(i-k)){//delete expired window eles
//                 maxHeap.pop();
//             }
//             res.push_back(maxHeap.top().first);
//             i++;
//         }
//         return res;
//     }
// };
/////////////////////////////////////////////////////////
// The idea is simple every time invalidate one element from nums vector.


/*
For Example: A = [2,1,3,4,6,3,8,9,10,12,56], w=4

partition the array in blocks of size w=4. The last block may have less then w.
2, 1, 3, 4 | 6, 3, 8, 9 | 10, 12, 56|

Traverse the list from start to end and calculate max_so_far. Reset max after each block boundary (of w elements).
left_max[] = 2, 2, 3, 4 | 6, 6, 8, 9 | 10, 12, 56

Similarly calculate max in future by traversing from end to start.
right_max[] = 4, 4, 4, 4 | 9, 9, 9, 9 | 56, 56, 56

now, sliding max at each position i in current window, sliding-max(i) = max{right_max(i), left_max(i+w-1)}
sliding_max = 4, 6, 6, 8, 9, 10, 12, 56
*/

// now let say you are at index i -> what you want😂😂
// we want max in this window.... so i ask a two things..

// let say we are at index 5
// 1. give me left max in this window
// 2. give me right max in previous window

// ans=max(1. , 2.); thats it
 

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int len=nums.size();
//         vector<int> res;
//         vector<int> lmax(len,0);
//         vector<int> rmax(len,0);

//         for(int i=0;i<len;i++){
//             if(i==0 || i%k==0){
//                 lmax[i]=nums[i];
//             }else{
//                 lmax[i]=max(lmax[i-1],nums[i]);
//             }
//             ///
//             if((len-1-i)==len-1 || ((len-1-i)+1)%k==0){
//                 rmax[len-1-i]=nums[len-1-i];
//             }else{
//                 rmax[len-1-i]=max(rmax[(len-1-i)+1],nums[len-1-i]);
//             }
//         }
//         // for(const int n:lmax){
//         //     cout<<n<<" ";
//         // }
//         // cout<<endl;
//         // for(const int n:rmax){
//         //     cout<<n<<" ";
//         // }
//         cout<<endl;
//         for(int j=0;j<=(len-k);j++){
//             res.push_back(max(rmax[j],lmax[j+k-1]));
//         }
//         return res;
//     }
// };

//////////////////////////////////////////////////////
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len=nums.size();
        vector<int> res;

        deque<int> dq;
        //first element of dq is max in window
        for(int i=0;i<len;i++){
            //remove invalid elems(elems of previous window)
            while(!dq.empty() && dq.front()<=(i-k)){
                dq.pop_front();
            }
            //pop elems < nums[i] (bacause they are useless for this and next comming window)
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            //now at this point nums[i] is greater than dq.back() but less than dq.front()
            //if nums[i] is less than dq.front() we till add it becuasse it can be max for 
            //coming windows
            dq.push_back(i);
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
