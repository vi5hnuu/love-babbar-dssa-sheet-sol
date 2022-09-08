// An additive number is a string whose digits can form an additive sequence.

// A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

// Given a string containing only digits, return true if it is an additive number or false otherwise.

// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

 

// Example 1:

// Input: "112358"
// Output: true
// Explanation: 
// The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
// 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// Example 2:

// Input: "199100199"
// Output: true
// Explanation: 
// The additive sequence is: 1, 99, 100, 199. 
// 1 + 99 = 100, 99 + 100 = 199
 

// Constraints:

// 1 <= num.length <= 35
// num consists only of digits.
 

// Follow up: How would you handle overflow for very large input integers?

class Solution {
    bool check_next(long long n1,long long n2,string rest,bool found) {
        if(rest.length()==0 && found)
            return true;
        
        string snum3=to_string(n1+n2);
        int ind=min(rest.length(),snum3.length());
        if(snum3!=rest.substr(0,ind))
            return false;
        return check_next(n2,stol(snum3),rest.substr(ind),true);
    }
public:
    bool isAdditiveNumber(string num) {
        int sz=num.length();
        if(sz<2)
            return false;
        
        for(int i=1;i<=sz/2;i++){//first number length , num1 can be only upto half the length ,eg "1111+1=1112"...
            string snum1=num.substr(0,i);
            long long int num1=stol(snum1);
            if(snum1!=to_string(num1))//invalid num "012"!="12" , valid "0"=="0"
                break;
            for(int j=i+1;j<sz;j++){//second number length
                string snum2=num.substr(i,j-i);
                long long int num2=stol(snum2);
                if(snum2!=to_string(num2))//"023"!="23"
                    break;
                /*
                1235 -> 1+2=2+3=5 true
                12 -> 1+2 false 
                */
                if(check_next(num1,num2,num.substr(j),false))
                   return true; 
            }
        }
        return false;
    }
};