#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    num=~num & (num+1);
    cout<<num;
}
