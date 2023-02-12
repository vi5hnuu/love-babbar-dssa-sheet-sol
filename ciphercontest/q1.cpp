#include<bits/stdc++.h>
using namespace std;



int heightMin(vector<int> &v){
  queue<int> nodes;
  nodes.push(1);
  int i=1;

  int height = 0;
  while(i<v.size()){

    int sz=nodes.size();

    while(sz>0){
      sz--;
      int node=nodes.front();
      nodes.pop();  
      // do{
      //   nodes.push(v[i]);
      //   i++;
      // }while(i<v.size() && (v[i]>v[i-1]));

      int j=i;
      while(j<v.size() && ((j==i) || v[j]>v[j-1])){
        nodes.push(v[j]);
        j++;
      }
      i=j;
    }
      height++;
  }
  return height;
}
int main(){
  int tc;
  cin>> tc;

  while(tc>0){
    tc--;

    int sz;
    cin>>sz;
    vector<int> v(sz,0);
    for(int i=0; i<sz; i++){
      cin>>v[i];
    }
    cout<<heightMin(v)<<endl;
  }
  return 0;
}