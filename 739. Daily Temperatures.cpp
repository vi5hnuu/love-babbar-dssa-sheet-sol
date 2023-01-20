/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //similar to next grater element.cpp and no of visible people in a queue.cpp
        //here we dont want next greater but the gap between curr pos and next greater pos..
        //modification : push index instead of els...

        int len=temperatures.size();
        vector<int> res(len,0);
        stack<int> stck;
        for(int i=len-1;i>=0;i--){
            while(!stck.empty() && temperatures[stck.top()]<=temperatures[i]){
                stck.pop();
            }
            if(!stck.empty()){
                res[i]=stck.top()-i;
            }else{
                res[i]=0;//no warmer day ahead
            }
            stck.push(i);
        }
        return res;
    }
};