/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

class Solution {
private:
    string add(const string &num1,const string &num2){
        int len1=num1.length();
        int len2=num2.length();
        int len=max(len1,len2);
        string ans="";
        int rem=0;
        for(int i=0;i<len;i++){
            int d1=i<len1 ? num1[i]-'0' : 0;
            int d2=i<len2 ?num2[i]-'0' : 0;
            cout<<d1<<"-"<<d2<<endl;
            int sum=d1+d2+rem;
            int num=sum%10;
            rem=sum/10;
            ans=ans+to_string(num);//rev add
        }
        if(rem>0)
            ans=ans+to_string(rem);//rev add
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        if(num1.length()==1 && num1[0]=='0' || (num2.length()==1 && num2[0]=='0')){
            return "0";
        } 
        vector<string> res;
        for(int m=num2.length()-1;m>=0;m--){
            string level=string(num2.length()-1-m,'0');

            int digit=num2[m]-'0';
            int rem=0;
            for(int i=num1.length()-1;i>=0;i--){
                int ndigit=num1[i]-'0';
                int mul=digit*ndigit+rem;
                int num=mul%10;
                rem=mul/10;
                level=level+to_string(num);//reverse add
            }
            if(rem>0)
                level=level+to_string(rem);//reverse add
            res.push_back(level);
        }
        if(res.size()==1){
            reverse(res[0].begin(),res[0].end());
            return res[0];
        }
        string ans=add(res[0],res[1]);
        for(int i=2;i<res.size();i++){
            ans=add(ans,res[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};