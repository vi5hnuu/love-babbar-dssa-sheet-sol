/*
You are provided with the two strings named X and Y respectively. Y has its own specific order and has no repeating characters. Your task is to arrange the characters of the first string i.e. X in such a way that the order of characters in X is exactly the same as in Y, which means if ‘d’ occurs after ‘c’ in Y then it should also occur after ‘c’ in X ( obviously if X has ‘d’ and ‘c’ as characters in it ). All you have to do is, convert string X in the specific order with respect to string Y.
Note :
Both the strings have only lowercase English alphabets. 
There may be more than one correct solution, you have to return any one of the possible solutions.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
1
acabd
abc
Sample Output 1:
aabcd
Explanation of Sample Input 1:
String Y has ‘a’ first then ‘b’ and then ‘c’ and therefore string X must be ordered as ‘aabcd’ to keep the respective order of characters same as in string Y.
Other possible answers are: ‘daabc’ , ‘adabc’ , ‘aadbc’, ‘aabdc’.
Sample Input 2:
4
dfhfgk
h
aabbb
gd
abababab
ab
cag
abcdef
Sample Output 2:
hdffgk
aabbb
aaaabbbb
acg
*/
#include <bits/stdc++.h> 
string specificOrder(string & x, string & y) {
    int fr[26]{};
    for(char c:x){
        fr[c-'a']++;
    }

    string ans="";
    for(char c:y){
        ans+=string(fr[c-'a'],c);
        fr[c-'a']=0;
    }
    for(int i=0;i<26;i++){
        if(fr[i]>0){
            ans+=string(fr[i],static_cast<char>(i+'a'));
        }
    }
    return ans;
}
