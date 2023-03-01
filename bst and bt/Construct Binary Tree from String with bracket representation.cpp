/*
Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the roots value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists. The integer values will be less than or equal to 10^5.

Example 1:

Input: "1(2)(3)" 
Output: 2 1 3
Explanation:
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Inorder of above tree is "2 1 3".
Example 2:

Input: "4(2(3)(1))(6(5))"
Output: 3 2 1 4 5 6
Explanation:
           4
         /   \
        2     6
       / \   / 
      3   1 5   
Your Task:
You don't need to read input or print anything. Your task is to complete the function treeFromString() which takes a string str as input parameter and returns the root node of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 <= |str| <= 105
*/


/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
private:
    Node *treeFromString(string &str,int low,int high){
        if(low>high){
            return NULL;
        }
        int val=0;
        while(low<=high && str[low]!='('){
            val=val*10+(str[low]-'0');
            low++;
        }
        if(low>high){
            return new Node(val);
        }
        Node *root=new Node(val);
        low++;
        int j=low;
        int lParen=1;
        while(lParen!=0){
            if(str[j]=='('){
                lParen++;
            }else if(str[j]==')'){
                lParen--;
            }
            j++;
        }
        root->left=treeFromString(str,low,j-2);
        root->right=treeFromString(str,j+1,high-1);
        return root;
    }
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        return treeFromString(str,0,str.length()-1);
    }
};