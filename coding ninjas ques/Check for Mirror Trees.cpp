/*
Problem Statement
While learning DSA, Ninja found two N-ary trees and wants to check whether they are mirror images of each other or not. But, he can’t find a suitable method to check the same. Can you help Ninja to solve this problem?
You are given two N-ary trees, ‘TREEA’ and ‘TREEB’ having ‘N’ vertices labeled from 0 to ‘N’-1, and both the trees are rooted at node 0. Your task is to find whether the trees are mirror images of each other or not. Edges of the tree are in order from left to right.
For Example:
For the given example below, the trees are mirror images of each other.

Detailed explanation ( Input/output format, Notes, Constraints, Images )
Input Format:
The first line of the input contains an integer, 'T,’ denoting the number of test cases.

The first line of each test case contains a single integer, the ‘N’ denoting the number of vertices in both the trees.
Next, ‘N’-1 lines have two integers i,j, denoting an edge between vertex i and vertex j in ‘TREE_A’.
Next, ‘N’-1 lines have two integers i,j, denoting an edge between vertex i and vertex j in ‘TREE_B’.
Output Format:
For each test case, print ‘YES’ if both the trees are mirror images of each other.

Print the output of each test case in a separate line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 1000.
0 <= Node Label <=N-1.


Time limit: 1 sec
Sample Input 1:
2
5 
0 1
1 2
1 3
1 4
0 1
1 4
1 3
1 2
5
0 1
0 2
2 3
2 4
0 2
0 1
2 3
2 4
Sample Output 1:
YES
NO
Explanation Of Sample Input 1:
For the first test case,

As from the image above, we can clearly see that these two N-ary trees are mirror images of each other. Hence, the answer is ‘YES’.



For the second test case, 

The given two trees are not the mirror images because corresponding to the Node 4 of ‘TREE_A’, there exist Node3 of ‘TREE_B’.Hence, the answer is ‘NO’.
Sample Input 2:
2
5
0 1
0 2
1 3
1 4
0 2
0 1
1 4
1 3
5
0 1
0 2
1 4
2 3
0 1
0 2
1 3
3 4
Sample Output 2:
YES
NO

*/
#include<bits/stdc++.h>

/*
please mention that the edges will are given in order(root->leaf fashion) and not like some are root->leaf and some are leaf->root...i meant edges form a directed graph
*/

bool isEqual(vector<int> &A,vector<int> &B){
    int lvlA=A.size();
    int lvlB=B.size();
    if(lvlA!=lvlB){
        return false;
    }
    int i=0,j=lvlA-1;
    while(i<lvlA){
        if(A[i]!=B[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
bool isMirror(int source,vector<vector<int>> &adjA,vector<vector<int>> &adjB) {
    ///////////////////////
    
    if(!isEqual(adjA[source],adjB[source])){
        return false;
    }
    //////////////////////
    for(int n:adjA[source]){
        if(!isMirror(n,adjA,adjB)){
            return false;
        }
    }
    return true;
}
bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB){
    if(n==0){
        return true;
    }
    vector<vector<int>> adjA(n),adjB(n);

    //directed edges are given
    for(auto &edge:edgesA){
        adjA[edge[0]].push_back(edge[1]);
    }
    
    for(auto &edge:edgesB){
        adjB[edge[0]].push_back(edge[1]);
    }

    return isMirror(0,adjA,adjB);
}