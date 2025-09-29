#include <bits/stdc++.h>

int main(){
    int cnt=1;
    std::string wo;
    std::cin>>wo;
    for(int i=0;i<wo.size();i++){
        if(wo[i]==wo[i+1])cnt++;
        else{std::cout<< wo[i]<<" "<<cnt<<" ";cnt=1;}
    }
}