/*
There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

 

Example 1:



Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
Example 2:

Input: heights = [5,1,2,3,10]
Output: [4,1,1,1,0]
 

Constraints:

n == heights.length
1 <= n <= 105
1 <= heights[i] <= 105
All the values of heights are unique.
*/

//brute force | TLE 34 / 42 
// class Solution {
// public:
//     vector<int> canSeePersonsCount(vector<int>& heights) {
//         int len=heights.size();
//         vector<int> res(len,0);
//         for(int i=0;i<len;i++){
//             int see=0;
//             int j=i+1;
//             int prev=0;
//             while(j<len && heights[j]<heights[i]){
//                 if(heights[j]>prev){
//                     see++;
//                     prev=heights[j];
//                 }
//                 j++;
//             }
//                 res[i]=see;
//                 if(j<len){//we stopped because we saw a bigger minion
//                     res[i]++;//count that bigger minion
//                 }
//         }
//         return res;
//     }
// };
/////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int len=heights.size();
        vector<int> res(len,0);
        stack<int> stck;
        for(int i=len-1;i>=0;i--){
            int see=0;
            while(!stck.empty() && stck.top()<heights[i]){
                stck.pop();//clear stack for this condition because it is sure
                            //that no minion lying behind this cannot see this minion...
                see++;
            }
            res[i]=see;
            if(!stck.empty()){//we stopped because we saw a bigger minion
                res[i]++;
            }
            stck.push(heights[i]);//prev left minion might see me
        }
        return res;
    }
};


// Observation :
//     let say minion stand at index i then this minion can see all 
//     minion smaller and greather than this minion but in increasing 
//     fashion (next minion greater than prev).

//     if you have understood my brute for solution you would have 
//     understood above statement.

//     but if we traverse from start we cannot do it in O(N).

//     -lets try traversing backword and understand it via an example.
//         Ex : [10,6,8,5,11,9]
//         --for index len-1
//                 res[len-1]=0;
//                 stck=9
//         --for index len-2
//                 look we are sure about one thing here that this minion
//                 can eat all minons in front of it but the condition 
//                 is they are smaller than this but you might think 
//                 wont this affect minons behind this minion.
//                 the ans is no because minions behind this minion
//                 cannot see minions smaller than this cur minion.
//                 you will understand at the end of this sol.
//             res[len-2]=1;//+1 for popping 9                 
//             stck=11 // push cuurent as minions behind this minion
//             can see this
//         --for index len-3
//                 res[len-3]=1;//we didnt popped anything because we saw
//                             minion bigger than cur minion
//                 stck=5,11
//         --for index len-4
//                 res[len-4]=2;//pop 5 and +1 because we see bigger 
//                                 minion 
//                 stck=8,11
//         --for index len-5
//                 res[len-5]=1;//+1 because we see bigger minion 
//                 stck=6,8,11
//         --for index len-6
//                 res[len-6]=3;//pop*2+1 because we see bigger minion 
//                 stck=11


//     Observation: we clear smaller minions in stack because thay are
//     userless for all minions behind cur minion.

//     [10,6,8,5,11,9]
//     stck=9          index=5
//     stck=11         index=4 cur minion eat up 9 because he is useless
//     stck=5,11       index=3 cur minion didnt eat anything
//     stck=8,11       index=2 cur minion eat up 5 because he is useless
//     stck=6,8,11     index=1 cur minion didnt eat anything
//     stck=11         index=0 eats up 6,8 because they are useless.

//     solution [3,2,2,1,1,0]

//     [15,12,9,6,2,1]
//     stck=1          index=5
//     stck=2          index=4 cur minion eat up 1 because he is useless
//     stck=6          index=3 cur minion eat up 2 because he is useless notice that this minion didnt eat 1 because its already eaten by someone in front(anyone in front).
//     stck=9          index=2 cur minion eat up 6 because he is useless
//     stck=12         index=1 cur minion eat up 9 because he is useless
//     stck=15         index=0 eats up 12 because they are useless.

//     solution [1,1,1,1,1,0]