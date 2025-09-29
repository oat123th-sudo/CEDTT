#include <bits/stdc++.h>

int main(){
    int n,l,r,s;
    std::cin>>n;
    r=l=s=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<s;j++){
            if(i==n-1){std::cout<<"*";continue;}
            if(i==0&&j==s-1){std::cout<<"*";continue;}
            if(j==l-1||j==r-1){
                std::cout<<"*";
            }else{std::cout<<".";}
        }
        std::cout<<std::endl;
        l--;
        r++;
        s++;
    }
}