#include <bits/stdc++.h> 


int getMin(initializer_list<int> nums){
    int mn=INT_MAX;
    for(int n:nums){
        mn=min(mn,n);
    }
    return mn;
}
int minDirectionChanges(int i,int j,vector<vector<char>> &grid,int &n,int &m,int changes){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='/'){
        return INT_MAX;
    }
    if(i==n-1 && j==m-1){
        return changes;
    }
    char state=grid[i][j];
    grid[i][j]='/';
    int a=minDirectionChanges(i,j+1,grid,n,m,state=='R' ? changes :changes+1);
    int b=minDirectionChanges(i,j-1,grid,n,m,state=='L' ? changes :changes+1);
    int c=minDirectionChanges(i+1,j,grid,n,m,state=='D' ? changes :changes+1);
    int d=minDirectionChanges(i-1,j,grid,n,m,state=='U' ? changes :changes+1);
    grid[i][j]=state;
    return getMin({a,b,c,d});
}
int minDirectionChanges(vector<vector<char>> grid, int n, int m){
    int ans= minDirectionChanges(0,0,grid,n,m,0);
    return ans;
}

