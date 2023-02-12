/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)


Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50
*/


/*
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"} <- sorted

baa & abcd => b->a
abcd & abca => d->a
abca & cab => a->c
cab & cad => b->d

//////////
b->a,d
d->a
a->c
*/

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int> > alpAdj(K);// 0->1 ==> a->b
        vector<int> indegree(K,0);
        int i=0,j=1;
        while(j<N){
            int len=min(dict[i].length(),dict[j].length());
            for(int m=0;m<len;m++){
                if(dict[i][m]!=dict[j][m]){
                    alpAdj[dict[i][m]-'a'].push_back(dict[j][m]-'a');
                    indegree[dict[j][m]-'a']++;
                    break;
                }
            }
            i++;
            j++;
        }
        queue<int> nodes;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                nodes.push(i);
            }
        }
        
        string ans="";
        while(!nodes.empty()){
            int node=nodes.front();
            nodes.pop();
            ans=ans+static_cast<char>(node+'a');
            for(int neighbour:alpAdj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    nodes.push(neighbour);
                }
            }
        }
        // cout<<ans;
        return ans;
    }
};