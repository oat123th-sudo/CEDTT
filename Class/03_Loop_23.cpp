#include <bits/stdc++.h>

int main(){
    std::string wo;
    int cnt=1,n;
    std::cin>>wo>>n;
    for(int i=0;i<wo.size();i++){
        if(wo[i]==wo[i+1]){cnt++;}
        else{
            while(cnt<n){
                if(cnt==0)break;
                cnt--;
                std::cout<<wo[i];
            }
            cnt=1;
        }
    }
}