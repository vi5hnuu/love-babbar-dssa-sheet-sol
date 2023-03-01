/*
Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.


Example 1:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 3, 1, 2}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      3    2 
As we can clearly see, the second tree
is mirror image of the first.
Example 2:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 2, 1, 3}
Output:
0
Explanation:
   1          1
 / \        /  \
2   3      2    3 
As we can clearly see, the second tree
isn't mirror image of the first.

Your Task:
You don't need to read input or print anything. Your task is to complete the function checkMirrorTree() which takes 2 Integers n, and e;  and two arrays A[] and B[] of size 2*e as input and returns 1 if the trees are mirror images of each other and 0 if not.


Expected Time Complexity: O(e)
Expected Auxiliary Space: O(e)


Constraints:
1 <= n,e <= 105
*/


class Solution {
private:
    bool areMirrorTree(int root1,int root2,
    unordered_map<int,vector<int>> &adjTree1,
    unordered_map<int,vector<int>> &adjTree2){
        vector<int> &adj1=adjTree1[root1];
        vector<int> &adj2=adjTree2[root2];
        
        if(root1!=root2 || (adj1.size()!=adj2.size())){
            return false;
        }
        
        if(adj1.size()==0 && adj1.size()==adj2.size()){
            return true;
        }
        
        int i=0;
        int sz=adj1.size();
        while(i<sz){
            if(!areMirrorTree(adj1[i],adj2[sz-1-i],adjTree1,adjTree2)){
                return false;
            }
            i++;
        }
        return true;
    }
public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        int i=0;
        unordered_map<int,vector<int>> adjTree1,adjTree2;
        for(int i=0;i<2*e;i+=2){
            adjTree1[A[i]].push_back(A[i+1]);
            adjTree2[B[i]].push_back(B[i+1]);
        }
        return areMirrorTree(1,1,adjTree1,adjTree2);
    }
};