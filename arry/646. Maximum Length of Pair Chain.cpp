// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

 

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].
// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

// Constraints:

// n == pairs.length
// 1 <= n <= 1000
// -1000 <= lefti < righti <= 1000

class comparator{
public:
    bool operator ()(const vector<int> &p1,const vector<int> &p2) const{
        return p1[1]<p2[1];
    }    
};
class Solution {
private:   
    void printPairs(const vector<vector<int>>& pairs) const{
        for(const vector<int> &v : pairs){
            cout<<v[0]<<" "<<v[1]<<endl;
        }
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comparator());
        //printPairs(pairs);
        int ans=0;
        int cur=INT_MIN;
        for(const vector<int> &v : pairs){
            if(v[0]>cur){
                ans++;
                cur=v[1];
            }        
        }
        return ans;
    }
};