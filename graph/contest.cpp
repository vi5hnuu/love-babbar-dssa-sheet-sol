#include<bits/stdc++.h>
using namespace std;


// int solve(vector<int> &nums){
//   int sum=0;
//   bool found=false;
//   bool negative=nums[0]<0;
//   for(int i=1;i<nums.size();i++){
//     if(nums[i]==nums[i-1] && nums[i]==-1){
//       nums[i]=nums[i-1]=1;
//       found=true;
//       break;
//     }
//     if(nums[i]<0){
//       negative=true;
//     }
//   }
//   if(found || negative){
//     return accumulate(nums.begin(),nums.end(),0);
//   }

//   return accumulate(nums.begin(),nums.end(),-4);
// }
// int main(){
//   int tc;
//   cin>>tc;
//   while(tc>0){
//     tc--;
//     int sz;
//     cin>>sz;
//     vector<int> v(sz);
//     for(int i=0;i<sz;i++){
//       cin>>v[i];
//     }
//     cout<<solve(v)<<endl;
//   }
// }
////////////////////////////
bool maxScore(int r_source,int v,vector<vector<int>> &adj,vector<int> &nodeVals, vector<int> &subtreeVals,vector<bool> &visited){
  visited[r_source]=true;

  
}

int main(){
  int tc;
  cin>>tc;

  while(tc>0){
    tc--;
    int nodeCount;
    cin>>nodeCount;
    vector<int> nodeVals(nodeCount);
    for(int i=0;i<nodeCount;i++){
      cin>>nodeVals[i];
    }

    vector<vector<int>> adj(nodeCount);
    while(nodeCount>1){
        nodeCount--;
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin>>q;
    vector<pair<int,int>> queries;
    for(int i=0;i<q;i++){
        int r,v;
        cin>>r>>v;
        queries.push_back({r,v});
    }
    for(auto query:queries){
      vector<int> subtreeVals;
      vector<bool> visited(nodeCount,false);
      cout<<maxScore(query.first,query.second,adj,nodeVals,subtreeVals,visited)<<endl;
    }
  }
}