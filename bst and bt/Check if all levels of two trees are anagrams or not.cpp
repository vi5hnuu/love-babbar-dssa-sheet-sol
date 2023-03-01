/*
Given two binary trees with same number of nodes, the task is to check if each of their levels are anagrams of each other or not. 
Note: All nodes of a tree should be unique.

Example 1:

Input:

Output: 1
Explanation: 
Tree 1:
Level 0 : 1
Level 1 : 3, 2
Level 2 : 5, 4

Tree 2:
Level 0 : 1
Level 1 : 2, 3
Level 2 : 4, 5

As we can clearly see all the levels of above two binary trees 
are anagrams of each other, hence return true.
Example 2:

Input:

Output: 0
Explanation: 
Tree 1:
Level 0 : 1
Level 1 : 2, 3 
Level 2 : 5, 4 

Tree 2: 
Level 0 : 1 
Level 1 : 2, 4 
Level 2 : 5, 3 

As we can clearly see that level 1 and leve 2 are not anagrams of each other, hence return false.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function areAnagrams() which takes the root of two trees as input and returns an 1 if all the levels are anagrams, else returns 0 as output.
 

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 104
1 <= tree.val <= 109
*/


class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2){
        if((root1 && !root2) || (!root1 && root2) || (root1->data!=root2->data)){
            return false;
        }
        queue<Node*> q1,q2;
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() && !q2.empty()){
            int sz1=q1.size();
            int sz2=q2.size();
            
            unordered_map<int,int> freq;
            while(sz1>0){
                sz1--;
                Node *node=q1.front();
                q1.pop();
                freq[node->data]++;
                if(node->left){
                    q1.push(node->left);
                }
                if(node->right){
                    q1.push(node->right);
                }
            }
            while(sz2>0){
                sz2--;
                Node *node=q2.front();
                q2.pop();
                freq[node->data]--;
                if(node->left){
                    q2.push(node->left);
                }
                if(node->right){
                    q2.push(node->right);
                }
            }
            unordered_map<int,int>::const_iterator itr=freq.cbegin();
            while(itr!=freq.cend()){
                if(itr->second!=0){
                    return false;
                }
                itr++;
            }
        }
        if(!q1.empty() || !q2.empty()){
            return false;
        }
        return true;
    }
};