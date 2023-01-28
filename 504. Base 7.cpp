/*
Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"
 

Constraints:

-107 <= num <= 107
*/


class Solution {
public:
    string convertToBase7(int num) {
        if(num==0){
            return "0";
        }
        bool neg=num<0;
        num=abs(num);
        string base7="";
        while(num>0){
            int rem=num%7;
            num/=7;
            base7=to_string(rem)+base7;
        }
        return (neg ? "-" : "")+base7;
    }
};