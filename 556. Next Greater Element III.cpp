/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
 

Constraints:

1 <= n <= 231 - 1
*/


/*
51465321

only using 1 -> not posible(inc sequence)
only using 21 -> not posible(inc sequence)
only using 321 -> not posible(inc sequence)
only using 5321 -> not posible(inc sequence)
only using 65321 -> not posible(inc sequence)
only using 465321 -> posible(inc sequence)

swap :
  4,6 -> ok
  4,5 -> ok (best fit)
  4,3 -> X (make no small)
  4,2 -> X (make no small)
  4,1 -> X (make no small)

51564321

now we know the sequence after 4 (51465321) is increasing from right to left
515(12346) <- ans [12346<64321]
*/


class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<=11){
            return -1;
        }
        string num=to_string(n);
        int len=num.length();
        int i=len-2;
        for(;i>=0;i--){
            if((num[i])<(num[i+1])){//first dip
                break;
            }
        }
        if(i<0){
            return -1;
        }
        //just greater that num[i]
        int j=len-1;
        for(;j>i;j--){
            if(num[j]>num[i]){
                break;
            }
        }
        swap(num[j],num[i]);
        //reverse after i (make inc seq from len-1 to i+1 to a decreasing seq.)
        int st=i+1;
        int end=len-1;
        while(st<end){
            swap(num[st],num[end]);
            st++;
            end--;
        }
        long long nm=stol(num);
        return nm>INT_MAX ? -1 : nm;
    }
};

