/*
You are given a string S containing only uppercase English characters. Find whether S is the same as its reflection in the mirror.
For Example, S = “AMAMA” is the same as its reflection in the mirror.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
1
ITATI
Sample Output 1:
YES
Explanation Of Sample Input 1:
String “ITATI” is the same as its reflection in the mirror.
Sample Input 2:
2
MMMM
MZM
Sample Output 2:
YES
NO
*/
#include <bits/stdc++.h>

bool isReflectionEqual(string &s){
	set<int> rf{'A','H','I','M','O','T','U','V','W','X','Y'};

	int i=0,j=s.length()-1;
	while(i<=j){
		if(s[i]!=s[j] || rf.find(s[i])==rf.end() || rf.find(s[j])==rf.end()){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
