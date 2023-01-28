/*
Intuition
Write some example, you find all even length palindromes are divisible by 11.
So we need to search only palindrome with odd length.

We can prove as follow:
11 % 11 = 0
1111 % 11 = 0
111111 % 11 = 0
11111111 % 11 = 0

So:
1001 % 11 = (1111 - 11 * 10) % 11 = 0
100001 % 11 = (111111 - 1111 * 10) % 11 = 0
10000001 % 11 = (11111111 - 111111 * 10) % 11 = 0

For any palindrome with even length:
abcddcba % 11
= (a * 10000001 + b * 100001 * 10 + c * 1001 * 100 + d * 11 * 1000) % 11
= 0

All palindrome with even length is multiple of 11.
So among them, 11 is the only one prime
if (8 <= N <= 11) return 11

For other cases, we consider only palindrome with odd dights.


More Generally
Explanation from @chuan-chih:
A number is divisible by 11 if sum(even digits) - sum(odd digits) is divisible by 11.
Base case: 0
Inductive step:
If there is no carry when we add 11 to a number, both sums +1.
Whenever carry happens, one sum -10 and the other +1.
The invariant holds in both cases.


Time Complexity
O(10000) to check all numbers 1 - 10000.
isPrime function is O(sqrt(x)) in worst case.
But only sqrt(N) worst cases for 1 <= x <= N
In general it's O(logx)


C++:

    int primePalindrome(int N) {
        if (8 <= N && N <= 11) return 11;
        for (int x = 1; x < 100000; ++x) { // is hald of [2,10^8] range => x (max) = 9999999 = 10^8
            string s = to_string(x), r(s.rbegin(), s.rend());
            int y = stoi(s + r.substr(1));
            if (y >= N && isPrime(y)) return y;
        }
        return -1;
    }
    bool isPrime(int num) {
        if (num < 2 || num % 2 == 0) return num == 2;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
Java:

    public int primePalindrome(int N) {
        if (8 <= N && N <= 11) return 11;
        for (int x = 1; x < 100000; x++) {
            String s = Integer.toString(x), r = new StringBuilder(s).reverse().toString();
            int y = Integer.parseInt(s + r.substring(1));
            if (y >= N && isPrime(y)) return y;
        }
        return -1;
    }

    public Boolean isPrime(int x) {
        if (x < 2 || x % 2 == 0) return x == 2;
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    }
Python:

    def primePalindrome(self, N):
        def isPrime(x):
            if x < 2 or x % 2 == 0: return x == 2
            for i in xrange(3, int(x**0.5) + 1, 2):
                if x % i == 0: return False
            return True
        if 8 <= N <= 11: return 11
        for x in xrange(10 ** (len(str(N)) / 2), 10**5):
            y = int(str(x) + str(x)[-2::-1])
            if y >= N and isPrime(y): return y
*/

///////////////////////////////////////////////////////////////MYCODE////////////////////////////////
/*
Given an integer n, return the smallest prime palindrome greater than or equal to n.

An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

For example, 2, 3, 5, 7, 11, and 13 are all primes.
An integer is a palindrome if it reads the same from left to right as it does from right to left.

For example, 101 and 12321 are palindromes.
The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

 

Example 1:

Input: n = 6
Output: 7
Example 2:

Input: n = 8
Output: 11
Example 3:

Input: n = 13
Output: 101
 

Constraints:

1 <= n <= 108
*/
// //TLE 51 / 61 
// class Solution {
//     bool isPrime(int n){
//         if(n<=1){
//             return false;
//         }
//         if(n<=3){
//             return true;
//         }
//         if(n%2==0 || n%3==0){
//             return false;
//         }

//         for(int i=5;i*i<=n;i+=6){
//             if(n%i==0 || n%(i+2)==0){
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool isPalindrome(int n){
//         string str=to_string(n);
//         int len=str.length();
//         int i=0,j=len-1;
//         while(i<j){
//             if(str[i]!=str[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
// public:
//     int primePalindrome(int n) {
//         int i=n;
//         while(true){
//             if(isPrime(i) && isPalindrome(i)){
//                 return i;
//             }
//             i++;
//         }
//         return -1;
//     }
// };
////////////////////////////////////////////////////////////////////////////
class Solution {
    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        if(n<=3){
            return true;
        }
        if(n%2==0 || n%3==0){
            return false;
        }

        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0){
                return false;
            }
        }
        return true;
    }
public:
    int primePalindrome(int n) {
        if(n>=8 && n<=11){
            return 11;
        }

        for(int i=1;i<100000;i++){
            string left=to_string(i);
            string right=left;
            reverse(right.begin(),right.end());
            int num=stoi(left+right.substr(1));
            if(num>=n && isPrime(num)){
                return num;
            }
        }
        return -1;
    }
};