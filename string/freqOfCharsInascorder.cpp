#include<iostream>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    //all caps
    int dp[26]={0};
    for(const char &c:str){
        dp[c-'A']++;
    }
    for(int i=0;i<26;i++){
        if(dp[i]!=0)
        cout<<((char)(65+i))<<" Occur "<<dp[i]<<" times."<<endl;
    }
        
}