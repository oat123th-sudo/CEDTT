#include <bits/stdc++.h>

int main(){
    int a;
    std::cin>>a;
    a=a-543;
    a=a%100;
    std::cout<<(a+a/4+11)%7;
}