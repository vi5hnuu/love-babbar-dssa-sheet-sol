/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
*/

/*
This approach failed 
nums =[2,2,2,2,3,4,5]
k=4
expected : false
output : true

dp ->
    1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 
    1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 
    1 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 
    1 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 
    1 0 1 1 1 1 1 1 1 1 0 1 0 0 0 0 
    1 0 1 1 1 1 1 1 1 1 1 1 1 1 0 1 
    1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
*/
// class Solution {
// private:
//     int sumvals(const vector<int> &nums)const{
//         int sum=0;
//         for(const int &n:nums){
//             sum+=n;
//         }
//         return sum;
//     }
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum=sumvals(nums);
//         if(sum%k!=0){
//             return false;
//         }
//         int rows=nums.size();
//         int cols=(k-1)*(sum/k)+1;
//         vector<vector<bool>> dp(rows,vector<bool>(cols,false));

//         for(int row=0;row<rows;row++){
//             for(int col=0;col<cols;col++){
//                 if(col==0){
//                     dp[row][col]=true;
//                 }else if(row==0){
//                     if(nums[row]==col){
//                         dp[row][col]=true;
//                     }else{
//                         dp[row][col]=false;
//                     }
//                 }else{
//                     if(dp[row-1][col]){
//                         dp[row][col]=true;
//                     }else if(col>=nums[row]){
//                         int diff=col-nums[row];
//                         if(dp[row-1][diff]){
//                             dp[row][col]=true;
//                         }else{
//                             dp[row][col]=false;
//                         }
//                     }else{
//                         dp[row][col]=false;
//                     }
//                 }
//             }
//         }
//         for(int row=0;row<rows;row++){
//             for(int col=0;col<cols;col++){
//                 cout<<dp[row][col]<<" ";
//             }
//             cout<<endl;
//         }
//         for(int i=sum/k;i<cols;i+=(sum/k)){
//             if(!dp[rows-1][i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

///////////////Recursion -> TLE at 37/162/////////////////
// class Solution {
// private:
//     int sumvals(const vector<int> &nums)const{
//         int sum=0;
//         for(const int &n:nums){
//             sum+=n;
//         }
//         return sum;
//     }
    
//     bool canPartitionKSubsets(vector<int>& nums, int k,int idx,vector<int> &sets) {
//         if(idx>=nums.size()){
//             for(int i=1;i<k;i++){
//                 if(sets[i]!=sets[i-1]){
//                     return false;
//                 }
//             }
//             return true;
//         }

//         for(int i=0;i<k;i++){
//             sets[i]+=nums[idx];
//             int a=canPartitionKSubsets(nums,k,idx+1,sets);
//             if(a){
//                 return true;
//             }
//             sets[i]-=nums[idx];
//         }
//         return false;
//     }
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum=sumvals(nums);
//         if(sum%k!=0){
//             return false;
//         }
//         vector<int> sets(k,0);
//         return canPartitionKSubsets(nums,k,0,sets);
//     }
// };
//////////////////////////////////////////////////////////////
//Optimized  : TLE at 49 / 162
// class Solution {
// private:
//     int sumvals(const vector<int> &nums)const{
//         int sum=0;
//         for(const int &n:nums){
//             sum+=n;
//         }
//         return sum;
//     }
    
//     bool canPartitionKSubsets(vector<int>& nums, int k,int idx,vector<int> &sets,int limitPerCol) {
//         if(idx>=nums.size()){
//             for(int i=1;i<k;i++){
//                 if(sets[i]!=sets[i-1]){
//                     return false;
//                 }
//             }
//             return true;
//         }

//         for(int i=0;i<k;i++){
//             sets[i]+=nums[idx];
//             if(sets[i]<=limitPerCol){
//                 int a=canPartitionKSubsets(nums,k,idx+1,sets,limitPerCol);
//                 if(a){
//                     return true;
//                 }
//             }
//             sets[i]-=nums[idx];
//         }
//         return false;
//     }
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum=sumvals(nums);
//         if(sum%k!=0){
//             return false;
//         }
//         vector<int> sets(k,0);
//         return canPartitionKSubsets(nums,k,0,sets,sum/k);
//     }
// };

/////////////////////////////////////////////////////////////////////////////
// Lets give choice to buckets TLE at 158/162
// class Solution {
// private:
//     int sumvals(const vector<int> &nums)const{
//         int sum=0;
//         for(const int &n:nums){
//             sum+=n;
//         }
//         return sum;
//     }
//     bool canFillBucket(vector<int>& nums,int idx,int bkt,int k,vector<bool>& taken,int rnbucketSum,int bucketSum) {
//            if(rnbucketSum==0){
//                if(bkt<k)
//                     return canFillBucket(nums,0,bkt+1,k,taken,bucketSum,bucketSum);
//                 else
//                     return true;
//            }else if(rnbucketSum<0 || idx>=nums.size()){
//                return false;
//            }

