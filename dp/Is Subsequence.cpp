/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length())
            return false;
            
        stack<char> stck;
        for(int i=0;i<t.length();i++)
            stck.push(t[i]);
        
        for(int j=s.length()-1;j>=0;j--){
            if(!stck.empty() && stck.top()==s[j]){
                stck.pop();
            }
            else {
                if(stck.empty())
                    return false;
                stck.pop();
                j++;
            }
        }
        return true;
    }
};
*/
/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length())
            return false;
            
        if(!s.length())
            return true;
        int sL=s.length();
        int tL=t.length();
        int dp[sL+1][tL+1];
        for(int row=0;row<=sL;row++)
            dp[row][0]=0;
        for(int col=0;col<=tL;col++)
            dp[0][col]=0;
        
        //lcs
        for(int i=0;i<sL;i++)
            for(int j=0;j<tL;j++){
                if(s[i]==t[j])
                    dp[i+1][j+1]=1+dp[i][j];
                else
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        
        return dp[sL][tL]==sL;
    }
};
*/
/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()>t.length())
            return false;
        if(!s.length())
            return true;
        int i=0;
        for(const char &c:t){
            if(c==s[i])
                i++;
            if(i==s.length())
                return true;
        }
        return false;
    }
};
*/
//recursive
class Solution {
private:
    bool isSubsequence(const string &s,const string &t,int indexs,int indext){
        if(indexs==s.length())
            return true;
        else if(indext>=t.length())
            return false;
        
        if(s[indexs]==t[indext])
            return isSubsequence(s,t,indexs+1,indext+1);
        else
            return isSubsequence(s,t,indexs,indext+1);
    }
public:
    bool isSubsequence(string s, string t) {
        return isSubsequence(s,t,0,0);
    }
};