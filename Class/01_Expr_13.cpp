#include <bits/stdc++.h>

int main(){
    double a,b,c;
    std::cin>>a>>b>>c;
    std::cout<<round(((-b-sqrt(pow(b,2)-4*a*c))/(2*a))*1e3)/1e3<<" ";
    std::cout<<round(((-b+sqrt(pow(b,2)-4*a*c))/(2*a))*1e3)/1e3;
}