/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        vector<int> lmax(len,0),rmax(len,0);

        for(int i=1;i<len;i++){
            lmax[i]=max(lmax[i-1],height[i-1]);
            rmax[len-1-i]=max(rmax[len-i],height[len-i]);
        }
        for(int i=0;i<len;i++){
            cout<<lmax[i]<<" "<<rmax[i]<<endl;
        }
        int maxWater=0;
        for(int i=0;i<len;i++){
            int minh=min(lmax[i],rmax[i]);
            if(minh>height[i]){
                maxWater+=(minh-height[i])*1;
            }
        }
        return maxWater;
    }
};

/*
eg : [0,1,0,2,1,0,1,3,2,1,2,1]

meta-chart.png

i cannot represent graph format let understand via numbers...

zero index cannot hold water because it does not have wall to left
last index cannot hold water because it does not have wall to end.

we go from i=1 to last idx-1 (or to last idx doesnt matter)
now at current height...ie height[i] how much water it can hold ?

step 1 :pick up max height wall from left of cur index.
step 2 :pick up max height wall from right of cur index.
scene : [max height wall] [height[i]] [max height wall]

now at this point how much water this height[i] can hold
minHeightWallOnEitherSide=min([max height wall on left],[max height wall on right])

now if this 'minHeightWallOnEitherSide' > height[i] we can store water
and that water amount to (minHeightWallOnEitherSide-height[i])*width
:: width=1

eg 1.
|
|
| |
| |
|||

select min height

| | =>
| |
|||

water :

| | =>
| |

eg 2.
|
|
|
||
|||

select min height

|
|||

water :

not possible : walls are short water will flow out.

Hope you got the point
*/



//sol 3 | 2 pointer

//solution 3 


class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        int lmax=0,rmax=0;
        int maxWater=0;

        int i=0;
        int j=len-1;
        while(i<j){
            lmax=max(lmax,height[i]);
            rmax=max(rmax,height[j]);

            if(lmax<rmax){
                maxWater+=(lmax-height[i])*1;
                i++;//water collected move forward
            }else{
                maxWater+=(rmax-height[j])*1;
                j--;//water collected move backword
            }
        }
        return maxWater;
    }
};

/*
Explaination to solution 3 :

lmax has max wall size from 0 to cur index
rmax has max wall size from i to len;

at any index i :
    if lmax<rmax -> this clearly means that curr index can hold water 
    and that is (lmax-height[i]) , we collect water and move forward
    else -> it means curr i cannot hold water but j  hol water that is
    (rmax-height[j]), we collect and move left

    above steps goes until i<j.



Hope you got the point.
*/
