// You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

// If the length of the word is 1 or 2 letters, change all letters to lowercase.
// Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
// Return the capitalized title.

 

// Example 1:

// Input: title = "capiTalIze tHe titLe"
// Output: "Capitalize The Title"
// Explanation:
// Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.
// Example 2:

// Input: title = "First leTTeR of EACH Word"
// Output: "First Letter of Each Word"
// Explanation:
// The word "of" has length 2, so it is all lowercase.
// The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
// Example 3:

// Input: title = "i lOve leetcode"
// Output: "i Love Leetcode"
// Explanation:
// The word "i" has length 1, so it is lowercase.
// The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
 

// Constraints:

// 1 <= title.length <= 100
// title consists of words separated by a single space without any leading or trailing spaces.
// Each word consists of uppercase and lowercase English letters and is non-empty.


/*
class Solution {
public:
    string capitalizeTitle(string title) {
        title+=" ";
       int sz=title.length();
        int chcount=0;
        for(int i=0;i<sz;i++){
                if(chcount==0 && (title[i]>='a' && title[i]<='z'))
                    title[i]-=32;
                else if(chcount!=0 && (title[i]>='A' && title[i]<='Z'))
                    title[i]+=32;
            
            chcount++;
            
            if(title[i]==' '){
                if(chcount==3){
                    title[i-2]+=32;
                }else if(chcount==2){
                    title[i-1]+=32;
                }
                chcount=0;
            }
        }
        return title.substr(0,sz-1);
    }
};
*/

//using two pointer
class Solution {
public:
    string capitalizeTitle(string title) {
        int i=0,j=0,sz=title.length(); //i at first ch of every word
        while(j<=sz){
            if(j==sz || title[j]==' '){//order of condition
                if((j-i)>2){
                    title[i]=toupper(title[i]);//2. cap first only when
                }
                i=j+1;
            }else{
                title[j]=tolower(title[j]);//1. every character to cap
            }
            j++;
        }
        return title;
    }
};
