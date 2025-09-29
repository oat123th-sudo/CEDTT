#include <bits/stdc++.h>

int main(){
    double a;
    std::cin>>a;
    std::cout<<round((pow(a,sqrt(log(pow(a+1,2))))/(10-a))*1e6)/1e6;
}