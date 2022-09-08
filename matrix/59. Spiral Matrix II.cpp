// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

// Example 1:


// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 20


/*
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rows=n;
        int cols=n;
        vector<vector<int>> res(n,vector<int>(n,0));
        
        int st=1;
        //top row
        int tcolst=0;
        int tcolen=rows;
        
        //right col
        int rrowst=1;
        int rrowen=rows;
        
        //bottom row
        int bcolst=cols-2;
        int bcolen=0;
        
        //left col
        int lrowst=rows-2;
        int lrowen=1;
        
        int browNo=0;
        int lcolNo=cols-1;
        int urowNo=rows-1;
        int ucolNo=0;
        
        while(st<=n*n){
            //to right
            for(int i=tcolst;i<tcolen;i++){
                res[browNo][i]=st++;
            }
            browNo++;
            tcolst++;
            tcolen--;

            //to bottom
            for(int i=rrowst;i<rrowen;i++){
                res[i][lcolNo]=st++;
            }
            lcolNo--;
            rrowst++;
            rrowen--;
            
            
            //to left
            for(int i=bcolst;i>=bcolen;i--)
                res[urowNo][i]=st++;
            urowNo--;
            bcolst--;
            bcolen++;
            
            //to up
            for(int i=lrowst;i>=lrowen;i--)
                res[i][ucolNo]=st++;
            lrowst--;
            lrowen++;
            ucolNo++;
        }
        return res;
    }
};
*/

//modified
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int st=1;
        
        //each iteration [top,right,bottom,left] has 2 element less than prev so 2 var is enough
        int lrowst=n-2;//name is misleading
        int ucolNo=0;//name misleading
        
        while(st<=n*n){
            //to right
            for(int i=ucolNo;i<lrowst+2;i++){
                res[ucolNo][i]=st++;
            }

            //to bottom
            for(int i=ucolNo+1;i<lrowst+2;i++){
                res[i][lrowst+1]=st++;
            }
            
            
            //to left
            for(int i=lrowst;i>=ucolNo+1-1;i--)
                res[lrowst+1][i]=st++;
            
            //to up
            for(int i=lrowst;i>=ucolNo+1;i--)
                res[i][ucolNo]=st++;
            lrowst--;
            ucolNo++;
        }
        return res;
    }
};