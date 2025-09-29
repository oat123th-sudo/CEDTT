#include <bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    if(n>0){std::cout<<"positive\n";}
    if(n==0){std::cout<<"zero\n";}
    if(n<0){std::cout<<"negative\n";}
    if(n%2==0){std::cout<<"even";}
    else{
        std::cout<<"odd";
    }
}