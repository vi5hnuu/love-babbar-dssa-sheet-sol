/*
class RecentCounter {
    vector<int> res;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        res.push_back(t);
        int ans=0;
        int tstart=t-3000;
        for(int i=res.size()-1;i>=0;i--){
            if(res[i]>=tstart)
                ans++;
        }
        return ans;
    }
};
*/

class RecentCounter {
private:
    vector<int> res;
    
    int getIndexOfOrGre(int n){//index of n or greater than n , or -1 if both fails
        int low=0,high=res.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(res[mid]==n)
                return mid;
            else if(res[mid]>n){
                if(mid-1>=0 && res[mid-1]<n)
                    return mid;
                high=mid-1;
            }else{
                if(mid+1<res.size() && res[mid+1]>n)
                    return mid+1;
                low=mid+1;
            }
        }
        return -1;
    }
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        res.push_back(t);
        int ans=0;
        int tstart=t-3000;
        int i=getIndexOfOrGre(tstart);
        if(i<0)
            return res.size();
        else
            return res.size()-i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */