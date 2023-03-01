/*
Given a binary tree, you need to find the number of all root to leaf paths along with their path lengths.

Example 1:

Input:
      3
    /   \
   2     4
Output:
2 2 $

Explanation :
There are 2 roots to leaf paths
of length 2(3 -> 2 and 3 -> 4)
Example 2:

Input:
        10
     /   \
    20    30
   / \    
  40  60

Output:
2 1 $3 2 $

Explanation:
There is 1 root leaf paths of
length 2 and 2 roots to leaf paths
of length 3.
Your Task:
Your task is to complete the function pathCounts that prints the number of all root to leaf paths along with their path length separated by space and "$".

Constraints:
1 <= T <= 30
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*You are required to complete below method */
void pathCounts(Node *root,int len,map<int,int> &mp){
    if(!root){
        return;
    }
    len++;
    if(!root->left && !root->right){
        mp[len]++;
    }
    pathCounts(root->left,len,mp);
    pathCounts(root->right,len,mp);
}
void pathCounts(Node *root)
{
    map<int,int> mp;//len->count
    pathCounts(root,0,mp);
    map<int,int>::const_iterator itr=mp.cbegin();
    while(itr!=mp.cend()){
        cout<<itr->first<<" "<<itr->second<<" "<<"$";
        itr++;
    }
    return;
}