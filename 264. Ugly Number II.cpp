/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
*/

// //TLE 500 / 596 
// class Solution {
// bool isUgly(int num){
//     for(int n:{2,3,5}){
//         while(num%n==0){
//             num/=n;
//         }
//     }
//     return num==1;
// }
// public:
//     int nthUglyNumber(int n) {
//         int i=1;
//         int count=1;
//         while(count<n){
//             i++;
//             if(isUgly(i)){
//                 count++;
//             }
//         }
//         return i;
//     }
// };

/*
first ugly number : 1
later ugly number should have prime factors only -> 2,3,5

2 => 2*1, 2*2, 2*3, 2*4, 2*5, 2*6, 2*7, 2*8, 2*9, 2*10 
3 => 3*1, 3*2, 3*3, 3*4, 3*5, 3*6, 3*7, 3*8, 3*9, 3*10 
5 => 5*1, 5*2, 5*3, 5*4, 5*5, 5*6, 5*7, 5*8, 5*9, 5*10 

2 => 2(2), 4(4), 6(6), 8(7), 10(9), 12(10), 14(WRONG), 16, 18, 20 
3 => 3(3), 6(6), 9(8), 12(10), 15, 18, 21, 24, 27, 30
5 => 5(5), 10(9), 15, 20, 25, 30, 35, 40, 45, 50
y(x) -> x means ith ughly number


14 -> 2*7 X
next number should be 16....lets arrange the array pattern
[1,2,3,5,4,5,6,8,9,10,12]
observe the pattern they are telling us something
1. They have 2,3,5 as only prime factor thats obvious
2. They are also telling the next multiple of factor{2,3,5}
i.e 10 ugly -> 2*5 <-
    next multiple will be 8 ->2*8
    [confused why not 6 let's see why]

    the ugly number must be of for 2^x3^y5^z.

    now if you see belo programm i have used
    nmof3 aka x,nmof3 aka y,nmof5 aka z

    first ugly number 1;
    ugly = {1}
    next can be :
        (2^1)(3^0)(5^0) =2
        (2^0)(3^1)(5^0) =3
        (2^0)(3^0)(5^1) =5
    we choose 2 now power of 2 next time will be +1
    .......and so on.........

    see below programm
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0]=1;

        int i2=0,i3=0,i5=0;

        int nmof2=2*1; //next multiple of 2
        int nmof3=3*1; //next multiple of 3
        int nmof5=5*1; //next multiple of 5
        for(int i=1;i<n;i++){
            int nextUglyNumber=min(nmof2,min(nmof3,nmof5));
            ugly[i]=nextUglyNumber;
            if(nextUglyNumber==nmof2){
                i2++;
                nmof2=2*ugly[i2];
            }
            if(nextUglyNumber==nmof3){
                i3++;
                nmof3=3*ugly[i3];
            }
            if(nextUglyNumber==nmof5){
                i5++;
                nmof5=5*ugly[i5];
            }
        }
        return ugly[n-1];
    }
};