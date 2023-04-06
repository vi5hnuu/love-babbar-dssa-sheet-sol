/*
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Example 1:

Input:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].
Example 2:

Input:
Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}}
Your Task:
Complete the function overlappedInterval() that takes the list N intervals as input parameters and returns sorted list of intervals after merging.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(Log(N)) or O(N).

Constraints:
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 1000
*/


class Comparator{
public:
    bool operator ()(const vector<int> &v1,const vector<int> &v2) const{
            return v1[0]<v2[0];
    }
};
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> newIntervals;
        sort(intervals.begin(),intervals.end(),Comparator());
        int sz=intervals.size();
        for(int i=0;i<sz;i++){
            if(newIntervals.empty()){
                newIntervals.push_back(intervals[i]);
            }else{
                auto &tp=newIntervals.back();
                if(intervals[i][0]>tp[1]){
                    newIntervals.push_back(intervals[i]);
                }else{
                    tp[1]=max(tp[1],intervals[i][1]);
                }
            }
        }
        return newIntervals;
    }
};