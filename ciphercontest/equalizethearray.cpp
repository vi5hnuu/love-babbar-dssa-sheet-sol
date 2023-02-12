#include <bits/stdc++.h>
using namespace std;


class Comparator{
  public:
    bool operator ()(const pair<int,int> &a, const pair<int,int> &b){
      return a.second > b.second;
    }
};
int minRemovals(vector<int> &v){
  unordered_map<int,int> mp;
  for(int i = 0; i < v.size();i++){
    mp[i]++;
  }

  vector<pair<int,int>> els(mp.begin(),mp.end());
  sort(els.begin(),els.end(),Comparator());
  int minRem=0;
  int r=0;
  for(int i = 1; i < els.size();i++){
    if(els[i].second<els[i-1].second){
      r++;
    }else{
      minRem=max(minRem,r);
      r=0;
    }
  }
  minRem=min(minRem,r);
  return minRem;
}
int main(){
  int tc;
  cin>>tc;

  while(tc>0){
    tc--;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
      cin>>v[i];
    }

    cout<<"Ans"<<minRemovals(v)<<endl;
  }
  return 0;
}