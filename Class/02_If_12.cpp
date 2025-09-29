#include <bits/stdc++.h>
int main(){
    int n;
    std::cin>>n;
    if(n>=80){
        std::cout<<"A";
    }
    else if(n>=70){
        std::cout<<"B";
    }
    else if(n>=60){
        std::cout<<"C";
    }
    else if(n>=50){
        std::cout<<"D";
    }
    else{
        std::cout<<"F";
    }
}