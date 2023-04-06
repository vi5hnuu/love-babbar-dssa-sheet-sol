/*
Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

Example 1:

Input:
a = amazon
b = azonam
Output: 1
Explanation: amazon can be rotated anti
clockwise by two places, which will make
it as azonam.
Example 2:

Input:
a = geeksforgeeks
b = geeksgeeksfor
Output: 0
Explanation: If we rotate geeksforgeeks by
two place in any direction , we won't get
geeksgeeksfor.
Your Task:
The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

Expected Time Complexity: O(N).
Expected Auxilary Complexity: O(N).
Challenge: Try doing it in O(1) space complexity.

Constraints:
1 ≤ length of a, b ≤ 105
*/


class Solution{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2){
        int s1len=str1.length();
        int s2len=str2.length();
        if(s1len!=s2len){
            return false;
        }
        
        bool found=true;
        for(int i=2;i<s1len+2;i++){
            if(str1[i%s1len]!=str2[(i-2)<0 ? i-2+s1len : i-2]){
                found=false;
                break;
            }
        }
        if(found){
            return true;
        }
        
        ////////////////////////////////////////////////////////////////
        found=true;
        for(int i=s1len-2,k=0;i<s1len*2-2;i++,k++){
            if(str1[i%s1len]!=str2[k]){
                found=false;
                break;
            }
        }
        return found;
    }

};