// #include<bits/stdc++.h>
// using namespace std;

// // int getSum(queue<pair<int,int>> &nums,int x){
// //   int sum = 0;
// //   while(!nums.empty()){
// //     auto n=nums.front();
// //     sum+=(n.first*n.second);
// //     nums.pop();
// //     if(n.first%x==0){
// //       int ad=n.first/x;
// //         nums.push({ad,x*n.second});
// //     }else{
// //       break;
// //     }
// //   }
// //   while(!nums.empty()){
// //     auto nm=nums.front();
// //     nums.pop();
// //     sum+=nm.first*nm.second;
// //   }
// //   return sum;
// // }

// ////////////
// int getSum(queue<int> &nums,int x){
//   int sum = 0;
//   while(!nums.empty()){
//     auto n=nums.front();
//     sum+=n;
//     nums.pop();
//     if(n%x==0){
//       int ad=n/x;
//       for(int j=0;j<x;j++)
//         nums.push(ad);
//     }else{
//       break;
//     }
//   }
//   while(!nums.empty()){
//     auto nm=nums.front();
//     nums.pop();
//     sum+=nm;
//   }
//   return sum;
// }

// int main(){
//   int tc;
//   cin>>tc;


//   while(tc>0){
//     tc--;
//     int n,x;
//     cin>>n>>x;
//     queue<int> nums;
//     for(int i=0;i<n;i++){
//       int n;
//       cin>>n;
//       nums.push(n);
//     }

//     cout<<getSum(nums,x)<<endl;
//   }
// }

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){

    ll t;
    cin>>t;
    
    
    while(t--){
        ll n,x;
        cin>>n>>x;
        
        vector<pair<ll,ll>> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=a[i].first;   
        }
        
        ll c=0;
        ll d=0;
        ll e=0;
        ll f=0;

        while(++e){
            for(int i=0;i<n;i++){
                if(a[i].first%x==0){
                    c+=a[i].second;
                    a[i].first=a[i].first/x;
                    a[i].second=(a[i].first*pow(x,e));  
                }
                else{
                    c+=a[i].second;
                    if(d==0)
                    f=i;
                    d=1;
                }
            }
            if(d)
            break;
        }
        
        for(int i=0;i<f;i++)
        c+=a[i].second;   
        
        cout<<c<<"\n";   
    }
    
}