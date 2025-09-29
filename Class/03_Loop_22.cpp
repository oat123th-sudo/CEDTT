#include <bits/stdc++.h>

int main(){
    int n,mn,r=2,cnt=0,ocnt=0;
    std::cin>>n;
    while(n%2==0){
        std::cout<<2;
        cnt++;
        n/=2;
        if(cnt!=ocnt&&n!=1){std::cout<<"*";ocnt=cnt;}
    }
    for(int i=3;i<=n;i+=2){
        while(n%i==0){
            std::cout<<i;
            cnt++;
            n/=i;
            if(cnt!=ocnt&&n!=1){std::cout<<"*";ocnt!=cnt;}
        }
        
    }
}