#include <bits/stdc++.h>

int main(){
    std::vector<int> num;
    int n;
    std::cin>>n;
    while(n!=1){
        if(num.size()<15){
            num.push_back(n);
        }
        else{
            num.push_back(n);
            num.erase(num.begin());
        }
        if(n%2==0){
            n=n/2;
        }
        else{
            n=3*n+1;
        }
    }
    num.push_back(1);
    if(num.size()>15){
        num.erase(num.begin());
    }
    //std::cout<<num.size()<<'\n';
    for(int i=0;i<num.size();i++){
        std::cout<<num[i];
        if(i!=num.size()-1){
            std::cout<<"->";
        }
    }
}