#include<bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  cin>>a>>b;

  int alen=a.length();
  int blen=b.length();
  vector<vector<int>> dp(blen,vector<int>(alen,0));


  int mx=INT_MIN;
  int mn=INT_MAX;
  dp[0][0]=a[0]==b[0];
  if(!dp[0][0]){
    mx=0;
    mn=0;
  }
  for(int col=1;col<alen;col++){
    dp[0][col]=a[col]==b[0] || dp[0][col-1];
  }
  for(int row=1;row<blen;row++){
    dp[row][0]=a[0]==b[row] || dp[row-1][0];
    if(a[0]!=b[row]){
      mx=max(mx,row);
      mn=min(mn,row);
    }
  }


  for(int row=1;row<blen;row++){
    for(int col=1;col<alen;col++){
      int mxM=max(dp[row][col-1],dp[row-1][col]);
      dp[row][col]=(b[row]==a[col] ? 1+dp[row-1][col-1] : mxM);
        if(b[row]!=a[col]){
        if(mxM!=row+1){
          mx=max(mx,row);
          mn=min(mn,row);
        }else{
          mx=INT_MIN;
          mn=INT_MAX;
        }
      }else if(mxM+1==row+1){
          mx=INT_MIN;
          mn=INT_MAX;
      }
    }
  }

  int matchCount=dp[blen-1][alen-1];
  if(matchCount==blen){
    cout<<0<<endl;//b is cs of a
    return 0;
  }
  cout<<(mx-mn+1)<<endl;
  return 0;
}