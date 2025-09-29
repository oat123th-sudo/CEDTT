#include <bits/stdc++.h>
std::map<int,int> num;
int main(){
    int n;
    while(std::cin>>n){
        num[n]++;
    }
    int cnt=0;
    std::cout<<num.size()<<'\n';
    for(auto e=num.begin();e!=num.end()&&cnt<10;e++,cnt++){
        std::cout<<e->first<<" ";
    }
    std::cout<<'\n';
}