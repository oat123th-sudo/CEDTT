#include <bits/stdc++.h>

int main(){
    double cnt=-1;
    double n=0,sum=1;
    while(n!=-1){
        std::cin>>n;
        cnt++;
        sum+=n;
    }
    if(cnt>0){
        std::cout<<round(sum*100/cnt)/100;
    }
    else{
        std::cout<<"No Data";
    }
}