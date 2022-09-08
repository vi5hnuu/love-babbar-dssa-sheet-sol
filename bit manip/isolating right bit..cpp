#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    num=(~num+1) & num;
    cout<<num;
}
