#include <bits/stdc++.h>
using namespace std;

string isPerfect(vector<int> &a) {
    int n=a.size();
    for(int i = 0; i < n; i++) {
        int x = sqrt(a[i]);
        if((x * x) != a[i]) {
            return "YES" ;
        }
    }
    return "NO";
}

int main() {
    int tc;
    cin >> tc;

    while(tc>0){
      tc--;
      int n;
      cin>>n;
      vector<int> a(n);
      for(int i = 0; i < n; i++) {
          cin >> a[i];
      }
      cout<<isPerfect(a)<<endl;
    }

    return 0; 
}