//             if(!taken[idx]){
//                 taken[idx]=true;
//                 bool take=canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum-nums[idx],bucketSum);
//                 if(take){
//                     return true;
//                 }
//                 taken[idx]=false;
//                 return canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum,bucketSum);
//             }else{
//                 return canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum,bucketSum);
//             }
//            return false;
//     }
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         //1 <= nums[i] <= 104
//         int sum=sumvals(nums);
//         if(sum%k!=0){
//             return false;
//         }
//         vector<bool> taken(nums.size(),false);
        
//         return canFillBucket(nums,0,1,k,taken,sum/k,sum/k);
//     }
// };

//////////////////////////////////////////////////////////

// class Solution {
// private:
//     int sumvals(const vector<int> &nums)const{
//         int sum=0;
//         for(const int &n:nums){
//             sum+=n;
//         }
//         return sum;
//     }
//     bool canFillBucket(vector<int>& nums,int idx,int bkt,int k,int &taken,int rnbucketSum,int bucketSum) {
//            if(rnbucketSum==0){
//                if(bkt<k)
//                     return canFillBucket(nums,0,bkt+1,k,taken,bucketSum,bucketSum);
//                 else
//                     return true;
//            }else if(rnbucketSum<0 || idx>=nums.size()){
//                return false;
//            }

//             if(!((taken>>idx)&1)){
//                 taken=taken | (1<<idx);//set bit 1
//                 bool take=canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum-nums[idx],bucketSum);
//                 if(take){
//                     return true;
//                 }
//                 taken=taken & ~(1<<idx);//set bit 0
//                 return canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum,bucketSum);
//             }else{
//                 return canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum,bucketSum);
//             }
//            return false;
//     }
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         //1 <= nums[i] <= 104
//         int sum=sumvals(nums);
//         if(sum%k!=0){
//             return false;
//         }
        
//         // 1 <= k <= nums.length <= 16
//         int taken=0;
        
//         return canFillBucket(nums,0,1,k,taken,sum/k,sum/k);
//     }
// };

/////////////////////////////////////////////////////
// class Solution {
// private:
//     int sumvals(const vector<int> &nums)const{
//         int sum=0;
//         for(const int &n:nums){
//             sum+=n;
//         }
//         return sum;
//     }
//     bool canFillBucket(vector<int>& nums,int idx,int bkt,int k,int &taken,int rnbucketSum,int bucketSum) {
//            if(rnbucketSum==0){
//                if(bkt+1==k)//for 4 division, if 3 division success 4th will be there for sure
//                     return true;
//                 else
//                     return canFillBucket(nums,0,bkt+1,k,taken,bucketSum,bucketSum);
//            }else if(rnbucketSum<0 || idx>=nums.size()){
//                return false;
//            }

//             if(!((taken>>idx)&1)){
//                 taken=taken | (1<<idx);//set bit 1
//                 bool take=canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum-nums[idx],bucketSum);
//                 if(take){
//                     return true;
//                 }
//                 taken=taken & ~(1<<idx);//set bit 0
//                 return canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum,bucketSum);
//             }else{
//                 return canFillBucket(nums,idx+1,bkt,k,taken,rnbucketSum,bucketSum);
//             }
//            return false;
//     }
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         //1 <= nums[i] <= 104
//         if(k==1){
//             return true;
//         }
//         int sum=sumvals(nums);
//         if(sum%k!=0){
//             return false;
//         }
        
