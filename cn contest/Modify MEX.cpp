
int getMex(vector<int> &a){
    
    if(a[0]>0){
        return 0;
    }
    for(int i=1;i<a.size();i++){
        if(a[i]==a[i-1]){
            continue;
        }
        if(a[i]!=1+a[i-1]){
            return a[i-1]+1;
        }
    }
    return a[a.size()-1]+1;
}
int modifyMex(int n, vector<int> &a) {
    sort(a.begin(),a.end());
    unordered_set<int> st(a.begin(),a.end());
    int mex=getMex(a);
    int ans=2;
    if(st.find(mex+2)!=st.end()){
        return -1;
    }
    if(st.find(mex+1)!=st.end()){
        ans--;
    }
    return ans;
}
