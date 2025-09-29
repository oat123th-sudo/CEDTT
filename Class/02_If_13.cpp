#include <bits/stdc++.h>

int main(){
    double a,b=INT_MIN,c=INT_MAX,s=0;
    for(int i=0;i<4;i++){
        std::cin>>a;
        if(a>b){b=a;}
        if(a<c){c=a;}
        s+=a;
    }
    std::cout<<round((s-b-c)/2*100)/100;
}