// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
 

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int slen=s.length();
      int tlen=t.length();
      if(slen!=tlen)
          return false;
        
      vector<char> mpf(128,'#');
        vector<char> mpb(128,'#'); //128 valid ascii exist hence the length .... took '#' as invalid ascii
      for(int i=0;i<slen;i++){
	  //the login is let say if 'a'->'b' then if we again found that a-> map to other then 'b' then return false
	  //else map a fresh pair
	  //but this isnt enough let say a->b and we get d->b wait what a is mapped to b and d is also mapped to b
	  //here we also need the reverse check that is a is mapped to b then reverse b should also be mapped to a else 
	  //return false
	  
            if(mpf[s[i]]=='#')
                mpf[s[i]]=t[i];
            else if(mpf[s[i]]!=t[i])
                return false;
          
            if(mpb[t[i]]=='#') 
                mpb[t[i]]=s[i];
            else if(mpb[t[i]]!=s[i])
                return false;
      }
        return true;
    }
};
*/
//credit  : @geandyang -> same logic as mine but easier to understand
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[128] = {0}, m2[128] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
		//logic
		//we do the same as what i explained in prev answer 
		//the same happed here 
		//eg
		//egg   add
		//check e and a has same value [true 0,0]
		//e->1  a->1
		//check g and d has same value [true 0,0]
		//g->2 d->2
		//check g and d has same value [true 2,2]
		//g->3 d->3
		
		//eg foo bar
		//check f and b [true 0,0]
		//f->1 b->1
		//check o and a [true 0,0]
		//o->2 a->2
		//check o and r [false 2,0]
		
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};