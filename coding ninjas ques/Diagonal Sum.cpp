#include <bits/stdc++.h> 
/**********************************************************
    
    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
    public :
	    T data;
	    BinaryTreeNode<T> *left;
	    BinaryTreeNode<T> *right;

	    BinaryTreeNode(T data) {
	        this -> data = data;
	        left = NULL;
	        right = NULL;
	    }
    };

***********************************************************/

#include <vector>

void diagonalSum(BinaryTreeNode < int >* root,map<int,vector<int>> &dSum,int dIdx){
  if (!root) {
	  return;
  }
  dSum[dIdx].push_back(root->data);
  diagonalSum(root->left,dSum,dIdx+1);
  diagonalSum(root->right,dSum,dIdx);
}
vector < long long > diagonalSum(BinaryTreeNode < int >* root) {
    //go right keep diagonal same, go left increase diagonal number
	map<int,vector<int>> dSum;
	diagonalSum(root,dSum,0);
	map<int,vector<int>>::const_iterator itr=dSum.cbegin();
	vector < long long > diagonalSum(dSum.size());
	while(itr!=dSum.cend()){
		for(int n:itr->second)
			diagonalSum[itr->first]+=n;
		itr++;
	}
	return diagonalSum;
}
