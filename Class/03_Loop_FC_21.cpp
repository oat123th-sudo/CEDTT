#include <bits/stdc++.h>

int main(){
    double p,k=1,t=1;
    bool o=0;
    std::cin>>p;
    while(1-t<p){
        t=(t*(365-(k-1)))/365;
        k++;
        o=1;
    }
    if(o==1){k--;}
    std::cout<<k;
}