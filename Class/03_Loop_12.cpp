#include <bits/stdc++.h>

int main(){
    double x,a,lx,L=0.0,R;
    std::cin>>a;
    R=a;
    while(1){
        x=(L+R)/2.0;
        double p =pow(10,x);
        if(fabs(a - p) <= 1e-10 * std::max(a, p)) break;
        if(p>a)R=x;
        else L=x;
    }
    std::cout<<x;
}