#include<bits/stdc++.h>
using namespace std;


int setBits(int N) {
        int count=0;
        while(N){
            count++;
            N=N & (N-1);
        }
        return count;
    }