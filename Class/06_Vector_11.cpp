#include <bits/stdc++.h>

int main(){
    std::vector<int> num;
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        num.push_back(x);
    }
    std::string nn;
    getline(std::cin,nn);
    std::stringstream ss(nn);
    int x;
    while(ss>>x){
        num.push_back(x);
    }
    while(x>=0){
        std::cin>>x;
        if(x==-1){
            break;
        }
        num.push_back(x);
    }
    std::vector<int> show;
    int cnt=0,cnti=0;
    for(int i=0;i<num.size();i++){
        if(i%2==0){
            show.push_back(num[i]);
            continue;
        }
        show.insert(show.begin(),num[i]);
    }
    if(show.size()==0){
        std::cout<<"[]";
    }
    for(int i=0;i<show.size();i++){
        if(i==0){
            std::cout<<'[';
            std::cout<<show[i]<<", ";
        }
        else if(i==show.size()-1){
            std::cout<<show[i];
            std::cout<<']';
        }
        else{
            std::cout<<show[i];
            std::cout<<", ";

        }
    }
    
}