/*
Problem Statement
You are given ‘K’ and ‘N’ and you have to do the following:-
Output all possible combinations of arrays whose elements sum is equal to ‘N’ and you can use only elements in the range 1 to 9 inclusive and you can use each element only once and the size of the combination should be ‘K’.
Two combinations are called different if there is an element that is in one combination and not in another.
Example:
Input: ‘K’ = 2, ‘N’ = ‘5’

Output: [[1, 4], [2, 3]]

1 + 4 = 5 and 2 + 3 = 5. Only these two combinations are there which sum upto n so answer is [[1, 4], [2, 3]].
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Input Format :
The first line will contain the integer 'T', denoting the number of test cases.

The second line will contain the value of ‘K’.

The third line will contain the value of ‘N’.
Output format :
For each test case, print all the possible combinations. If there is no combination -1 will be printed on the console.
Note :
You don't need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
2 <= K <= 9
1 <= N <= 60

Time Limit: 1 sec
Sample Input 1 :
2
2
5
3
8
Sample Output 1 :
1 4
2 3
1 2 5
1 3 4
Explanation Of Sample Input 1 :
For the first case:
1 + 4 = 5 and 2 + 3 = 5. Only these two combinations are there which sum upto n so answer is [[1, 4], [2, 3]].

For the second case:
1 + 2 + 5 = 8 and 1 + 3 + 4 = 8. Only these two combinations are there which sum upto n so answer is [[1, 2, 5], [1, 3, 4]].
Sample Input 2 :
2
4
10
3
9
Sample Output 2 :
1 2 3 4
1 2 6
1 3 5
2 3 4

*/
#include <bits/stdc++.h>

void generateCombinations(int i, int &n, int &k,vector<vector<int>> &combinations,vector<int> &combination, int sum = 0) {
    if(sum==n && combination.size()==k){
        combinations.push_back(combination);
        return;
    }
    if (i > 9 || sum > n || combination.size() > k) {
        return;
    }
    generateCombinations(i+1,n,k,combinations,combination,sum);
    combination.push_back(i);
    generateCombinations(i+1,n,k,combinations,combination,sum+i);
    combination.pop_back();
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> combinations;
    vector<int> combination;
    generateCombinations(1,n,k,combinations,combination);
    
    sort(combinations.begin(),combinations.end());
    return combinations;
}
