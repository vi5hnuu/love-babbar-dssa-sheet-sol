class Solution {
vector<int> nextMin(vector<int>& heights,int n){
    stack<int> stck;
    vector<int> nxtmn(n,n);
    for(int i=n-1;i>=0;i--){
        while(!stck.empty() && heights[stck.top()]>=heights[i]){
            stck.pop();
        }
        if(!stck.empty()){
            nxtmn[i]=stck.top();
        }
        stck.push(i);
    }
    return nxtmn;
}
vector<int> prevMin(vector<int>& heights,int n){
    stack<int> stck;
    vector<int> prvmn(n,-1);
    for(int i=0;i<n;i++){
        while(!stck.empty() && heights[stck.top()]>=heights[i]){
            stck.pop();
        }
        if(!stck.empty()){
            prvmn[i]=stck.top();
        }
        stck.push(i);
    }

    return prvmn;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nm=nextMin(heights,n);
        vector<int> pm=prevMin(heights,n);

        int mxArea=INT_MIN;
        for(int i=0;i<n;i++){
            mxArea=max(mxArea,heights[i]*(nm[i]-pm[i]-1));
        }
        return mxArea;
    }
};


// we spread the bar to right and to left 
// for example int the above give diagram :
//     Overview :

//     index 0 : 
//         we spread it to right and it will go upto index 0 only
//         we spread it to left and it will go upto index 0 only
//     index 1 : 
//         we spread it to right and it will go upto index 5
//         we spread it to left and it will go upto index 0 only
//     index 2 : 
//         we spread it to right and it will go upto index 3 only
//         we spread it to left and it will go upto index 2 only
//     index 3 : 
//         we spread it to right and it will go upto index 3 only
//         we spread it to left and it will go upto index 3 only
//     index 4 : 
//         we spread it to right and it will go upto index 5 only
//         we spread it to left and it will go upto index 2 only
//     index 5 : 
//         we spread it to right and it will go upto index 5 only
//         we spread it to left and it will go upto index 5 only
    

//     Now, how do we do this ?

//     we make two array which will store(index) next min,prev min...
    
//     why do we maintain prev min and next min : stop and read above
//     overview to understand by yourself first...

//     n=length of heights

//     if you dont know how to calculate next minimum ele or previous
//     minimum ele i would suggest you to solve next preater element or
//     previous greater element question first.
    
//     nextMin(indexes)=(fill right to left)[1,n,4,4,n,n]
//     prevMin(indexes)=(fill left to right)[-1,-1,1,2,1,4]

//     area=height[i]*width=height[i]*(nextMin[i]-prevMin[i]-1);
//     width=count(ele itself+ele greater then itself)

//     area for index 0 : Area= 2*(1-(-1)-1)=2 
//     area for index 1 : Area= 1*(n-(-1)-1)=6
//     area for index 2 : Area= 5*(4-1-1)=10      
//     area for index 3 : Area= 6*(4-2-1)=6
//     area for index 4 : Area= 2*(n-1-1)=8
//     area for index 5 : Area= 3*(n-4-1)=3

//     max = 10
//     Read above line using diagram ☝️




