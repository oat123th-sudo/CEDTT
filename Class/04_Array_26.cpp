#include <bits/stdc++.h>

int main(){
    int n,in=0,re;
    std::cin>>n;
    int num[n*n];
    for(int i=0;i<n*n;i++){
        std::cin>>num[i];
        if(num[i]==0){re=i/n;}
    }
    for(int i=0;i<n*n;i++){
        for(int j=i+1;j<n*n;j++){
            if(num[j]<num[i]&&(num[j]!=0&&num[i]!=0)){
                in++;
            }
        }
    }
    //std::cout<<in<<" "<<re;
    if(n%2==1&&in%2==0){
        std::cout<<"YES";
    }
    else if(n%2==0){
        if(in%2==1&&re%2==0){
            std::cout<<"YES";
        }
        else if(in%2==0&&re%2==1){
            std::cout<<"YES";
        }
        else{std::cout<<"NO";}
    }
    else{std::cout<<"NO";}
}