//         // 1 <= k <= nums.length <= 16
//         int taken=0;
//         vector<vector<int>> dp();
//         return canFillBucket(nums,0,1,k,taken,sum/k,sum/k);
//     }
// };
/////////////////////////////////////////////////////
class Solution {
private:
    int sumvals(const vector<int> &nums)const{
        int sum=0;
        for(const int &n:nums){
            sum+=n;
        }
        return sum;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //1 <= nums[i] <= 104
        /*
        -1 : illegal
         x : i might succeed make x==sum/k==sum of 1 bucket
         0 : i dont know how many time dp[i] become zero but yes some bucket become==sum of bucket
         dp[i<<n-1]==0 : i made k buckets successfylly [dp[i<<n-1] become k times zero]
        
        eg : [1,1,1,2,2,2]
            k=3
            sum=9
            sum/k=3

        all possible ways (sum/k=3)
        dp[ 000000 ] =  0  <- mask
                    what choices do we have :
                    take 1st dp[ 000001 ] = dp[ 000000 ] + nums[0] = [2]%3 = 2 
                    take 2nd dp[ 000010 ] = dp[ 000000 ] + nums[1] = [2]%3 = 2
                    take 3rd dp[ 000100 ] = dp[ 000000 ] + nums[2] = [2]%3 = 2
                    take 4th dp[ 001000 ] = dp[ 000000 ] + nums[3] = [1]%3 = 1
                    take 5th dp[ 010000 ] = dp[ 000000 ] + nums[4] = [1]%3 = 1
                    take 6th dp[ 100000 ] = dp[ 000000 ] + nums[5] = [1]%3 = 1

                    now what does dp[let say 000001] represent
                    it says that i might make bucket sum 3 in future who knows😶‍🌫️

                    now what does dp[let say any mask with val -1] represent
                    it says that this pattern can never give you success...
                    
                    //lets see how
        dp[ 000001 ] <-mask   .... after mask 000000 we come here 00001
                dp[ 000001 ] = dp[ 000000 ] + nums[0] = [2]%3 = 2 [state by dp[000000]]
                    what choices do we have
                    take 2nd dp[ 000011 ] = -1
                    take 3rd dp[ 000101 ] = -1
                    take 4th dp[ 001001 ] =  (dp[ 000001 ] + 1<- num at ith bit)=(3)%3 = [0]
                    take 5th dp[ 010001 ] =  (dp[ 000001 ] + 1<- num at ith bit)=(3)%3 = [0]
                    take 6th dp[ 100001 ] =  (dp[ 000001 ] + 1<- num at ith bit)=(3)%3 = [0]
        dp[ 000010 ]
                dp[ 000010 ] = dp[ 000000 ] + nums[1] = [2]%3 = 2 old state by dp[000000]
                //I am not going to fill this...😡😡😡😡😡😡😡
                //go to end of this sequence...only if you want to understand this 💩💩💩💩
        dp[ 000011 ] = -1                          let your algo fill this 😂😂😂 
        dp[ 000100 ] = -1                          let your algo fill this 😂😂😂
        dp[ 000101 ] = -1                          let your algo fill this 😂😂😂
        dp[ 000110 ] = -1                          let your algo fill this 😂😂😂
        dp[ 000111 ] = -1                          let your algo fill this 😂😂😂 ->
        dp[ 001000 ] = -1                          let your algo fill this 😂😂😂
        dp[ 001001 ] = -1                          let your algo fill this 😂😂😂
        dp[ 001010 ] = -1                          let your algo fill this 😂😂😂
        dp[ 001011 ] = -1                          let your algo fill this 😂😂😂
        dp[ 001100 ] = -1                          let your algo fill this 😂😂😂
        dp[ 001101 ] = -1                          let your algo fill this 😂😂😂
        dp[ 001110 ] = -1                          let your algo fill this 😂😂😂
        dp[ 001111 ] = -1                          let your algo fill this 😂😂😂
        dp[ 010000 ] = -1                          let your algo fill this 😂😂😂
        dp[ 010001 ] = -1                          let your algo fill this 😂😂😂
        dp[ 010010 ] = -1                          let your algo fill this 😂😂😂
        dp[ 010011 ] = -1                          let your algo fill this 😂😂😂
        dp[ 010100 ] = -1                          let your algo fill this 😂😂😂
        dp[ 010101 ] = -1                          let your algo fill this 😂😂😂
        dp[ 010110 ] = -1                          let your algo fill this 😂😂😂
        dp[ 010111 ] = -1                          let your algo fill this 😂😂😂
        dp[ 011000 ] = -1                          let your algo fill this 😂😂😂
        dp[ 011001 ] = -1                          let your algo fill this 😂😂😂
        dp[ 011010 ] = -1                          let your algo fill this 😂😂😂
        dp[ 011011 ] = -1                          let your algo fill this 😂😂😂
        dp[ 011100 ] = -1                          let your algo fill this 😂😂😂
        dp[ 011101 ] = -1                          let your algo fill this 😂😂😂
        dp[ 011110 ] = -1                          let your algo fill this 😂😂😂
        dp[ 011111 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100000 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100001 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100010 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100011 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100100 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100101 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100110 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100111 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101000 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101001 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101010 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101011 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101100 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101101 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101110 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101111 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100000 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100001 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100010 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100011 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100100 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100101 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100110 ] = -1                          let your algo fill this 😂😂😂
        dp[ 100111 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101000 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101001 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101010 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101011 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101100 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101101 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101110 ] = -1                          let your algo fill this 😂😂😂
        dp[ 101111 ] = -1                          let your algo fill this 😂😂😂
        one of the valid path : 
            100100->dp[100100]==0
            110110->dp[110110]==0
            111111->dp[111111]==0
        
        
        //////////////////////////////////////////
        Thsese are the last two patters for ref..
             dp[ 000000 ] =  0  <- mask
                    what choices do we have :
                    take 1st dp[ 000001 ] = dp[ 000000 ] + nums[0] = [2]%3 = 2 
                    take 2nd dp[ 000010 ] = dp[ 000000 ] + nums[1] = [2]%3 = 2
                    take 3rd dp[ 000100 ] = dp[ 000000 ] + nums[2] = [2]%3 = 2
                    take 4th dp[ 001000 ] = dp[ 000000 ] + nums[3] = [1]%3 = 1
                    take 5th dp[ 010000 ] = dp[ 000000 ] + nums[4] = [1]%3 = 1
                    take 6th dp[ 100000 ] = dp[ 000000 ] + nums[5] = [1]%3 = 1

                    now what does dp[let say 000001] represent
                    it says that i might make bucket sum 3 in future who knows😶‍🌫️

                    now what does dp[let say any mask with val -1] represent
                    it says that this pattern can never give you success...
                    
                    //lets see how
        dp[ 000001 ] <-mask   .... after mask 000000 we come here 00001
                dp[ 000001 ] = dp[ 000000 ] + nums[0] = [2]%3 = 2 [state by dp[000000]]
                    what choices do we have
                    take 2nd dp[ 000011 ] = -1
                    take 3rd dp[ 000101 ] = -1
                    take 4th dp[ 001001 ] =  (dp[ 000001 ] + 1<- num at ith bit)=(3)%3 = [0]
                    take 5th dp[ 010001 ] =  (dp[ 000001 ] + 1<- num at ith bit)=(3)%3 = [0]
                    take 6th dp[ 100001 ] =  (dp[ 000001 ] + 1<- num at ith bit)=(3)%3 = [0]
       
        now, read carefully...
        dp[000000] -> in the given array for each element starting from index 0 to nums.size()-1
        we need to select element in proper sequence then only we can fill k buckets..
        of size sum/k

        eg. [1,1,1,2,2,2] 
            k=3
            sum = 9
            sum/k=3

            we can select [1,1,1] -> first bucket filled
            but what about the rest two we fail

            so we need to choose element wisely but how...
            simple.... think that what you are choosing is right
                    000001 <- i choose 1st element first
                    000010 <- i choose 2nd element first
                    000100 <- i choose 3rd element first
                    001000 <- i choose 4th element first
                    010000 <- i choose 5th element first
                    100000 <- i choose 6th element first
            so i have 6 ways to choose first element
            which means each sequence have 1 bit set

            lookt it as binary tree

                        000000 root
             000001 000010 000100 001000 010000 100000 <- 6 child

             now in recursion [this is dp i know but dp comes from recursion if you know]
             we first complate 1 branch

             take 1st branch and that is 000001
             what this dipict(branch)-> hey i have taken first element from nums(vector) as 
             my first choice could you please tell me if i can make it to end...

             000001 <- i took 1 element but that doest fill my bucket of size sum/k
             now i need to choose another element
             i can choose 2nd,3rd,4th,5th,6th....but wait😶

                            000001 root
                000011(X) 000101(X) 001001(ok) 010001(ok) 100001(ok)

                000011(X) because sum of last 2 element is 4>sum/k

                now as told recursion first complete its branch
                we choose 001001
                remember dp[001001]==0 you knw why ?

                now again i have to choose an element
                                001001 root
                        001011(ok) 001101(ok) 011001(ok) 101001(ok)
                
                i choose 001011

                                001001 root
                            001111(X) 011011(ok) 101011(ok)
                
                i choose 011011
                                011011 root
                            011111(ok) 111011(ok)
                
                i choose 011111
                        011111 root
                        111111
                
                Notes : 
                    -each child of root increase 1 bit->1 element we choose
                    -child is invalid means root never change state dp[child]
                    for example dp[001001 see last 3r tree] never update dp[001111]
                    hence dp[001111]=-1
                    which implies this sequence can not give us our answer
                    see code below for clarification (we actuall check for this...)


        */
        // 1 <= k <= nums.length <= 16
        if(k==1){ //the vector itself is answer 😂😂
            return true;
        }
        int sum=sumvals(nums);
        if(sum%k!=0){
            return false;
        }
        int n=nums.size();
        int bucketSum=sum/k;

        int tpp=1<<n;// total possible patterns
        vector<int> dp(tpp,-1);
        dp[0]=0;

        for(int mask=0;mask<tpp;mask++){
            if(dp[mask]==-1){
                continue; //we dont want to choose next element as we know this sequence will 
                           // never give answer because his parent didnt like this kid😂😂😂.
            }
            //let say mask=010010 we choose proper**** childs for this mask(root) here
            for(int child=0;child<nums.size();child++){
                //is nums[child] a valid child for root ? 🤕🤕
                if(!(mask & (1<<child)) && ((dp[mask]+nums[child])<=bucketSum)){
                    int newMask=mask |(1<<child); //new element added
                    dp[newMask]=(dp[mask]+nums[child])%bucketSum;
                    //understand above line carefully....
                }
            }
        }
        return dp[tpp-1]==0;
    }
};

