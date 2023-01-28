/*
In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

 

Example 1:

Input: maxChoosableInteger = 10, desiredTotal = 11
Output: false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
Example 2:

Input: maxChoosableInteger = 10, desiredTotal = 0
Output: true
Example 3:

Input: maxChoosableInteger = 10, desiredTotal = 1
Output: true
 

Constraints:

1 <= maxChoosableInteger <= 20
0 <= desiredTotal <= 300
*/


//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// class Solution {
// private:
//     //mcn : maxChoosableInteger
//     //dt : desiredTotal
//     //cn : chosen numbers
//     /*
//     how to read this code..
//     NOTE : base case in public function are must..
//     now for private function... let say player1 choose 'i' (comment //1.)
//     then in next call we saw dt<=0(comment //2.) now it was opponent who 
//     saw dt<=0->opponent lose we won

//     but you might as that what if player 1 see dt<=0 -> then player 1 loses->return false to
//     parent->parent is player 1->return true->condition false....

//     IMPORTANT : 
//     if((cn&(1<<i))==0 && !canIWin(mci,dt-i,cn|(1<<i))){// 1. 
//         return true;
//     }

//     this code at one point in time speaks differently
//     i.e -> opponent turn : i take this ele and if player1 fails i won(opponent)
//     at another time it speaks
//     i.e -> player1 turn : i take this ele and if opponent fails i won(player1)

//     it like a tree we choose a root(level 1) whose branches return false

//     for example let say we have 
//     desiredtotal=4;
//     maxChosable=6;

//     roots can be -> 1(root1)   2(root1)   3(root1)   4(root1) <- level 1

//     root1 said(1,2,3,4 either one) -> 1 pick let say 1 -> if level 2 roots fails i won..
//     what i mean is ---------->
//                         root1(let say 1) <----level 1 (player1)
//     child of root1----->root2(2)    root2(3)    root2(3) root2(4)  <---level 2 (opponent)
//     so you see game proceed in player1->opponent->player1->opponent
//     and if any number chosen by player1 makes opponent loses is our answer

//     if all root2 return false for givent i player 1 won else lose
//     Hope you got the answer
//     */
//     bool canIWin(int mci, int dt,int cn) {
//         if(dt<=0){//2.
//             return false;
//         }
//         for(int i=1;i<=mci;i++){
//             //if i is not already taken->i will take it and if opponent cannot win->i won
//             if((cn&(1<<i))==0 && !canIWin(mci,dt-i,cn|(1<<i))){// 1. 
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
//         int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
//         if(sum < desiredTotal) return false;
//         if(desiredTotal <= 0) return true;
//         if(sum== desiredTotal) return maxChoosableInteger&1;
        
//         return canIWin(maxChoosableInteger,desiredTotal,0);
//     }
// };
/////////////////////////////////
class Solution {
private:
    //mcn : maxChoosableInteger
    //dt : desiredTotal
    //cn : chosen numbers
    bool canIWin(int mci, int dt,int cn,unordered_map<int,int> &memo) {
        if(dt<=0){//2.
            return false;
        }
        if(memo[cn]){
            return true;
        }
        for(int i=1;i<=mci;i++){
            //if i is not already taken->i will take it and if opponent cannot win->i won
            if((cn&(1<<i))==0 && !canIWin(mci,dt-i,cn|(1<<i),memo)){// 1. 
                return memo[cn]=true;
            }
        }
        return memo[cn]=false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if(sum < desiredTotal) return false;
        if(desiredTotal <= 0) return true;
        if(sum== desiredTotal) return maxChoosableInteger&1;
        
        unordered_map<int,int> memo;
        return canIWin(maxChoosableInteger,desiredTotal,0,memo);
    }
};