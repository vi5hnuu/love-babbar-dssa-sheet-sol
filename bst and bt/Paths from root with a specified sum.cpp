/*
Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum. Path maynot end on a leaf node.

Example 1:

Input : 
sum = 8,
Root of tree
         1
       /   \
     20      3
           /    \
         4       15   
        /  \     /  \
       6    7   8    9      

Output :
1 3 4
Explanation : 
Sum of path 1, 3, 4 = 8.
Example 2:

Input : 
sum = 38,
Root of tree
          10
       /     \
     28       13
           /     \
         14       15
        /   \     /  \
       21   22   23   24
Output :
10 28
10 13 15  
Explanation :
Sum of path 10, 28 = 38 , and, 
Sum of path 10, 13, 15 = 38.
Your task :
You don't have to read input or print anything. Your task is to complete the function printPaths() that takes the root of the tree and sum as input and returns a vector of vectors containing the paths that lead to the sum.
 
Expected Time Complexity : O(N)
Expected Time Complexity : O(N)
 
Your Task :
1<=N<=10^5
1<=sum<=10^6
*/


/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution{
private:
    void printPaths(Node *root,int sum,vector<int> &path,vector<vector<int>> &paths){
        if(!root){
            return;
        }
        sum-=root->key;
        path.push_back(root->key);
        if(sum==0){
            paths.push_back(path);
            path.pop_back();
            return;
        }
        printPaths(root->left,sum,path,paths);
        printPaths(root->right,sum,path,paths);
        path.pop_back();
    }
public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<int> path;
        vector<vector<int>> paths;
        printPaths(root,sum,path,paths);
        return paths;
    }
};