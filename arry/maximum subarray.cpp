class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int maxSum=0;
 int thisSum=0;
        bool positiveFound=false;
 for(int i=0;i<a.size();i++){
     if(a[i]>=0)
         positiveFound=true;
    thisSum+=a[i];
    if(thisSum>maxSum){
        maxSum=thisSum;
    }
    else if(thisSum<0){
        thisSum=0;
    }
 }
    if(!positiveFound){
        int minNeg=INT_MIN;
        for(int i=0;i<a.size();i++)
            if(a[i]>minNeg)
                minNeg=a[i];
        return minNeg;
    }
 return maxSum;
    }
};

///////////////////////
//kadanes algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=0,curmax=0;
        bool posFound=false;
        for(const int &x:nums){
            if(x>=0)
                posFound=true;
            curmax=max(curmax+x,x);
            maxsum=max(curmax,maxsum);
        }
        if(!posFound){
            int m=INT_MIN; 
            for(const int &x:nums){
                 if(x>m)
                     m=x;
             }
            return m;
        }
        return maxsum;
    }
};