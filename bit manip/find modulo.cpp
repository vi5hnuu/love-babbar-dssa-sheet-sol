#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    //%8
    num=num & (0x7);
    cout<<num;
}
